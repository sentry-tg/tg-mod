
#include "..\variables.h"

if !(isServer) exitWith {};

params ["_curator", "_WarfactoryOrRefinery", "_delay"];

sleep _delay;

private _side = [GDI, NOD] select ( _curator getVariable CURATOR_SIDE );
private _grp = createGroup _side;
private _type = HARVESTER_CLASSES select ( _curator getVariable CURATOR_SIDE );


private _buildingDefs = _curator call TG_fnc_CuratorGetBuildingDefs;
private _refineryDefs = _buildingDefs select { _x # SELECT_BUILDING_TYPE == typeOf _WarfactoryOrRefinery };
private _def = _refineryDefs # 0;
private _RPP = _WarfactoryOrRefinery modelToWorld ( _def # SELECT_READY_PRODUCT_POS );
_RPP set [2, 0.5]; //-- Slightly elevate the RPP


private _harvester = _type createvehicle _RPP;
[_harvester, _grp] spawn BIS_fnc_spawnCrew;

[_harvester, 0, 1400] call TG_fnc_HarvesterSetCapacity;
[_harvester, _curator] call TG_fnc_HarvesterSetOwner;

_harvester setBehaviour "CARELESS";
_harvester disableAI "AUTOTARGET";

_curator addCuratorEditableObjects [[_harvester], false];

[_harvester] execFSM "\tg_modules\FSM\harvester.fsm";


