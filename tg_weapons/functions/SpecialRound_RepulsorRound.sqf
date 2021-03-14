
/*
	While stealing this code, please give credits to kaydol.
	Originally written for Tiberian Genesis addon which can be found on Arma 3 Steam Workshop.
*/

#define DEBUG 1

params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile"];

#define BLAST_FORCE 10
#define BLAST_RADIUS 4
#define OFFSET 10
#define LOS_NONE 0
#define LOS_DIRECT 1
#define LOS_INDIRECT 2

_fnc_lineOfSightKind = {
	params ["_unit", "_object"];
	_p1 = eyePos _unit;
	_p2 = getPosASL _object;
	if (_object isKindOf "Man") then {
		_p2 = AGLToASL ( _object modelToWorldVisual (_object selectionPosition "pelvis") ); 
	};
	
	_terrainIntersect = terrainIntersectASL [_p1, _p2];
	if (_terrainIntersect) exitWith { LOS_NONE };
	
	_losObjects = lineIntersectsWith [_p1, _p2, _unit, _object, false];
	if ({_x isKindOf "House"} count _losObjects > 0) exitWith { LOS_NONE };
	
	if (count _losObjects == 0) exitWith { LOS_DIRECT };
	LOS_INDIRECT
};

//-- Cast a ray with a length of OFFSET and if it intersects with something then use the 
//-- intersection pos as center for the explosion otherwise use the end of the ray as the explosion center
_centerASL = eyePos _unit vectorAdd (_unit weaponDirection currentWeapon _unit vectorMultiply OFFSET);
_intersection = lineIntersectsSurfaces [eyePos _unit, _centerASL, _unit];
if (count _intersection > 0) then {
	(_intersection # 0) params ["_intersectPosASL", "_surfaceNormal", "_intersectObject", "_parentObject"];
	_centerASL = _intersectPosASL;
};

_affectedUnits = ((ASLToAGL _centerASL) nearEntities BLAST_RADIUS) select { _x != _unit && [_unit, _x] call _fnc_lineOfSightKind != LOS_NONE };
_affectedUnitsWithForceDir = _affectedUnits apply { [_x, (eyePos _unit vectorFromTo getPosASL _x) vectorMultiply ((_unit distance _x) * BLAST_FORCE)] };

#ifdef DEBUG 
TG_RepulsorRound_EndPos = ASLToAGL _centerASL;
TG_RepulsorRound_MuzzlePos = ASLToAGL eyePos _unit;

if !( isNil { TG_RepulsorRound_Draw3D_Circle } ) then {
	if !( TG_RepulsorRound_Draw3D_Circle isEqualTo "" ) then {
		[TG_RepulsorRound_Draw3D_Circle, "onEachFrame"] call BIS_fnc_removeStackedEventHandler;
	};
	TG_RepulsorRound_Draw3D_Circle = nil;
};

_code = {
	_circles = [];
	{
		_corners = [];
		_cornersCount = 20;
		_turnAngle = 360 / _cornersCount;
		_i = 0;
		for [{_i = 0},{_i < _cornersCount},{_i = _i + 1}] do {
			_pos = _x getPos [BLAST_RADIUS, _i * _turnAngle];
			_pos set [2, _x # 2];
			_corners pushBack _pos;
		};
		_circles pushBack _corners;
	}
	forEach [TG_RepulsorRound_EndPos];
	
	{
		_size = count _x;
		for [{_i = 0},{_i < _size},{_i = _i + 1}] do {
			drawLine3D [_x # _i, _x # (( _i + 1 ) % _size ), [1,0,0,1]];
		};
	} 
	forEach _circles;		
};
TG_RepulsorRound_Draw3D_Circle = ["TG_RepulsorRound_Draw3D_Circle", "onEachFrame", _code] call BIS_fnc_addStackedEventHandler;


["TG_RepulsorRound_Draw3D", "onEachFrame"] call BIS_fnc_removeStackedEventHandler;
["TG_RepulsorRound_Draw3D", "onEachFrame", {
	drawLine3D [TG_RepulsorRound_MuzzlePos, TG_RepulsorRound_EndPos, [1,0,0,1]];
}] call BIS_fnc_addStackedEventHandler;

#endif

//systemChat str _affectedUnitsWithForceDir;

[[_unit, _centerASL], {
	if (!hasInterface) exitWith {};
	params ["_unit", "_centerASL"];
	private _emitter = "#particlesource" createVehicleLocal getPos _unit;
	_emitter setPosASL _centerASL;
	_emitter setParticleParams [["\A3\data_f\ParticleEffects\Universal\Refract.p3d",1,0,1,1],
		"", 
		"Billboard",
		1, 
		1, // lifeTime
		[0,0,0], // position
		(_unit weaponDirection currentWeapon _unit) vectorMultiply 10, // moveVelocity
		0, // rotationVelocity (rotations per second)
		1, // weight (weight of the particle, kg)
		1, // volume (volume of the particle in m3)
		0.05, // rubbing (determines how much particles blown by winds)
		[1,40], // size (array of particle size along its lifetime)
		[[1,1,1,1]], // color (array of [RGBA] arrays)
		[1], // animationSpeed
		0, // randomDirectionPeriod
		0, // randomDirectionIntensity
		"", // onTimerScript
		"", // beforeDestroyScript
		"", // this (if this parameter isn't objNull, the particle source will be attached to the object, the generation of particles stops when beyond Object View Distance)
		0, // angle (optional)
		false, // onSurface (optional)
		0, // bounceOnSurface (optional, default -1. Coef of bounce in collision with ground, 0..1 for collisions, -1 to disable collision. Should be used soberly as it has a significant impact on performance)
		[[0,0,0,0]] // emissiveColor (optional, array of [RGBA] arrays, needs to match 'color' values and be 100x times the RGB color values. Alpha is not used)
	];
	_emitter setParticleRandom [0,[0,0,0],[0,0,0],0,0,[0,0,0,0],0,0,0,0];
	_emitter setParticleCircle [0,[0,0,0]];
	_emitter setParticleFire [0,0,0];
	_emitter setDropInterval 1;
	sleep 0.5;
	deleteVehicle _emitter;
}] remoteExec ["spawn", 0];
	
[[_affectedUnitsWithForceDir],
{
	//-- First call is on server, because only server knows what clients own what units
	params ["_affectedUnitsWithForceDir"];
	
	_ownerArr = _affectedUnitsWithForceDir apply { owner (_x # 0) };
	_owners = _ownerArr arrayIntersect _ownerArr;
	
	//-- Separate units by their locality and then do a single remoteExec on each group 
	{
		_clientId = _x;
		_unitsOwnedByThisClient = _affectedUnitsWithForceDir select { owner (_x # 0) == _clientId };
		
		//-- Execute where the unit is local
		[[_unitsOwnedByThisClient], {
			params ["_localUnitsWithForceDir"];
			_fnc_forceRagdoll = {
				params ["_target", "_force"];
				if (_target isKindOf "Man") then {
					_target allowDamage false;
					_target setUnconscious true;
					_target setVelocity ((_force vectorAdd velocity _target) vectorAdd [0,0,2]);
					0 = [_target] spawn {
						sleep 0.5;
						params ['_target'];
						_target setUnconscious false;
						_target allowDamage true;
					};
				} else {
					_target addForce [_force, [0,0,0]];
				};
			};
			{
				[_x # 0, _x # 1] call _fnc_forceRagdoll;
			} forEach _localUnitsWithForceDir;
		
		}] remoteExec ["call", _clientId];
		
	} forEach _owners;
	
}] remoteExec ["call", 0];
