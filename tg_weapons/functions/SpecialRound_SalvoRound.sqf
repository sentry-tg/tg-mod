
/*
	While stealing this code, please give credits to kaydol.
	Originally written for Tiberian Genesis addon which can be found on Arma 3 Steam Workshop.
*/

#define DEBUG 1

params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile"];
	
(TG_SpecialRounds select { _x # 0 == _ammo } select 0) params ["_parentProjectileType", "_maxMoa", "_minMoa", "_numberOfProjectiles", "_newProjectileType", "_deleteParent", ["_onDeletionFunc", ""]];
	
_velocity = velocity _projectile;
_magnitude = vectorMagnitude _velocity;

private _fnc_getDispersion = {
	params ["_minMoa", "_maxMoa", "_magnitude"];
	_moa_metric = (_minMoa + random (_maxMoa-_minMoa)) * 0.02908; // In metric units 1 MOA at 100 meters = 2.908 centimeters (1.144inches)
	systemChat format ["_minMoa = %1 | _maxMoa = %2 | %3", _minMoa, _maxMoa, _moa_metric];
	_moa_metric * _magnitude / 100;
};
			
#ifdef DEBUG
TG_SalvoRound_SpawnedRounds = [];
#endif
			
for "_i" from 1 to _numberOfProjectiles do {
	// V1. For some reason does not behave well when min_moa is close to max_moa, often gives higher moa in that case
	//_dX = _velocity # 0 + (selectRandom [-0.5,0.5]) * ([_minMoa, _maxMoa, _magnitude] call _fnc_getDispersion); 
	//_dY = _velocity # 1 + (selectRandom [-0.5,0.5]) * ([_minMoa, _maxMoa, _magnitude] call _fnc_getDispersion); 
	//_dZ = _velocity # 2 + (selectRandom [-0.5,0.5]) * ([_minMoa, _maxMoa, _magnitude] call _fnc_getDispersion); 
	
	// V2. Does not go above max_moa. When min_moa is close to max_moa, tends to produce the same spread pattern over and over
	_velocityCopy = _velocity;
	_velocityCopy = [_velocityCopy, (_minMoa + random(_maxMoa-_minMoa))/60, 2] call BIS_fnc_RotateVector3D;
	_velocityCopy set [2, _velocityCopy # 2 + (selectRandom [-0.5,0.5]) * ([_minMoa, _maxMoa, _magnitude] call _fnc_getDispersion)];
	_velocityCopy params ["_dX", "_dY", "_dZ"];
	
	_bullet = _newProjectileType createVehicle [0,0,2000];
	_bullet setShotParents [vehicle _unit,_unit];
	_bullet setVelocity [_dX, _dY, _dZ];
	_bullet setPosATL getPosATL _projectile;
	
#ifdef DEBUG 
	TG_SalvoRound_SpawnedRounds pushBack _bullet;
	if (_deleteParent == 0) then {
		TG_SalvoRound_SpawnedRounds pushBack _projectile;
	};
#endif
};
			
#ifdef DEBUG
TG_SalvoRound_MuzzlePos = ASLToAGL eyePos _unit;
TG_SalvoRound_EndPoints = [];
[] spawn {
	waitUntil {
		{
			if (alive _x) then { TG_SalvoRound_EndPoints set [_forEachIndex, getPos _x] };
		} forEach TG_SalvoRound_SpawnedRounds;
		{alive _x} count TG_SalvoRound_SpawnedRounds == 0
	};
	
	["TG_SalvoRound_Draw3D", "onEachFrame"] call BIS_fnc_removeStackedEventHandler;
	
	["TG_SalvoRound_Draw3D", "onEachFrame", {
		{ drawLine3D [TG_SalvoRound_MuzzlePos, _x, [1,0,0,1]] } forEach TG_SalvoRound_EndPoints;
		
		_maxSpread = 0;
		_first = TG_SalvoRound_EndPoints # 0;
		{
			_dist = _first distance _x;
			if (_dist > _maxSpread) then { _maxSpread = _dist; };
		} forEach TG_SalvoRound_EndPoints;
		
		hintsilent format ["%1 cm\n%2 MOA", _maxSpread * 100, _maxSpread * 100 / 2.908 * 100 / (TG_SalvoRound_MuzzlePos distance TG_SalvoRound_EndPoints # 0)];
		
	}] call BIS_fnc_addStackedEventHandler;
};
#endif