
#include "..\variables.h"

params ["_harvester", "_refinery"];

(_harvester call TG_fnc_HarvesterGetCapacity) params ["_currentLoad", "_maximumLoad"];
if (_currentLoad <= 0 || !(alive _refinery)) exitWith { false };

([_harvester, _refinery] call TG_fnc_HarvesterGetRefineryRPP) params ["_RPP", "_direction"];

_RPP distance _harvester < UNITS_HARVESTER_MAX_DIST_TO_REFINERY

