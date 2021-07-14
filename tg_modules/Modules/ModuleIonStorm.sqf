
#include "..\variables.h"

_mode = param [0,"",[""]];
_input = param [1,[],[[]]];

[_mode, _input] call TG_fnc_VisualizeModuleRadius3DEN;

switch _mode do {
	// Default object init
	case "init": 
	{
		_logic = _input param [0,objNull,[objNull]]; // Module logic
		_isActivated = _input param [1,true,[true]]; // True when the module was activated, false when it's deactivated
		_isCuratorPlaced = _input param [2,false,[true]]; // True if the module was placed by Zeus
		
		_radius = _logic getVariable "Radius";
		_rain = (_logic getVariable "Rain") == 1;
		_constantTimeBetweenBolts = _logic getVariable "ConstantTimeBetweenBolts";
		_randomAdditionTimeBetweenBolts = _logic getVariable "RandomAdditionTimeBetweenBolts";
		_numberOfBolts = _logic getVariable "NumberOfBolts";
		_hitProbability = _logic getVariable "HitProbability";
		
		_startCondition = compile ( _logic getVariable ["StartCondition", "true"] );
		_stopCondition = compile ( _logic getVariable ["StopCondition", "false"] );
		_loopConditions = ( _logic getVariable ["LoopConditions", 0] ) == 1;
		
		_fnc_distanceCheck = {
			params ["_logic", "_inside"];
			if (isNull _logic || isNull player) exitWith { false };
			_radius = _logic getVariable "Radius";
			if (_radius <= 0) exitWith { true };
			call (
				[
					{player distance _logic > _radius}, // if _inside == false 
					{player distance _logic <= _radius} // if _inside == true
				] select _inside
			)
		};
		
		_colorCorrHandle = 0 spawn {};
		_lightningsHandle = 0 spawn {};
		_ppCCBase = [0.199, 0.587, 0.114, 0.0];
		_ppCCIn = [1, 1, 0, [0.0, 0.0, 0.3, 0.3], [1.0, 1.2, 1.0, 1.0], _ppCCBase];
		_ppCCOut = [1, 1, 0, [0.0, 0.0, 0.0, 0.0], [1.0, 1.0, 1.0, 1.0], _ppCCBase];
		_transitionTime = 3;
		_oldOvercast = 0;
		_oldGusts = 0;
		_oldRain = 0;
		_oldLightnings = 0;
		
		while { true } do 
		{
			diag_log format ["Initiating the loop %1=%2 && %3",_startCondition,call _startCondition, [_logic, true] call _fnc_distanceCheck];
			
			/* Wait until a user-defined condition is true */
			WaitUntil { sleep 1; call _startCondition }; 
			
			if (_rain) then 
			{
				// save old params 
				_oldOvercast = overcast;
				_oldGusts = gusts;
				_oldRain = rain;
				_oldLightnings = lightnings;
				
				// ==================================== //
				// 					rain				//
				// ==================================== //
				
				_transitionTime setGusts 1;
				_transitionTime setOvercast 1;
				_transitionTime setLightnings 1;
				_transitionTime setRain 1;
				forceWeatherChange;
				
				// ==================================== //
				// 				lightning				//
				// ==================================== //
				
				if (isServer) then 
				{
					_lightningsHandle = [_logic, _radius, _numberOfBolts, _hitProbability,  _constantTimeBetweenBolts, _randomAdditionTimeBetweenBolts] spawn 
					{
						params ["_logic", "_radius", "_numberOfBolts", "_hitProbability", "_constantTimeBetweenBolts", "_randomAdditionTimeBetweenBolts"];
						
						_hitPos = [];
						_infinite = false;
						
						if !(_numberOfBolts isEqualType 0) then {
							_numberOfBolts = 0;
						};
						if (_numberOfBolts <= 0) then {
							_infinite = true;
						};
						
						while { _infinite || _numberOfBolts > 0 } do 
						{
							if (random 1 < _hitProbability) then {
								_targets = nearestObjects [_logic, ["Land", "Air", "House"], _radius, true];
								if (count _targets > 0) then {
									_hitPos = getPos selectRandom _targets;
								};
							};
							if (_hitPos isEqualTo []) then {
								_hitPos = (getPos _logic) getPos [random _radius, random 360];
							};
							
							// global execution
							[[_hitPos], {
								params ["_pos", "_bolt", "_light", "_lightning", "_duration"];
								
								if (isServer) then {
									_bolt = createVehicle ["LightningBolt",_pos,[],0,"CAN_COLLIDE"];
									_bolt setPosATL _pos;
									_bolt setDamage 1;
								};
								
								_light = "#lightpoint" createVehicleLocal _pos;
								_light setPosATL [_pos select 0,_pos select 1,(_pos select 2) + 10];
								_light setLightDayLight true;
								_light setLightBrightness 300;
								_light setLightAmbient [0.05, 0.05, 0.1];
								_light setLightColor [1, 1, 2];
								
								sleep 0.1;
								_light setLightBrightness 0;
								sleep (random 0.1);
								
								_lightning = (selectRandom ["lightning1_F","lightning2_F"]) createVehicleLocal [100,100,100];
								_lightning setDir random 360;
								_lightning setPos _pos;
								
								_duration = random 3;
								
								for "_i" from 0 to _duration do {
									_time = time + 0.1;
									_light setLightBrightness (100 + random 100);
									waituntil { time > _time };
								};
								deleteVehicle _lightning;
								deleteVehicle _light;
								
							}] remoteExec ["spawn", 0];
							
							sleep (_constantTimeBetweenBolts + random _randomAdditionTimeBetweenBolts);
							if !(_infinite) then { _numberOfBolts = _numberOfBolts - 1 };
						};
					};
				};
			};
			
			if (hasInterface) then 
			{
				// ======================================== //
				// 				color corrections			//
				// ======================================== //
				
				_colorCorrHandle = [_logic, _transitionTime, _ppCCBase, _ppCCIn, _ppCCOut, _fnc_distanceCheck] spawn
				{
					params ["_logic", "_transitionTime", "_ppCCBase", "_ppCCIn", "_ppCCOut", "_fnc_distanceCheck"];
					
					_name = "colorCorrections";
					
					while {true} do 
					{
						// wait until the logic is deleted or player is inside
						WaitUntil { sleep 1; [_logic, true] call _fnc_distanceCheck }; 
						
						// enable color effect
						_ppCol = _logic getVariable ["_ppCol", -1];
						
						if !(ppEffectEnabled _ppCol) then {
							_ppCol = -1;
							_priority = 1550;
							while {
								_ppCol = ppEffectCreate [_name, _priority]; 
								_ppCol < 0 
							} do { 
								_priority = _priority + 1; 
							};
							_logic setVariable ["_ppCol", _ppCol];
							_ppCol ppEffectAdjust _ppCCIn;
							_ppCol ppEffectCommit _transitionTime;
							_ppCol ppEffectEnable true;
						};
						
						// wait until the logic is deleted or player is outside
						WaitUntil { sleep 1; [_logic, false] call _fnc_distanceCheck }; 
						
						// disable color effect
						if !(_ppCol isEqualTo -1) then {
							_ppCol ppEffectAdjust _ppCCOut;
							_ppCol ppEffectCommit _transitionTime;
							[_ppCol, _transitionTime] spawn {
								params ["_ppCol", "_transitionTime"];
								sleep _transitionTime;
								ppEffectDestroy _ppCol;
								diag_log format ["Color corrections are disabled"];
							};
						};
					};
					
				};
			};
			
			_logic setVariable ["ION_STORM_OVER", false, true]; 
			
			/* Wait until a user-defined condition is true */
			WaitUntil { sleep 1; (isServer && scriptDone _lightningsHandle) || _logic getVariable ["ION_STORM_OVER", false] || (call _stopCondition) };
			
			if (isServer) then {
				_logic setVariable ["ION_STORM_OVER", true, true]; 
			};
			_logic setVariable ["ION_STORM_OVER", nil]; 
			
			if !(scriptDone _colorCorrHandle) then {
				terminate _colorCorrHandle;
			};
			
			if !(scriptDone _lightningsHandle) then {
				terminate _lightningsHandle;
			};
			
			if !( _loopConditions ) exitWith 
			{
				if (_rain) then {
					_transitionTime setGusts _oldGusts;
					_transitionTime setOvercast _oldOvercast;
					_transitionTime setLightnings _oldLightnings;
					_transitionTime setRain _oldRain;
					sleep _transitionTime;
					forceWeatherChange;
				};
			
				// disable color effect
				_ppCol = _logic getVariable ["_ppCol", -1];
				if !(_ppCol isEqualTo -1) then {
					_ppCol ppEffectAdjust _ppCCOut;
					_ppCol ppEffectCommit _transitionTime;
					[_ppCol, _transitionTime] spawn {
						params ["_ppCol", "_transitionTime"];
						sleep _transitionTime;
						ppEffectDestroy _ppCol;
						diag_log format ["Color corrections are disabled"];
					};
				};
				
				diag_log format ["The loop will not be restarted"];
			};
		};
		
		if !(isNull _logic) then {
			deleteVehicle _logic;
		};
	};
	
	default {};
};


