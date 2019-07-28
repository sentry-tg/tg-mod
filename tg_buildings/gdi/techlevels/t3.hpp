	class gdi_radar: House{
		scope = 2;
		side = 1;
		model = "\tg_buildings\gdi\model\gdi_radar.p3d";
		//icon = "";
		displayName = "$STR_GDI_RADAR";
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
		ladders[]= {{"start", "end"},{"start1", "end1"}};
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