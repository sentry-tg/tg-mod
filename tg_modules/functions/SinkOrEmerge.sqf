/*
	Author: kaydol
	
	Description:
	Makes the object sink or emerge, gradually changing its height until given height is reached.
	
	Parameters:
	_this: ARRAY
		0: ARRAY - Array of objects that need their height changed
		1: NUMBER - Moving speed
		2: NUMBER - +1 or -1, direction of shifting (1 is emerging, -1 is sinking)
		3: (Optional) NUMBER - Distance between old height and new height, uses the height of the tallest object by default
		4: (Optional) STRING - Sound to be played at the start of procedure, no sound played by default
		5: (Optional) BOOL - Use fourth parameter as an absolute height instead of relative shift

*/

params ["_objects", "_speed", "_direction", "_shift", "_sound", ["_isAbsolute", FALSE]];

/* If _shift is not given, use the height of the tallest object */
if (isNil{ _shift }) then {
	_shift = 0;
	{
		private _box = _x call BIS_fnc_boundingBoxDimensions;
		if ( _box select 2 > _shift ) then { _shift = _box select 2 }; 
	}
	forEach _objects;
};

/* For each object, calculate positions where they should be in the end */
private "_newHeight";
private "_i";
private "_obj";
private _scriptHandlers = [];
private _count = count _objects;
private "_script";
private "_curPos";

{
	_curPos = getPosATL _x;
	
	if ( _isAbsolute ) then { 
		_newHeight = _shift 
	} else {
		_newHeight = ( _curPos select 2 ) + _shift * _direction;
	};
	
	_script = [_x, _curPos, _newHeight, _shift, _speed] spawn 
	{
		params ["_obj", "_curPos", "_newHeight", "_shift", "_speed"];
		
		private _iterations = 0;
		private _time = time;
		private "_deltaTime";
		private _curHeight = ( getPosATL _obj ) select 2;
		private "_newPos";
		private "_lerpHeight";
		
		private _dirAndUp = [vectorDir _obj, vectorUp _obj];
		
		while { abs( _curHeight - _newHeight ) > abs( _shift / 70 ) } do 
		{
			scopeName "loop";
			
			_deltaTime = time - _time;
			_time = time;
			
			_curHeight = ( getPosATL _obj ) select 2;
			_lerpHeight = ( _curHeight * ( 1.0 - _deltaTime * _speed )) + ( _newHeight * _deltaTime * _speed );
			
			_newPos = [_curPos select 0, _curPos select 1, _lerpHeight];
			
			_obj setPosATL _newPos;
			_obj setVectorDirAndUp _dirAndUp;
			
			if ( _iterations > 200 ) then 
			{
				breakOut "loop";
			} 
			else 
			{
				_iterations = _iterations + 1 
			};
			
			sleep 0.015;
		};
		
		/* Eliminating remaining distance */
		_obj setPosATL [_curPos select 0, _curPos select 1, _newHeight];
		_obj setVectorDirAndUp _dirAndUp;
	};
	
	_scriptHandlers pushback _script;

} forEach _objects;


if ( !isNil{ _sound } ) then {
	playSound _sound; 
};

waitUntil { { scriptDone _x } count _scriptHandlers == _count };