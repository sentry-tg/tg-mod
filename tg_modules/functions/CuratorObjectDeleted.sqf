
#include "..\variables.h"

//-- Is called by an "CuratorObjectDeleted" event handler when curator is deleting an object

params ["_curator", "_entity"];

private _buildingDefs = _curator call TG_fnc_CuratorGetBuildingDefs;
private _buildingClasses = [_buildingDefs, SELECT_BUILDING_TYPE] call TG_fnc_BuildingDefs;

if !(typeOf _entity in _buildingClasses) exitWith {};

//-- Sell the building!
//-- Initiate a refund of 50% of the initial cost
private _buildingCost = _buildingDefs select { _x # SELECT_BUILDING_TYPE == typeOf _entity } select 0 select SELECT_BUILDING_COST;
[_curator, _buildingCost / 2] call TG_fnc_CuratorAddMoney;

//-- Create a copy of the deleted building 
private _dummyEntity = typeOf _entity createVehicle getPos _entity;
_dummyEntity setVectorDirAndUp [vectorDir _entity, vectorUp _entity];
_dummyEntity setPos getPos _entity;
deleteVehicle _entity;

//-- Destroy the copy gracefully
[_dummyEntity, _buildingDefs select { _x # SELECT_BUILDING_TYPE == typeOf _dummyEntity } select 0 select SELECT_BUILD_TIME, true] spawn TG_fnc_AnimateConstruction;
playSound "building_sold";

[_curator] call TG_fnc_CuratorUpdateBuildingArea;
[_curator] call TG_fnc_CuratorUpdateBuildingList;
[_curator] call TG_fnc_CuratorUpdateCuratorPoints;