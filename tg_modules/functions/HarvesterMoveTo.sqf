
#include "..\variables.h"

params ["_harvester", "_objectOrPosASL", ["_radius", -1]];

private _group = group _harvester;
group _harvester call CBA_fnc_clearWaypoints;

private _NewWP = _group addWaypoint [_objectOrPosASL, _radius];
_NewWP setWaypointType "MOVE";
_NewWP setWaypointStatements ["true", format["vehicle this setVariable ['%1', true]; deleteWaypoint [group this, currentWaypoint (group this)]", MOVE_TO_COMPLETED]];
_harvester setVariable [MOVE_TO_COMPLETED, false, true];