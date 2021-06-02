
#include "..\variables.h"

//-- Is called by an "CuratorObjectSelectionChanged" event handler when a building is selected
//-- Draws building's name

params ["_curator", "_entity"];
	
private _buildingDefs = _curator call TG_fnc_CuratorGetBuildingDefs;
private _buildingClasses = [_buildingDefs, SELECT_BUILDING_TYPE] call TG_fnc_BuildingDefs;

if (isNil{ uiNamespace getVariable "RscTitleDisplayEmpty" }) then {
	"CommanderGUI" cutRsc ["RscTitleDisplayEmpty", "PLAIN"];
} else {
	if (isNull( uiNamespace getVariable "RscTitleDisplayEmpty" )) then {
		"CommanderGUI" cutRsc ["RscTitleDisplayEmpty", "PLAIN"];
	};
};

if (typeOf _entity in _buildingClasses) then 
{
	private _buildingName = ((_buildingDefs select { _x # SELECT_BUILDING_TYPE == typeOf _entity }) select 0) select SELECT_NAME;

	if (isNil{TG_CuratorSelectedObjectCtrl}) then {
		TG_CuratorSelectedObjectCtrl = objNull;
	};
	if (isNull TG_CuratorSelectedObjectCtrl) then 
	{
		private _ctrl = (uiNamespace getVariable "RscTitleDisplayEmpty") ctrlCreate ["RscStructuredText", -1];
		_ctrl ctrlSetBackgroundColor [0,0,0,0.5];
		_ctrl ctrlSetFont "EtelkaMonospacePro"; 
		_ctrl ctrlSetTextColor [0.3, 1, 0.3, 1];
		//_ctrl ctrlSetFontHeight 0.01; //-- Not used in structured rsc ???
		TG_CuratorSelectedObjectCtrl = _ctrl;
	};

	TG_CuratorSelectedObjectCtrl ctrlSetStructuredText parseText format ["<t size='%2' align='center'>%1</t>", _buildingName, BUILDING_NAME_HINT_FONT_SIZE];
	TG_CuratorSelectedObject = _entity;
	TG_CuratorSelectedObjectCtrl ctrlShow true;
}
else
{
	TG_CuratorSelectedObject = objNull;
	TG_CuratorSelectedObjectCtrl ctrlShow false;
};

//-- Draw a label with building's name on the screen
if (isNil{ missionNameSpace getVariable CURATOR_GUI_HANDLER }) then 
{
	private _id = addMissionEventHandler ["EachFrame", {
		if (isNull ( TG_CuratorSelectedObject     )) exitWith {};
		if (isNil  { TG_CuratorSelectedObjectCtrl }) exitWith {};
		if (isNull ( TG_CuratorSelectedObjectCtrl )) exitWith {};
		private _GUILabelPos = worldToScreen getPos TG_CuratorSelectedObject;
		_GUILabelPos set [0, _GUILabelPos # 0 - BUILDING_NAME_HINT_WIDTH / 2];
		_GUILabelPos set [1, _GUILabelPos # 1 - BUILDING_NAME_HINT_HEIGHT / 2];
		if (
			!(_GUILabelPos isEqualTypeAll 0) || 
			!(_GUILabelPos isEqualType []) || 
			_GUILabelPos isEqualTo []
		) exitWith {}; //-- Outside of screen view or worldToScreen returned [NaN, NaN]
		private _ctrl = TG_CuratorSelectedObjectCtrl;
		if !(ctrlEnabled _ctrl) exitWith {};
		_ctrl ctrlSetPosition [_GUILabelPos # 0, (_GUILabelPos # 1) - 0.05, BUILDING_NAME_HINT_WIDTH, BUILDING_NAME_HINT_HEIGHT];
		_ctrl ctrlCommit 0;
	}];
	missionNameSpace setVariable [CURATOR_GUI_HANDLER, _id];
};