class cfgWeapons 
{
	class Default;		// External class reference
	class PistolCore;	// External class reference
	class RifleCore;	// External class reference
	class MGunCore;		// External class reference
	class CannonCore;	// External class reference
	class MGun;		// External class reference
	
	class vulcan_weapon: MGun {		

			canLock = 0;
			scope = 2;
			magazines[] = {"vulcan_mag"};
			burst = 5;
			multiplier = 5;
			reloadTime = 0.22000;
			sound[] = {"\tg_buildings\sound\vulcan_shot.wav", 1, 1};
			soundContinuous = 0;
			flash = "gunfire";
			flashSize = 0.100000;
			recoil = "Empty";
			maxLeadSpeed = 600;
			aiDispersionCoefX = 5;
			ffMagnitude = 0.500000;
			ffFrequency = 11;
			ffCount = 6;
			dispersion = 0.015000;
			minRange = 1;
			minRangeProbab = 0.100000;
			midRange = 300;
			midRangeProbab = 0.580000;
			maxRange = 400;
			maxRangeProbab = 0.040000;
		};
	class vulcan_weapon2: vulcan_weapon {};

	class rpg_weapon: CannonCore {
		scope = 2;
		displayName = "RPG";
		sound[]= {"\tg_buildings\sound\rpg_shot.ogg", 316.227753, 1};
		reloadSound[]= {};
		magazines[]= {"rpg_mag","rpg_mag"};
		minRange = 1;
		minRangeProbab = 0.100000;
		midRange = 1200;
		midRangeProbab = 0.700000;
		maxRange = 2500;
		maxRangeProbab = 0.100000;
		reloadTime = 3;
		magazineReloadTime = 8;
		maxLeadSpeed = 100;
		autoReload = 1;
	};
	class rpg_weapon2: rpg_weapon {};

};