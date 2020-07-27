
params ["_logic", "_globalVariableName", "_logicName"];

//	Logic module that runs this code must be a singletone
if !(isNil{ missionNameSpace getVariable _globalVariableName }) exitWith {
	[format["%1: Only one object of this kind is allowed per mission", _logicName]] call BIS_fnc_error;
};
missionNameSpace setVariable [_globalVariableName, _logic, true];

[_logic, _globalVariableName] spawn {
	params ["_logic", "_globalVariableName"];
	while { !isNull _logic } do { sleep 1; };
	missionNameSpace setVariable [_globalVariableName, nil, true];
};
