#include "BIS_AddonInfo.hpp"
#define _ARMA_

class CfgPatches {
	class TG_Weapons {
		author = "Tiberian Genesis";
		units[] = {};
		weapons[] = {"TG_GDI_Assault_Rifle", "TG_NOD_Assault_Rifle", "TG_Nod_Laser_Weapon", "TG_DiscThrow", "TG_NOD_RocketLauncher"};
		magazines[] = {"TG_GDI_AR_Magazine", "TG_NOD_AR_Magazine", "TG_Nod_Laser_Magazine", "TG_GDI_DiscGrenade", "TG_NOD_RocketLauncher_Magazine"};
		requiredVersion = 0.1;
		requiredAddons[] = {"TG_Sounds", "TG_Core", "tg_modules"};
	};
};

class RscInGameUI
{
	class RscUnitInfo;
	class RscWeaponZeroing;
	class TG_PiP_Scope: RscWeaponZeroing
	{
		onLoad = "['onLoad',_this,'RscUnitInfo','IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay'); [_this select 0, 3, 'pip_scope'] call TG_fnc_Scope2Screen;";
	}; 
};

class CfgCloudlets {
	class Default;
	class TG_Laser_Effect_01 
	{
		//interval = 9.00001e-005;
		interval = 0.000001e-0001;
		circleRadius = 0;
		circleVelocity[] = {0, 0, 0};
		ignoreWind = 1;
		angle = 0;
		angleVar = 1;
		particleFSLoop = 1;
		particleShape = "\a3\data_f\particleeffects\universal\Universal.p3d";
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 8;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 0.6;
		moveVelocity[] = {0, 0, 0};
		rotationVelocity = 0;
		weight = 1.01;
		volume = 0.8;
		rubbing = 0;
		size[] = {0.08, 0.3};
		sizeCoef = 3;
		//color[] = {{0.7, 0.7, 0.7, 0}, {0.75, 0.75, 0.75, 0}, {0.8, 0.8, 0.8, 0}};
		color[] = {{1, 0, 0, 0.04}, {1, 0, 0, 0.018}, {1, 0, 0, 0.006}, {1, 0, 0, 0.001}};
		colorCoef[] = {1, 1, 1, 1};
		animationSpeed[] = {1};
		animationSpeedCoef = 1;
		randomDirectionPeriod = 0.03;
		randomDirectionIntensity = 0.03;
		onTimerScript = "";
		beforeDestroyScript = "";
		blockAIVisibility = 0;
		lifeTimeVar = 0;
		position[] = {0,0,0};
		positionVar[] = {0, 0, 0};
		positionVarConst[] = {0,0,0};
		MoveVelocityVar[] = {0, 0, 0};
		MoveVelocityVarConst[] = {0,0,0};
		rotationVelocityVar = 1;
		sizeVar = 0;
		colorVar[] = {0, 0, 0, 0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
		emissiveColor[] = {{500000, 0, 0, 0}, {0, 0, 0, 0}};
		//emissiveColor[] = {{420, 1630, 1170, 0}, {0, 0, 0, 0}};
	};
	
	class TG_Laser_Effect_02
	{
		//interval = 9.00001e-005;
		interval = 0.000001e-0001;
		circleRadius = 0;
		circleVelocity[] = {0, 0, 0};
		ignoreWind = 1;
		angle = 0;
		angleVar = 1;
		particleFSLoop = 1;
		particleShape = "\a3\data_f\particleeffects\universal\Universal.p3d";
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 8;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 0.6;
		moveVelocity[] = {0, 0, 0};
		rotationVelocity = 0;
		weight = 1.01;
		volume = 0.8;
		rubbing = 0;
		size[] = {0.1, 0.2};
		sizeCoef = 2.5;
		//color[] = {{0.7, 0.7, 0.7, 0}, {0.75, 0.75, 0.75, 0}, {0.8, 0.8, 0.8, 0}};
		color[] = {{1, 1, 1, 0.04}, {1, 1, 1, 0.018}, {1, 1, 1, 0.006}, {1, 1, 1, 0.001}};
		colorCoef[] = {1, 1, 1, 1};
		animationSpeed[] = {1};
		animationSpeedCoef = 1;
		randomDirectionPeriod = 0.03;
		randomDirectionIntensity = 0.03;
		onTimerScript = "";
		beforeDestroyScript = "";
		blockAIVisibility = 0;
		lifeTimeVar = 0;
		position[] = {0,0,0};
		positionVar[] = {0, 0, 0};
		positionVarConst[] = {0,0,0};
		MoveVelocityVar[] = {0, 0, 0};
		MoveVelocityVarConst[] = {0,0,0};
		rotationVelocityVar = 1;
		sizeVar = 0;
		colorVar[] = {0, 0, 0, 0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
		emissiveColor[] = {{500000, 500000, 500000, 0}, {0, 0, 0, 0}};
		//emissiveColor[] = {{420, 1630, 1170, 0}, {0, 0, 0, 0}};
	};

	class TG_Laser_Effect_03: Default
	{
		interval = 0.001;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		ignoreWind = 1;
		particleShape = "\A3\data_f\ParticleEffects\Universal\Refract";
		particleFSNtieth = 1;
		particleFSIndex = 0;
		particleFSFrameCount = 1;
		particleFSLoop = 0;
		angleVar = 0.5;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 1;
		position[] = {"positionX + 0.12 * directionLocalX","positionY + 0.12 * directionLocalY","positionZ + 0.12 * directionLocalZ"};
		moveVelocity[] = {0,0,0};
		rotationVelocity = 0;
		weight = 2.5;
		volume = 1;
		rubbing = 0;
		size[] = {8.1,7.2};
		sizeCoef = 3;
		color[] = {{0.3,0.3,0.3,0.01},{0.3,0.3,0.3,0.26},{0.3,0.3,0.3,0.24},{0.3,0.3,0.3,0.22},{0.3,0.3,0.3,0.16},{0.3,0.3,0.3,0.08},{0.3,0.3,0.3,0.02}};
		colorCoef[] = {1,1,1,1.1};
		animationSpeed[] = {1.2};
		animationSpeedCoef = 1;
		randomDirectionPeriod = 0;
		randomDirectionIntensity = 0;
		onTimerScript = "";
		beforeDestroyScript = "";
		blockAIVisibility = 0;
		destroyOnWaterSurface = 1;
		destroyOnWaterSurfaceOffset = -0.1;
		lifeTimeVar = 0.5;
		positionVar[] = {0,0,0};
		MoveVelocityVar[] = {0,0,0};
		rotationVelocityVar = 1;
		sizeVar = 0.03;
		colorVar[] = {0,0,0,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};

