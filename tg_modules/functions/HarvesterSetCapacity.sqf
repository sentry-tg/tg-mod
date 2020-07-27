
#include "..\variables.h"

params ["_harvester", "_capacity", "_maxCapacity"];

if (isNil{ _maxCapacity } && isNil{ _harvester getVariable UNITS_HARVESTER_MAXCAPACITY }) then {
	["Harvester should have its maximum capacity set on the first call"] call BIS_fnc_error;
};

_harvester setVariable [UNITS_HARVESTER_CAPACITY, _capacity, true];
if !(isNil{ _maxCapacity }) then {
	_harvester setVariable [UNITS_HARVESTER_MAXCAPACITY, _maxCapacity, true];
};