
#include "..\variables.h"

params ["_spawner", ["_type", ""], "_fieldCenter", "_fieldRadius"];

_spawners = missionNameSpace getVariable [MISSION_TIBERIUM_SPAWNERS, []];
_spawners pushBackUnique _spawner;

if ( _type != "" ) then {
	_spawner setVariable [SPAWNER_TIBERIUM_TYPEOF, _type];
	_spawner setVariable [SPAWNER_TIBERIUM_FIELDCENTER, _fieldCenter];
	_spawner setVariable [SPAWNER_TIBERIUM_FIELDRADIUS, _fieldRadius];
};

missionNameSpace setVariable [MISSION_TIBERIUM_SPAWNERS, _spawners, true];
