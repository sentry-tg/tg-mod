
#include "..\variables.h"

params ["_harvester"];

(_harvester call TG_fnc_HarvesterGetCapacity) params ["_currentLoad", "_maximumLoad"];
if (_currentLoad <= 0) exitWith { false };

private _refineries = _harvester nearObjects [UNITS_HARVESTER_REFINERY_ROOT_CLASS, UNITS_HARVESTER_MAX_DIST_TO_REFINERY];
count _refineries > 0 

