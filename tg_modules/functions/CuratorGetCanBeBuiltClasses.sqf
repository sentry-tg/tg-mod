
#include "..\variables.h"

params ["_curator"];

private _buildingDefs = _curator call TG_fnc_CuratorGetBuildingDefs;
private _buildingClasses = [_buildingDefs, SELECT_BUILDING_TYPE] call TG_fnc_BuildingDefs;
private _curatorBuildingsClasses = (curatorEditableObjects _curator select { typeOf _x in _buildingClasses && alive _x }) apply { typeOf _x };
private _curatorBuildingsDefs = _buildingDefs select { _x # SELECT_BUILDING_TYPE in _curatorBuildingsClasses };
private _canBeBuiltDefs = _buildingDefs select { count(_x # SELECT_BUILDING_NEEDS arrayIntersect ([_curatorBuildingsDefs, SELECT_CONFIG_NAME] call TG_fnc_BuildingDefs)) >= count(_x # SELECT_BUILDING_NEEDS) };
private _canBeBuiltClasses = [_canBeBuiltDefs, SELECT_BUILDING_TYPE] call TG_fnc_BuildingDefs;

_canBeBuiltClasses 