	class ImpactSparksSabot1;
	class TG_Laser_Sparks_01:ImpactSparksSabot1
	{
		color[] = {{ 1,0.5,0.5,-50 }};
		position[] = {"positionX + (directionLocalX * 1.1)","positionY + (directionLocalY * 1.1)","positionZ + (directionLocalZ * 1.1)"};
	};

	class ImpactSparksSabot2;
	class TG_Laser_Sparks_02:ImpactSparksSabot2
	{
		color[] = {{ 1, 0, 0.025,-50 }};
		position[] = {"positionX + (directionLocalX * 1.1)","positionY + (directionLocalY * 1.1)","positionZ + (directionLocalZ * 1.1)"};
	};

};

class CfgLights
{
	class Chemlight_Red;
	class TG_Laser_Light_Red: Chemlight_Red
	{
		ambient[] = {1,0.2,0.2,3};
		color[] = {1,0.2,0.2,1};
		brightness = 4;
		intensity = 8000;
		position[] = {"positionX + (directionLocalX * 1.1)","positionY + (directionLocalY * 1.1)","positionZ + (directionLocalZ * 1.1)"};
	};

	class SparksLight;
	class TG_Laser_Sparks_Light: SparksLight
	{
		position[] = {"positionX + (directionLocalX * 1.3)","positionY + (directionLocalY * 1.3)","positionZ + (directionLocalZ * 1.3)"};
	};

	class TG_Laser_Fired_Light {
		color[] = {1,0.2,0.2,1};
		ambient[] = {1,0.2,0.2,3};
		brightness = 4;
		intensity = 8000;
		drawLight = 0;
		daylight = 1;
		
		class Attenuation {
			start = 0;
			constant = 1;
			linear = 0;
			quadratic = 40;
		};
		position[] = {0, 0, 0};
		diffuse[] = {0.1, 0, 0.0025};
	};

};

class TG_Laser_Fired
{
	class Light1
	{
		simulation = "light";
		type = "TG_Laser_Fired_Light";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.12;
	};
	class LightPink
	{
		simulation = "light";
		type = "TG_Laser_Light_Red";
		position[] = {0,0,0};
		intensity = 0.8;
		interval = 1;
		lifeTime = 0.6;
	};

	class SparksLight
	{
		simulation = "light";
		type = "TG_Laser_Sparks_Light";
		position[] = {0,0,0};
		intensity = 0.001;
		interval = 1;
		lifeTime = 0.75;
	};
//	class ImpactSparks1
//	{
//		simulation = "particles";
//		type = "TG_Laser_Sparks_01";
//		position[] = {0,0,0};
//		intensity = 1;
//		interval = 1;
//		lifeTime = 0.75;
//	};
//	class ImpactSparks2
//	{
//		simulation = "particles";
//		type = "TG_Laser_Sparks_02";
//		position[] = {0,0,0};
//		intensity = 1;
//		interval = 1;
//		lifeTime = 1.4;
//	};
};

class TG_Laser_Fly
{
	class TG_Light_01
	{
		simulation = "light";
		type = "TG_Laser_Fired_Light";
		position[] = {0,0,0};
		intensity = 10;
		interval = 1;
		lifeTime = 10.12;
	};

	class TG_Rail_01 {
		simulation = "particles";
		type = "TG_Laser_Effect_01";
		position[] = {0, 0, 0};
		intensity = 50;
		interval = 0.1;
		lifeTime = 20;
	};
	
	class TG_Rail_02 {
		simulation = "particles";
		type = "TG_Laser_Effect_02";
		position[] = {0, 0, 0};
		intensity = 50;
		interval = 0.1;
		lifeTime = 20;
	};

//	class TG_Rail_03 {
//		simulation = "particles";
//		type = "TG_Laser_Effect_03";
//		position[] = {0,0,0};
//		intensity = 20;
//		interval = 1;
//		lifeTime = 20;
//	};
};

class TG_Laser_Explosion
{
	class LightPink
	{
		simulation = "light";
		type = "TG_Laser_Light_Red";
		position[] = {0,1,0};
		intensity = 1;
		interval = 1;
		lifeTime = 2;
	};			
};

class CfgCameraShake {
	defaultCaliberCoefWeaponFire = 0.0;
};

class CfgAmmo {

	class Default;
	class BulletBase;
	class R_PG32V_F;
	class Grenade: Default{};
	class GrenadeHand: Grenade{};

	class TG_NOD_Laser_Ammo: Bulletbase {
		simulation = "shotBullet";
		effectsFire = "ChemlightLight_Red";
		effectFly = "TG_Laser_Fly";
		airfriction = 0;
		caliber = 10;
		cost = 500;
		cratereffects = "ExploAmmoCrater";
		craterwatereffects = "ImpactEffectsWaterExplosion";
		coefGravity = 0;
		deflecting = 0;
		explosive = 1;
		hit = 400;
		indirecthit = 10;
		indirecthitrange = 2;
		model = "\A3\Weapons_f\Data\bullettracer\shell_tracer_red";
		muzzleeffect = "";
		timetolive = 10;
		tracerendtime = 10;
		tracerscale = 0.5;
		tracerstarttime = 0.0000;
		typicalspeed = 50000;
		whistledist = 14;
		whistleonfire = 1;

		soundhit[] = {"tg_sounds\nod\defense\laserturret\laser_hit.wss", 1.99526, 1, 1800};
		supersoniccrackfar[] = {"tg_sounds\nod\defense\laserturret\laser_hit.wss", 0.223872, 1.5, 150};
		supersoniccracknear[] = {"tg_sounds\nod\defense\laserturret\laser_hit.wss", 0.316228, 1, 50};


		class HitEffects {
			default_mat = "ImpactMetalSabotBig";
			hitbuilding = "ImpactMetalSabotBig";
			hitconcrete = "ImpactMetalSabotBig";
			hitgroundhard = "ImpactMetalSabotBig";
			hitgroundsoft = "ImpactMetalSabotBig";
			hitmetal = "ImpactMetalSabotBig";
			hitmetalplate = "ImpactMetalSabotBig";
			hitwater = "ImpactEffectsWaterBig";
		};
		class CamShakeExplode {
			distance = "0";
			duration = "0";
			frequency = 0;
			power = "0";
		};
		class CamShakeHit {
			distance = 0;
			duration = "0";
			frequency = 0;
			power = 0;
		};
		class CamShakeFire {
			distance = 0;
			duration = 0;
			frequency = 0;
			power = 0;
		};
		class CamShakePlayerFire {
			distance = 0;
			duration = 0;
			frequency = 0;
			power = 0;
		};

