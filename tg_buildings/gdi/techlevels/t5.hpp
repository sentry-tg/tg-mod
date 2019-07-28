	class gdi_helipad: House{
		scope = 2;
		side = 1;
		model = "\tg_buildings\gdi\model\gdi_helipad.p3d";
		//icon = "";
		displayName = "$STR_GDI_HPAD";
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