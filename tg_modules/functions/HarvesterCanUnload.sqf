
#include "..\variables.h"

params ["_harvester"];

private _refineries = _harvester nearEntities [UNITS_HARVESTER_REFINERY_CLASSES, UNITS_HARVESTER_MAX_DIST_TO_REFINERY];

count _refineries > 0 

