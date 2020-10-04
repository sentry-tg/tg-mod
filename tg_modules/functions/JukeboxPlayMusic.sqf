
#include "..\variables.h"

params ["_logic"];

if !(isServer) exitWith {};

_announceTracks = ( _logic getVariable ['AnnounceTracks', 0] ) == 1;
_poolWeighted = _logic getVariable [LOGIC_JUKEBOX_TRACKS_POOL, []];

/* Conforming to EA demands... */
_forceAnnounce = _logic getVariable [LOGIC_JUKEBOX_FORCE_ANNOUNCE, false];
	
/* 1) If there is only one track in the pool, let it have non-zero weight */
if ( count _poolWeighted == 2 ) then { _poolWeighted set [1, 1] };

/* 2) Select the first track */
_newTrack = selectRandomWeighted _poolWeighted;
_newTrackID = _poolWeighted findIf { _x isEqualTo _newTrack };

/* 3) Increase all the weights by the increment */
_poolWeighted = _poolWeighted apply {
	if ( _x isEqualType 0 ) then {
		_x = _x + 1.0 / ((count _poolWeighted - 2) / 2);
		_w = [_x, 1.0] select (_x > 1.0);
		_x = _w;
	};
	_x
};

/* 4) Set the weight of the currently selected track to be 0 */
_poolWeighted set [_newTrackID + 1, 0];

/* 5) Store the track pool in the Logic namespace */
_logic setVariable [LOGIC_JUKEBOX_TRACKS_POOL, _poolWeighted];

/* 6) Run the track on all connected clients */
[_newTrack] remoteExec ["playMusic", 0];

/* 7) Write track name in chat if enabled */
if ( _announceTracks || _forceAnnounce ) then {
	_name = getText (configFile >> "CfgMusic" >> _newTrack >> "name");
	if ( _forceAnnounce ) then {
		["© Copyright Electronic Arts, Inc., all rights reserved"] remoteExec ["SystemChat", 0];
	};
};