	class gdi_wall: House{
		scope = 2;
		side = 1;
		model = "\tg_buildings\gdi\model\gdi_wall.p3d";
		//icon = "";
		displayName = "$STR_GDI_WALL";
		animated = 0;
		vehicleClass = "GDI_B";
		nameSound = "house";
		accuracy = 0.200000;
		typicalCargo = {};
		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;
		mapSize = 8;
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
	};

	class gdi_wall2: House{
		scope = 2;
		side = 1;
		model = "\tg_buildings\gdi\model\gdi_wall2.p3d";
		//icon = "";
		displayName = "$STR_GDI_WALL2";
		animated = 0;
		vehicleClass = "GDI_B";
		nameSound = "house";
		accuracy = 0.200000;
		typicalCargo = {};
		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;
		mapSize = 8;
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
	};

	class gdi_gate: House{
		scope = 2;
		side = 1;
		model = "\tg_buildings\gdi\model\gdi_gate.p3d";
		//icon = "";
		displayName = "$STR_GDI_GATE";
		animated = 0;
		vehicleClass = "GDI_B";
		nameSound = "house";
		accuracy = 0.200000;
		typicalCargo = {};
		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;
		mapSize = 8;
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
	};

	class gdi_empcannon : StaticWeapon 
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
		model = "\tg_buildings\gdi\model\gdi_empcannon.p3d";
		picture = "\ca\Weapons\data\ico\m2_mg_CA.paa";
		icon = "\Ca\weapons\Data\map_ico\icomap_M2_CA.paa";
		mapSize = 4;
		sound[] = {"\ca\Weapons\Data\Sound\MachineGuns_M2HB_SS_v5", 100, 1};
		reloadMagazineSound[] = {"\ca\Weapons\Data\Sound\m2gun_inout", 0.0316228, 1};
		displayName = $STR_GDI_EMP;
		nameSound = "mgun";
		typicalCargo[] = {"gdi_rifleman"};

                extCameraPosition[]={0,5,-30};

		class Reflectors
		{
			class Left
			{
				color[] = {0.0, 0.0, 0.0, 0.0};
				ambient[] = {0.0, 0.0, 0.0, 0.0};
				position = "L svetlo";
				direction = "konec L svetla";
				hitpoint = "L svetlo";
				selection = "L svetlo";
				size = 0;
				brightness = 0;
			};
			
			class Right
			{
				color[] = {0.0, 0.0, 0.0, 0.0};
				ambient[] = {0.0, 0.0, 0.0, 0.0};
				position = "P svetlo";
				direction = "konec P svetla";
				hitpoint = "P svetlo";
				selection = "P svetlo";
				size = 0;
				brightness = 0;
};
};
		
		
		class Turrets : Turrets {
			class MainTurret : MainTurret {
				gunnerCompartments="compartment1";
				memoryPointsGetInGunner = "pos_gunner";
				memoryPointsGetInGunnerDir = "pos_gunner_dir";
				memoryPointGunnerOptics = "gunnerview";
				memoryPointGun = "usti hlavne";
				outGunnerMayFire = 1;
				gunnerOpticsModel = "\ca\Weapons\optika_empty";
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
				weapons[] = {"vulcan_weapon"};
				magazines[] = {"4000Rnd_762x51_M134"};
				gunnerAction = "M2_Gunner";
			};
		};
		
		soundGetOut[] = {"\ca\Weapons\Data\Sound\m2gun_inout", 0.001, 1};
		soundGetIn[] = {"\ca\Weapons\Data\Sound\m2gun_inout", 0.000316228, 1};
		armorStructural = 10.0;

		
		class Library {
			libTextDesc = <(^^')>;
		};
	};