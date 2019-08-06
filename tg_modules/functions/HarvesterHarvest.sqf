/*
#include "..\variables.h"

params ["_harvester", "_crystal"];

if (isNull _crystal) exitWith {};

_price = 0;

switch (typeOf _crystal) do {
	case "TG_TiberiumGreen_1_Seedling": { _price = 112 };
	case "TG_TiberiumGreen_1_Medium": { _price = 252 };
	case "TG_TiberiumGreen_1": { _price = 350 };
	case "TG_TiberiumBlue_1_Seedling": { _price = 224 };
	case "TG_TiberiumBlue_1_Medium": { _price = 504 };
	case "TG_TiberiumBlue_1": { _price = 700 };
	case "TG_TiberiumPurple_1_Seedling": { _price = 224 };
	case "TG_TiberiumPurple_1_Medium": { _price = 504 };
	case "TG_TiberiumPurple_1": { _price = 700 };
	default {};
};

_curLoad = _curLoad +  _price;
if (_curLoad > _maxLoad) then { _curLoad = _maxLoad; };

_unit setVariable [HARVESTER_TIBERIUM_CURRENTLOAD, _curLoad, TRUE];
_pos = position _crystal;

deleteVehicle _crystal;


_harvester animate ["shovel3", 0.6];
sleep 0.6;
_harvester animate ["shovel3", 0];


//	Awaking crystals
_crystals = nearestObjects [_pos, _fertileClasses, _awakeDistance, true];
{
	_input = _x getVariable "TG_input"; // Put this into variables.h
	if (!isNil {_input}) then {_input spawn FS_fnc_SpawnTiberium};
}
forEach _crystals;
*/