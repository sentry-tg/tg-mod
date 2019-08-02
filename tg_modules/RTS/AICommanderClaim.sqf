
params ["_commanderName", "_collection"];

{
	_unitCategory = "";
	_pushed = objNull;
	
	if ( _x isKindOf "House" ) then 
	{ 
		_unitCategory = "Buildings"; 
		_energyCost = 0;
		if ( _x isKindOf "Refinery" ) then { _energyCost = 1; };
		if ( _x isKindOf "Refinery" ) then { _energyCost = 1; };
		if ( _x isKindOf "Refinery" ) then { _energyCost = 1; };
		if ( _x isKindOf "Refinery" ) then { _energyCost = 1; };
		if ( _x isKindOf "Refinery" ) then { _energyCost = 1; };
		
		_pushed = [_x, _energyCost]; 
	};
	
	if ( _x isKindOf "AnyBrain" && _side == side _x ) then { 
		_unitCategory = "Groups"; 
		_pushed = group _x; 
	};
	
	if ( _x isKindOf "Harvester" && _side == side _x ) then { // TODO change "Harvester" to a correct kind
		_unitCategory = "Harvesters"; 
		_pushed = group _x; 
	};	
	
	if ( _unitCategory != "" ) then {
		_array = [];
		call compile format ["
			if ( isNil { %1_%2 } ) then { %1_%2 = [] }; 
			_array = TG_%1_%2;
		", _commanderName, _unitCategory];
		
		_array pushBackUnique _x;
	};
} 
forEach _collection;



