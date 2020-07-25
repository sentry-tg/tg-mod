
#include "..\variables.h"

_logic = _this select 0;
_units = _this select 1;
_activated = _this select 2;

//	Logic module that runs this code must be a singletone
[_logic, MISSION_MODULE_TIBERIUM_CRYSTAL_VALUE, "Tiberium Crystal Value Module"] call TG_fnc_MakeSingletone;