		lightColor[] = {1, 1, 1, 0};
		maxSpeed = 500000;
		sideAirFriction = 0;
		explosioneffects = "TG_Laser_Explosion";
	};

	class TG_GDI_AR_Ball : BulletBase 
	{
		hit = 9;
		indirectHit = 0;
		indirectHitRange = 0;
		cartridge = "FxCartridge_9mm";
		model = "\A3\Weapons_f\Data\bullettracer\tracer_white";
		typicalSpeed = 716.28;
		initSpeed = 716.28;
		airFriction = -0.001312;
		caliber = 1;
		deflecting = 20;
		
	};

	class TG_NOD_AR_Ball : BulletBase 
	{
		hit = 9;
		indirectHit = 0;
		indirectHitRange = 0;
		cartridge = "FxCartridge_9mm";
		model = "\A3\Weapons_f\Data\bullettracer\tracer_white";
		typicalSpeed = 716.28;
		initSpeed = 716.28;
		airFriction = -0.001312;
		caliber = 1;
		deflecting = 20;
		
	};
	
	class GrenadeHand_stone: GrenadeHand {};
	class TG_GDI_DiscGrenade_Ammo : GrenadeHand_stone {
		model = "\tg_weapons\gdi\model\gdi_discgrenade";
		hit = 100;
		indirectHit = 8;
		indirectHitRange = 6;
		dangerRadiusHit=10;
		suppressionRadiusHit=10;
		explosive = true;
		explosionEffectsRadius = 5;
		initSpeed = 80;
		typicalspeed=80;
		whistleDist=0;
		deflecting = 100;
		airfriction = 0;
		soundFly[] = {"tg_sounds\gdi\weapons\gdi_discfly.wav", db-30, 1, 50};
		soundEngine[] = {"", 1, 1};
		explosionSoundEffect = "DefaultExplosion";
		CraterEffects = "GrenadeCrater";
		CraterWaterEffects = "ImpactEffectsWaterExplosion";
		explosionEffects = "GrenadeExplosion";
		visibleFire = 1;	// how much is visible when this weapon is fired
		audibleFire = 0.25;
		visibleFireTime = 0;	// how long is it visible
		explosionTime = 5;
		timeToLive = 6;
		
		class HitEffects {
			hitWater = "ImpactEffectsWaterRocket";
		};
		
		class CamShakeExplode {
			power = 4;
			duration = 1;
			frequency = 15;
			distance = 20;
		};
	};

	class TG_NOD_RocketLauncher_Ammo : R_PG32V_F {
		sideairfriction = 0.075;
		thrust = 255;
		thrusttime = 0.4;
		timetolive = 10;
		maxspeed = 255;
	};
	
	class TG_SpecialRound : Bulletbase {};
	
	class TG_Salvo_Round : TG_SpecialRound { //["BulletCore","Default"]
		hit = 2;
		tracersEvery = 1; 
		typicalSpeed = 800; // Hit value is valid when projectile moves at this speed. With lower speed, the hit caused by the ammo is lower as well.
		indirectHit = 0;
		indirectHitRange = 0;
		simulation = "shotBullet";
		caliber = 0; //Acts as penetration multiplier for the projectile. velocity[m/s] * caliber * penetrability / 1000. Penetrability is a material property (for RHA steel it is 15, for concrete 80, for meat 250).
		cartridge = "FxCartridge_slug"; //Declares the path to the cartridge P3D model, which may be ejected on each shot. Like all model specifications, .p3d is inferred.
		cost = 5;
		visibleFire = 10;
		audibleFire = 15;
		airFriction = -0.0023;
		waterEffectOffset = -0.8;
		dangerRadiusBulletClose = 4;
		dangerRadiusHit = 8;
		suppressionRadiusBulletClose = 2;
		suppressionRadiusHit = 4;
		model = "\A3\Weapons_f\ammo\shell";
		
		tg_scripted_ammo = 1; // Parameters below will be meaningful only for ammo that has tg_scripted_ammo = 1 
		tg_max_moa = 10; // Hardcoded maximum MOA; in metric units 1 MOA at 100 meters = 2.908 centimeters (1.144inches)
		tg_min_moa = 0; // Hardcoded minimum MOA; minimum spread of projectiles. Higher min moa = higher chance of hitting maximum MOA.
		
		tg_delete_parent = 0; // Delete the "parent" projectile after spawning all child projectiles. 
		// If this is set to 0, the actual amount of projectiles fired will be tg_numberOfProjectiles + 1
		// and the parent projectile will be very accurate because MOA dispersion won't be applied to it		
		
		tg_numberOfProjectiles = 3; // Number of child projectiles spawned per shot. More projectiles = higher chance of hitting maximum MOA
		tg_projectile = "TG_Salvo_Round"; // Classname of the child projectiles
		tg_on_deletion = "TG_fnc_SpecialRound_SalvoRound";
	};
	
	class TG_Repulsor_Round : TG_SpecialRound { //["BulletCore","Default"]
		hit = 0;
		tracersEvery = 1; 
		typicalSpeed = 800; // Hit value is valid when projectile moves at this speed. With lower speed, the hit caused by the ammo is lower as well.
		indirectHit = 0;
		indirectHitRange = 0;
		simulation = "shotBullet";
		caliber = 0; //Acts as penetration multiplier for the projectile. velocity[m/s] * caliber * penetrability / 1000. Penetrability is a material property (for RHA steel it is 15, for concrete 80, for meat 250).
		cartridge = "FxCartridge_slug"; //Declares the path to the cartridge P3D model, which may be ejected on each shot. Like all model specifications, .p3d is inferred.
		cost = 5;
		visibleFire = 10;
		audibleFire = 15;
		airFriction = -0.0023;
		waterEffectOffset = -0.8;
		dangerRadiusBulletClose = 4;
		dangerRadiusHit = 8;
		suppressionRadiusBulletClose = 2;
		suppressionRadiusHit = 4;
		model = "\A3\Weapons_f\ammo\shell";
		
