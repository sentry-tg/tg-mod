/*
	Checks if the unit is standing firmly on surface.
	
	_this select 0: unit
*/

params ["_unit"];

//	The height above which the unit is considered airborne
_minHeight = 0.25;

_height = getPos _unit # 2; 

if ( (speed _unit <= 0.1 && isTouchingGround _unit) || ( _height < _minHeight )) exitWith { True };

False
