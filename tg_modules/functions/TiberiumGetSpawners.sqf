
#include "..\variables.h"

_spawners = missionNameSpace getVariable [MISSION_TIBERIUM_SPAWNERS, []];
_spawners = +_spawners;

missionNameSpace setVariable [MISSION_TIBERIUM_SPAWNERS, [], true];

_spawners
