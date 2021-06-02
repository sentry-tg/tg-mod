
#include "..\variables.h"

//-- Is called by an "CuratorObjectPlaced" event handler when curator is placing a new object

params ["_curator", "_entity"];

private _buildingDefs = _curator call TG_fnc_CuratorGetBuildingDefs;
private _buildingClasses = [_buildingDefs, SELECT_BUILDING_TYPE] call TG_fnc_BuildingDefs;

if !(typeOf _entity in _buildingClasses) exitWith {};

//-- Check if we can afford this
private _buildingDef = _buildingDefs select { _x # SELECT_BUILDING_TYPE == typeOf _entity } select 0;
private _buildingCost = _buildingDef # SELECT_BUILDING_COST;
private _curatorMoney = _curator call TG_fnc_CuratorGetMoney;
if (_curatorMoney < _buildingCost) exitWith {
	//-- Can't afford
	deleteVehicle _entity;
	(["eva_insufficient_funds", "cabal_insufficient_funds"] # (_curator getVariable [CURATOR_SIDE, 0])) call TG_fnc_SoundQueue_Add;
};

//-- Can afford
[_curator, -_buildingCost] call TG_fnc_CuratorAddMoney;
(["eva_building", "cabal_building"] # (_curator getVariable [CURATOR_SIDE, 0])) call TG_fnc_SoundQueue_Add;

[_curator] call TG_fnc_CuratorUpdateBuildingArea;
[_entity, _buildingDefs select { _x # SELECT_BUILDING_TYPE == typeOf _entity } select 0 select SELECT_BUILD_TIME] spawn TG_fnc_AnimateConstruction;

[_curator] call TG_fnc_CuratorUpdateBuildingList;
[_curator] call TG_fnc_CuratorUpdateCuratorPoints;

//-- See if there are any scripts added to this building
if !( _buildingDef # SELECT_SERVER_SCRIPTS isEqualTo [] ) then {
	{
		[[[_curator, _entity, _buildingDef # SELECT_BUILD_TIME ], _x], { _this # 0 execVM _this # 1 }] remoteExec ["call", 2];
	}
	forEach ( _buildingDef # SELECT_SERVER_SCRIPTS );
};
if !( _buildingDef # SELECT_GLOBAL_SCRIPTS isEqualTo [] ) then {
	{
		[[[_curator, _entity, _buildingDef # SELECT_BUILD_TIME ], _x], { _this # 0 execVM _this # 1 }] remoteExec ["call", 0];
	}
	forEach ( _buildingDef # SELECT_GLOBAL_SCRIPTS );
};




