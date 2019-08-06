/*
	Author: kaydol
	
	Description:
	Checks whether the area contains any objects in given radius and if the steepness of the terrain is within given limit. If the area is flat and empty, returns _pos, otherwise returns [].
	
	Parameters:
	_this: ARRAY
		0: ARRAY - Position to check
		1: NUMBER - Radius of the object, if any other object is closer than this, it counts as an intersection
		2: NUMBER - Radius of searching for intersecting objects via nearObjects
		3: ARRAY - Array of STRING. If object's kindOf matches one of the strings, it's ignored
		4: ARRAY - params passed to isFlatEmpty, which is used to evaluate steepness 
	
	Returns:
	_pos: ARRAY - Position sent in _this select 0 if the area is good, or empty array [].
	
*/

params ["_pos", "_objRadius", "_searchRadius", "_ignore", "_params"];

/* Proximity check */
private _objects = _pos nearObjects _searchRadius;
private _count = count _objects;
private _obstructed = false;

private "_obj";
private "_i";
private "_closestPos";
private "_dir";

for [{_i = 0}, {_i < _count}, {_i = _i + 1}] do 
{
	_obj = _objects select _i;
	if ({ _obj isKindOf _x } count _ignore == 0 ) then 
	{
		/* If the object is not to be ignored, check intersection */
		
		/* If the object is within objRadius, count it as intersection */
		if ( _pos distance2D _obj <= _objRadius ) exitWith {
			_obstructed = true;
			//hintSilent format ["Intersection with %1\n%2", _obj];
		};
		
		/* Dir from _pos to the object, a normalized vector */
		_dir = _pos vectorFromTo position _obj;
		
		/* Find the end point of the vector with the length of _objRadius, collinear to dir */
		_closestPos = _pos vectorAdd ( _dir vectorMultiply _objRadius );
		
		/* Check if that end point lies within _obj's bounding box */
		if ( _closestPos InPolygon ( _obj call TG_fnc_GetCorners )) exitWith { 
			_obstructed = true;
			//hintSilent format ["Intersection with %1\n%2", _obj];
		};
		
	};
	
};

if ( _obstructed ) exitWith {[]};

/* Flatness check */
_pos isFlatEmpty _params
