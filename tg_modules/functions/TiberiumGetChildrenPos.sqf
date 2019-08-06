
params ["_father", "_dirToGrandpa", "_childrenCount", "_distance", "_steepness"];

private _sweeps = 20;
private _obstaclesSearchRadius = 50;

private _ignore = ["Land_ClutterCutter_large_F", "HoneyBee", "FxWindPollen1", "HouseFly", "Car", "Man", "Air"];
private _param = [-1, -1, _steepness, 1];

/* Try to find a position */
private _sweepDirection = 1 - 2 * round ( random 1 );
private _degreeInc = 360 / _sweeps;

private "_sweepPosition";
private "_i";
private "_proposedCoords";
_proposedCoords = [];

if ( isNull _father ) exitWith {};

_size = _father call BIS_fnc_boundingBoxDimensions;
_size params ["_x", "_y", "_z"];
_shortestSide = [_x, _y] select ( _x > _y );

for [{_i = 1}, {_i < _sweeps && _childrenCount > 0}, {_i = _i + 1}] do 
{
	_sweep = _dirToGrandpa + _i * _degreeInc * _sweepDirection;
	if ( _sweep < 0 ) then { _sweep = _sweep + 360; };
	if ( _sweep > 360 ) then { _sweep = _sweep % 360; };
	
	if ( isNull _father ) exitWith {};

	_sweepPosition = _father getPos [_shortestSide + _distance * 1.5, _sweep];
	_sweepPosition = [_sweepPosition, _distance, _obstaclesSearchRadius, _ignore, _param] call TG_fnc_IsFlatEmpty;
	
	if ( count _sweepPosition > 0 ) then 
	{
		if ( _proposedCoords findIf { _x distance _sweepPosition < _distance } < 0 ) then 
		{
			_proposedCoords pushBack _sweepPosition;
			_childrenCount = _childrenCount - 1;
			_sweepDirection = -_sweepDirection;
			_i = 1;
		};
	};
};

if (_childrenCount > 0) then {
	//hint "Couldn't find position for a seedling.";
};

_proposedCoords 