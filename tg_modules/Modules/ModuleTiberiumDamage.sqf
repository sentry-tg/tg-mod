
#include "..\variables.h"

_logic = _this select 0;
_units = _this select 1;
_activated = _this select 2;

//	Logic module that runs this code must be a singletone
[_logic, MISSION_MODULE_TIBERIUM_DAMAGE, "Tiberium Damage Module"] call TG_fnc_MakeSingletone;

_enableDamage = _logic getVariable "DamageInfantry";
_radius = _logic getVariable "Radius";
_damage = _logic getVariable "Damage";
_healedClasses = _logic getVariable "HealedClasses";
_healedClasses = call compile _healedClasses;

if ( _enableDamage == 1 && _damage > 0 ) then 
{
	as = [_radius, _damage, _healedClasses] execVM "tg_modules\scripts\TiberiumDamage.sqf";
};