
/*
	While stealing this code, please give credits to kaydol.
	Originally written for Tiberian Genesis addon which can be found on Arma 3 Steam Workshop.
*/

#define DEBUG 1

params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile"];

if (isNil{ TG_SpecialRounds }) then 
{
	// I dont know how long does it take to read from the config, but I assume that 
	// caching inside missionNameSpace and reading from there should be faster than 
	// attempting to read tg_scripted_ammo from the ammo config each time
	
	TG_SpecialRounds = [];
	private _supportedAmmoCfgs = configProperties [configFile >> "CfgAmmo", "isClass _x && getNumber (_x >> 'tg_scripted_ammo') == 1"];
	TG_SpecialRounds = _supportedAmmoCfgs apply {[
		configName _x, 
		getNumber(_x >> 'tg_max_moa'), 
		getNumber(_x >> 'tg_min_moa'), 
		getNumber(_x >> 'tg_numberOfProjectiles'), 
		getText(_x >> 'tg_projectile'),
		getNumber(_x >> 'tg_delete_parent'),
		getText(_x >> 'tg_on_deletion')
	]};
	
};

if (_ammo in (TG_SpecialRounds apply {_x # 0})) then 
{
	(TG_SpecialRounds select { _x # 0 == _ammo } select 0) params ["_parentProjectileType", "_maxMoa", "_minMoa", "_numberOfProjectiles", "_newProjectileType", "_deleteParent", ["_onDeletionFunc", ""]];
	
	switch (_ammo) do {
		case "TG_Salvo_Round": 
		{
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
			TG_SalvoRound_MuzzlePos = ASLToAGL eyePos player;
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
					
					hintsilent format ["%1 cm\n%2 MOA", _maxSpread * 100, _maxSpread * 100 / 2.908 * 100 / (player distance TG_SalvoRound_EndPoints # 0)];
					
				}] call BIS_fnc_addStackedEventHandler;
			};
#endif
		};
		default {};
	};
	
	if (_onDeletionFunc != "" && _deleteParent == 0) then {
		[_this, _projectile, _onDeletionFunc] spawn {
			params ["_args", "_projectile", "_onDeletionFunc"];
			WaitUntil {!alive _projectile};
			_args call compile _onDeletionFunc;
		};
	} else {
		if (_deleteParent == 1) then {
			deleteVehicle _projectile;
		};
		if (_onDeletionFunc != "") then {
			copyToClipBoard str _this;
			_this call call compile _onDeletionFunc;
		};
	};
};
