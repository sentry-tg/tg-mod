/* ----------------------------------------------------------------------------
Function: TG_fnc_GetBoundingBoxDiscrete

Description:
	Get a slightly bigger bounding box with each side dividable by _step. 
	This function is used to perfectly encase construction sites with fences of given width. 
	
Parameters:
    _building - Building or other object with bounding box [Object].
    _step - Number by which each side of the new bounding box will be dividable [Number].
    
Returns:
    Slightly bigger 2D bounding box of the _building which can fit a whole number of _step on each side [Array of 4 coordinates representing corners of the new bounding box].

Author:
    kaydol
---------------------------------------------------------------------------- */

params ["_building", "_step"];

private _dimensions = _building call BIS_fnc_boundingBoxDimensions;
private _fencesForDim0 = floor( _dimensions # 0 / _step ) + 1;
private _fencesForDim1 = floor( _dimensions # 1 / _step ) + 1;
private _newDim0 = _fencesForDim0 * _step;
private _newDim1 = _fencesForDim1 * _step;
private _buildingCenterPos = _building modelToWorld [0,0,0];
_buildingCenterPos set [2, getPos _building # 2];

private _rotationAngle = getDir _building;
private _allCorners = [
	_buildingCenterPos vectorAdd ([[-_newDim0 / 2, -_newDim1 / 2, 0], _rotationAngle] call BIS_fnc_rotateVector2D),
	_buildingCenterPos vectorAdd ([[-_newDim0 / 2, +_newDim1 / 2, 0], _rotationAngle] call BIS_fnc_rotateVector2D),
	_buildingCenterPos vectorAdd ([[+_newDim0 / 2, +_newDim1 / 2, 0], _rotationAngle] call BIS_fnc_rotateVector2D),
	_buildingCenterPos vectorAdd ([[+_newDim0 / 2, -_newDim1 / 2, 0], _rotationAngle] call BIS_fnc_rotateVector2D)
];
_allCorners