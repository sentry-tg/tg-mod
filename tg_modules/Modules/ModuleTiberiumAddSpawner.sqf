
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
			case 1: { _fakeType = "TG_TiberiumBlue_1"; };
			case 2: { _fakeType = "TG_TiberiumPurple_1"; };
			case 3: { _fakeType = "TG_TiberiumRed_1"; };
			default { _fakeType = "TG_TiberiumGreen_1"; };
		};
		_synced = synchronizedObjects _logic;
		{
			[_x, _fakeType, getPos _x, _fieldRadius] call TG_fnc_TiberiumAddSpawner;
		} 
		forEach _synced;
		_logic synchronizeObjectsRemove _synced;
	};
	
	default {};
};

true
