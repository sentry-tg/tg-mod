	class civ_officebuilding1: House{
		scope = 2;
		side = 3;
		model = "\tg_buildings\civ\model\civ_office1.p3d";
		icon = "\Ca\buildings\Icons\i_camosmall_CA.paa";
		displayName = "$STR_CIV_O1";
		animated = 1;
		vehicleClass = "CIV_B";
		nameSound = "house";
		accuracy = 0.200000;
		typicalCargo = {};
		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;

		ladders[]= {{"start", "end"}};

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

	class office1Light1 {
		name="light1";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office1Light1";
		};
	class office1Light2 {
		name="light2";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office1Light2";
		};
	class office1Light3 {
		name="light3";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office1Light3";
		};
	class office1Light4 {
		name="light4";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office1Light4";
		};
};

};
	class civ_officebuilding2: House{
		scope = 2;
		side = 3;
		model = "\tg_buildings\civ\model\civ_office2.p3d";
		icon = "\Ca\buildings\Icons\i_camosmall_CA.paa";
		displayName = "$STR_CIV_O2";
		animated = 1;
		vehicleClass = "CIV_B";
		nameSound = "house";
		accuracy = 0.200000;
		typicalCargo = {};
		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;

		ladders[]= {{"start", "end"},{"start1", "end1"}};

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

	class office2Light1 {
		name="light1";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light1";
		};
	class office2Light2 {
		name="light2";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light2";
		};
	class office2Light3 {
		name="light3";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light3";
		};
	class office2Light4 {
		name="light4";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light4";
		};
	class office2Light5 {
		name="light5";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light5";
		};
	class office2Light6 {
		name="light6";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light6";
		};
	class office2Light7 {
		name="light7";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light7";
		};
	class office2Light8 {
		name="light8";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light8";
		};
};

};


	class civ_lightpost: House{
		scope = 2;
		side = 3;
		model = "\tg_buildings\civ\model\civ_lightpost.p3d";
		icon = "\Ca\buildings\Icons\i_camosmall_CA.paa";
		displayName = "$STR_CIV_LP";
		animated = 1;
		vehicleClass = "CIV_B";
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

	class office2Light1 {
		name="light1";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light1";
		};
	class office2Light2 {
		name="light2";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light2";
		};
	class office2Light3 {
		name="light3";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light3";
		};
	class office2Light4 {
		name="light4";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light4";
		};
	class office2Light5 {
		name="light5";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light5";
		};
	class office2Light6 {
		name="light6";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light6";
		};
	class office2Light7 {
		name="light7";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light7";
		};
	class office2Light8 {
		name="light8";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light8";
		};
};

};



	class civ_lightpost2: House{
		scope = 2;
		side = 3;
		model = "\tg_buildings\civ\model\civ_lightpost2.p3d";
		icon = "\Ca\buildings\Icons\i_camosmall_CA.paa";
		displayName = "$STR_CIV_LP2";
		animated = 1;
		vehicleClass = "CIV_B";
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

	class office2Light1 {
		name="light1";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light1";
		};
	class office2Light2 {
		name="light2";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light2";
		};
	class office2Light3 {
		name="light3";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light3";
		};
	class office2Light4 {
		name="light4";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light4";
		};
	class office2Light5 {
		name="light5";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light5";
		};
	class office2Light6 {
		name="light6";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light6";
		};
	class office2Light7 {
		name="light7";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light7";
		};
	class office2Light8 {
		name="light8";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light8";
		};
};

};


	class civ_sub: House{
		scope = 2;
		side = 3;
		model = "\tg_buildings\civ\model\civ_sub.p3d";
		icon = "\Ca\buildings\Icons\i_camosmall_CA.paa";
		displayName = "$STR_CIV_SUB";
		animated = 1;
		vehicleClass = "CIV_B";
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

	class office2Light1 {
		name="light1";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light1";
		};
	class office2Light2 {
		name="light2";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light2";
		};
	class office2Light3 {
		name="light3";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light3";
		};
	class office2Light4 {
		name="light4";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light4";
		};
	class office2Light5 {
		name="light5";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light5";
		};
	class office2Light6 {
		name="light6";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light6";
		};
	class office2Light7 {
		name="light7";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light7";
		};
	class office2Light8 {
		name="light8";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light8";
		};
};

};

	class civ_tank: House{
		scope = 2;
		side = 3;
		model = "\tg_buildings\civ\model\civ_tank.p3d";
		icon = "\Ca\buildings\Icons\i_camosmall_CA.paa";
		displayName = "$STR_CIV_TANK";
		animated = 1;
		vehicleClass = "CIV_B";
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

	class office2Light1 {
		name="light1";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light1";
		};
	class office2Light2 {
		name="light2";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light2";
		};
	class office2Light3 {
		name="light3";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light3";
		};
	class office2Light4 {
		name="light4";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light4";
		};
	class office2Light5 {
		name="light5";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light5";
		};
	class office2Light6 {
		name="light6";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light6";
		};
	class office2Light7 {
		name="light7";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light7";
		};
	class office2Light8 {
		name="light8";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light8";
		};
};

};


	class civ_solar: House{
		scope = 2;
		side = 3;
		model = "\tg_buildings\civ\model\civ_solar.p3d";
		icon = "\Ca\buildings\Icons\i_camosmall_CA.paa";
		displayName = "$STR_CIV_SOL";
		animated = 1;
		vehicleClass = "CIV_B";
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

	class office2Light1 {
		name="light1";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light1";
		};
	class office2Light2 {
		name="light2";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light2";
		};
	class office2Light3 {
		name="light3";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light3";
		};
	class office2Light4 {
		name="light4";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light4";
		};
	class office2Light5 {
		name="light5";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light5";
		};
	class office2Light6 {
		name="light6";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light6";
		};
	class office2Light7 {
		name="light7";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light7";
		};
	class office2Light8 {
		name="light8";
		color[]={0.0,0.9,0.0,1};
		ambient[]={0.30,0.30,0.20};
		brightness=0.002;
		blinking=1;
		displayName="office2Light8";
		};
};

};







};