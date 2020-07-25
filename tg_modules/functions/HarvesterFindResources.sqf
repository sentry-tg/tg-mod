
#include "..\variables.h"

params ["_harvester"];

private _prevPos = _harvester call TG_fnc_HarvesterGetPreviousPosition;
private _tiberium = [];

//-- Check for tiberium around the previous position
if !(_prevPos isEqualTo []) then {
	_tiberium = _prevPos nearEntities [TIBERIUM_ROOT_CLASS, UNITS_HARVESTER_PREVIOUS_POSITION_SEARCH_RADIUS];
};

//-- Scan the entire map if there was no tiberium around the previous position
if (_tiberium isEqualTo []) then {
	_tiberium = allMissionObjects TIBERIUM_ROOT_CLASS;
};

//-- Return closest tiberium or []
if (_tiberium isEqualTo []) exitWith { [] };
private _tiberiumOrderedByDistance = [_tiberium, [_harvester], { _input0 distance _x }, "ASCEND"] call BIS_fnc_sortBy;
private _closestTiberium = _tiberiumOrderedByDistance # 0;
private _pos = getPos _closestTiberium;

_pos

