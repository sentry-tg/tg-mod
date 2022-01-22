
#include "..\variables.h"

#define ATMOSPHERE_PRESET_GREEN_TIBERIUM_FOG 0

_mode = param [0,"",[""]];
_input = param [1,[],[[]]];

[_mode, _input] call TG_fnc_VisualizeModuleRadius3DEN;

switch _mode do {
	// Default object init
	case "init": 
	{
		_logic = _input param [0,objNull,[objNull]]; // Module logic
		_isActivated = _input param [1,true,[true]]; // True when the module was activated, false when it's deactivated
		_isCuratorPlaced = _input param [2,false,[true]]; // True if the module was placed by Zeus
		
		_radius = _logic getVariable "Radius";
		_preset = _logic getVariable "Preset";
		
		_startCondition = _logic getVariable ["StartCondition", "true"];
		if (_startCondition isEqualType false) then { _startCondition = {_startCondition} };
		if (_startCondition isEqualType "") then { _startCondition = compile _startCondition };
		
		_stopCondition = compile ( _logic getVariable ["StopCondition", "false"] );
		if (_stopCondition isEqualType false) then { _stopCondition = {_stopCondition} };
		if (_stopCondition isEqualType "") then { _stopCondition = compile _stopCondition };
		
		_loopConditions = ( _logic getVariable ["LoopConditions", 0] ) == 1;
		
		_fnc_distanceCheck = {
			params ["_logic", "_inside"];
			if (isNull _logic || isNull player) exitWith { false };
			_radius = _logic getVariable "Radius";
			if (_radius <= 0) exitWith { true };
			call (
				[
					{player distance _logic > _radius}, // if _inside == false 
					{player distance _logic <= _radius} // if _inside == true
				] select _inside
			)
		};
		
		while { true } do 
		{
			diag_log format ["Initiating the loop %1=%2 && %3",_startCondition,call _startCondition, [_logic, true] call _fnc_distanceCheck];
			
			/* Wait until a user-defined condition is true */
			WaitUntil { sleep 1; call _startCondition && [_logic, true] call _fnc_distanceCheck }; 
			
			diag_log format ["Got behind the first wait until "];
			
			// Defining variables to make them visible outside of the switch-case block
			_handle = 0 spawn {};
			_ppCol = -1;
			_ppCCBase = [0.199, 0.587, 0.114, 0.0];
			_ppCCOut = [1, 1, 0, [0.0, 0.0, 0.0, 0.0], [1.0, 1.0, 1.0, 1.0], _ppCCBase];
			_emitter = objNull;
			_transitionTime = 0;
			
			switch ( _preset ) do {
				case ATMOSPHERE_PRESET_GREEN_TIBERIUM_FOG: {
					
					// save old fog params 
					_oldFogParams = fogParams; // [_fogValue, _fogDecay, _fogBase]
					_oldOvercast = overcast;
					
					// ==================================== //
					// 				fog spawner				//
					// ==================================== //
					
					_transitionTime = 3;
					_handle = [_transitionTime] spawn {
						params ["_transitionTime"];
						_fogValue = 0.7;
						_fogDecay = 0.01;
						
						while {true} do {
							_transitionTime setOvercast 0.5;
							sleep _transitionTime;
							// the fog base will be constantly adjusting to player's height above sea 
							_transitionTime setFog [_fogValue, _fogDecay, getPosASL player select 2];
							sleep _transitionTime;
							diag_log format ["Reapplying the fog..."];
						};
					};
					
					// restores fog to the old params once the fog spawner is terminated
					[_handle, _oldFogParams, _oldOvercast, _transitionTime] spawn {
						params ["_handle", "_params", "_overcast", "_transitionTime"];
						waitUntil { sleep 0.5; scriptDone _handle };
						_transitionTime setOvercast _overcast;
						sleep _transitionTime;
						_transitionTime setFog _params;
						diag_log format ["_handle is terminated, old fog parameters restored"];
					};
					
					// ==================================== //
					// 				dust spawner			//
					// ==================================== //
					
					_emitter = "#particlesource" createVehicleLocal getpos player;
					
					//particle_emitter_0 setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal.p3d",16,12,13,0],"","Billboard",1,10,[0,0,0],[0,0,0.2],0,0.0525,0.04,0.05,[1.6,3.5],[[0.5,0.4,0.3,0],[0.499251,0.414643,0.336079,0],[0.5,0.4,0.3,0.06],[0.5,0.4,0.3,0.05],[0.5,0.4,0.3,0.015],[0.6,0.5,0.4,0]],[1000],0.1,0.05,"","","",0,false,0,[[0,0,0,0],[0,0,0,0]]];
					
					_emitter setParticleParams [
						["\A3\data_f\ParticleEffects\Universal\Universal.p3d",16,12,13,0], // p3dPath, Ntieth, Index, FrameCount, Loop
						"", // animationName (obsolete parameter that was meant to play .rtm anims, should be empty)
						"Billboard", // particleType ("Billboard" or "SpaceObject")
						1, // timerPeriod
						10, // lifeTime
						[0,0,0], // position
						[0,0,0.2], // moveVelocity
						0, // rotationVelocity (rotations per second)
						0.0525, // weight (weight of the particle, kg)
						0.04, // volume (volume of the particle in m3)
						0.05, // rubbing (determines how much particles blown by winds)
						[1.6,3.5], // size (array of particle size along its lifetime)
						[[0.5,0.4,0.3,0],[0.5,0.4,0.3,0.06],[0.5,0.4,0.3,0.05],[0.5,0.4,0.3,0.015],[0.6,0.5,0.4,0]], // color (array of [RGBA] arrays)
						[1000], // animationSpeed
						0.1, // randomDirectionPeriod
						0.05, // randomDirectionIntensity
						"", // onTimerScript
						"", // beforeDestroyScript
						player, // this (if this parameter isn't objNull, the particle source will be attached to the object, the generation of particles stops when beyond Object View Distance)
						0, // angle (optional)
						false, // onSurface (optional)
						0, // bounceOnSurface (optional, default -1. Coef of bounce in collision with ground, 0..1 for collisions, -1 to disable collision. Should be used soberly as it has a significant impact on performance)
						[[0,0,0,0],[0,0,0,0]] // emissiveColor (optional, array of [RGBA] arrays, needs to match 'color' values and be 100x times the RGB color values. Alpha is not used)
					];
					_emitter setParticleRandom [1,[10,10,0.2],[0.005,0.005,0.15],10,0.2,[0,0,0,0],0,0,0,0];
					_emitter setParticleCircle [0,[0,0,0]];
					_emitter setParticleFire [0,0,0];
					_emitter setDropInterval 0.1;
					
					// ======================================== //
					// 				color corrections			//
					// ======================================== //
					 
					_ppCCIn = [1, 1, 0, [0.0, 0.0, 0.0, 0.5], [1.0, 1.2, 1.0, 1.0], _ppCCBase];
					_name = "colorCorrections";
					_priority = 1550;
					while { 
						_ppCol = ppEffectCreate [_name, _priority]; 
						_ppCol < 0 
					} do { 
						_priority = _priority + 1; 
					};
					_ppCol ppEffectAdjust _ppCCIn;
					_ppCol ppEffectCommit _transitionTime;
					_ppCol ppEffectEnable true;
					
				};
				default {  };
			};
			
			
			/* Wait until a user-defined condition is true */
			WaitUntil { sleep 1; call _stopCondition && [_logic, false] call _fnc_distanceCheck };

			if !(scriptDone _handle) then {
				terminate _handle;
			};
			
			if !(isNull _emitter) then {
				deleteVehicle _emitter;
			};
			
			if !(_ppCol isEqualTo -1) then {
				_ppCol ppEffectAdjust _ppCCOut;
				_ppCol ppEffectCommit _transitionTime;
				[_ppCol, _transitionTime] spawn {
					params ["_ppCol", "_transitionTime"];
					sleep _transitionTime;
					ppEffectDestroy _ppCol;
					diag_log format ["Color corrections are disabled"];
				};
			};
			
			if !( _loopConditions ) exitWith {
				diag_log format ["The loop will not be restarted"];
			};

		};

		if !(isNull _logic) then {
			deleteVehicle _logic;
		};
		
	};
	
	default {};
};


