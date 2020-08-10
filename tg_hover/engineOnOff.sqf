
#define ANIM_SPEED 0.04 
#define STATE_UP 0.9
#define STATE_DOWN 0
#define ANIM_NAME "hover_source"
#define ANIM_DURATION 3 
#define SCRIPT_HANDLE "TG_Hover_UpDownScript"
#define SINE_AMPLITUDE 0.4

params ["_vehicle"];

//-- Add event handler on server, the EH fires only on server
[_vehicle, {
	_this addEventHandler ["Engine", {
		
		params ["_vehicle", "_engineState"];

		if !(isNil{ _vehicle getVariable SCRIPT_HANDLE }) then {
			private _handle = _vehicle getVariable SCRIPT_HANDLE;
			if !(scriptDone _handle) then {
				terminate _handle;
			};
		};

		if (_engineState) then {
			_vehicle animateSource [ANIM_NAME, STATE_UP, ANIM_SPEED];
			
			//-- Add going up and down cycle
			private _floating = _vehicle spawn {
				params ["_vehicle"];
				//-- Wait until we are in STATE_UP
				private _skipTime = linearConversion [STATE_DOWN, STATE_UP, _vehicle animationSourcePhase ANIM_NAME, ANIM_DURATION, 0];
				//hint str _skipTime;
				sleep _skipTime;
				
				while { isEngineOn _vehicle } do {
					//-- Start the sine movement
					private _alpha = abs(sin(time % 360 * 25)) * SINE_AMPLITUDE;
					//hint str _alpha;
					_vehicle animateSource [ANIM_NAME, STATE_UP - _alpha, ANIM_SPEED * 0.1];
					sleep 1;
				};
			};
			_vehicle setVariable [SCRIPT_HANDLE, _floating];
			
		} else {
			_vehicle animateSource [ANIM_NAME, STATE_DOWN, ANIM_SPEED];
		};
		
		//-- Spawn local dust effects globally
		[_this, {
			
			if (!hasInterface) exitWith {};
			
			_this spawn 
			{
				params ["_vehicle", "_engineState"];
				
				private _source = "#particlesource" createVehicleLocal getPos _vehicle;
				_source attachTo [_vehicle, [0,0,0]];
				
				//-- Handle the start\end of the engine
				_source setParticleClass "CircleDustTank";
				_source setDropInterval 0.1;
				
				private _start = 0.2;
				private _end = 0.001;
				if (_engineState) then {
					_start = 0.001;
					_end = 0.2;
				};
				
				private _time = time;
				while {time - _time < ANIM_DURATION} do {
					_source setDropInterval linearConversion [_time, _time + ANIM_DURATION, time, _start, _end, true];
					//hintSilent str linearConversion [_time, _time + ANIM_DURATION, time, _start, _end, true];
					sleep 0.01;
				};
				
				//-- Handle the actual continous effect that lasts until the engine is off
				if (_engineState) then 
				{
					_source setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal.p3d",16,12,13,0],"","Billboard",1,1.54,[0,0,0],[0,0,0],0,0.053,0.04,0.02,[2,3,3],[[0.23,0.22,0.21,0],[0.31,0.28,0.27,0.27],[0.23,0.22,0.22,0]],[1000,1000,1000],0.1,0.05,"","","",0,false,0,[[0,0,0,0],[0,0,0,0]]];
					_source setParticleRandom [0.3,[2,4,0],[0.5,0.5,0],20,0.3,[0,0,0,0],0,0,0,0];
					_source setParticleCircle [0.5,[1,1,0]];
					_source setParticleFire [0,0,0];
					_source setDropInterval 0.05;
				
					waitUntil { sleep 1; !isEngineOn _vehicle};
				};
				
				_source setDropInterval 0;
				deleteVehicle _source;
			};
		
		}] remoteExec ["spawn", 0];
	}]; 
}] remoteExec ["call", 2];


