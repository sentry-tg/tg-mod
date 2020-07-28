
#include "..\variables.h"

//-- Notification queue framework

params ["_newSound"];
	
private _queue = missionNameSpace getVariable ["SoundQueue", []];
_queue pushBack _newSound;
missionNameSpace setVariable ["SoundQueue", _queue];

if (isNil {missionNameSpace getVariable "SoundQueuePlayer"}) then {
	private _scriptHandler = [] spawn TG_fnc_SoundQueue_Loop;
	missionNameSpace setVariable ["SoundQueuePlayer", _scriptHandler];
};