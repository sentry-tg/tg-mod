
#include "..\variables.h"

#define RESURRECT_PRESET_NONE 0
#define RESURRECT_PRESET_VISCEROIDS 1
#define RESURRECT_PRESET_ZOMBIES 2
#define RESURRECT_PRESET_ALIENS 3

#define CFGPATCHES_ZOMBIES "Ryanzombies"
#define CFGPATCHES_ALIENS "max_alien"

_logic = _this select 0;
_units = _this select 1;
_activated = _this select 2;

//	Logic module that runs this code must be a singletone
[_logic, MISSION_MODULE_TIBERIUM_DAMAGE, "Tiberium Damage Module"] call TG_fnc_MakeSingletone;

_radius = _logic getVariable "Radius";
_damage = _logic getVariable "Damage";
_healedClasses = _logic getVariable "HealedClasses";
_healedClasses = call compile _healedClasses;
_protectiveItems = _logic getVariable "ProtectiveItems";
_protectiveItems = call compile _protectiveItems;

_resurrectInfantry = _logic getVariable "ResurrectInfantry";
_enableColorCorrection = _logic getVariable "EnableColorCorrection";
_customResurrect = _logic getVariable "CustomResurrect";
_ressurectionConfig = call compile _customResurrect;
_resurrectPreset = _logic getVariable "ResurrectPreset";

/* This check mainly fires if the user screwed up when entering Custom track pool */
if !( _ressurectionConfig isEqualType [] ) exitWith {
	["Invalid custom resurect array for Tiberium Damage Module: '%1'. Exiting...", _ressurectionConfig] call BIS_fnc_error;
};
if ( !(_ressurectionConfig isEqualTo []) && !(_ressurectionConfig isEqualTypeAll []) ) exitWith {
	["Invalid custom resurect array for Tiberium Damage Module: '%1'. Exiting...", _ressurectionConfig] call BIS_fnc_error;
};

switch _resurrectPreset do {
	case RESURRECT_PRESET_ZOMBIES: { 
		_addonName = CFGPATCHES_ZOMBIES;
		_addonEnabled = isClass (configFile >> "CfgPatches" >> _addonName);
		 
		if ( _addonEnabled ) then {
			{ _ressurectionConfig pushBack [_x, RESISTANCE, 1, true] } forEach getArray (configFile >> "CfgPatches" >> _addonName >> "units");
		} else {
			["CfgPatches does not contain '%1', are you missing some addons?", _addonName] call BIS_fnc_error;
		};
	};
	case RESURRECT_PRESET_ALIENS: {
		_addonName = CFGPATCHES_ALIENS;
		_addonEnabled = isClass (configFile >> "CfgPatches" >> _addonName);
		 
		if ( _addonEnabled ) then {
			{ _ressurectionConfig pushBack [_x, RESISTANCE, 1, true] } forEach getArray (configFile >> "CfgPatches" >> _addonName >> "units");
		} else {
			["CfgPatches does not contain '%1', are you missing some addons?", _addonName] call BIS_fnc_error;
		};
	};
	default {};
};

if ( _damage > 0 ) then 
{
	as = [_radius, _damage, _healedClasses, _protectiveItems, _resurrectInfantry == 1, _ressurectionConfig, _enableColorCorrection == 1] execVM "tg_modules\scripts\TiberiumDamage.sqf";
};