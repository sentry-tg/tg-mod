
/*
	This function adds Visual and Sound effects to Jetpack users while they're airborne.
	> Must be spawned, not called.
	> Works as long as the unit is wearing a jetpack and not inside any vehicles, after that must be restarted.
	> When used on a local player, does not give jetpack controls. For that use TG_fnc_addJetpackControls
	
	_this select 0: unit (can be both local or remote)
	
	Example:
		[_unit] remoteExec ["TG_fnc_addJetpackEffects", 0];
	
*/

if !( hasInterface ) exitWith {};

_unit = _this;

if !( _unit call TG_fnc_ableToFly ) exitWith {};

///////////////////////////////////////////////////////////////
//	VFX on the ground (circles of dust)	//
//////////////////////////////////////////

_vfxGround = _unit spawn 
{
	params ["_unit"];
	
	//	Max height at which the circles are spawned on the ground
	_maxHeight = 10; 
	
	_source = "#particlesource" createVehicleLocal getPos _unit;
	_source setParticleClass "CircleDustTank";
	_source setDropInterval 0.1;
	
	while { _unit call TG_fnc_ableToFly } do {
		_height = getPos _unit # 2;
		if ( _height < _maxHeight && !( _unit call TG_fnc_isUnitLanded )) then {
			_source attachTo [_unit, [0,0,-_height]];
			_source setDropInterval 0.1;
		} else {
			_source setDropInterval 0;
		};
	};
	
	deleteVehicle _source;
};

///////////////////////////////////////////////////////////////
//	VFX on the jetpack (smoke, refraction)	//
//////////////////////////////////////////////

_vfxJetpack = _unit spawn 
{
	params ["_unit"];

	_jetpack = unitBackpack _unit;

	_FlameM = "#particlesource" createVehicle position _unit;  
	_SparksL = "#particlesource" createVehicle position _unit;  
	_SparksR = "#particlesource" createVehicle position _unit;  
	_SmokeL = "#particlesource" createVehicle position _unit;  
	_SmokeR = "#particlesource" createVehicle position _unit;  

	_FlameM setParticleParams [["\A3\data_f\ParticleEffects\Universal\Refract", 1, 0, 1], "", "Billboard", 1, 0.5, [0, 0, 0], [1, 1, -1], 0, 1.5, 1, 1, [1, 1.5, 1.25], [[0.1, 0.1, 0.1, 1], [0.25, 0.25, 0.25, 0.5], [0.5, 0.5, 0.5, 0]], [0.08], 1, 0, "", "", ""];
	_FlameM setParticleRandom [0, [0.25, 0.25, 0], [0.175, 0.175, 0], 0, 0.25, [0, 0, 0, 0.1], 0, 0];
	_FlameM setParticleCircle [0, [0, 0, 0]];
	_SparksL setParticleClass "AirFireSparks"; 
	_SparksR setParticleClass "AirFireSparks"; 
	_SmokeL setParticleClass "MachineGunCloud1";  
	_SmokeR setParticleClass "MachineGunCloud1"; 

	_SparksL setDropInterval 0;  
	_SparksR setDropInterval 0; 
	_FlameM setDropInterval 0;
	_SmokeL setDropInterval 0; 
	_SmokeR setDropInterval 0; 

	_minHeight = 0.25;
	_intensity = 0.005;
	_timeStamps = [0, 0, 0];

	while { _unit call TG_fnc_ableToFly } do 
	{
		//	Wait until flying
		waitUntil {!( _unit call TG_fnc_isUnitLanded )};
		if !( _unit call TG_fnc_ableToFly ) exitWith {};
		
		_SparksL setDropInterval _intensity;  
		_SparksR setDropInterval _intensity; 
		_FlameM setDropInterval _intensity;
		_SmokeL setDropInterval _intensity; 
		_SmokeR setDropInterval _intensity; 
		
		_ventL = _jetpack selectionPosition ["ventL", "Memory"];
		_ventL = _ventL vectorAdd [0,0.6,-0.4];
		_ventR = _jetpack selectionPosition ["ventR", "Memory"];
		_ventR = _ventR vectorAdd [0,0,-0.3];
		_ventM = _jetpack selectionPosition ["ventM", "Memory"];
		_ventM = _ventM vectorAdd [0,-0.3,-0.2];
		
		_FlameM attachTo [_unit, _ventM, "Spine3"]; 
		_SmokeL attachTo [_unit, _ventL, "Spine3"];
		_SmokeR attachTo [_unit, _ventR, "Spine3"];
		_SparksL attachTo [_unit, _ventL, "Spine3"]; 
		_SparksR attachTo [_unit, _ventR, "Spine3"]; 
		
		_timeStamps set [0, time];
		[_SparksR, _SparksL, _timeStamps] spawn {
			params ["_SparksR", "_SparksL", "_timeStamps"];
			/* Heavy sparking effect */
			_time = 0.6; //	This sleep defines how soon the effect is stopped after flying started
			sleep _time;	
			if ( time - _timeStamps # 0 > _time ) then {
				_SparksR setDropInterval 0.1;
				_SparksL setDropInterval 0.1;
			};
			/* Rare sparks effect */
			_time = 2; //	This sleep defines how soon the effect is stopped after flying started
			sleep _time;	
			if ( time - _timeStamps # 0 > _time ) then {
				_SparksR setDropInterval 0;
				_SparksL setDropInterval 0;
			};
		};
		
		//	Wait until landed
		waitUntil { !( _unit call TG_fnc_ableToFly ) || _unit call TG_fnc_isUnitLanded };
		if !( _unit call TG_fnc_ableToFly ) exitWith {};
		
		_timeStamps set [1, time];
		[_FlameM, _timeStamps, _unit] spawn {
			params ["_FlameM", "_timeStamps", "_unit"];
			/* Refraction effect */
			_time = 1.6; //	This sleep defines how soon the effect is stopped after landing
			sleep _time; 	
			if ( time - _timeStamps # 1 > _time &&_unit call TG_fnc_isUnitLanded ) then {
				_FlameM setDropInterval 0;
			};
		};
		
		_timeStamps set [2, time];
		[_SmokeL, _SmokeR, _timeStamps, _unit] spawn {
			params ["_SmokeL", "_SmokeR", "_timeStamps", "_unit"];
			/* Smoke effects */
			_time = 2;	//	This sleep defines how soon the effect is stopped after landing
			sleep _time;	
			if ( time - _timeStamps # 2 > _time && _unit call TG_fnc_isUnitLanded ) then {
				_SmokeL setDropInterval 0;
				_SmokeR setDropInterval 0;
			};
		};

	};

	/* 
		Setting the timestamps to future so none of the spawned instances 
		would try to execute any code with the emitters that were deleted 
	*/
	_timeStamps set [0, time + 100];
	_timeStamps set [1, time + 100];
	_timeStamps set [2, time + 100];

	//	Deleting the emitters
	deleteVehicle _SparksL;  
	deleteVehicle _SparksR; 
	deleteVehicle _FlameM;
	deleteVehicle _SmokeL; 
	deleteVehicle _SmokeR; 
};

