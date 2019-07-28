	class gdi_componenttower: House{
		scope = 2;
		side = 1;
		model = "\tg_buildings\gdi\model\gdi_componenttower.p3d";
		//icon = "";
		displayName = "$STR_GDI_CT";
		animated = 0;
		vehicleClass = "GDI_B";
		nameSound = "house";
		accuracy = 0.200000;
		typicalCargo = {};
		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;
		mapSize = 11;
		cost = 0;
		armor = 5000;
		class DestructionEffects: DestructionEffects {

			class Ruin1 {
				simulation = "ruin";
				type = "";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};

		class MarkerLights: MarkerLights {

	class CTLight1 {
		name="light1";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.0;
		blinking=1;
		displayName="CTLight1";
		};
	class CTLight2 {
		name="light2";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.0;
		blinking=1;
		displayName="CTLight2";
		};
	class CTLight3 {
		name="light3";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.0;
		blinking=1;
		displayName="CTLight3";
		};
	class CTLight4 {
		name="light4";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.0;
		blinking=1;
		displayName="CTLight4";
		};
};

	};

	class gdi_warfactory: House{
		scope = 2;
		side = 1;
		model = "\tg_buildings\gdi\model\gdi_warfactory.p3d";
		//icon = "";
		displayName = "$STR_GDI_WARFAC";
		animated = 0;
		vehicleClass = "GDI_B";
		nameSound = "house";
		accuracy = 0.200000;
		typicalCargo = {};
		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;
		mapSize = 11;
		cost = 0;
		armor = 5000;
		ladders[]= {{"start", "end"}};
		class DestructionEffects: DestructionEffects {

			class Ruin1 {
				simulation = "ruin";
				type = "";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
};

	class StaticWeapon : LandVehicle {
			
		class Turrets {
			class MainTurret : NewTurret {
						
				class ViewOptics {
					
				};
			};
		};

	};			

	class gdi_vulcancannon : StaticWeapon 
        {
		scope = 2;
		vehicleClass = "GDI_B";
		side = 1;
		cost = 1000000;
		steerAheadSimul = 0.4;
		steerAheadPlan = 0.6;
		predictTurnSimul = 1.2;
		predictTurnPlan = 1.8;
		hasGunner = 1;
		hasCommander = 0;
		ejectDeadDriver = 1;
		ejectDeadCargo = 1;
		hasDriver = 0;
		nightVision = 1;
		driverAction = "ManActCargo";
		driverInAction = "ManActCargo";
		simulation = "tank";
		occludeSoundsWhenIn = 1.0;
		obstructSoundsWhenIn = 1.0;
		formationX = 10;
		formationZ = 10;
		precision = 1;
		brakeDistance = 0;
		maxSpeed = 0;
		canFloat = 0;
		threat[] = {0.0, 0.0, 1.0};
		irScanRange = 4000;
		sensitivity=0.7;
		gunnerCanSee = 31;
		crew = "gdi_lightinfantry";
		model = "\tg_buildings\gdi\model\gdi_vulcan_upgrade.p3d";
		picture = "\ca\Weapons\data\ico\m2_mg_CA.paa";
		icon = "\Ca\weapons\Data\map_ico\icomap_M2_CA.paa";
		mapSize = 4;
		sound[] = {"\ca\Weapons\Data\Sound\MachineGuns_M2HB_SS_v5", 100, 1};
		reloadMagazineSound[] = {"\ca\Weapons\Data\Sound\m2gun_inout", 0.0316228, 1};
		displayName = $STR_GDI_VU;
		nameSound = "mgun";
		typicalCargo[] = {"gdi_lightinfantry"};

		armor = 1000;
		armorStructural = 100.0;

                extCameraPosition[]={0,5,-30};

		class Reflectors
		{
			class Left
			{
				color[] = {0.9, 0.8, 0.8, 1.0};
				ambient[] = {0.1, 0.1, 0.1, 1.0};
				position = "L svetlo";
				direction = "konec L svetla";
				hitpoint = "L svetlo";
				selection = "L svetlo";
				size = 0.5;
				brightness = 0.5;
			};
			
			class Right
			{
				color[] = {0.9, 0.8, 0.8, 1.0};
				ambient[] = {0.1, 0.1, 0.1, 1.0};
				position = "P svetlo";
				direction = "konec P svetla";
				hitpoint = "P svetlo";
				selection = "P svetlo";
				size = 0.5;
				brightness = 0.5;
};
};
		
		
		class Turrets : Turrets {
			class MainTurret : MainTurret {
				gunnerCompartments="compartment1";
				gunnerOpticsModel = "\ca\Tracked\optika_zsu_gunner";
				memoryPointsGetInGunner = "pos_gunner";
				memoryPointsGetInGunnerDir = "pos_gunner_dir";
				memoryPointGunnerOptics = "gunnerview";
				memoryPointGun = "usti hlavne";
				outGunnerMayFire = 1;
				soundServo[] = {"\tg_buildings\sound\turret.wav", 0.000316, 1.000000};
				minTurn = -180;
				maxTurn = 180;
				initTurn = 0;
				minElev = -120;
				maxElev = 120;
				initElev = 0;
				irScanRange = 4000;
				castGunnerShadow = 0;
				ejectDeadGunner = 0;
				threat[] = {0.0, 0.0, 1.0};
				gunnerCanSee = 31;
				sensitivity=0;
				commanding = 1;
				primarygunner = 1;
				weapons[] = {"50mm_vulcan"};
				magazines[] = {"50mm_mag","50mm_mag","50mm_mag","50mm_mag"};
				gunnerAction = "M2_Gunner";
			};
			class MainTurret2 : MainTurret
			{
				gunnerCompartments="compartment2";
				gunBeg = "usti hlavne2";
				gunEnd = "konec hlavne2";
				memoryPointGun = "usti hlavne2";
				weapons[] = {"50mm_vulcan2"};
				magazines[] = {"50mm_mag","50mm_mag","50mm_mag","50mm_mag"};
			};
		};
		
		class AnimationSources
		{
			class spinanim
			{
				source = "reload";
				weapon = "50mm_vulcan";
				animPeriod = 1.1;
			};
		};
		soundGetOut[] = {"\ca\Weapons\Data\Sound\m2gun_inout", 0.001, 1};
		soundGetIn[] = {"\ca\Weapons\Data\Sound\m2gun_inout", 0.000316228, 1};

		class EventHandlers 
		{
		fired="_this exec ""\tg_buildings\scripts\mg.sqf"""
		};

		
		class Library {
			libTextDesc = <(^^')>;
		};
	};