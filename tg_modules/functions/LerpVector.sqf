/*
	Author: kaydol
	
	Description:
	Linear vector3 interpolation

	Parameters:
	_this: ARRAY
		0: Value A
		1: Value B
		2: Interpolation speed
		3: Delta time
	Returns:
	ARRAY
*/

params [["_a", [0,0,0]], ["_b", [0,0,0]], ["_speed", 1.0, [0.0]], ["_deltaTime", 0.0, [0.0]]];

private "_result";
_result = [0,0,0];

if (( _a vectorDistance _b ) > 0.05) then
{
	_result = ( _a vectorMultiply ( 1.0 - _deltaTime * _speed )) vectorAdd ( _b vectorMultiply ( _deltaTime * _speed ));
};

_result;