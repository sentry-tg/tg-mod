
#include "..\variables.h"

params ["_harvester"];

(_harvester call TG_fnc_HarvesterGetCapacity) params ["_currentCapacity", "_maxCapacity"];

_currentCapacity >= _maxCapacity 
