

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
			
		};
		case "TG_Repulsor_Round": 
		{
			
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
			_this call call compile _onDeletionFunc;
		};
	};
};
