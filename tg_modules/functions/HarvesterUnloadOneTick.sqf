
#include "..\variables.h"

params ["_harvester"];

private _curator = _harvester call TG_fnc_HarvesterGetOwner;
if (isNull _curator) exitWith {
	//-- Harvester has no owner set
	["The harvester has no owner set"] call BIS_fnc_error;
	_harvester setDamage 1;
	objNull
};

(_harvester call TG_fnc_HarvesterGetCapacity) params ["_currentCapacity", "_maxCapacity"];

private _unloadPerTick = _maxCapacity / UNITS_HARVESTER_UNLOAD_TIME;

[_harvester, -_unloadPerTick] call TG_fnc_HarvesterAddCapacity;
[_curator, _unloadPerTick] call TG_fnc_CuratorAddMoney;

sleep 1;



