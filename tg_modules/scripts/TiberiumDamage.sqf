
#include "..\variables.h"

#define DEF_CONFIG_CLASS 0
#define DEF_CONFIG_SIDE 1
#define DEF_CONFIG_WEIGHT 2

if !(isServer) exitWith {};

params [["_radius", 6], ["_damage", 0.05], ["_healedClasses", []], ["_protectiveItems", []], ["_resurrectInfantry", false], ["_ressurectionConfig", []], ["_enableColorCorrection", true], ["_sleep", 2]];

/* Prevent player's death in singleplayer in order to be able to resurrect him */
_presetClasses = _ressurectionConfig select { count _x == 4 };
_customClasses = _ressurectionConfig select { count _x == 3 };

// Zombies & Demons, MAX Aliens specific 
// They have 'player' in their classnames to indicate that the classname is playable
_zombiesAndAliensPlayableClasses = _presetClasses apply {toLowerANSI (_x # 0)} select { _x find "player" > 0 };

_fnc_forcedRagdoll = {
	params ["_target"];
	private _rag = "Land_Can_V3_F" createVehicleLocal [0,0,0];
	_rag setMass 1e10;
	_rag attachTo [_target, [0,0,0], "Spine3"];
	_rag setVelocity [0,0,6];
	_target allowDamage false;
	_target setVelocityModelSpace [0,-2,2];
	detach _rag;
	0 = [_rag,_target] spawn {
		sleep 0.1;
		params ['_rag','_target'];
		deleteVehicle _rag;
		_target allowDamage true;
	};
};

private _playableClasses = (_customClasses select {_x # 0 isKindOf "MAN"}) + (_presetClasses select {_x # 0 find "player" > 0});
private _objectsAndMen = _customClasses + (_presetClasses select {_x # 0 find "player" == -1});
private _skipSetDamage = false;
private _pool = [];

while { True } do 
{
	{
		private _iterable = _x;
		private _isInsideVehicle = vehicle _iterable != _iterable;
		private _isImmune = _iterable getVariable [TG_UNIT_IS_IMMUNE_TO_TIBERIUM, false];
		private _isHealed = typeOf _iterable in _healedClasses;
		
		if !( _isInsideVehicle || (_isImmune && !_isHealed) ) then 
		{
			_tiberiumIsNear = count ( _iterable nearObjects [TIBERIUM_ROOT_CLASS, _radius] ) > 0; 
			if ( _tiberiumIsNear ) then 
			{
				_sign = 1;
				if ( _isHealed ) then { _sign = -1 };
				_newDamageLevel = (( getDammage _iterable ) + _sign * _damage );
				_newDamageIsLethal = _newDamageLevel > 0.9 && !_isHealed;
				
				/*
					This is here because not every class from addon presets 
					is designed to be controllable by players. 
					
					All classes from _customClasses are considered to be either 
					playable by player or being a vehicle\object.
				*/
				if (isPlayer _x) then {
					_pool = _customClasses + _playableClasses;
				} else {
					_pool = _objectsAndMen;
				};
				
				if ( _newDamageIsLethal && _resurrectInfantry && count _pool > 0 ) then {
					private _weights = _pool apply { _x # DEF_CONFIG_WEIGHT };
					(_pool selectRandomWeighted _weights) params ["_class", "_side"];
					
					if (isNil{ _class } || isNil{ _side }) then {
						["Could not select a class to be resurrected as. All weights are 0?"] call BIS_fnc_error;
					};
					
					//diag_log str _ressurectionConfig;
					//diag_log format ["Resurrection: the chosen class is %1, side %2", _class, _side];
					
					if ( _class isKindOf "MAN" ) then { //-- Replace unit with another unit
						if ( isPlayer _iterable ) then { //-- Try to "resurrect" a player
							_skipSetDamage = true;
							[_iterable, _fnc_forcedRagdoll] remoteExec ["call", _iterable];
							[[_side, _class, _enableColorCorrection], {
								params ["_side", "_class", "_enableColorCorrection"];
								
								player switchCamera "INTERNAL";
								cutText ["", "BLACK OUT", 1];
								sleep 1;
								
								//diag_log format ["Resurrection: Created unit for player: %1", _newBody];
								
								private _oldBody = player;
								private _newGrp = createGroup _side;
								private _newBody = _newGrp createUnit [_class, position player, [], 0, "FORM"];
								selectPlayer _newBody;
								_newBody setPos getPos _oldBody;
								deleteVehicle _oldBody;
								
								_newBody setVariable [TG_UNIT_IS_IMMUNE_TO_TIBERIUM, true, true];
								
								//-- Color
								if (_enableColorCorrection) then 
								{									
									[_newBody] spawn 
									{
										params ["_newBody"];
										
										private _ppCCBase = [0.199, 0.587, 0.114, 0.0];
										private _ppCCIn = [1, 1, 0, [0.0, 0.0, 0.0, 0.5], [4.0, 1.0, 1.0, 0.4], _ppCCBase];
										private _ppCCOut = [1, 1, 0, [0.0, 0.0, 0.0, 0.0], [1.0, 1.0, 1.0, 1.0], _ppCCBase];
										
										private _ppCol = -1;
										private _priority = 1550;
										while { 
											_ppCol = ppEffectCreate ["colorCorrections", _priority]; 
											_ppCol < 0 
										} do { 
											_priority = _priority + 1; 
										}; 
										
										private _colorCorrected = false;
										while {alive _newBody} do {
											if (player != _newBody && _colorCorrected) then {
												_ppCol ppEffectAdjust _ppCCOut;
												_ppCol ppEffectCommit 0;
												_ppCol ppEffectEnable false;
												_colorCorrected = false;
											};
											if (player == _newBody && !_colorCorrected) then {
												_ppCol ppEffectAdjust _ppCCIn;
												_ppCol ppEffectCommit 2;
												_ppCol ppEffectEnable true;
												_colorCorrected = true;
											};
											sleep 1;
										};
										_ppCol ppEffectAdjust _ppCCOut;
										_ppCol ppEffectCommit 2;
										sleep 2;
										_ppCol ppEffectEnable false;
										ppEffectDestroy _ppCol;
									};
								};
								cutText ["", "BLACK IN", 10];
								
							}] remoteExec ["spawn", _iterable]; 
							
						} else { //-- Try to "resurrect" an AI controlled unit
							_skipSetDamage = true;
							[_iterable, _fnc_forcedRagdoll] remoteExec ["call", _iterable];
						
							sleep 1;
							
							private _oldBody = _iterable;
							private _newGrp = createGroup _side;
							private _newBody = _newGrp createUnit [_class, position _oldBody, [], 0, "FORM"];
							_newBody setPos getPos _oldBody;
							
							_newBody setVariable [TG_UNIT_IS_IMMUNE_TO_TIBERIUM, true, true];
							
							//diag_log format ["Resurrection: Created unit for AI: %1", _newBody];
							
							deleteVehicle _oldBody;
						};
						
					} else {
						//-- Replace unit with an object
						private _object = _class createVehicle position _iterable;
						_object setPos getPos _iterable;
						deleteVehicle _iterable;
						
						//diag_log format ["Resurrection: Created object: %1", _object];
					};
				};
				if ( _skipSetDamage ) then {
					_skipSetDamage = false;
				} else {
					_hasProtectiveItems = false;
					if (count _protectiveItems > 0) then {
						_protectiveItems = _protectiveItems apply {toLowerANSI _x};
						//_equippedItems = [headgear _iterable, goggles _iterable, vest _iterable] + vestItems _iterable + uniformItems _iterable + backpackItems _iterable apply {toLowerANSI _x};
						_equippedItems = [headgear _iterable, goggles _iterable, uniform _iterable, vest _iterable] apply {toLowerANSI _x};
						_hasProtectiveItems = count (_equippedItems arrayIntersect _protectiveItems) > 0;
					};
					
					if !(_hasProtectiveItems) then {
						_iterable setDamage _newDamageLevel;
					};
				};
			};
		};
	}
	forEach AllUnits;
	
	sleep _sleep;
};

