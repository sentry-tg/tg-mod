
#include "..\variables.h"

params ["_harvester"];

//-- TiberimCrystalValue Module
private _moduleTiberiumValues = missionNameSpace getVariable MISSION_MODULE_TIBERIUM_CRYSTAL_VALUE;
if (isNil{ _moduleTiberiumValues }) then {
	//-- Try to find module in allMissionObjects
	private _modules = allMissionObjects MISSION_MODULE_TIBERIUM_CRYSTAL_VALUE;
	if (_modules isEqualTo []) then {
		["No Tiberium Crystal Value module found"] call BIS_fnc_error;
	} else {
		_moduleTiberiumValues = _modules # 0;
		missionNameSpace setVariable [MISSION_MODULE_TIBERIUM_CRYSTAL_VALUE, _moduleTiberiumValues, true];
	};
};
//-- TiberiumGardener Module
private _moduleGardener = missionNameSpace getVariable MISSION_MODULE_GARDENER;
if (isNil{ _moduleGardener }) then {
	//-- Try to find module in allMissionObjects
	private _modules = allMissionObjects MISSION_MODULE_GARDENER;
	if (_modules isEqualTo []) then {
		["No Tiberium Gardener module found"] call BIS_fnc_error;
	} else {
		_moduleGardener = _modules # 0;
		missionNameSpace setVariable [MISSION_MODULE_GARDENER, _moduleGardener, true];
	};
};
//-- Destroy the harvester to prevent infinite loops in FSM
//-- It's upon mission makers to ensure the required modules are present in the mission
if (isNil{ _moduleTiberiumValues } || isNil{ _moduleGardener }) exitWith {
	_harvester setDamage 1;
};

//-- Now that we know both modules are present, start pulling values from them
private _crystalAwakeRadius = 2 * ( _moduleGardener getVariable "CrystalDistance" );
private _costs = [
	[TIBERIUM_GREEN, _moduleTiberiumValues getVariable "Green" ],
	[TIBERIUM_BLUE, _moduleTiberiumValues getVariable "Blue" ],
	[TIBERIUM_PURPLE, _moduleTiberiumValues getVariable "Purple" ],
	[TIBERIUM_RED, _moduleTiberiumValues getVariable "Red" ]
];

//-- Determine the cost of the crystal based on the data we just pulled
private _nearestCrystal = getPos _harvester nearestObject TIBERIUM_ROOT_CLASS;
if (isNull _nearestCrystal) exitWith {};

private _price = 0;
{
	private _classes = (_x # 0) apply { toLowerANSI _x };
	private _prices = _x # 1;
	if (toLowerANSI typeOf _nearestCrystal in _classes) exitWith {
		_price = _prices # ( _classes find (toLowerANSI (typeOf _nearestCrystal)) ); // Search is cASe-seNsItiVE!
	};
}
forEach _costs;

//-- Increase harvester's current load
(_harvester call TG_fnc_HarvesterGetCapacity) params ["_currentLoad", "_maximumLoad"];
[_harvester, _price] call TG_fnc_HarvesterAddCapacity;

//-- Animate harvester's fork

private _animationSequence = [
	"harvester_harvest", 
	["fork_source", 0.5, true],  
	0.6, 
	["roll", 3], 
	["blades1", 1.5], 
	["blades2", 1.5],  
	0.6,
	["blades1", 0], 
	["blades2", 0],
	0.6,
	["blades1", 1.5], 
	["blades2", 1.5],
	0.6,
	["blades1", 0], 
	["blades2", 0],
	0.6,
	["fork_source", 0, true],  
	["roll", 0] 
];
[_harvester, _animationSequence] spawn TG_fnc_AnimationSequence;


//-- Awake nearby crystals to fill in the gap
private _crystalPos = getPos _nearestCrystal;
deleteVehicle _nearestCrystal;
private _nearbyCrystals = _crystalPos nearObjects [TIBERIUM_ROOT_CLASS, _crystalAwakeRadius];
{
	[_x] call TG_fnc_TiberiumAddSpawner;
}
forEach _nearbyCrystals;

//-- Store position of the last harvest
[_harvester, _crystalPos] call TG_fnc_HarvesterSetPreviousPosition;

sleep 3;
