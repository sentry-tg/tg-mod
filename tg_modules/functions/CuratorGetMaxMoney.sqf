
#include "..\variables.h"

//-- Get curator max money by iterating through all owned buildings

params ["_curator"];
	
private _buildingDefs = _curator call TG_fnc_CuratorGetBuildingDefs;
private _buildingClasses = [_buildingDefs, SELECT_BUILDING_TYPE] call TG_fnc_BuildingDefs;
private _curatorBuildings = curatorEditableObjects _curator select { typeOf _x in _buildingClasses && alive _x };

private _maxMoney = 0;
{
	private _building = _x;
	private _buildingStorage = _buildingDefs select { _x # SELECT_BUILDING_TYPE == typeOf _building} select 0 select SELECT_BUILDING_STORAGE;
	_maxMoney = _maxMoney + _buildingStorage; 
}
forEach _curatorBuildings;

_maxMoney