		tg_scripted_ammo = 1;
		tg_delete_parent = 1;
		tg_on_deletion = "TG_fnc_SpecialRound_RepulsorRound"; // Function to be *called* when the parent is deleted
	};
};

class Extended_FiredBIS_Eventhandlers {
	class Man {
		class TG_SpecialRound_Fired {
			FiredBIS = "_this call TG_fnc_SpecialRound_FiredEH";
		};
	};
};

class CfgFunctions {
	class TG {
		class EventHandlers {
			class SpecialRound_FiredEH { file = "\tg_weapons\functions\SpecialRound_FiredEH.sqf"; };
			class SpecialRound_RepulsorRound { file = "\tg_weapons\functions\SpecialRound_RepulsorRound.sqf"; };
			class SpecialRound_SalvoRound { file = "\tg_weapons\functions\SpecialRound_SalvoRound.sqf"; };
		};
		class PiP {
			class Scope2Screen { file = "\tg_weapons\functions\Scope2Screen.sqf"; };
		};
	};
	
};


class CfgMagazines {

	class Default;
	class VehicleMagazine;
	class RPG32_F;
	class CA_Magazine: Default {};
	class HandGrenade: CA_Magazine {};

	class TG_Nod_Laser_Magazine: VehicleMagazine{
		author = "Tiberian Genesis";
		scope = 2;
		scopeCurator = 2;          
		scopeArsenal = 2;
		count = 1000;
		mass = 1;
		ammo = "TG_Nod_Laser_Ammo";
		displayname = "Nod Laser";
		displaynameshort = "Nod Laser";
		initspeed = 50000;
		maxLeadSpeed = 50000;
		tracersevery = 1;
		lastRoundsTracer = 1;
	};

	class TG_GDI_AR_Magazine : CA_Magazine 
	{
		author = "Tiberian Genesis";
		scope = 2;
		scopeCurator = 2;          
		scopeArsenal = 2;
		picture = ;
		displayName = "GDI Assault Rifle Magazine";
		displayNameShort = "GDI AR Mag";
		descriptionShort = "GDI Assault Rifle Magazine";
		ammo = "TG_GDI_AR_Ball";
		count = 30;
		initSpeed = 716.28;
		tracersEvery = 0;
		lastRoundsTracer = 0;
		mass = 12;
		model = "tg_weapons\gdi\model\gdi_assault_rifle_mag.p3d";
	};

	class TG_NOD_AR_Magazine : CA_Magazine 
	{
		author = "Tiberian Genesis";
		scope = 2;
		scopeCurator = 2;          
		scopeArsenal = 2;
		picture = ;
		displayName = "Nod Assault Rifle Magazine";
		displayNameShort = "Nod AR Mag";
		descriptionShort = "Nod Assault Rifle Magazine";
		ammo = "TG_NOD_AR_Ball";
		count = 30;
		initSpeed = 716.28;
		tracersEvery = 0;
		lastRoundsTracer = 0;
		mass = 12;
		model = "tg_weapons\nod\model\nod_assault_rifle_mag.p3d";
	};

	class HandGrenade_Stone: HandGrenade {};
	class TG_GDI_DiscGrenade: HandGrenade_Stone {
		author = "Tiberian Genesis";
		scope = 2;
		scopeCurator = 2;          
		scopeArsenal = 2;
		value = 0.1;
		displayName = "GDI Disc Grenade";
		picture = "\A3\Weapons_F\Data\UI\gear_M67_CA.paa";
		model = "\tg_weapons\gdi\model\gdi_discgrenade.p3d";
		ammo = "TG_GDI_DiscGrenade_Ammo";
		descriptionShort = "GDI Disc Grenade";
		displayNameShort = "GDI Disc";
	};

	class TG_NOD_RocketLauncher_Magazine: RPG32_F {
		author = "Tiberian Genesis";
		scope = 2;
		scopeCurator = 2;          
		scopeArsenal = 2;
		descriptionshort = "Nod Rocket";
		ammo = "TG_NOD_RocketLauncher_Ammo";
		mass = 1;
		displayname = "Nod Rocket";
		displaynameshort = Nod Rocket;
		modelSpecial = "\tg_weapons\nod\model\nod_rocketlauncher_empty.p3d";
		initSpeed = 255;
		count = 1;
	};
	
	class 1Rnd_Salvo_Magazine : CA_Magazine { //["Default"]
		author = "Tiberian Genesis";
		scope = 2;
		model = "bnae_core\bnae_core\mesh\bnae_shotgun_mag";
		displayName = "1Rnd Salvo";
		ammo = "TG_Salvo_Round";
		count = 100;
		initSpeed = 1100;
		picture = "\bnae_core\bnae_core\UI\gear_bnae_shotgun_mag_x_ca";
		descriptionShort = "";
		mass = 32;
	};
	class 1Rnd_Buckshot_Magazine : CA_Magazine { //["Default"]
		author = "Tiberian Genesis";
		scope = 2;
		model = "bnae_core\bnae_core\mesh\bnae_shotgun_mag";
		displayName = "1Rnd 00-Buckshot";
		ammo = "B_12G_Pellet";
		count = 1;
		initSpeed = 400;
		picture = "\bnae_core\bnae_core\UI\gear_bnae_shotgun_mag_x_ca";
		descriptionShort = "";
		mass = 4;
	};
	class 1Rnd_Repulsor_Magazine : CA_Magazine { //["Default"]
		author = "Tiberian Genesis";
		scope = 2;
		model = "bnae_core\bnae_core\mesh\bnae_shotgun_mag";
		displayName = "1Rnd Repulsor Magazine";
		ammo = "TG_Repulsor_Round";
		count = 1;
		initSpeed = 1;
		picture = "\bnae_core\bnae_core\UI\gear_bnae_shotgun_mag_x_ca";
		descriptionShort = "";
		mass = 32;
	};
};

class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;

class SlotInfo;
class MuzzleSlot;
class CowsSlot;
class PointerSlot;
class UnderBarrelSlot;

class CfgWeapons 
{
	class Default;
	class GrenadeLauncher : Default {};
	class Throw : GrenadeLauncher {};
	class MGun;
	class ItemCore;
	class launch_RPG32_F;	
	class InventoryOpticsItem_Base_F;
	
	class Rifle;
	class Rifle_Base_F: Rifle
	{
		class WeaponSlotsInfo;
		class GunParticles;
	};

	class TG_Nod_Laser_Weapon: Mgun {
		scope = 2;
		scopeCurator = 2;          
		scopeArsenal = 2; 
		displayname = "Nod Laser";
		reloadtime = 2;

