#define _ARMA_

enum 
{
	destructengine = 2,
	destructdefault = 6,
	destructwreck = 7,
	destructtree = 3,
	destructtent = 4,
	stabilizedinaxisx = 1,
	stabilizedinaxesxyz = 4,
	stabilizedinaxisy = 2,
	stabilizedinaxesboth = 3,
	destructno = 0,
	stabilizedinaxesnone = 0,
	destructman = 5,
	destructbuilding = 1
};
class CfgPatches
{
	class tg_hover
	{
		//addonRootClass = "A3_Armor_F_EPB";
		units[] = {"gdi_hover_mlrs"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"tg_core"};
	};
};

class DefaultEventhandlers;
class WeaponFireGun;
class WeaponCloudsGun;
class WeaponFireMGun;
class WeaponCloudsMGun;
class RCWSOptics;
class Optics_Armored;
/* class Optics_Commander_01: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
 */
class Optics_Gunner_MBT_02: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
class CfgVehicles
{
	class LandVehicle;
	class Tank: LandVehicle
	{
		class NewTurret;
		class Sounds;
		class HitPoints;
	};
	class Tank_F: Tank
	{
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class ViewGunner;
 				class Turrets
				{
					class CommanderOptics;
				};
				
			};
		};
		class AnimationSources;
		class ViewPilot;
		class ViewOptics;
		class ViewCargo;
		class HeadLimits;
		class HitPoints: HitPoints
		{
			class HitHull;
			class HitFuel;
			class HitEngine;
			class HitLTrack;
			class HitRTrack;
		};
		class Sounds: Sounds
		{
			class Engine;
			class Movement;
		};
		class EventHandlers;
	};
	class gdi_hover_mlrs_base_F: Tank_F
	{
		author = "Tiberian Genesis";
		scope = 0;
		MapSize = 7;
		model = "";
		nameSound = "tank";
		displayname = "-";
		scopeArsenal = 0;
		camouflage = 4;
		accuracy = 0.3;
		fuelCapacity = 640;
		insideSoundCoef = 0.9;
//		tracksSpeed = 1.375;
		driveOnComponent[] = {"slide","pasoffsetl","pasoffsetp"};
		slingloadcargoMemoryPoints[] = {"slingloadcargo1","slingloadcargo2","slingloadcargo3","slingloadcargo4"};

/// Offense/Defense		
		smokeLauncherGrenadeCount = 6; //Number of smoke shells launched at once
		smokeLauncherVelocity = 14; //Velocity which smoke shells are launched at
		smokeLauncherOnTurret = 1; //0 if smoke launchers are on hull, 1 if on turret
		smokeLauncherAngle = 120; //Angle within which smoke grenades are launched (actual spacing may end up smaller so use slighty higher number)
		threat[] = {0.9,0.9,0.4};
		
/// Strength and Durability		
		cost=1500000;
		damageResistance = 0.02;
		armor = 260;
		armorStructural = 280;
		destrType = "DestructDefault";
		
/// Sensor Stuff
		radarType = 1;
		LockDetectionSystem = 4;
		IncommingMisslieDetectionSystem = 16;
		irscanrangemax = 3000;
		irscanrangemin = 500;
		irtarget = 1;
		irScanGround = 0;
		laserscanner = 0;
		enableRadio = 1;
		enableGPS = 1;
		
/// WATER
		canFloat = 1;
		terrainCoef = 10;
		turnCoef = 0.1;
		waterPPInVehicle = 0;
		waterResistance = 0.0;
		waterResistanceCoef = 0.0005;
		waterLeakiness = 1.5;
		engineShiftY = 1.0;
		waterSpeedFactor = 10.9;
		waterAngularDampingCoef = 1.2;
		waterLinearDampingCoefY = 2.0;
		waterLinearDampingCoefX = 2.0;
		maxFordingDepth = 2.5;

		overSpeedBrakeCoef = 0.02;

		rudderForceCoef			= 0.100000;	/// increase this to gain more turning on lower speeds
		rudderForceCoefAtMaxSpeed	= 0.003000;	/// increase this to gain more turning on higher speeds
		
		engineEffectSpeed = 5.0;
		memoryPointsLeftWaterEffect = "watereffectl";
		memoryPointsRightWaterEffect = "watereffectr";
		memoryPointsLeftEngineEffect = "engineeffectl";
		memoryPointsRightEngineEffect = "engineeffectr";
		
///Crew Stuff
		viewCargoShadow = 1;
		viewCargoShadowDiff = 0.05;
		viewCargoShadowAmb = 0.5;
		getInAction = "GetInLow";
		getOutAction = "GetOutLow";
		cargoGetInAction[] = {"GetInHigh"};
		cargoGetOutAction[] = {"GetOutHigh"};
		forceHideDriver = 0;
		viewDriverInExternal = 1;
		DriverForceOptics = 0;
		driverDoor = "hatchDriver";
		crewVulnerable = false;
		crewExplosionProtection = 0.9999;
		memoryPointsGetInDriver = "pos pilot";
		memoryPointsGetInDriverDir = "pos pilot dir";
		transportSoldier = 0;
		cargoAction[] = {"passenger_apc_generic04","passenger_apc_generic02","passenger_apc_generic03","passenger_apc_generic04","passenger_apc_narrow_generic01","passenger_apc_narrow_generic02","passenger_apc_generic03","passenger_apc_narrow_generic03"};
		hideWeaponsCargo = 1;
		
///Weight Compensation
        	antiRollbarForceCoef = 24;
        	antiRollbarForceLimit = 42;
        	antiRollbarSpeedMin = 30;
        	antiRollbarSpeedMax = 75;
		
///Powertrain
		simulation = "tankX";
		normalSpeedForwardCoef = 0.5;
		slowSpeedForwardCoef = 0.25;
		
		torqueCurve[] = {{0.00, 1},{0.14, 1},{0.29, 1},{0.43, 1},{0.57, 1},{0.71, 1},{0.86, 1},{1.00, 1}};

		maxOmega = 2000;
		minOmega = 150.0;
		engineMOI = 9.0;
		enginePower = 1200; //1230;
		peakTorque = 10000;
		idleRPM = 2500;
		redRPM = 5600;
		thrustDelay = 0.2;
		//engineLosses = 5;
		switchTime = 0.1;
		clutchStrength = 100; //105.0;
		//changeGearMinEffectivity[] = {0.95,0.0,0.85};
		//transmissionLosses = 5;
		latency = 0.5;
		tankTurnForce = 100000;
		tankTurnForceAngMinSpd = 10.1;
		tankTurnForceAngSpd = 10.5;
		accelAidForceCoef = 2.5;
		accelAidForceYOffset = 0.0;
		accelAidForceSpd = 4.7;
		
		maxSpeed = 86;
		brakeIdleSpeed = 0.5;

		engineStartSpeed = 5;

		changeGearType = "effective"; 
		changeGearMinEffectivity[] = {0.7, 0.0, 0.5}; // use effective

		class ComplexGearbox 
		{
            //GearboxRatios[] = {"R1",-8.0,"N",0,"D1",2.1,"D2",2.7};
	    GearboxRatios[]    = {"R2",-3.9,"N",0,"D1",4.7,"D2",3.5,"D3",2.6,"D4",2.0,"D5",1.5,"D6",1.125,"D7",0.85};			
            //AmphibiousRatios[] = {"R1", -1.5,"N", 0,"D1", 21.5};
	    AmphibiousRatios[] = {"R1",-10,"N",0,"D1",10};
            //transmissionRatios[] = {"High", 8};
	    TransmissionRatios[] = {"High",15};
            gearBoxMode = "auto";
            moveOffGear = 1;
            driveString = "D";
            neutralString = "N";
            reverseString = "R";
            transmissionDelay = 0.1;
        };
        
		/// ////////////////////////////// WHEELS ///////////////////////////////////////////
		numberPhysicalWheels = 18;
		wheelCircumference = 2.56;
		class Wheels
		{
 			class L1
			{
				//wheelBrakeFrictionCoef = 0.01;
				boneName = "wheel_podkoloL1";
				center = "wheel_1_1_center";
				boundary = "wheel_1_1_bound";
				//damping = 65.0;
				steering = 0;
				width = 0.1;
				side = "left";
				mass = 40;
				MOI = 6;// 0.5 * wheelMass * wheelRadius^2 , then tweaked a little
				latStiffX = 12;
				latStiffY = 60;
				longitudinalStiffnessPerUnitGravity = 10; //150000; //
				maxBrakeTorque = 20;
				sprungMass = 5; // mass/18
				springStrength = 20; //198000; // 50668.75; // sprungMass*5^2 (try 5^2 up to 10^2, then tweak)
				springDamperRate = 1; //14811; // 2026.75; // sDR = dampingRate X 2 X sqrt(springStrength X sprungMass)
				dampingRate = 180;
				dampingRateInAir = 180;
				dampingRateDamaged = 500;
				dampingRateDestroyed = 10000;
				maxDroop = 0.6;
				maxCompression = 0.6;
				frictionVsSlipGraph[] = {{0.0,1.0},{0.1,1.6},{0.5,0.6}};
			};
			
			class L2
			{
				boneName = "wheel_podkoloL2";
				center = "wheel_1_2_center";
				boundary = "wheel_1_2_bound";
				//damping = 65.0;
				steering = 0;
				width = 0.5;
				side = "left";
				mass = 90;
				MOI = 9;// 0.5 * wheelMass * wheelRadius^2 , then tweaked a little
				latStiffX = 3;
				latStiffY = 30;
				longitudinalStiffnessPerUnitGravity = 20000; //150000; //
				maxBrakeTorque = 2860;
				sprungMass = 1062; 
				springStrength = 53333; //198000; // 50668.75; // sprungMass*5^2 (try 5^2 up to 10^2, then tweak)
				springDamperRate = 7000; //14811; // 2026.75; // sDR = dampingRate X 2 X sqrt(springStrength X sprungMass)
				dampingRate = 180;
				dampingRateInAir = 180;
				dampingRateDamaged = 500;
				dampingRateDestroyed = 10000;
				maxDroop = 0.6;
				maxCompression = 0.6;
				frictionVsSlipGraph[] = {{0.0,1.0},{0.1,1.6},{0.5,0.6}};
			};
			class L3: L2
			{
				boneName = "wheel_podkoloL3";
				center = "wheel_1_3_center";
				boundary = "wheel_1_3_bound";
			};
			class L4: L2
			{
				boneName = "wheel_podkoloL4";
				center = "wheel_1_4_center";
				boundary = "wheel_1_4_bound";
			};
			class L5: L2
			{
				boneName = "wheel_podkoloL5";
				center = "wheel_1_5_center";
				boundary = "wheel_1_5_bound";
			};
			class L6: L2
			{
				boneName = "wheel_podkoloL6";
				center = "wheel_1_6_center";
				boundary = "wheel_1_6_bound";
			};
			class L7: L2
			{
				boneName = "wheel_podkoloL7";
				center = "wheel_1_7_center";
				boundary = "wheel_1_7_bound";
			};
			class L8: L2
			{
				boneName = "wheel_podkoloL8";
				center = "wheel_1_8_center";
				boundary = "wheel_1_8_bound";
			};
			class L9: L2
			{
				boneName = "wheel_podkoloL9";
				center = "wheel_1_9_center";
				boundary = "wheel_1_9_bound";
			};
/* 			class L10: L1
			{
				boneName = "wheel_podkoloL10";
				center = "wheel_1_10_center";
				boundary = "wheel_1_10_bound";
			};
 */			
 			class R1: L1
			{
				boneName = "wheel_podkoloP1";
				side = "right";
				center = "wheel_2_1_center";
				boundary = "wheel_2_1_bound";
			};
 			
			class R2: L2
			{
				boneName = "wheel_podkoloP2";
				side = "right";
				center = "wheel_2_2_center";
				boundary = "wheel_2_2_bound";
			};
			class R3: R2
			{
				boneName = "wheel_podkoloP3";
				center = "wheel_2_3_center";
				boundary = "wheel_2_3_bound";
			};
			class R4: R2
			{
				boneName = "wheel_podkoloP4";
				center = "wheel_2_4_center";
				boundary = "wheel_2_4_bound";
			};
			class R5: R2
			{
				boneName = "wheel_podkoloP5";
				center = "wheel_2_5_center";
				boundary = "wheel_2_5_bound";
			};
			class R6: R2
			{
				boneName = "wheel_podkoloP6";
				center = "wheel_2_6_center";
				boundary = "wheel_2_6_bound";
			};
			class R7: R2
			{
				boneName = "wheel_podkoloP7";
				center = "wheel_2_7_center";
				boundary = "wheel_2_7_bound";
			};
			class R8: R2
			{
				boneName = "wheel_podkoloP8";
				center = "wheel_2_8_center";
				boundary = "wheel_2_8_bound";
			};
			class R9: R2
			{
				boneName = "wheel_podkoloP9";
				center = "wheel_2_9_center";
				boundary = "wheel_2_9_bound";
			};
/* 			class R10: R1
			{
				boneName = "wheel_podkoloP10";
				center = "wheel_2_10_center";
				boundary = "wheel_2_10_bound";
			};
 */			
		};

		
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor = 1.8;
				material = -1;
				armorComponent = "hit_hull";
				name = "hit_hull_point";
				visual = "zbytek";
				passThrough = 1;
				minimalHit = 0.2;
				explosionShielding = 0.2;
				radius = 0.3;
			};
			class HitEngine: HitEngine
			{
				armor = 0.4;
				material = -1;
				armorComponent = "hit_engine";
				name = "hit_engine_point";
				visual = "-";
				passThrough = 0.2;
				minimalHit = 0.2;
				explosionShielding = 0.2;
				radius = 0.3;
			};
			class HitFuel: HitFuel
			{
				armor = 0.3;
				material = -1;
				armorComponent = "hit_fuel";
				name = "hit_fuel_point";
				visual = "-";
				passThrough = 0.1;
				minimalHit = 0.1;
				explosionShielding = 0.6;
				radius = 0.3;
			};
			class HitLTrack: HitLTrack
			{
				material = -1;
				armorComponent = "hit_trackL";
				name = "hit_trackL_point";
				visual = "-";
				radius = 0.2;
				armor = -650;
				minimalHit = 0.0738462;
				explosionShielding = 0.8;
				passThrough = 0;
			};
			class HitRTrack: HitRTrack
			{
				material = -1;
				armorComponent = "hit_trackR";
				name = "hit_trackR_point";
				visual = "-";
				radius = 0.2;
				armor = -650;
				minimalHit = 0.0738462;
				explosionShielding = 0.8;
				passThrough = 0;
			};
		};
		class ViewOptics: ViewOptics
		{
			visionMode[] = {"Normal","NVG"};
			initFov = 0.25;
			minFov = 0.15;
			maxFov = 0.25;
		};
		
		class AnimationSources : AnimationSources
		{
			class Missiles_revolving {
				source = "revolving";
				weapon = "missiles_DAGR";
			};

			class hover_source {
				source = "user";
				animPeriod = 0.08;
				initPhase = 0;
			};
		};

		class Exhausts
		{
			class Exhaust1
			{
				position = "exhaust1";
				direction = "exhaust1_end";
				effect = "ExhaustEffectTankSide";
			};
			class Exhaust2
			{
				position = "exhaust2";
				direction = "exhaust2_end";
				effect = "ExhaustEffectTankSide";
			};
		};
		class Reflectors {
			class Left {
				color[] 	= {1900, 1300, 950};
				ambient[]	= {5,5,5};
				position 	= "Light_L";
				direction 	= "Light_L_end";
				hitpoint 	= "Light_L";
				selection	= "Light_L";
				size 		= 1;
				innerAngle 	= 100;
				outerAngle 	= 179;
				coneFadeCoef = 10;
				intensity 	= 1; //17.5
				useFlare 	= 0;
				dayLight 	= 0;
				flareSize 	= 1.0;
				class Attenuation 
				{
					start 		= 1.0;
					constant 	= 0;
					linear 		= 0;
					quadratic 	= 0.25;
					hardLimitStart = 30;
					hardLimitEnd = 60;
				};
			};
			class Right: Left {
				position 	= "Light_R";
				direction 	= "Light_R_end";
				hitpoint 	= "Light_R";
				selection 	= "Light_R";
			};
			class Right2: Right {
				position 	= "light_R_flare";
				useFlare 	= 1;
			};
			class Left2: Left {
				position 	= "light_L_flare";
				useFlare 	= 1;
			};
		};
		aggregateReflectors[] = {{"Left","Right","Left2","Right2"}};
		armorLights = 0.1;
		/*
		class ViewPilot: ViewPilot
		{
			initAngleX = 7;
			minAngleX = -15;
			maxAngleX = 25;
			initAngleY = 0;
			minAngleY = -90;
			maxAngleY = 90;
		};
		*/
		class ViewPilot: ViewPilot
		{
			initAngleX = -3;
			initAngleY = 0;
			initFov = 0.9;
			minFov = 0.25;
			maxFov = 1.25;
			minAngleX = -65;
			maxAngleX = 85;
			minAngleY = -150;
			maxAngleY = 150;
			minMoveX = 0.0;
			maxMoveX = 0.0;
			minMoveY = -0.075;
			maxMoveY = 0.075;
			minMoveZ = -0.075;
			maxMoveZ = 0.1;
		};
		
		class TransportBackpacks
		{};
		class TransportMagazines
		{};
		class TransportItems
		{};		
		class TransportWeapons
		{};		
		class EventHandlers
		{
			/* 
			hitpart = "_this call SLX_XEH_EH_HitPart;_this call rhs_fnc_hitHandler";
			getIn = "_this call SLX_XEH_EH_GetIn;_this call rhs_fnc_m2_doors";
			getOut = "_this call SLX_XEH_EH_GetOut;_this call rhs_fnc_m2_doors";
			 */
		};
		
	};
	class gdi_hover_mlrs: gdi_hover_mlrs_base_F
	{
		author = "Tiberian Genesis";
		model = "tg_hover\gdi_hover_mlrs.p3d";
		displayName = "GDI Hover MLRS";
		scope = 2;
		scopeArsenal = 0;
		editorPreview = "\tg_core\Data\gdi.paa";
		editorcategory = "tg";
		editorSubcategory = "gdi_hover";
		side = 1;
		crew = "TG_LightInfantry_GDI_01";
		
		class Turrets: Turrets
		{
			class MainTurret : MainTurret
			{

				memoryPointLMissile = "rocket_1";
				memoryPointRMissile = "rocket_2";
				memoryPointMissile[] = {"rocket_1", "rocket_2"};
				memoryPointMissileDir[] = {"rocket_1_dir", "rocket_2_dir"};

				missileBeg = "rocket_1","rocket_2";
				missileEnd = "rocket_1_dir", "rocket_2_dir";

				body = "mainTurret";
				gun = "mainGun_2";
				hasGunner= 1;
				weapons[] = {"missiles_DAGR"};
				magazines[] = {"24Rnd_PG_missiles","24Rnd_PG_missiles","24Rnd_PG_missiles","24Rnd_PG_missiles","24Rnd_PG_missiles","24Rnd_PG_missiles"};
				soundServo[] = {"A3\sounds_f\dummysound",0.01,1.0,10};
				minElev=-20;
				maxElev=+30;
				initElev=0;
				minTurn=-360;
				maxTurn=+360;
				initTurn=0;
				viewGunnerInExternal=true;
				castGunnerShadow = 1;
				stabilizedInAxes = StabilizedInAxesNone;
				gunnerRightHandAnimName = "OtocHlaven_shake";
				gunnerLeftHandAnimName = "OtocHlaven_shake";
			};
		};
		
		class Library
		{
			libTextDesc = "GDI Hover MLRS";
		};
		armor = 700;
		class Damage
		{
			tex[] = {};
			mat[] = {};
		};
		class AnimationSources
		{
			class Missiles_revolving {
				source = "revolving";
				weapon = "missiles_DAGR";
			};

			class hover_source {
				source = "user";
				animPeriod = 0.08;
				initPhase = 0;
			};
			class HatchC
			{
				source = "door";
				animPeriod = 0.8;
			};
			class HatchG: HatchC{};
			class HatchDriver: HatchC{};
			
		};
	};
};