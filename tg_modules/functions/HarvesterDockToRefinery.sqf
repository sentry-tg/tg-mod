
#include "..\variables.h"

params ["_harvester", ["_refinery", objNull]];

([_harvester, _refinery] call TG_fnc_HarvesterGetRefineryRPP) params [["_RPP", [0,0,0]], ["_direction", 0]];
if (_RPP isEqualTo [0,0,0]) exitWith {};

//-- Clerp the harvester to RPP and _direction
private _clerpEnd = _direction;
private _clerpStart = getDir _harvester;
private _clerpTime = linearConversion [50, 0, _harvester distance _RPP,  5, 0, true];
private _time = time;
private _lerpStart = getPos _harvester;
private _lerpEnd = _RPP;

_harvester allowDamage false;
//-- Does not seem to be working with buildings :(
//[_harvester, _refinery] remoteExec ["disableCollisionWith", _harvester]; 

while {_time + _clerpTime > time} do {
	private _alpha = linearConversion [_time, _time + _clerpTime, time, 0, 1];
	private _newPos = [_lerpStart, _lerpEnd, _alpha, 1] call TG_fnc_LerpVector;
	private _dir = [_clerpStart, _clerpEnd, _alpha] call BIS_fnc_clerp;
	_harvester setDir _dir;
	_harvester setPos _newPos;
};

_harvester allowDamage true;
//[_harvester, _refinery] remoteExec ["enableCollisionWith", _harvester];