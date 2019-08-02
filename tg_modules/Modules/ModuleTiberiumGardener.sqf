_logic = _this select 0;
_units = _this select 1;
_activated = _this select 2;

//	Logic module that runs this code must be a singletone
if !(isNil{ TG_ModuleTiberium }) exitWith {
	["Tiberium Growth Module: Only place one module of this kind"] call BIS_fnc_error;
};
TG_ModuleTiberium = 0;

_logic spawn TG_fnc_TiberiumGardener;

while { !isNull _logic } do { sleep 1; };
TG_ModuleTiberium = nil; 