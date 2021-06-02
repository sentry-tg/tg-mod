
#include "..\variables.h"

params ["_curator", "_buildingDefs"];

private _buildingDefs = _curator call TG_fnc_CuratorGetBuildingDefs;
private _buildingClasses = [_buildingDefs, SELECT_BUILDING_TYPE] call TG_fnc_BuildingDefs;
private _curatorBuildings = curatorEditableObjects _curator select { typeOf _x in _buildingClasses && alive _x };
private _curatorBuildingsClasses = _curatorBuildings apply { typeOf _x };
private _curatorBuildingsDefs = _buildingDefs select { _x # SELECT_BUILDING_TYPE in _curatorBuildingsClasses };

removeAllCuratorEditingAreas _curator;
{
	private _dims = _x call BIS_fnc_boundingBoxDimensions;
	private _buildAreaRadius = 2 * (_dims # 0 max _dims # 1);
	//-- Only big objects add editing areas
	if ( _buildAreaRadius > 30 ) then {
		_curator addCuratorEditingArea [call compile format ["%1%2", round(position _x select 0), round(position _x select 1)], position _x, _buildAreaRadius];
	};
}
forEach _curatorBuildings;