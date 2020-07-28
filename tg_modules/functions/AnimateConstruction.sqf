
#include "..\variables.h"

params ["_building", ["_buildTime", 5], ["_backwards", false], ["_debug", false]];

private _buildingHeight = (_building call BIS_fnc_boundingBoxDimensions) select 2;
private _dummyFenceObj = FENCE_CLASS createVehicleLocal [0,0,-1000];
(_dummyFenceObj call BIS_fnc_boundingBoxDimensions) params ["_fenceLength", "_fenceWidth", "_fenceHeight"];
deleteVehicle _dummyFenceObj;
private _allCorners = [_building, _fenceLength] call TG_fnc_GetBoundingBoxDiscrete;


//-- Debug 
private _bboxHandler = 0;
if (_debug) then {
	DebugDrawAllCorners = _allCorners;
	_bboxHandler = addMissionEventHandler ["EachFrame", {
		private _allCorners = (missionNameSpace getVariable ["DebugDrawAllCorners", []]);
		for [{_j = 0},{_j < count _allCorners},{_j = _j + 1}] do {
			private _startPoint = _allCorners # _j;
			private _endPoint = _allCorners # ((_j + 1) % count _allCorners);
			drawLine3D [_startPoint, _endPoint, [1,0,0,1]];
		};
	}];
};


private _fenceList = [];
private _fenceRotationAngle = 360 / count _allCorners;
for[{_j = 0},{_j < count _allCorners},{_j = _j + 1}] do 
{
	private _startPoint = _allCorners # _j;
	private _endPoint = _allCorners # ((_j + 1) % count _allCorners);
	
	private _fencesNeededForDimension = round( (_startPoint distance _endPoint) / _fenceLength );
	
	for[{_i = 0},{_i < _fencesNeededForDimension},{_i = _i + 1}] do 
	{
		private _normalizedDir = _startPoint vectorFromTo _endPoint;
		private _newPosForFence = _startPoint vectorAdd ( _normalizedDir vectorMultiply ( _fenceLength * _i ));
		private _fenceObj = FENCE_CLASS createVehicle _newPosForFence;
		_fenceObj setVectorDir ([_normalizedDir, _fenceRotationAngle] call BIS_fnc_rotateVector2D);
		_fenceObj setPos _newPosForFence;
		_fenceList pushBack _fenceObj;
	};
};

[[_building], _buildingHeight, _buildTime, 0.03, _backwards] call TG_fnc_ConstructionEmerge; 
[_fenceList, _fenceHeight, 1, 0.03] call TG_fnc_ConstructionEmerge; 
sleep _buildTime;
[_fenceList, _fenceHeight * 1.1, 1, 0.03, true] call TG_fnc_ConstructionEmerge; 
sleep 1;
{
	deleteVehicle _x;
} 
forEach _fenceList;

//-- Debug
if (_debug) then {
	removeMissionEventHandler ["EachFrame", _bboxHandler];
};
