
params ["_mode", "_input"];

[_mode, _input, "Logic"] call TG_fnc_VisualizeModuleRadius3DEN;

switch _mode do 
{
	// Default object init
	case "init": 
	{
		_logic = _input param [0,objNull,[objNull]];
		
		_claimRadius = _logic getVariable "Radius";
		_preset = _logic getVariable "Preset";
		_side = _logic getVariable "Side";
		_side = [WEST, EAST, INDEPENDENT] # _side;
		_name = _logic getVariable ["CommanderName", format ["%1_COMMANDER_%2"], round random 1000000];
		
		[_logic, _side, _name, _preset] call TG_fnc_AICommanderInit;
		
		
		_synced = synchronizedObjects _logic;
		_nearEntities = _logic nearEntities [["Man", "Tank", "House"], _claimRadius];
		_toBeClaimed = _synced + _nearEntities;
		_toBeClaimed = _toBeClaimed arrayIntersect _toBeClaimed; // filter out duplicates
		
		[_name, _toBeClaimed] call TG_fnc_AICommanderClaim;
		
		
		
	};
};




