/*
	Returns True if the unit has a working jetpack equipped and not inside a vehicle.
	
	_this select 0: unit
*/

params ["_unit"];

if ( isNull _unit ) exitWith { False };

_jetpacks = ["GDI_Jetpack_BP"]; // case sensitive

if ( vehicle _unit == _unit && backpack _unit in _jetpacks ) exitWith { True };

False
