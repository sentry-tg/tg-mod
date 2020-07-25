
#include "..\variables.h"

params ["_harvester", ["_activity", UNITS_HARVESTER_ACTIVITY_IDLE]];

_harvester setVariable [UNITS_HARVESTER_ACTIVITY, _activity, true];
