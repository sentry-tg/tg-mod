/*
	Author: kaydol
	
	Description:
	Returns coordinates of the bounding box of the given object, all correctly rotated based on object's direction.
	
	Parameters:
	_this: ARRAY
		0: OBJECT - Object with bounding box
		1: (Optional) ARRAY - Bounding box dimensions of given object
		2: (Optional) ARRAY - Surplus to sum with bounding box dimensions

	Returns:
	_return: ARRAY - World positions of bounding box corners 
		0: position of the right forward corner
		1: position of the right rear corner
		2: position of the left rear corner
		3: position of the left forward corner
*/

params ["_building", "_size", ["_margin", [0,0,0]], "_return"];

if (isNil{ _size }) then {
	_size = _building call BIS_fnc_boundingBoxDimensions
};

_size = _size vectorAdd _margin;
_size params ["_x", "_y", "_z"];

_return = [
	_building modelToWorld [_x / 2, _y / 2, 0],
	_building modelToWorld [_x / 2, - _y / 2, 0],
	_building modelToWorld [- _x / 2, - _y / 2, 0],
	_building modelToWorld [- _x / 2, _y / 2, 0]
];

_return
