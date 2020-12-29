
#include "..\variables.h"

_mode = param [0,"",[""]];
_input = param [1,[],[[]]];

[_mode, _input, "Synced"] call TG_fnc_VisualizeModuleRadius3DEN;

switch _mode do {
	// Default object init
	case "init": 
	{
		_logic = _input param [0,objNull,[objNull]]; // Module logic
		_isActivated = _input param [1,true,[true]]; // True when the module was activated, false when it's deactivated
		_isCuratorPlaced = _input param [2,false,[true]]; // True if the module was placed by Zeus
		
		_color = _logic getVariable "CrystalColor";
		_fieldRadius = _logic getVariable "Radius";
		_fakeType = "";
		switch ( _color ) do {
			case 1: { _fakeType = TIBERIUM_BLUE select count TIBERIUM_BLUE - 1; };
			case 2: { _fakeType = TIBERIUM_PURPLE select count TIBERIUM_PURPLE - 1; };
			case 3: { _fakeType = TIBERIUM_RED select count TIBERIUM_RED - 1; };
			default { _fakeType = TIBERIUM_GREEN select count TIBERIUM_GREEN - 1; };
		};
		_synced = synchronizedObjects _logic;
		{
			_x allowDamage false;
			[_x, _fakeType, getPos _x, _fieldRadius] call TG_fnc_TiberiumAddSpawner;
		} 
		forEach _synced;
		_logic synchronizeObjectsRemove _synced;
		
		//-- Show error if no Tiberim Gardener Module is present in the mission		
		sleep 1;
		private _moduleGardener = missionNameSpace getVariable MISSION_MODULE_GARDENER;
		if (isNil{ _moduleGardener }) then {
			["No Tiberium Gardener module found"] call BIS_fnc_error;
		};
		
	};
	
	default {};
};

true
