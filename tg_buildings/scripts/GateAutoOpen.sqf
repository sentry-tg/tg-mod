
params ["_gate"];

waitUntil { sleep 1; time > 0 };

// the frequency of the scans, also the max delay before the gate opens \ closes when certain factors are present
_cycleSleep = 1; 
_animation = "gate";
_side = 0;
_openedAt = -6.5;
_closedAt = 0;

switch (typeOf _gate) do {
	case "nod_g": { _side = EAST; _openedAt = -5.3; };
	case "gdi_g": { _side = WEST; _openedAt = -6.5; };
	default { _side = GUER; };
}; 

//( _gate call BIS_fnc_boundingBoxDimensions ) params ["_gateWidth", "_gateThickness", "_gateHeight"];
//_triggerRadius = _gateWidth / 1.5;
_triggerRadius = 20;


// main loop
while { alive _gate } do 
{
	_friendliesPresent = False;
	_enemiesPresent = False;
	
	_opened = _gate animationPhase _animation == _openedAt;
	_closed = _gate animationPhase _animation == _closedAt;
	
	if !( _opened || _closed ) then 
	{
		/* 
			the gate has not finished animation 
			the animation is in progress
		*/
	} 
	else 
	{
		_entities = _gate nearEntities [["MAN", "CAR", "TANK"], _triggerRadius];
		//_enemiesPresent = count ( _entities select { [side _x, _side] call BIS_fnc_sideIsEnemy } ) > 0;
		_friendliesPresent = count ( _entities select { [side _x, _side] call BIS_fnc_sideIsFriendly } ) > 0;
		
		//systemchat format ["Friendlies=%1 | opened=%2 | closed=%3", _friendliesPresent, _opened, _closed];
		
		_needToOpen = _friendliesPresent && _closed;
		_needToClose = !_friendliesPresent && _opened;
		
		if ( _needToOpen ) then {
			//	OPENING
			_gate animate [_animation, _openedAt];
			playSound3D ["tg_sounds\all\gateup.ogg", _gate, false, getPos _gate, 15, 1, 150];
		};
		if ( _needToClose ) then {
			//	CLOSING
			_gate animate [_animation, _closedAt];
			playSound3D ["tg_sounds\all\gatedown.ogg", _gate, false, getPos _gate, 15, 1, 150];
		};
		
	};
	
	sleep _cycleSleep;
};