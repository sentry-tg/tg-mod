
#include "..\variables.h"

params ["_harvester"];

private _activity = _harvester getVariable [UNITS_HARVESTER_ACTIVITY, UNITS_HARVESTER_ACTIVITY_IDLE];

_activity != UNITS_HARVESTER_ACTIVITY_IDLE