		magazines[] = {"TG_Nod_Laser_Magazine"};
		reloadSound[] = {};
		magazineReloadTime = 12;
		cursor = "EmptyCursor";
		ballisticsComputer = 1;
		dispersion=0;
		dexterity = 10;
		canLock = 2;
		initSpeed = 50000;
		sounds[] = {"TG_LaserTurret_Sound"};

		aiRateOfFire = 2.0;	// delay between shots at given distance
		aiRateOfFireDispersion = 0;
		aiRateOfFireDistance = 500;

			
		class TG_LaserTurret_Sound {
			begin1[] = {"tg_sounds\nod\defense\laserturret\laser_fire.wss", 1.0, 1, 2100};
			begin2[] = {"tg_sounds\nod\defense\laserturret\laser_fire.wss", 1.0, 1, 2100};
			begin3[] = {"tg_sounds\nod\defense\laserturret\laser_fire.wss", 1.0, 1, 2100};
			soundBegin[] = {"begin1", 0.33, "begin2", 0.33, "begin3", 0.34};
		};

		class GunParticles {
			class FirstEffect {
				directionname = "konec hlavne";
				effectname = "TG_Laser_Fired";
				positionname = "usti hlavne";
			};
		};
};

	class TG_Assault_Rifle : Rifle_Base_F 
	{
		author = "Tiberian Genesis";
		displayName = "TG Assault Rifle";
		scope = 0;
		scopeCurator = 0;          
		scopeArsenal = 0;
		reloadAction = "GestureReloadMX";
		handAnim[] = {"OFP2_ManSkeleton", "\A3\Weapons_F\Rifles\MX\data\Anim\MX_gl.rtm"};
	};

	class TG_GDI_Assault_Rifle: TG_Assault_Rifle
	{
		_generalMacro = "TG_GDI_Assault_Rifle";
		baseWeapon="TG_GDI_Assault_Rifle";
		scope = 2;
		scopeCurator = 2;          
		scopeArsenal = 2;
		model = "\tg_weapons\gdi\model\gdi_assault_rifle.p3d";
		//modelOptics = "\A3\Weapons_F\acc\reticle_HAMR.p3d";
		displayName = "GDI Assault Rifle";
		descriptionShort = "GDI AR";
		picture = ;
		muzzles[] = {"this","Underbarrel"};
		magazines[] = {"TG_GDI_AR_Magazine"};
		class Library
		{
			libTextDesc = "GDI Assault Rifle";
		};
		maxZeroing = 600;
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: CowsSlot
			{
				linkProxy = "\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]= {"TG_GDI_Scope_01"};
				iconPicture = ;
				iconPosition[] = {0.5,0.3};
				iconPinpoint = "Bottom";
				iconScale = 0.2;
			};
			class MuzzleSlot: MuzzleSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[]= {"muzzle_snds_H"};
				iconPosition[]={0,0.44999999};
				iconScale=0.2;
			};
			class PointerSlot{};
			class UnderBarrelSlot{};
			mass = 125;
			allowedSlots[] = {801,701,901};
		};

		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="TG_GDI_Scope_01";
			};
		};

		class GunParticles : GunParticles
		{
			class SecondEffect
			{
				positionName = "Nabojnicestart";
				directionName = "Nabojniceend";
				effectName = "CaselessAmmoCloud";
			};
		};

