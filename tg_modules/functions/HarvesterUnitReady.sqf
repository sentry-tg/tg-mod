
#include "..\variables.h"
/*
params ["_harvester", "_destinationPosOrObj"];

private _condition = false;
if (_destinationPosOrObj isEqualType []) then {
	_condition = speed _harvester == 0 && _harvester distance _destinationPosOrObj < UNITS_HARVESTER_MAX_UNIT_READY_DIST;
};
if (_destinationPosOrObj isEqualType objNull) then {
	if (alive _destinationPosOrObj) then {
		private _closestCorner = [_destinationPosOrObj, _harvester] call BIS_fnc_boundingBoxCorner;
		_condition = speed _harvester == 0 && (_harvester distance _destinationPosOrObj) min (_harvester distance _closestCorner) < UNITS_HARVESTER_MAX_UNIT_READY_DIST;
		
		//-- Additional check to see if bounding boxes of the building and harvester are colliding
		if !(_condition) then {
			_condition = [_harvester, _destinationPosOrObj] call TG_fnc_CheckIntersection;
		};
	};
};
_condition 
*/