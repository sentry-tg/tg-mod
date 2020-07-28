
#include "..\variables.h"

//-- Checks whether the update of Zeus's Create list is needed and calls TG_fnc_CuratorReopenDisplay if so
//-- Does not do anything if Zeus's Create list is up to date

params ["_curator"];
	
private _canBeBuiltClasses = [_curator] call TG_fnc_CuratorGetCanBeBuiltClasses;
private _canBeBuiltClassesPrev = _curator getVariable [CURATOR_CAN_BE_BUILT_CLASSES_PREV, []];

//-- Store all built classes ever to play "New construction options" only once when buildings are first unlocked
private _buildingClassesBuiltSoFar = _curator getVariable [CURATOR_CLASSES_BUILT_SO_FAR, []];

if !(_canBeBuiltClasses isEqualto _canBeBuiltClassesPrev) then 
{
	if (count _canBeBuiltClasses > count _canBeBuiltClassesPrev) then 
	{
		//-- Check if we can now build buildings that weren't able to build ever before
		private _newBuildings = [];
		{ if !( _x in _buildingClassesBuiltSoFar ) then { _newBuildings pushBackUnique _x }; } forEach _canBeBuiltClasses;
		if ( count _newBuildings > 0 ) then {
			(["eva_new_construction_options", "cabal_new_construction_options"] # (_curator getVariable [CURATOR_SIDE, 0])) call TG_fnc_SoundQueue_Add;
			_buildingClassesBuiltSoFar = _buildingClassesBuiltSoFar + _newBuildings;
			_curator setVariable [CURATOR_CLASSES_BUILT_SO_FAR, _buildingClassesBuiltSoFar];
		};
		
		//{
		//	private _cost = 0;
		//	private _show = true;
		//	missionnameSpace setvariable [format["BIS_fnc_registerCuratorObject_%1", _x],[_show,_cost,_cost]];
		//}
		//forEach (_canBeBuiltClasses - _canBeBuiltClassesPrev);
		[] spawn TG_fnc_CuratorReopenDisplay;
	};
	if (count _canBeBuiltClasses < count _canBeBuiltClassesPrev) then 
	{
		//-- We are no longer able to build some buildings
		//{
		//	private _cost = 0;
		//	private _show = false;
		//	missionnameSpace setVariable [format["BIS_fnc_registerCuratorObject_%1", _x],[_show,_cost,_cost]];
		//} 
		//forEach (_canBeBuiltClassesPrev - _canBeBuiltClasses);
		[] spawn TG_fnc_CuratorReopenDisplay;
	};
	_curator setVariable [CURATOR_CAN_BE_BUILT_CLASSES_PREV, _canBeBuiltClasses];
};