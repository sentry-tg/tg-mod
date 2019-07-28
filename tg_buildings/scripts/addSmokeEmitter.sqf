
/*
	This script adds smoke to objects, such as factory chimneys.
	
	_this select 0: the object that emits sounds
		0: object in which relative space the speaker will be located
		1: array [x,y,z] of relative coordinates pointing to a specific location. Default [0,0,0]
	_this select 1: (optional) function name that returns a boolean deciding whether to emit sound or not, e.g. only emit sound when the object is powered up, etc. The function input is the object from (_this select 0), output must be boolean. Default ""
	_this select 2: (optional) the size of the particles. Default 1
	_this select 3: (optional) the lifetime of the particles. Default 10
	_this select 4: (optional) color. Default [0.5,0.5,0.5,0.5]
	_this select 5: (optional) How much will particles be affected by wind. Default 1
	_this select 6: (optional) Variability of particles movement. Default 1
	_this select 7: (optional) Amount of particles generated per second. Default 10
	_this select 8: (optional) Initial speed of a particle when it is created. Default 1
	_this select 9: (optional) Speed of a particle during its climbing. Default 1
	_this select 10: (optional) debug, marks the sound emitter with a yellow sphere, default False
		
	Usage:
		a = [[powerplant, [11.5,11,7]]] execVM "addObjectGFX.sqf";

*/


params [	
	"_object", 
	["_func", ""], 
	["_particleSize", 1],
	["_particleLifeTime", 10], // Time in seconds after which particle disappears.
	["_color", [0.5,0.5,0.5,0.5]], 
	["_windEffect", 1], // How much will particles be affected by wind.
	["_expansion", 1], // Variability of particles movement.
	["_particleDensity", 10], // Amount of particles generated per second.
	["_particleSpeed", 1], // Initial speed of a particle when it is created.
	["_particleLifting", 1], // Speed of a particle during its climbing. 
	["_debug", False]
];

_object params ["_obj", ["_relpos", [0,0,0]]];

_fnc_alwaysTrue = { True };
_func = if ( count _func > 0 ) then [{ compile _func },{ _fnc_alwaysTrue }];

if ( _debug ) then {
	_sphere = "Sign_Sphere25cm_F" createVehicle getPos _obj;
	_sphere attachTo [_obj, _relpos];
};

_emitter = "#particlesource" createVehicleLocal position _obj;  

_color params [["_colorRed", 0.5], ["_colorGreen", 0.5], ["_colorBlue", 0.5], ["_colorAlpha", 0.5]];

//--- particle effect creation
_emitter setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal_02", 8, 0, 40, 1], "", "billboard", 1, _particleLifeTime, [0, 0, 0], [0, 0, 2*_particleSpeed], 0, 0.05, 0.04*_particleLifting, 0.05*_windEffect, [1 *_particleSize + 1, 1.8 * _particleSize + 15], [[0.7*_colorRed, 0.7*_colorGreen, 0.7*_colorBlue, 0.7*_colorAlpha], [0.7*_colorRed, 0.7*_colorGreen, 0.7*_colorBlue, 0.6*_colorAlpha], [0.7*_colorRed, 0.7*_colorGreen, 0.7*_colorBlue, 0.45*_colorAlpha], [0.84*_colorRed, 0.84*_colorGreen, 0.84*_colorBlue, 0.28*_colorAlpha], [0.84*_colorRed, 0.84*_colorGreen, 0.84*_colorBlue, 0.16*_colorAlpha], [0.84*_colorRed, 0.84*_colorGreen, 0.84*_colorBlue, 0.09*_colorAlpha], [0.84*_colorRed, 0.84*_colorGreen, 0.84*_colorBlue, 0.06*_colorAlpha], [1*_colorRed, 1*_colorGreen, 1*_colorBlue, 0.02*_colorAlpha], [1*_colorRed, 1*_colorGreen, 1*_colorBlue, 0*_colorAlpha]], [1, 0.55, 0.35],  0.1,  0.08*_expansion,  "",  "",  ""];

_effectSize = 1;
_emitter setParticleRandom [_particleLifeTime/2, [0.5*_effectSize, 0.5*_effectSize, 0.2*_effectSize], [0.3,0.3,0.5], 1, 0, [0,0,0,0.06], 0, 0];

_emitter setDropInterval 0; 
_emitter attachTo [_obj, _relpos];

// 	1. get a list of all emitters attached to this object
_attachedEmitters = _obj getVariable ["TG_AttachedEmitters", []];

//	2. if there were none, add the first one and add an EventHandler 
//	that will delete ALL of them upon object's destruction
if (count _attachedEmitters == 0) then {
	_obj addEventHandler ["Killed", {
		params ["_obj", "_killer"];
		_attachedEmitters = _obj getVariable ["TG_AttachedEmitters", []];
		{ deleteVehicle _x } forEach _attachedEmitters;
		_obj removeEventHandler ["Killed", _thisEventHandler];
	}];
};
_attachedEmitters pushBack _emitter;
_obj setVariable ["TG_AttachedEmitters", _attachedEmitters];


// The emitting part
while { alive _obj } do
{
	if ( _obj call _func ) then [{ _emitter setDropInterval ( 1 / _particleDensity ) },{ _emitter setDropInterval 0 }];
	sleep 2.5;
};

