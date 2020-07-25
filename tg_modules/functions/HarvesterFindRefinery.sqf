
#include "..\variables.h"

params ["_harvester"];

private _curator = _harvester call TG_fnc_HarvesterGetOwner;
if (isNull _curator) exitWith {
	//-- Harvester has no owner set
	["__FILE__: The harvester has no owner set"] call BIS_fnc_error;
	_harvester setDamage 1;
	objNull
};

private _refineries = curatorEditableObjects _curator select { typeOf _x in UNITS_HARVESTER_REFINERY_CLASSES && alive _x });

if (_refineries isEqualTo []) exitWith { objNull }; //-- No refineries

private _refineriesOrderedByDistance = [_refineries, [_harvester], { _input0 distance _x }, "ASCEND"] call BIS_fnc_sortBy;
private _closestRefinery = _refineriesOrderedByDistance # 0;

_closestRefinery
