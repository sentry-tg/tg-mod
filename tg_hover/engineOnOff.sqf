
#define ANIM_SPEED 0.04
#define STATE_UP 0.9
#define STATE_DOWN 0
#define ANIM_NAME "hover_source"
#define ANIM_DURATION 3
#define SCRIPT_HANDLE "TG_Hover_UpDownScript"

params ["_hover"];

//-- Add event handler on server. 
[_hover, {
	_hover addEventHandler ["Engine", {
		
		params ["_vehicle", "_engineState"];

		if (_engineState) then {
			_vehicle animateSource [ANIM_NAME, STATE_UP, ANIM_SPEED];
		} else {
			_vehicle animateSource [ANIM_NAME, STATE_DOWN, ANIM_SPEED];
		};
		
		//-- Spawn local dust effects globally
		[_this, {
			
			//if !(isNil{ _this # 0 getVariable SCRIPT_HANDLE }) then {
			//	private _handle = _this # 0 getVariable SCRIPT_HANDLE;
			//	if !(scriptDone _handle) then {
			//		terminate _handle;
			//	};
			//};
			
			private _script = _this spawn 
			{
				params ["_vehicle", "_engineState"];
				
				private _source = "#particlesource" createVehicleLocal getPos _vehicle;
				_source attachTo [_vehicle, [0,0,0]];
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
					hintSilent str linearConversion [_time, _time + ANIM_DURATION, time, _start, _end, true];
					sleep 0.01;
				};
				
				_source setDropInterval 0;
				deleteVehicle _source;
			};
			
			//_this # 0 setVariable [SCRIPT_HANDLE, _script];
		
		}] remoteExec ["spawn", 0];
	}]; 
}] remoteExec ["call", 2];


