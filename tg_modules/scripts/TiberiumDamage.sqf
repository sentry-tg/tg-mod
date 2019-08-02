

if !(isServer) exitWith {};

if !( isNil{ TG_ModuleTiberiumDamage_Loop } ) exitWith {};
TG_ModuleTiberiumDamage_Loop = True;

params [["_radius", 6], ["_damage", 0.05], ["_healedClasses", []], ["_sleep", 2]];

while { True } do 
{
	{
		_isInsideVehicle = vehicle _x != _x;
		if !( _isInsideVehicle ) then 
		{
			_tiberiumIsNear = count ( _x nearObjects ["TG_Tiberium", _radius] ) > 0; 
			if ( _tiberiumIsNear ) then 
			{
				_sign = 1;
				if ( typeOf _x in _healedClasses ) then { _sign = -1 };
				_x setDamage (( getDammage _x ) + _sign * _damage );
			};
		};
	} 
	forEach AllUnits;
	
	sleep _sleep;
};

