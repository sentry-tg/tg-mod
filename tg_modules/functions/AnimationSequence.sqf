
#include "..\variables.h"

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


