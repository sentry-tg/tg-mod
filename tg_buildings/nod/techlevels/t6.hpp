	class nod_wall: House{
		scope = 2;
		side = 1;
		model = "\tg_buildings\nod\model\nod_wall.p3d";
		icon = "\Ca\buildings\Icons\i_camosmall_CA.paa";
		displayName = "$STR_NOD_WALL";
		animated = 0;
		vehicleClass = "NOD_B";
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

	class nod_wall2: House{
		scope = 2;
		side = 1;
		model = "\tg_buildings\nod\model\nod_wall2.p3d";
		icon = "\Ca\buildings\Icons\i_camosmall_CA.paa";
		displayName = "$STR_NOD_WALL2";
		animated = 0;
		vehicleClass = "NOD_B";
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