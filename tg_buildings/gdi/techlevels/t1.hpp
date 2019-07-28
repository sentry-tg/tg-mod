	/*extern*/ class Thing;
	/*extern*/ class Building;
	/*extern*/ class Strategic;

	class NonStrategic: Building {
		/*extern*/ class DestructionEffects;
	};
	/*extern*/ class HouseBase;
	/*extern*/ class Land_VASICore;

	class House: HouseBase {
		/*extern*/ class DestructionEffects;
		/*extern*/ class MarkerLights;
	};
	/*extern*/ class Ruins;	

	class gdi_constructionyard: House{
		scope = 2;
		side = 1;
		model = "\tg_buildings\gdi\model\gdi_conyard.p3d";
		//icon = "";
		displayName = "$STR_GDI_CY";
		animated = true;
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

              class AnimationSources
		{
			class Fan1
			{
				source = "user"; //The controller is defined as a user animation.
				animPeriod = 1;  //The animation period used for this controller.
				initPhase = 0;     //Initial phase when object is created. 0 = CLOSED	
			};
                        class Fan2
			{
				source = "user"; //The controller is defined as a user animation.
				animPeriod = 1;  //The animation period used for this controller.
				initPhase = 0;     //Initial phase when object is created. 0 = CLOSED		
			};
                        class Fan3
			{
				source = "user"; //The controller is defined as a user animation.
				animPeriod = 1;  //The animation period used for this controller.
				initPhase = 0;     //Initial phase when object is created. 0 = CLOSED		
			};
                        class TurnLight
			{
				source = "user"; //The controller is defined as a user animation.
				animPeriod = 1;  //The animation period used for this controller.
				initPhase = 0;     //Initial phase when object is created. 0 = CLOSED		
			};		
};

		class MarkerLights: MarkerLights {

	class RefineryLight1 {
		name="light1";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight1";
		};
	class RefineryLight2 {
		name="light2";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight2";
		};
	class RefineryLight3 {
		name="light3";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight3";
		};
	class RefineryLight4 {
		name="light4";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight4";
		};
	class RefineryLight5 {
		name="light5";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight5";
		};
	class RefineryLight6 {
		name="light6";
		color[]={1.0000,0.0000,0.0000,0};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight6";
		};
	class RefineryLight7 {
		name="light7";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight7";
		};
	class RefineryLight8 {
		name="light8";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight8";
		};
	class RefineryLight9 {
		name="light9";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight9";
		};
	class RefineryLight10 {
		name="light10";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight10";
		};
	class RefineryLight11 {
		name="light11";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight11";
		};
	class RefineryLight12 {
		name="light12";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight12";
		};
	class RefineryLight13 {
		name="light13";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight13";
		};
	class RefineryLight14 {
		name="light14";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight14";
		};
	class RefineryLight15 {
		name="light15";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0;
		size=100;
		blinking=0;
		displayName="RefineryLight15";
		};
	class RefineryLight16 {
		name="light16";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0;
		size=100;
		blinking=0;
		displayName="RefineryLight16";
		};
	class RefineryLight17 {
		name="light17";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0;
		size=100;
		blinking=0;
		displayName="RefineryLight17";
		};
	class RefineryLight18 {
		name="light18";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0;
		size=100;
		blinking=0;
		displayName="RefineryLight18";
		};
	class RefineryLight19 {
		name="light19";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0;
		blinking=0;
		displayName="RefineryLight19";
		};
	class RefineryLight20 {
		name="light20";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0;
		blinking=0;
		displayName="RefineryLight20";
		};
	class RefineryLight21 {
		name="light21";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0;
		size=100;
		blinking=0;
		displayName="RefineryLight21";
		};
	class RefineryLight22 {
		name="light22";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0;
		size=100;
		blinking=0;
		displayName="RefineryLight22";
		};
	class RefineryLight23 {
		name="light23";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0;
		size=100;
		blinking=0;
		displayName="RefineryLight23";
		};
};

		class Reflectors {

			class MainLight {
				color[] = {0.900000, 0.800000, 0.800000, 1.000000};
				ambient[] = {0.100000, 0.100000, 0.100000, 1.000000};
				position = "Source_MainLight";
				direction = "Direction_MainLight";
				hitpoint = "MainLight";
				selection = "MainLight";
				size = 1;
				brightness = 10;
				period = {4.600000, 2.400000};
			};
			class MainLight2 {
				color[] = {0.900000, 0.800000, 0.800000, 1.000000};
				ambient[] = {0.100000, 0.100000, 0.100000, 1.000000};
				position = "Source_MainLight2";
				direction = "Direction_MainLight2";
				hitpoint = "MainLight2";
				selection = "MainLight2";
				size = 1;
				brightness = 10;
				period = {4.600000, 2.400000};
			};
			class MainLight3 {
				color[] = {0.900000, 0.800000, 0.800000, 1.000000};
				ambient[] = {0.100000, 0.100000, 0.100000, 1.000000};
				position = "Source_MainLight3";
				direction = "Direction_MainLight3";
				hitpoint = "MainLight3";
				selection = "MainLight3";
				size = 1;
				brightness = 10;
				period = {4.600000, 2.400000};
			};
			class MainLight4 {
				color[] = {0.900000, 0.800000, 0.800000, 1.000000};
				ambient[] = {0.100000, 0.100000, 0.100000, 1.000000};
				position = "Source_MainLight4";
				direction = "Direction_MainLight4";
				hitpoint = "MainLight4";
				selection = "MainLight4";
				size = 1;
				brightness = 10;
				period = {4.600000, 2.400000};
			};

		};

		class eventhandlers
		{
			init="[_this select 0,_this select 1] execVM ""\tg_buildings\scripts\Fan.sqf""";   
		};
        };

	class gdi_powerplant: House{
		scope = 2;
		side = 1;
		model = "\tg_buildings\gdi\model\gdi_powerplant.p3d";
		//icon = "";
		displayName = "$STR_GDI_PP";
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
	};

	class gdi_barracks: House{
		scope = 2;
		side = 1;
		model = "\tg_buildings\gdi\model\gdi_barracks.p3d";
		//icon = "";
		displayName = "$STR_GDI_BA";
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

	class Barrackslight5 {
		name="light5";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="Barrackslight5";
		};
};
};

	class gdi_tiberiumrefinery: House{
		scope = 2;
		side = 1;
		model = "\tg_buildings\gdi\model\gdi_tiberiumrefinery.p3d";
		//icon = "";
		displayName = "$STR_GDI_TR";
		animated = 1;
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

	class RefineryLight1 {
		name="light1";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight1";
		};
	class RefineryLight2 {
		name="light2";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight2";
		};
	class RefineryLight3 {
		name="light3";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight3";
		};
	class RefineryLight4 {
		name="light4";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight4";
		};
	class RefineryLight5 {
		name="light5";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight5";
		};
	class RefineryLight6 {
		name="light6";
		color[]={1.0000,0.0000,0.0000,0};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight6";
		};
	class RefineryLight7 {
		name="light7";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight7";
		};
	class RefineryLight8 {
		name="light8";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight8";
		};
	class RefineryLight9 {
		name="light9";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight9";
		};
	class RefineryLight10 {
		name="light10";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight10";
		};
	class RefineryLight11 {
		name="light11";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight11";
		};
	class RefineryLight12 {
		name="light12";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight12";
		};
	class RefineryLight13 {
		name="light13";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight13";
		};
	class RefineryLight14 {
		name="light14";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.0,0.9,0.0,1};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight14";
		};
	class RefineryLight15 {
		name="light15";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight15";
		};
	class RefineryLight16 {
		name="light16";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight16";
		};
	class RefineryLight17 {
		name="light17";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0.04;
		blinking=0;
		displayName="RefineryLight17";
		};
	class RefineryLight18 {
		name="light18";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0;
		size=100;
		blinking=0;
		displayName="RefineryLight18";
		};
	class RefineryLight19 {
		name="light19";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0;
		blinking=0;
		displayName="RefineryLight19";
		};
	class RefineryLight20 {
		name="light20";
		color[]={0.60,0.60,0.40};
		ambient[]={0.30,0.30,0.20};
		brightness=0;
		blinking=0;
		displayName="RefineryLight20";
		};
	class RefineryLight21 {
		name="light21";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0;
		blinking=0;
		displayName="RefineryLight21";
		};
	class RefineryLight22 {
		name="light22";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0;
		blinking=1;
		displayName="RefineryLight22";
		};
	class RefineryLight23 {
		name="light23";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0;
		blinking=1;
		displayName="RefineryLight23";
		};
};

		class Reflectors {

			class MainLight {
				color[] = {0.900000, 0.800000, 0.800000, 1.000000};
				ambient[] = {0.100000, 0.100000, 0.100000, 1.000000};
				position = "Source_MainLight";
				direction = "Direction_MainLight";
				hitpoint = "MainLight";
				selection = "MainLight";
				size = 1;
				brightness = 0;
				period = {4.600000, 2.400000};
			};
			class MainLight2 {
				color[] = {0.900000, 0.800000, 0.800000, 1.000000};
				ambient[] = {0.100000, 0.100000, 0.100000, 1.000000};
				position = "Source_MainLight2";
				direction = "Direction_MainLight2";
				hitpoint = "MainLight2";
				selection = "MainLight2";
				size = 1;
				brightness = 0;
				period = {4.600000, 2.400000};
			};
			class MainLight3 {
				color[] = {0.900000, 0.800000, 0.800000, 1.000000};
				ambient[] = {0.100000, 0.100000, 0.100000, 1.000000};
				position = "Source_MainLight3";
				direction = "Direction_MainLight3";
				hitpoint = "MainLight3";
				selection = "MainLight3";
				size = 1;
				brightness = 0;
				period = {4.600000, 2.400000};
			};
		};
};

	class gdi_tiberiumsilo: House{
		scope = 2;
		side = 1;
		model = "\tg_buildings\gdi\model\gdi_tiberiumsilo.p3d";
		//icon = "";
		displayName = "$STR_GDI_TS";
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
	};

	class nod_constructionyard: House{
		scope = 2;
		side = 1;
		model = "\tg_buildings\nod\model\nod_conyard.p3d";
		//icon = "";
		displayName = "$STR_NOD_CY";
		animated = 0;
		vehicleClass = "NOD_B";
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
	};

	class nod_powerplant: House{
		scope = 2;
		side = 1;
		model = "\tg_buildings\nod\model\nod_powerplant.p3d";
		//icon = "";
		displayName = "$STR_NOD_PP";
		animated = 0;
		vehicleClass = "NOD_B";
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
	};

	class nod_barracks: House{
		scope = 2;
		side = 1;
		model = "\tg_buildings\nod\model\nod_barracks.p3d";
		//icon = "";
		displayName = "$STR_NOD_BA";
		animated = 0;
		vehicleClass = "NOD_B";
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
	};

	class nod_tiberiumrefinery: House{
		scope = 2;
		side = 1;
		model = "\tg_buildings\nod\model\nod_tiberiumrefinery.p3d";
		//icon = "";
		displayName = "$STR_NOD_TR";
		animated = 0;
		vehicleClass = "NOD_B";
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
	};

	class nod_tiberiumsilo: House{
		scope = 2;
		side = 1;
		model = "\tg_buildings\nod\model\nod_tiberiumsilo.p3d";
		//icon = "";
		displayName = "$STR_NOD_TS";
		animated = 0;
		vehicleClass = "NOD_B";
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
	};