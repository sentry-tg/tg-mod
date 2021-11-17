
#include "..\variables.h"

/*
	Author: kaydol
	
	Description:
	Plays a sequence of say3D, sleeps and animateSource commands.
	
	Example:
		private _animationSequence = [
			"harvester_harvest", 
			["fork_source", 0.5, true],  
			0.6, 
			["roll", 3], 
			["blades1", 1.5], 
			["blades2", 1.5],  
			0.6,
			["blades1", 0], 
			["blades2", 0],
			0.6,
			["blades1", 1.5], 
			["blades2", 1.5],
			0.6,
			["blades1", 0], 
			["blades2", 0],
			0.6,
			["fork_source", 0, true],  
			["roll", 0] 
		];
		[_harvester, _animationSequence] spawn TG_fnc_AnimationSequence;
	
	
	Parameters:
	_this: ARRAY - Array where each element is either a STRING (for say3D), NUMBER (for sleep), or ARRAY (for anumateSource).
	
*/

params ["_vehicle", "_sequence"];

{
	if ( _x isEqualType 0 ) then { 
		sleep _x;
	};
	if ( _x isEqualType "" ) then { 
		[_vehicle, _x] remoteExec ["say3D", 0];
	};
	if ( _x isEqualType [] ) then { 
		_x params ["_animationName", "_animationValue", ["_isAnimateSource", false]];
		if (_isAnimateSource) then {
			_vehicle animateSource [_animationName, _animationValue];
		} else {
			_vehicle animate [_animationName, _animationValue];
		}; 
	};
}
forEach _sequence;


