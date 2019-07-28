	class gdi_repairpad: House{
		scope = 2;
		side = 1;
		model = "\tg_buildings\gdi\model\gdi_repairpad.p3d";
		//icon = "";
		displayName = "$STR_GDI_REP";
		animated = 0;
		vehicleClass = "GDI_B";
		nameSound = "house";
		accuracy = 0.200000;
		typicalCargo = {};
		transportAmmo = 0;
		transportRepair = 200000000;
		supplyRadius = 7.500000;
		transportFuel = 200000000;
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