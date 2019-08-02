/*
	Author: kaydol
	
	Description:
	Checks if two objects intersect, check is based on their bounding boxes.
	
	Parameters:
	_this: ARRAY
		0: OBJECT - Object with bounding box
		1: OBJECT - Object with bounding box

	Returns:
	_intersectionFound: BOOLEAN - True if objects intersect, false otherwise.
	
*/

params ["_object1", "_object2"];

private _corners1 = _object1 call TG_fnc_getCorners;
private _corners2 = _object2 call TG_fnc_getCorners;

private _intersectionFound = false;

{
	if ( _x InPolygon _corners1 ) exitWith { _intersectionFound = true; };
}
forEach _corners2;

if !( _intersectionFound ) then { 
	{
		if ( _x InPolygon _corners2 ) exitWith { _intersectionFound = true; };
	}
	forEach _corners1;
};

_intersectionFound
