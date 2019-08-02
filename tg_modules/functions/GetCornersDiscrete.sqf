/*
	Author: kaydol
	
	Description:
	Returns coordinates of the bounding box of the given object, all correctly rotated based on object's direction. The bounding box is big enough to fit an integer amount of fences on each side.
	
	Parameters:
	_this: ARRAY
		0: OBJECT - Object with bounding box
		1: NUMBER - Width of 1 fence
		2: (Optional) ARRAY - Bounding box dimensions of given object

	Returns:
	_result: ARRAY
		0: ARRAY - World positions of bounding box corners
		1: ARRAY - New bounding box dimensions
*/

params ["_object", "_fenceWidth", "_size"];
if (isNil{ _size }) then {
	_size = _object call BIS_fnc_boundingBoxDimensions
};
_size params ["_x", "_y", "_z"];

/* How many fences needed to cover sides of the building */
private _unitsX = ceil ( _x / _fenceWidth );
private _unitsY = ceil ( _y / _fenceWidth );

/* How long those fences are */
private _widthX = _unitsX * _fenceWidth;
private _widthY = _unitsY * _fenceWidth;

/* Calculating difference between new widths */
private _surplusX = _widthX - _x;
private _surplusY = _widthY - _y;

private _margin = [_surplusX, _surplusY, 0];

private _result = [
	[_object, _size, _margin] call TG_fnc_getCorners,
	_size vectorAdd _margin
];

_result
