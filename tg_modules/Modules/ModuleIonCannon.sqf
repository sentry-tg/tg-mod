
_fnc_rayParticles = {
	/*
		Author: TheTimidShade

		Description:
			Creates particles for main laser beam. Executed internally from tts_beam_fnc_beam.

		Parameters:
			0: OBJECT - Beam emitter object passed from fnc_beam.
			1: ARRAY - Colour of laser passed from fnc_beam.
			2: ARRAY - Position of target object passed from fnc_beam.
			
		Returns:
			NONE
	*/

	params ["_beamEmitter", "_col", "_targetPos"];

	_ray = "#particlesource" createVehicleLocal (getpos _beamEmitter);
	_ray setParticleCircle [0, [0, 0, -3]];
	_ray setParticleRandom [0, [0.25, 0.25, 0], [0.175, 0.175, 0], 0, 0.25, [0, 0, 0, 0.1], 0, 0];
	_ray setParticleParams [["\A3\data_f\cl_exp", 1, 0, 1], "", "Billboard", 1, 3, [0, 0, 0], [0, 0, 0], 13, 10, 7.6, 0, [15,11,7,3], [[_col#0, _col#1, _col#2, 1]], [0.08], 1, 0, "", "", _ray];
	_ray setDropInterval 0.0025;
	_ray attachTo [_beamEmitter, [0,0,0]];

	// lights
	_lights = "#particlesource" createVehicleLocal (getpos _beamEmitter);
	_lights setParticleCircle [0, [0, 0, -3]];
	_lights setParticleRandom [0, [0.25, 0.25, 0], [0.175, 0.175, 0], 0, 0.25, [0, 0, 0, 0.1], 0, 0];
	_lights setParticleParams [["\A3\data_f\VolumeLight", 1, 0, 1], "", "SpaceObject", 1, 3, [0, 0, 0], [0, 0, 0], 0, 10, 7.6, 0, [8,6,3,1], [[_col#0, _col#1, _col#2, 1]], [0.08], 1, 0, "", "", _lights];
	_lights setDropInterval 0.002;
	_lights attachTo [_beamEmitter, [0,0,0]];

	// lightpoint
	_lightp = "#lightpoint" createVehicleLocal (getpos _beamEmitter);
	_lightp setLightBrightness 80;
	_lightp setLightAmbient _col;
	_lightp setLightColor _col;
	_lightp lightAttachObject [_beamEmitter, [20,20,200]];

	sleep 1; // sleep to let beamEmitter accelerate first
	waitUntil {sleep 0.01; vectorMagnitude (velocity _beamEmitter) < 20 || _beamEmitter distance _targetPos < 5 || (getPosATL _beamEmitter)#2 < 5};

	sleep 0.1; // small sleep to let dust cloud get created to hide deletion of beam

	{deleteVehicle _x} forEach [_ray, _lights, _lightp];
};

_fnc_explosionDamage = {
	/*
		Author: TheTimidShade

		Description:
			Damages/destroys/throws/ragdolls any units within the killzone of the beam. Should only be executed on the server/host player.

		Parameters:
			0: OBJECT - Impact emitter object passed from fnc_beam.
			1: NUMBER - Maximum radius to deal lethal damage to units/vehicles.
			2: NUMBER - Maximum radius to deal damage/ragdoll units.
			
		Returns:
			NONE
	*/

	if (!isServer) exitWith {}; // make sure this function is only run on server

	params ["_impactEmitter","_maxKillRange", "_maxDamageRange"];

	private _ace_enabled = isClass(configFile >> "CfgPatches" >> "ace_main");

	_nearObjects = nearestObjects[_impactEmitter, ["Building", "House", "Man", "LandVehicle", "Air"], _maxDamageRange];
	{
		private _distance = _impactEmitter distance _x;
		private _dirFromTo = (getPosATL _impactEmitter) vectorFromTo (getPosATL _x);
		
		_effectCoef = if (_distance < _maxKillRange) then {1} else {
			private _coef = (_distance - _maxKillRange)/(_maxDamageRange - _maxKillRange); // should be 0 at maxKillRange, 1 at edge of maxDamageRange
			(1 - _coef)
		};
		
		private _throwSpeedKill = [30*_dirFromTo#0, 30*_dirFromTo#1, 5] vectorMultiply _effectCoef;
		private _throwSpeedDamage = [15*_dirFromTo#0, 15*_dirFromTo#1, 5] vectorMultiply _effectCoef;

		if (_distance <= _maxKillRange) then { // if unit is within the killzone, instantly destroy it
			if (!(_x isKindOf "Static")) then {[_x, _throwSpeedKill] remoteExec ["setVelocity", _x, false];}; // throw non-static objects
			[_x, _impactEmitter] spawn {sleep 0.001; if (_this#0 != _this#1) then {_this#0 setDamage 1};};
		} else { // if not, damage it depending on distance
			if (_distance <= _maxDamageRange) then {
				if (!(_x isKindOf "Static")) then {[_x, _throwSpeedDamage] remoteExec ["setVelocity", _x, false];}; // throw non-static objects
				
				private _damageToAdd = 0.5*(_effectCoef^2);
				if (!(_x isKindOf "Man")) then { // damage vehicles/buildings
					_x setDamage ((damage _x) + _damageToAdd);
				} else { // damage unit
					if (_ace_enabled) then { // check if ace is enabled, use ace damage if it is
						_damageRegions = ["body", "hand_l", "hand_r", "leg_l", "leg_r"];
						_damagePoint = selectRandom _damageRegions;
						[_x, _damageToAdd*2, _damagePoint, "explosive"] remoteExec ["ace_medical_fnc_addDamageToUnit", _x, false];
					} else {
						_x setDamage ((damage _x) + _damageToAdd);
					};

					if (_effectCoef >= 0.1) then { // ragdoll the unit if they are close enough to the explosion
						_x spawn {
							sleep 0.001; 
							[_this, {
							/*
								Author: Killzone_Kid

								Description:
									Forces the unit into ragdoll. Should be executed where unit is local.

								Parameters:
									0: OBJECT - Unit being forced into ragdoll.
									
								Returns:
									NONE
							*/
							params ["_unit"];
							if (vehicle _unit != _unit) exitWith {};
							private "_rag";
							_rag = "Land_Can_V3_F" createVehicleLocal [0,0,0];
							_rag setMass 1e10;
							_rag attachTo [_unit, [0,0,0], "Spine3"];
							_rag setVelocity [0,0,6];
							_unit allowDamage false;
							detach _rag;
							[_rag, _unit] spawn {
								deleteVehicle (_this#0);
								(_this#1) allowDamage true;
							};
						
						}] remoteExec ["spawn", _this, false];};
					};
				};
			};
		};
		sleep 0.0005;
	} foreach _nearObjects;
};

_fnc_explosionParticles = {
	/*
		Author: TheTimidShade

		Description:
			Creates dust cloud particles and rock debris for beam impact.

		Parameters:
			0: OBJECT - The object the beam is created above.
			1: ARRAY - Colour of dust/rock debris created on impact in format [r,g,b].

		Returns:
			NONE
	*/

	if (!hasInterface) exitWith {}; // dedicated server & HC should not run particles

	params ["_impactEmitter", "_col"];

	// dust wave
	_wave = "#particlesource" createVehicleLocal getPos _impactEmitter;
	_wave setParticleParams [["A3\Data_F\ParticleEffects\Universal\universal.p3d", 16, 7, 48], "", "Billboard", 1, 7, [0, 0, 0],[0, 0, 0], 0, 1.5, 1, 0, [50, 100], [[_col#0, _col#1, _col#2, 0.5], [_col#0, _col#1, _col#2, 0.5], [_col#0, _col#1, _col#2, 0.3], [_col#0, _col#1, _col#2, 0]], [1,0.5], 0.1, 1, "", "", _impactEmitter];
	_wave setParticleRandom [2, [20, 20, 20], [5, 5, 0], 0, 0, [0, 0, 0, 0.1], 0, 0];
	_wave setParticleCircle [50, [-80, -80, 2.5]];
	_wave setDropInterval 0.001;

	// dust cloud
	_cloud = "#particlesource" createVehicleLocal getPos _impactEmitter;
	_cloud setParticleParams [["A3\Data_F\ParticleEffects\Universal\universal.p3d", 16, 7, 48], "", "Billboard", 1, 18, [0, 0, 0],[0, 0, 0], 0, 1.5, 1, 0, [50, 65], [[_col#0, _col#1, _col#2, 0.5], [_col#0, _col#1, _col#2, 0.5], [_col#0, _col#1, _col#2, 0.3], [_col#0, _col#1, _col#2, 0]], [1,0.5], 0.1, 1, "", "", _impactEmitter];
	_cloud setParticleRandom [2, [10, 10, 5], [10, 10, 5], 0, 0, [0, 0, 0, 0.1], 0, 0];
	_cloud setParticleCircle [50, [8, 8, 5]];
	_cloud setDropInterval 0.005;

	// dust tower
	_tower = "#particlesource" createVehicleLocal getPos _impactEmitter;
	_tower setParticleParams [["A3\Data_F\ParticleEffects\Universal\universal.p3d", 16, 7, 48], "", "Billboard", 1, 18, [0, 0, 0],[0, 0, 0], 0, 1.5, 1, 0, [40, 90], [[_col#0, _col#1, _col#2, 0.5], [_col#0, _col#1, _col#2, 0.5], [_col#0, _col#1, _col#2, 0.3], [_col#0, _col#1, _col#2, 0]], [1,0.5], 0.1, 1, "", "", _impactEmitter];
	_tower setParticleRandom [2, [10, 10, 5], [5, 5, 20], 0, 0, [0, 0, 0, 0.1], 0, 0];
	_tower setParticleCircle [20, [2, 2, 20]];
	_tower setDropInterval 0.01;

	// rocks
	_debris = "#particlesource" createVehicleLocal (getPosATL _impactEmitter);
	_debris setParticleParams [["\A3\data_f\ParticleEffects\Universal\Mud.p3d", 1, 0, 1, 1], "", "SpaceObject", 1,30,[0,0,0],[0, 0, 20], 1, 500,15,0,[2.5],[[0, 0, 0, 1]], [0.125],0, 0, "","",_impactEmitter, 0, true,0];
	_debris setParticleRandom [10,[25, 25, 0.1],[30, 30, 20],0.5,1,[0, 0, 0, 0],0,0,0,0];
	_debris setParticleCircle [0.5,[10, 10, 10]];
	_debris setDropInterval 0.0004;
	sleep 0.1;
	deleteVehicle _debris;
	sleep 0.9;
	{deleteVehicle _x} forEach [_wave, _cloud, _tower, _debris];
};

_fnc_postProcessEffects = {
	/*
		Author: TheTimidShade

		Description:
			Handles post processing effects for beam impact.

		Parameters:
			0: OBJECT - Beam target object, used to determine if player is close enough to need ppeffects
			
		Returns:
			NONE
	*/

	params ["_target"];

	if (!hasInterface) exitWith {}; // dedicated server & HC do not need to run post process effects
	if (player distance _target > 1000) exitWith {}; // don't play ppeffects if player is far away

	// film grain added by kaydol
	_fnc_spawnEffect = {
		params ["_name", "_priority", "_effect", "_lifeTime", "_handle"];
		while {
			_handle = ppEffectCreate [_name, _priority];
			_handle < 0
		} do {
			_priority = _priority + 1;
		};
		_handle ppEffectEnable true;
		_handle ppEffectAdjust _effect;
		_time = time;
		_maxIntensity = _effect # 0;
		while {time - _time < _lifeTime} do {
			_intensity = linearConversion [ _time, _time + _lifeTime, time, _maxIntensity, 0 ];
			_handle ppEffectAdjust [_intensity, _effect#1, _effect#2, _effect#3, _effect#4];
			_handle ppEffectCommit 0.01;
			sleep 0.01;
		};
		_handle ppEffectEnable false;
		ppEffectDestroy _handle;
	};
	_effect = [ 0.5, 1.25, 2.01, 0.75, 1.0, 0 ];
	["FilmGrain", 2000, _effect, 20] spawn _fnc_spawnEffect;
	
	// blur
	[] spawn {
		cutText ["", "WHITE OUT", 1];
		titleCut ["", "WHITE IN", 1];
		"dynamicBlur" ppEffectEnable true;   
		"dynamicBlur" ppEffectAdjust [8];   
		"dynamicBlur" ppEffectCommit 0;     
		"dynamicBlur" ppEffectAdjust [0.0];  
		"dynamicBlur" ppEffectCommit 1.5;  
		sleep 1.5;
		"dynamicBlur" ppEffectEnable false; 
	};

	// shake
	[] spawn {
		addCamShake [55, 5, 21];
		enableCamShake false;
		sleep 1;
		enableCamShake true;
		addCamShake [15, 5, 21];
		enableCamShake false;
	};
};

// ++++++++++++++++++++++++++++++++ \\
// 				 Start			    \\
// ++++++++++++++++++++++++++++++++ \\

params [
	["_target", objNull, [objNull]],
	"_units",
	"_activated"
];

private _beamColour = _target getVariable ["beamColour", [1,0.6,0.2]] ;
private _debrisColour = _target getVariable ["debrisColour", [0.3, 0.27, 0.15]] ;
// done dealing with this inconsistency 
if (_beamColour isEqualType "") then { _beamColour = compile _beamColour; };
if (_debrisColour isEqualType "") then { _debrisColour = compile _debrisColour; };

// input validation
if (isNull _target) exitWith {systemChat "Invalid position given for beam target! Exited";};
if (count _beamColour < 3) then {
	_beamColour = [1,0.6,0.2]; 
	["Invalid colour given for beam, default used instead"] call BIS_fnc_error;
};
if (count _debrisColour < 3) then {
	_debrisColour = [0.3, 0.27, 0.15]; 
	["Invalid colour given for beam debris, default used instead"] call BIS_fnc_error;
};

private _maxKillRange = 200;
private _maxDamageRange = 400;

private _targetPos = getPosATL _target;

// create emitters
private _impactEmitter = "Land_HelipadEmpty_F" createVehicleLocal _targetPos;
private _beamEmitter = "Land_Battery_F" createVehicleLocal _targetPos;
_beamEmitter setPosATL [_targetPos#0, _targetPos#1, 2000];

// accelerate beam emitter towards ground
_beamEmitter setVelocity [0,0,-600];

// create bright flash when beam is initially fired
_flash = "#lightpoint" createVehicleLocal (getpos _beamEmitter);
_flash setLightBrightness 300;
_flash setLightAmbient _beamColour;
_flash setLightColor _beamColour;
_flash lightAttachObject [_beamEmitter, [0,0,200]];
_flash spawn {sleep 0.1; deleteVehicle _this;};

// create beam particles
[_beamEmitter, _beamColour, _targetPos] spawn _fnc_rayParticles;

// wait until the beam is almost halfway and play laser sound
waitUntil {sleep 0.01; ((getPosATL _beamEmitter)#2 < 750)};
_impactEmitter say3D ["laser", 20000, 1, false];

// wait until touching ground/near target
waitUntil {sleep 0.01; vectorMagnitude (velocity _beamEmitter) < 20 || _beamEmitter distance _targetPos < 5 || (getPosATL _beamEmitter)#2 < 5};
_impactEmitter say3D ["laser_impact", 20000, 1, false];
_impactEmitter setPosATL (getPosATL _beamEmitter);
deleteVehicle _beamEmitter;

// destroy/damage any nearby units/objects/buildings
if (isServer) then {[_impactEmitter, _maxKillRange, _maxDamageRange] spawn _fnc_explosionDamage;};

// explosion particles
[_impactEmitter, _debrisColour] spawn _fnc_explosionParticles;

// impact post processing effects
[_target] spawn _fnc_postProcessEffects;

sleep 30;

deleteVehicle _impactEmitter;