///////////////////////////////////////////////////////////////
//	Sound Effects	//
//////////////////////

_sfxJetpack1 = _unit spawn 
{
	/* Handles flying SFX */
	params ["_unit"];
	
	_center = createCenter sideLogic;
	_group = createGroup _center;
	_speaker = objNull;
	_newSpeaker = objNull;
	
	_relpos = [0,-0.5,1];
	_sound = "JetpackLoop";
	_distance = 100;
	_length = 14;
	_overlap = 1;
	_step = 0.1;

	while { _unit call TG_fnc_ableToFly } do 
	{
		if !( _unit call TG_fnc_isUnitLanded ) then 
		{
			if ( isNull _speaker && isNull _newSpeaker ) then 
			{
				// Only happens at the start and when going airborne after being landed for some time
				_speaker = _group createUnit ["LOGIC", [0,0,0], [], 0, "NONE"];
				_speaker attachTo [_unit, _relpos];
				_speaker say3D [_sound, _distance];
			}; 
			if ( isNull _speaker ) then { 
				/* Happens when an overlap took place */
				_speaker = _newSpeaker
			};
			_i = 0;
			_overlapped = False;
			for [{_i = 0},{_i < _length},{_i = _i + _step}] do {
				if ( _unit call TG_fnc_isUnitLanded ) exitWith { };
				if ( _i / _length >= 0.9 && !_overlapped ) then {
					_newSpeaker = _group createUnit ["LOGIC", [0,0,0], [], 0, "NONE"];
					_newSpeaker attachTo [_unit, _relpos];
					_newSpeaker say3D [_sound, _distance];
					_length = _i + _overlap;
					_overlapped = True;
				};
				sleep _step;
			};
			deleteVehicle _speaker;
			if ( _unit call TG_fnc_isUnitLanded && !isNull _newSpeaker ) then {
				// The unit landed during overlap
				deleteVehicle _newSpeaker;
			};
		};
		sleep 0.25;
	};
};

_sfxJetpack2 = _unit spawn 
{
	/* Handles landing SFX */
	params ["_unit"];
	
	_center = createCenter sideLogic;
	_group = createGroup _center;
	_speaker = objNull;
	
	_relpos = [0,-0.5,1];
	_sound = "JetpackStop";
	_distance = 100;
	_length = 5;
	_speakers = [];
	
	while { _unit call TG_fnc_ableToFly } do 
	{
		waitUntil { !( _unit call TG_fnc_ableToFly ) || !( _unit call TG_fnc_isUnitLanded ) };
		waitUntil { !( _unit call TG_fnc_ableToFly ) || _unit call TG_fnc_isUnitLanded };
		
		if !( _unit call TG_fnc_ableToFly ) exitWith {};
		
		_freeSpeaker = _speakers findIf { ( time - _x # 1 ) > _length };
		
		if ( _freeSpeaker < 0 ) then {
			_speaker = _group createUnit ["LOGIC", [0,0,0], [], 0, "NONE"];
			_speakers pushBack [_speaker, time];
			_speaker attachTo [_unit, _relpos];
		} else {
			_speaker = ( _speakers # _freeSpeaker ) # 0;
			( _speakers # _freeSpeaker ) set [1, time];
		};
		
		_speaker say3D [_sound, _distance];
	};
	
	{ deleteVehicle ( _x # 0 )} forEach _speakers;
	_speakers resize 0;
};

// waitUntil { sleep 1; scriptDone _vfxGround && scriptDone _vfxJetpack && scriptDone _sfxJetpack1 && scriptDone _sfxJetpack2 };