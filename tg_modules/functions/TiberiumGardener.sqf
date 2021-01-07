
#include "..\variables.h"

params ["_logic"];

while { !isNull _logic } do 
{
	_sleepConst = _logic getvariable "GrowthSleep";
	_sleepRnd = _logic getvariable "GrowthRndSleep";
	_crystalRadius = _logic getvariable "CrystalDistance";
	_hideRadius = _logic getvariable "HideObjectRadius";
	_steepness = _logic getvariable "SteepnessLimit";
	_childrenPerFather = _logic getvariable "ChildrenPerFather";
	_greenPhaseTime = _logic getvariable "GreenTiberiumPhaseTime";
	_bluePhaseTime = _logic getvariable "BlueTiberiumPhaseTime";
	_purplePhaseTime = _logic getvariable "PurpleTiberiumPhaseTime";
	_redPhaseTime = _logic getvariable "RedTiberiumPhaseTime";

	_fathers = [] call TG_fnc_TiberiumGetSpawners;
	_acceptedCoords = [];
	_i = 0;

	for [{_i = 0},{_i < count _fathers},{_i = _i + 1}] do {
		( _fathers # _i ) params ["_father", ["_dirToGrandpa", random 360]];
		
		if !( isNull _father ) then //	Checking that the crystal has not been harvested
		{
			_FieldRadius = _father getVariable [SPAWNER_TIBERIUM_FIELDRADIUS, 0];
			_FieldCenter = _father getVariable [SPAWNER_TIBERIUM_FIELDCENTER, [0,0,0]];
			
			_proposedCoordinates = [];
			
			if ( _FieldRadius == 0 || _father distance _FieldCenter < _FieldRadius ) then {
				_proposedCoordinates = [_father, _dirToGrandpa, _childrenPerFather, _crystalRadius, _steepness] call TG_fnc_TiberiumGetChildrenPos;
			}
			else {
				/* 
					This crystal is too far from the center of his field, so 
					it will not propose any coordinates to spawn his children at
				*/
			};
			
			{
				_candidate = _x;
				// Preliminary check that should filter out most of the coordinates
				if ( _acceptedCoords findIf { (_x # 1) distance _candidate < _crystalRadius } < 0 ) then {
					// Final check
					if ( count( _candidate nearObjects [TIBERIUM_ROOT_CLASS, _crystalRadius] ) <= 0 ) then { 
						_acceptedCoords pushBack [_father, _candidate, _candidate getDir _father];
					};
				};
			} forEach _proposedCoordinates;
		};
	};
	
	for [{_i = 0},{_i < count _acceptedCoords},{_i = _i + 1}] do {
		( _acceptedCoords # _i ) params ["_father", "_pos", "_dirToGrandpa"];
		[_pos, _father, _hideRadius, _greenPhaseTime, _bluePhaseTime, _purplePhaseTime, _redPhaseTime] call TG_fnc_TiberiumSpawnCrystal;
		sleep ( _sleepConst + _sleepRnd );
	};
	_acceptedCoords resize 0;

	sleep 1;
};