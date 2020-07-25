
#include "..\variables.h"

params ["_harvester"];

private _crystals = _harvester nearEntities [TIBERIUM_ROOT_CLASS, UNITS_HARVESTER_MAX_DIST_TO_CRYSTAL];

count _crystals > 0 

