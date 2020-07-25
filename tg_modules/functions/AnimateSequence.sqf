
#include "..\variables.h"

params ["_vehicle", "_sequence"];

{
	if ( _x isEqualType 0 ) then { 
		sleep _x;
	};
	if ( _x isEqualType "" ) then { 
		//playSound3D _x;
	};
	if ( _x isEqualType [] ) then { 
		_vehicle animate [_x # 0, _x # 1]; 
	};
}
forEach _sequence;


