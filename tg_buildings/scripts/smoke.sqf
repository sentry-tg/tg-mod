
params ["_crystal", ["_startSmoking", True], ["_color", "GREEN"], ["_dropInterval", 0.03], "_smokeRadius"];

/* Defining color of the smoke */

private _col = [1, 1, 1];
 
if ( _color isEqualTo "BLUE" ) then {
	_col = [0.3, 0.3, 1];
};
if ( _color isEqualTo "GREEN" ) then {
	_col = [0.3, 1, 0.3];
};


/* Tiberium smoke effect is hardcoded */
if (isNil{ _smokeRadius }) then 
{
	switch ( typeOf _crystal ) do 
	{
		case "tg_tiberiumgreen_1_seedling" 	: { _smokeRadius = 0.5; _dropInterval = 0.2; };
		case "tg_tiberiumgreen_1_medium" 	: { _smokeRadius = 0.5; _dropInterval = 0.2; };
		case "tg_tiberiumgreen_1" 		: { _smokeRadius = 0.5; _dropInterval = 0.2; };
		case "tg_tiberiumgreen_3" 		: { _smokeRadius = 3.0; _dropInterval = 0.1; };
		case "tg_tiberiumgreen_5" 		: { _smokeRadius = 4.0; _dropInterval = 0.075; };
		case "tg_tiberiumgreen_13" 		: { _smokeRadius = 8.0; _dropInterval = 0.03; };

		case "gdi_tr" 				: { _smokeRadius = 4.0; _dropInterval = 0.075; };
		case "nod_tr" 				: { _smokeRadius = 4.0; _dropInterval = 0.075; };
		
		case "tg_tiberium_bluecrystal_1" 	: { _smokeRadius = 2.0; _dropInterval = 0.03; };
		case "tg_tiberiumblue_1_seedling" 	: { _smokeRadius = 0.5; _dropInterval = 0.2; };
		case "tg_tiberiumblue_1_medium" 	: { _smokeRadius = 0.5; _dropInterval = 0.2; };
		case "tg_tiberiumblue_1" 		: { _smokeRadius = 0.5; _dropInterval = 0.2; };
		case "tg_tiberiumblue_3" 		: { _smokeRadius = 3.0; _dropInterval = 0.1; };
		case "tg_tiberiumblue_5" 		: { _smokeRadius = 4.0; _dropInterval = 0.075; };
		case "tg_tiberiumblue_13" 		: { _smokeRadius = 8.0; _dropInterval = 0.03; };
		
		default { _smokeRadius = 0 };
	};
};

if ( _startSmoking ) then 
{
	/* Start smoking */
	
	private _pos = getPos _crystal;
	private _ps = "#particlesource" createVehicleLocal _pos;
	
	_ps setParticleCircle [0, [0.1, 0.1, 0.1]];
	_ps setParticleRandom [
		/*lifeTimeVar*/ 				0, 
		/*positionVar*/					[_smokeRadius, _smokeRadius, 0.0], 
		/*moveVelocityVar*/				[0.25, 0.25, 0.025], 
		/*rotationVelocityVar*/			0, 
		/*sizeVar*/						0.5, 
		/*colorVar*/					[0, 0, 0, 0.1], 
		/*randomDirectionPeriodVar*/	0, 
		/*randomDirectionIntensityVar*/	0, 
		/*angleVar*/					1
	];
		
	_ps setParticleParams [
		/*Sprite*/ 				["a3\data_f\ParticleEffects\Universal\Universal.p3d", 16, 7, 48], 
		/*AnimationName*/		"", 
		/*Type*/ 				"Billboard", 
		/*TimmerPer*/ 			1, 
		/*Lifetime*/ 			5, 
		/*Position*/ 			[0,0,1], 
		/*MoveVelocity*/ 		[0.2,0.1,0.1], 
		/*RotationVelocity*/	1,
		/*Simulation*/ 			1.277, 1, 0.025, //weight volume rubbing
		/*Scale*/ 				[0.1, 2, 6], 
		/*Color*/ 				[
									[_col select 0, _col select 1, _col select 2, 0], 
									[_col select 0, _col select 1, _col select 2, 0.05], 
									[_col select 0, _col select 1, _col select 2, 0.10], 
									[_col select 0, _col select 1, _col select 2, 0.20], 
									[_col select 0, _col select 1, _col select 2, 0.10], 
									[_col select 0, _col select 1, _col select 2, 0.05], 
									[_col select 0, _col select 1, _col select 2, 0]
								], 
		/*AnimSpeed*/ 			[0.125], 
		/*randDirPeriod*/ 		1, 
		/*randDirIntesity*/ 	0, 
		/*onTimerScript*/ 		"", 
		/*DestroyScript*/ 		"", 
		/*Follow*/ 				_crystal
	];
	
	_ps setDropInterval _dropInterval;

	_crystal setVariable ["TG_ParticleSource", _ps];

}
else 
{
	/* Stop smoking */
	
	private _ps = _crystal getVariable "TG_ParticleSource";

	if !(isNil{ _ps }) then {
		_ps setDropInterval 1;
		deleteVehicle _ps;
		_crystal getVariable ["TG_ParticleSource", nil]
	};

};