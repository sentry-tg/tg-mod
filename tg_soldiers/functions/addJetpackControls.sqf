
/*
	This function adds jetpack controls to a local player.
	Should be called together with TG_fnc_addJetpackEffects or 
	else the flying will be without both audio and visual effects.
	
	> Must be spawned, not called.
	
	Example:
		[] spawn TG_fnc_addJetpackControls;
*/

///////////////////////////////////////////////////////////////
//	Jetpack control (for player)	//
//////////////////////////////////////

_jetpackControl = [] spawn 
{
	//	The maximum height that can be reached with the jetpack
	_maxHeight = 100;
	//	The speed of acceleration, indirectly affects the maximum flying speed. Doubled when ascending.
	_speedBuff = 2.5; 
	//	Air resistance. How quickly the flyer slows down when no movement buttons are pressed. 
	// 	0 - insta stop, 1 - no slowdown at all.
	_decayRate = 0.8;
	//	How quickly the flyer accelerates towards the ground. 
	_gravityImpact = 1;
	
	//	Slower descent at 
	_getSlowerAt = 10;
	
	_buffer = [0,0,0];
	
	while { player call TG_fnc_ableToFly } do 
	{
		_gravImpact = _gravityImpact;
		_height = getPos player # 2;
		
		if !( player call TG_fnc_isUnitLanded ) then {
			player playActionNow "PlayerStand";
		};
		
		if (inputAction "MoveForward" > 0) then {
			_buffer set [1, _buffer # 1 + _speedBuff];
		};
		if (inputAction "MoveBack" > 0) then {
			_buffer set [1, _buffer # 1 - _speedBuff];
		};
		if (inputAction "TurnLeft" > 0) then {
			_buffer set [0, _buffer # 0 - _speedBuff / 2];
		};
		if (inputAction "TurnRight" > 0) then {
			_buffer set [0, _buffer # 0 + _speedBuff / 2];
		};
		if (inputAction "turbo" > 0) then {
			if ( getPos player # 2 >= _maxHeight ) exitWith {};
			_buffer set [2, _buffer # 2 + linearConversion [0, _maxHeight, _height, 1, 0] * _speedBuff * 2];
		};
		
		if ( _height <= _getSlowerAt ) then { _gravImpact = _gravImpact * 0.5 };
		
		if ( player call TG_fnc_isUnitLanded ) then { 
			_buffer set [0, 0];
			_buffer set [1, 0];
		};
		_buffer = _buffer vectorMultiply _decayRate; 
		
		_buffer set [2, _buffer # 2 - _gravImpact];
		//hint str _buffer;
		
		player setVelocityModelSpace _buffer;
		
		sleep 0.1;
	};
	
};

waitUntil { sleep 1; scriptDone _jetpackControl };
 