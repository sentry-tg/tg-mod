
#include "..\variables.h"

params ["_harvester", ["_refinery", objNull]];

private _curator = _harvester call TG_fnc_HarvesterGetOwner;
if (isNull _curator) exitWith {
	["The harvester has no owner set"] call BIS_fnc_error;
};
if !(alive _refinery) exitWith {};

private _buildingDefs = _curator call TG_fnc_CuratorGetBuildingDefs;
private _refineryDefs = _buildingDefs select { _x # SELECT_BUILDING_TYPE == typeOf _refinery };

if (_refineryDefs isEqualTo []) exitWith {
	[format["Building with building type `%1` is not present in BuildingDefs", typeOf _refinery]] call BIS_fnc_error;
	[[0,0,0], 0]
};

private _refineryDef = _refineryDefs # 0;
private _RPP = _refinery modelToWorld ( _refineryDef # SELECT_READY_PRODUCT_POS );
_RPP set [2, 0.5]; //-- Slightly elevate the RPP

private _direction = (_refineryDef # SELECT_DIRECTION + getDir _refinery + 180) mod 360;

[_RPP, _direction]