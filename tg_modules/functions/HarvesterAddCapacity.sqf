
#include "..\variables.h"

params ["_harvester", ["_amountAdded", 0], ["_amountAddedToMax", 0]];

(_harvester call TG_fnc_HarvesterGetCapacity) params ["_currentCapacity", "_maximumCapacity"];

if ( _amountAdded != 0 ) then {
	_harvester setVariable [UNITS_HARVESTER_CAPACITY, ((_currentCapacity + _amountAdded) min (_maximumCapacity + _amountAddedToMax)) max 0, true];
};
if ( _amountAddedToMax != 0 ) then {
	_harvester setVariable [UNITS_HARVESTER_MAXCAPACITY, _maximumCapacity + _amountAddedToMax, true];
};
	