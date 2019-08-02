
params ["_spawner", ["_type", ""], "_fieldCenter", "_fieldRadius"];

_spawners = missionNameSpace getVariable ["TG_TiberiumSpawners", []];
_spawners pushBackUnique _spawner;

if ( _type != "" ) then {
	_spawner setVariable ["TG_TypeOf", _type];
	_spawner setVariable ["TG_FieldCenter", _fieldCenter];
	_spawner setVariable ["TG_FieldRadius", _fieldRadius];
};

missionNameSpace setVariable ["TG_TiberiumSpawners", _spawners];
