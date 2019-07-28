class cfgMagazines 
{
	class Default;		// External class reference
	class PistolCore;	// External class reference
	class RifleCore;	// External class reference
	class MGunCore;		// External class reference
	class TwinM134;		// External class reference
	class VehicleMagazine;	// External class reference
	
	class rpg_mag: VehicleMagazine {
		scope = 2;
		displayName = "RPG";
		ammo = "rpg_ammo";
		count = 2000;
		initSpeed = 1000;
		maxLeadSpeed = 100;
	};

	class vulcan_mag: VehicleMagazine {
		scope = 2;
		ammo = "vulcan_ammo";
		count = 20000;
		maxLeadSpeed = 200;
	};

};