		distanceZoomMin = 300;
		distanceZoomMax = 300;
		bullet1[] = {};
		bullet2[] = {};
		bullet3[] = {};
		bullet4[] = {};
		bullet5[] = {};
		bullet6[] = {};
		bullet7[] = {};
		bullet8[] = {};
		bullet9[] = {};
		bullet10[] = {};
		bullet11[] = {};
		bullet12[] = {};
		soundBullet[] = {};
		selectionFireAnim = "muzzleFlash";
		modes[] = {"Single","Burst","FullAuto","fullauto_medium","single_medium_optics1","single_far_optics2"};
		changeFiremodeSound[] = {"A3\sounds_f\weapons\closure\firemode_changer_2",2,1,20};
		drySound[]= {"A3\sounds_f\weapons\Other\dry_1", db-5, 1, 10};
		reloadMagazineSound[]= {"A3\sounds_f\weapons\reloads\new_MX",db-8,1, 30};
		class Single: Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "DefaultRifle";
				closure1[] = {"A3\sounds_f\weapons\closure\closure_rifle_1",0.3,1,10};
				closure2[] = {"A3\sounds_f\weapons\closure\closure_rifle_1",0.3,1,10};
				soundclosure[] = {"closure1",0.5,"closure2",0.5};
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[] = {"tg_sounds\gdi\weapons\gdi_assault.wav",4.5,1,1200};
				begin2[] = {"tg_sounds\gdi\weapons\gdi_assault.wav",4.5,1,1200};
				begin3[] = {"tg_sounds\gdi\weapons\gdi_assault.wav",4.5,1,1200};
				soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.34};
			};
			reloadTime = 0.13;
			dispersion = 0.00203;
			recoil = "recoil_single_trg";
			recoilProne = "recoil_single_prone_trg";
			minRange = 2;
			minRangeProbab = 0.5;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 300;
			maxRangeProbab = 0.2;
		};
		class Burst: Mode_Burst
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "DefaultRifle";
				closure1[] = {"A3\sounds_f\weapons\closure\closure_rifle_1",0.3,1,10};
				closure2[] = {"A3\sounds_f\weapons\closure\closure_rifle_1",0.3,1,10};
				soundclosure[] = {"closure1",0.5,"closure2",0.5};
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[] = {"tg_sounds\gdi\weapons\gdi_assault.wav",4.5,1,1200};
				begin2[] = {"tg_sounds\gdi\weapons\gdi_assault.wav",4.5,1,1200};
				begin3[] = {"tg_sounds\gdi\weapons\gdi_assault.wav",4.5,1,1200};
				soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.34};
			};
			burst = 3;
			reloadTime = 0.08;
			dispersion = 0.0005;
			recoil = "recoil_auto_mk20";
			recoilProne = "recoil_auto_prone_mk20";
			minRange = 2;
			minRangeProbab = 0.9;
			midRange = 15;
			midRangeProbab = 0.7;
			maxRange = 30;
			maxRangeProbab = 0.1;
			aiRateOfFire = 1e-006;
		};
		class FullAuto: Mode_FullAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "DefaultRifle";
				closure1[] = {"A3\sounds_f\weapons\closure\closure_rifle_1",0.3,1,10};
				closure2[] = {"A3\sounds_f\weapons\closure\closure_rifle_1",0.3,1,10};
				soundclosure[] = {"closure1",0.5,"closure2",0.5};
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[] = {"tg_sounds\gdi\weapons\gdi_assault.wav",4.5,1,1200};
				begin2[] = {"tg_sounds\gdi\weapons\gdi_assault.wav",4.5,1,1200};
				begin3[] = {"tg_sounds\gdi\weapons\gdi_assault.wav",4.5,1,1200};
				soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.34};
			};
			reloadTime = 0.13;
			dispersion = 0.00203;
			recoil = "recoil_auto_trg";
			recoilProne = "recoil_auto_prone_trg";
			minRange = 2;
			minRangeProbab = 0.9;
			midRange = 15;
			midRangeProbab = 0.7;
			maxRange = 30;
			maxRangeProbab = 0.1;
			aiRateOfFire = 1e-006;
		};
		class fullauto_medium: FullAuto
		{
			showToPlayer = 0;
			burst = 3;
			minRange = 2;
			minRangeProbab = 0.5;
			midRange = 75;
			midRangeProbab = 0.7;
			maxRange = 100;
			maxRangeProbab = 0.05;
			aiRateOfFire = 2;
			aiRateOfFireDistance = 200;
		};
		class single_medium_optics1: Single
		{
			requiredOpticType = 1;
			showToPlayer = 0;
			minRange = 5;
			minRangeProbab = 0.2;
			midRange = 350;
			midRangeProbab = 0.7;
			maxRange = 500;
			maxRangeProbab = 0.3;
			aiRateOfFire = 5;
			aiRateOfFireDistance = 500;
		};
		class single_far_optics2: single_medium_optics1
		{
			requiredOpticType = 2;
			minRange = 100;
			minRangeProbab = 0.2;
			midRange = 550;
			midRangeProbab = 0.7;
			maxRange = 700;
			maxRangeProbab = 0.05;
			aiRateOfFire = 7;
			aiRateOfFireDistance = 700;
		};
		
		class Underbarrel : GrenadeLauncher {
			cursor = "arifle";
			cursoraim = "CursorAim";
			value = 3;
			type = 0;
			displayName = "Special ammo";
			reloadTime = 3;
			reloadAction = "ReloadMagazine";
			magazineReloadTime = 1;
			initSpeed = 75;
			canLock = 0;
			autoReload = 0;
			autoAimEnabled = 0;
			ffMagnitude = 0.1;
			ffFrequency = 1;
			ffCount = 1;
			dispersion = 0.00725;
			aiDispersionCoefY = 6;
			maxLeadSpeed = 15;
			muzzlePos = "usti hlavne";
			muzzleEnd = "konec hlavne";
			cartridgePos = "";
			cartridgeVel = "";
			minRange = 30;
			minRangeProbab = 0.1;
			midRange = 200;
			midRangeProbab = 0.7;
			maxRange = 400;
			maxRangeProbab = 0.05;
			textureType = "semi";
			
			magazines[] = {"1Rnd_Salvo_Magazine", "1Rnd_Buckshot_Magazine", "1Rnd_Repulsor_Magazine"}; 
			
			changeFiremodeSound[] = {"A3\Sounds_F\arsenal\weapons\UGL\Firemode_ugl",0.316228,1,5};
			reloadMagazineSound[] = {"A3\Sounds_F\arsenal\weapons\UGL\Reload_UGL",0.562341,1,10};
			drySound[] = {"A3\Sounds_F\arsenal\weapons\UGL\Dry_ugl",0.562341,1,10};
			modes[] = {"Single"};
			recoil = "recoil_default";
			optics = 1;
			modelOptics = "-";
			cameraDir = "UGL look";
			memoryPointCamera = "opticView";
			opticsZoomMin = 0.25;
			opticsZoomMax = 1.25;
			opticsZoomInit = 0.75;
			weaponInfoType = "RscWeaponZeroing";
			class Single : Mode_SemiAuto {
				sounds[] = {"StandardSound"};
				recoil = "M240Recoil";
				recoilProne = "M240Recoil";
				minRange = 30;
				minRangeProbab = 0.1;
				midRange = 200;
				midRangeProbab = 0.7;
				maxRange = 400;
				maxRangeProbab = 0.05;
				class BaseSoundModeType {
					closure1[] = {"A3\Sounds_F\arsenal\weapons\UGL\Closure_UGL",1,1,10};
					soundClosure[] = {"closure1",1};
				};
				class StandardSound : BaseSoundModeType {
					//begin1[] = {"A3\Sounds_F\arsenal\weapons\UGL\UGL_01",0.707946,1,200};
					//begin2[] = {"A3\Sounds_F\arsenal\weapons\UGL\UGL_02",0.707946,1,200};
					//soundBegin[] = {"begin1",0.5,"begin2",0.5};
					//soundSetShot[] = {"UGL_shot_SoundSet","UGL_Tail_SoundSet","UGL_InteriorTail_SoundSet"};
					begin1[] = {"a3\sounds_f\weapons\Shells\shotgun\metal_shotgun_01",0.501187,1,15};
					begin2[] = {"A3\Sounds_F\weapons\shells\shotgun\metal_shotgun_02",0.501187,1,15};
					begin3[] = {"A3\Sounds_F\weapons\shells\shotgun\metal_shotgun_03",0.501187,1,15};
					begin4[] = {"A3\Sounds_F\weapons\shells\shotgun\metal_shotgun_04",0.501187,1,15};
					begin5[] = {"A3\Sounds_F\weapons\shells\shotgun\dirt_shotgun_01",0.398107,1,15};
					begin6[] = {"A3\Sounds_F\weapons\shells\shotgun\dirt_shotgun_02",0.398107,1,15};
					begin7[] = {"A3\Sounds_F\weapons\shells\shotgun\dirt_shotgun_03",0.398107,1,15};
					begin8[] = {"A3\Sounds_F\weapons\shells\shotgun\dirt_shotgun_04",0.398107,1,15};
					begin9[] = {"A3\Sounds_F\weapons\shells\shotgun\grass_shotgun_01",0.223872,1,15};
					begin10[] = {"A3\Sounds_F\weapons\shells\shotgun\grass_shotgun_02",0.223872,1,15};
					begin11[] = {"A3\Sounds_F\weapons\shells\shotgun\grass_shotgun_03",0.223872,1,15};
					begin12[] = {"A3\Sounds_F\weapons\shells\shotgun\grass_shotgun_04",0.223872,1,15};
					soundBegin[] = {"begin1",0.083,"begin2",0.083,"begin3",0.083,"begin4",0.083,"begin5",0.083,"begin6",0.083,"begin7",0.083,"begin8",0.083,"begin9",0.083,"begin10",0.083,"begin11",0.083,"begin12",0.083};
					soundSetShot[] = {"Mk18_Shot_SoundSet","Mk18_tail_SoundSet","Mk18_InteriorTail_SoundSet"};
				};
				
				
				
				
			};
		};
		
	};

	class TG_NOD_Assault_Rifle: TG_Assault_Rifle
	{
		_generalMacro = "TG_NOD_Assault_Rifle";
		baseWeapon="TG_NOD_Assault_Rifle";
		scope = 2;
		scopeCurator = 2;          
		scopeArsenal = 2;
		model = "\tg_weapons\nod\model\nod_assault_rifle.p3d";
		//modelOptics = "\A3\Weapons_F\acc\reticle_HAMR.p3d";
		displayName = "Nod Assault Rifle";
		descriptionShort = "Nod AR";
		picture = ;
		magazines[] = {"TG_NOD_AR_Magazine"};
		class Library
		{
			libTextDesc = "Nod Assault Rifle";
		};
		maxZeroing = 600;
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: CowsSlot
			{
				linkProxy = "\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]= {"TG_NOD_Scope_01"};
				iconPicture = ;
				iconPosition[] = {0.5,0.3};
				iconPinpoint = "Bottom";
				iconScale = 0.2;
			};
			class MuzzleSlot: MuzzleSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[]= {"muzzle_snds_H"};
				iconPosition[]={0,0.44999999};
				iconScale=0.2;
			};
			class PointerSlot{};
			class UnderBarrelSlot{};
			mass = 125;
			allowedSlots[] = {801,701,901};
		};

		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="TG_NOD_Scope_01";
			};
		};

		class GunParticles : GunParticles
		{
			class SecondEffect
			{
				positionName = "Nabojnicestart";
				directionName = "Nabojniceend";
				effectName = "CaselessAmmoCloud";
			};
		};

		distanceZoomMin = 300;
		distanceZoomMax = 300;
		bullet1[] = {};
		bullet2[] = {};
		bullet3[] = {};
		bullet4[] = {};
		bullet5[] = {};
		bullet6[] = {};
		bullet7[] = {};
		bullet8[] = {};
		bullet9[] = {};
		bullet10[] = {};
		bullet11[] = {};
		bullet12[] = {};
		soundBullet[] = {};
		selectionFireAnim = "muzzleFlash";
		modes[] = {"Single","Burst","FullAuto","fullauto_medium","single_medium_optics1","single_far_optics2"};
		changeFiremodeSound[] = {"A3\sounds_f\weapons\closure\firemode_changer_2",2,1,20};
		drySound[]= {"A3\sounds_f\weapons\Other\dry_1", db-5, 1, 10};
		reloadMagazineSound[]= {"A3\sounds_f\weapons\reloads\new_MX",db-8,1, 30};
		class Single: Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "DefaultRifle";
				closure1[] = {"A3\sounds_f\weapons\closure\closure_rifle_1",0.3,1,10};
				closure2[] = {"A3\sounds_f\weapons\closure\closure_rifle_1",0.3,1,10};
				soundclosure[] = {"closure1",0.5,"closure2",0.5};
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[] = {"tg_sounds\nod\weapons\nod_assault.wav",4.5,1,1200};
				begin2[] = {"tg_sounds\nod\weapons\nod_assault.wav",4.5,1,1200};
				begin3[] = {"tg_sounds\nod\weapons\nod_assault.wav",4.5,1,1200};
				soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.34};
			};
			reloadTime = 0.13;
			dispersion = 0.00203;
			recoil = "recoil_single_trg";
			recoilProne = "recoil_single_prone_trg";
			minRange = 2;
			minRangeProbab = 0.5;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 300;
			maxRangeProbab = 0.2;
		};
		class Burst: Mode_Burst
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "DefaultRifle";
				closure1[] = {"A3\sounds_f\weapons\closure\closure_rifle_1",0.3,1,10};
				closure2[] = {"A3\sounds_f\weapons\closure\closure_rifle_1",0.3,1,10};
				soundclosure[] = {"closure1",0.5,"closure2",0.5};
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[] = {"tg_sounds\nod\weapons\nod_assault.wav",4.5,1,1200};
				begin2[] = {"tg_sounds\nod\weapons\nod_assault.wav",4.5,1,1200};
				begin3[] = {"tg_sounds\nod\weapons\nod_assault.wav",4.5,1,1200};
				soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.34};
			};
			burst = 3;
			reloadTime = 0.08;
			dispersion = 0.0005;
			recoil = "recoil_auto_mk20";
			recoilProne = "recoil_auto_prone_mk20";
			minRange = 2;
			minRangeProbab = 0.9;
			midRange = 15;
			midRangeProbab = 0.7;
			maxRange = 30;
			maxRangeProbab = 0.1;
			aiRateOfFire = 1e-006;
		};
		class FullAuto: Mode_FullAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "DefaultRifle";
				closure1[] = {"A3\sounds_f\weapons\closure\closure_rifle_1",0.3,1,10};
				closure2[] = {"A3\sounds_f\weapons\closure\closure_rifle_1",0.3,1,10};
				soundclosure[] = {"closure1",0.5,"closure2",0.5};
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[] = {"tg_sounds\nod\weapons\nod_assault.wav",4.5,1,1200};
				begin2[] = {"tg_sounds\nod\weapons\nod_assault.wav",4.5,1,1200};
				begin3[] = {"tg_sounds\nod\weapons\nod_assault.wav",4.5,1,1200};
				soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.34};
			};
			reloadTime = 0.13;
			dispersion = 0.00203;
			recoil = "recoil_auto_trg";
			recoilProne = "recoil_auto_prone_trg";
			minRange = 2;
			minRangeProbab = 0.9;
			midRange = 15;
			midRangeProbab = 0.7;
			maxRange = 30;
			maxRangeProbab = 0.1;
			aiRateOfFire = 1e-006;
		};
		class fullauto_medium: FullAuto
		{
			showToPlayer = 0;
			burst = 3;
			minRange = 2;
			minRangeProbab = 0.5;
			midRange = 75;
			midRangeProbab = 0.7;
			maxRange = 100;
			maxRangeProbab = 0.05;
			aiRateOfFire = 2;
			aiRateOfFireDistance = 200;
		};
		class single_medium_optics1: Single
		{
			requiredOpticType = 1;
			showToPlayer = 0;
			minRange = 5;
			minRangeProbab = 0.2;
			midRange = 350;
			midRangeProbab = 0.7;
			maxRange = 500;
			maxRangeProbab = 0.3;
			aiRateOfFire = 5;
			aiRateOfFireDistance = 500;
		};
		class single_far_optics2: single_medium_optics1
		{
			requiredOpticType = 2;
			minRange = 100;
			minRangeProbab = 0.2;
			midRange = 550;
			midRangeProbab = 0.7;
			maxRange = 700;
			maxRangeProbab = 0.05;
			aiRateOfFire = 7;
			aiRateOfFireDistance = 700;
		};
	};

	class TG_GDI_Scope_01: ItemCore
	{
		author="Tiberian Genesis";
		_generalMacro="TG_GDI_Scope_01";
		scope = 2;
		scopeCurator = 2;          
		scopeArsenal = 2;
		displayName="GDI Scope";
		picture= ;
		model="\tg_weapons\gdi\data\scopes\gdi_scope1_tg_r2t.p3d";
		descriptionShort="GDI Scope";
		weaponInfoType= "TG_PiP_Scope"; // weaponInfoType is a class in RscWeaponZeroing 
		class ItemInfo: InventoryOpticsItem_Base_F
		{
			mass=8;
			opticType=2;
			optics=1;
			modelOptics="\tg_weapons\gdi\data\scopes\gdi_scope1_tg_r2t.p3d";

			class OpticsModes
			{
				class TG_GDI_Scope_PiP
				{
					opticsID=1;
					useModelOptics=0;
					visionMode[] = {"Normal"};
					thermalMode[] = {0, 8}; 
					opticsPPEffects[]= {"OpticsCHAbera5","OpticsBlur5"};
					opticsZoomMin=0.25;
					opticsZoomMax=1.25;
					opticsZoomInit=0.75;
					memoryPointCamera="opticView";
					opticsFlare=1;
					opticsDisablePeripherialVision=1;
					distanceZoomMin=300;
					distanceZoomMax=300;
				};
				
				class TG_GDI_Scope_2D
                {
                    opticsID=2;
                    opticsDisplayName="2D ScopeView";
                    useModelOptics=1;
                    opticsPPEffects[]=
                    {
                        "OpticsCHAbera1",
                        "OpticsBlur1"
                    };
                    opticsZoomMin=0.050000001;
                    opticsZoomMax=0.107;
                    opticsZoomInit=0.107;
                    discreteDistance[]={300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600};
                    discreteDistanceInitIndex=0;
                    distanceZoomMin=300;
                    distanceZoomMax=1600;
                    discretefov[]={0.107,0.050000001};
                    discreteInitIndex=0;
                    memoryPointCamera="eye";
                    modelOptics[]=
                    {
                        "\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F",
                        "\A3\Weapons_F\acc\reticle_sniper_z_F"
                    };
                    visionMode[] = {"Normal", "NVG"};
                    thermalMode[] = {0, 1, 2, 3};
                    opticsFlare=1;
                    opticsDisablePeripherialVision=1;
                    cameraDir="";
                };
			};
		};
		inertia=0.1;
	};

	class TG_NOD_Scope_01: ItemCore
	{
		author="Tiberian Genesis";
		_generalMacro="TG_NOD_Scope_01";
		scope = 2;
		scopeCurator = 2;          
		scopeArsenal = 2;
		displayName="Nod Scope";
		picture= ;
		model="\tg_weapons\nod\model\nod_scope1.p3d";
		descriptionShort="Nod Scope";
		weaponInfoType="RscWeaponZeroing";
		class ItemInfo: InventoryOpticsItem_Base_F
		{
			mass=8;
			opticType=1;
			optics=1;
			modelOptics="\tg_weapons\nod\model\nod_scope1.p3d";
			class OpticsModes
			{
				class TG_NOD_Scope_View_01
				{
					opticsID=1;
					useModelOptics=0;
					opticsPPEffects[]= {"OpticsCHAbera5","OpticsBlur5"};
					opticsZoomMin=0.125;
					opticsZoomMax=0.125;
					opticsZoomInit=0.125;
					memoryPointCamera="opticView";
					opticsFlare=1;
					opticsDisablePeripherialVision=1;
					distanceZoomMin=300;
					distanceZoomMax=300;
				};
			};
		};
		inertia=0.1;
	};
	
	class TG_DiscThrow: Throw 
	{
		baseWeapon = "TG_DiscThrow";
		scope = 2;
		scopeCurator = 2;          
		scopeArsenal = 2;
		displayName = Throw;
		muzzles[] = {"TG_GDI_DiscGrenadeMuzzle"};
		
		class ThrowMuzzle: GrenadeLauncher
		{
			cursor = "EmptyCursor";
			cursorAim = "throw";
			sound[] = {"tg_sounds\gdi\weapons\gdi_disc_throw.wav",0.00031622776,1};
			reloadSound[] = {"",0.00031622776,1};
			aiDispersionCoefX = 6;
			aiDispersionCoefY = 6;
			reloadTime = 0;
			magazineReloadTime = 2.5;
			enableAttack = 0;
			showEmpty = 0;
			autoReload = 1;
			modelOptics = "";
			minRange = 1000;
			minRangeProbab = 0;
			midRange = 1200;
			midRangeProbab = 0;
			maxRange = 1500;
			maxRangeProbab = 0;
			keepInInventory = 1;			
		};
		
		class TG_GDI_DiscGrenadeMuzzle: ThrowMuzzle
		{
			magazines[] = {"TG_GDI_DiscGrenade"};
		};
	};

	class TG_NOD_RocketLauncher: launch_RPG32_F {
		author = "Tiberian Genesis";
		scope = 2;
		scopeCurator = 2;          
		scopeArsenal = 2;
		displayName = "Nod Rocket Launcher";
		model = "\tg_weapons\nod\model\nod_rocketlauncher_loaded.p3d";
		handAnim[] = {"OFP2_ManSkeleton", "\tg_weapons\nod\anim\nod_launcher.rtm"};
		magazines[] = {TG_NOD_RocketLauncher_Magazine};
		modeloptics = "\tg_weapons\nod\model\nod_rocket_optic.p3d";
		visionMode[] = {"Normal"};
		picture = ;
		opticszoommax = 0.14389;
		opticszoommin = 0.14389;
		distancezoommax = 100;
		distancezoommin = 100;
		reloadTime = 5.0;
		magazinereloadTime = 10;
	};
};