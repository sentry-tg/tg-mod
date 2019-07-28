class cfgAmmo 
{
	class Default;		// External class reference
	class PistolCore;	// External class reference
	class RifleCore;	// External class reference
	class MGunCore;		// External class reference
	class BulletBase;	// External class reference
	class ShellBase;	// External class reference
	
	class rpg_ammo: ShellBase {
		hit = 800;
		indirectHit = 50;
		indirectHitRange = 5;
		typicalSpeed = 80;
		cost = 1000;
		deflecting = 0;
		model = "\ca\Weapons\shell";
		soundHit[]= {"\tg_buildings\sound\rpg_hit.ogg", 316.227753, 1};
	};

	class vulcan_ammo: BulletBase {
		hit = 25;
		indirectHit = 0;
		indirectHitRange = 0;
		visibleFire = 25;
		audibleFire = 22;
		visibleFireTime = 4;
		tracerColor = {0, 0, 0, 0};
		tracerColorR = {0, 0, 0, 0};

		soundFly[]= {"\tg_buildings\sound\vulcan_fly.wav", 0.112202, 1.200000};
		soundHit1[]= {"\ca\Weapons\Data\Sound\bullet_ricochet_01", 0.010000, 1};
		soundHit2[]= {"\ca\Weapons\Data\Sound\bullet_ricochet_02", 0.031623, 1};
		soundHit3[]= {"\ca\Weapons\Data\Sound\bullet_ricochet_03", 0.010000, 1};
		soundHit4[]= {"\ca\Weapons\Data\Sound\bullet_ricochet_04", 0.031623, 1};
		soundHit5[]= {"\ca\Weapons\Data\Sound\bullet_ricochet_05", 0.010000, 1};
		soundHit6[]= {"\ca\Weapons\Data\Sound\bullet_ricochet_06", 0.010000, 1};
		soundHit7[]= {"\ca\Weapons\Data\Sound\bullet_ricochet_07", 0.010000, 1};
		soundHit8[]= {"\ca\Weapons\Data\Sound\bullet_ricochet_08", 0.031623, 1};
		soundHit9[]= {"\ca\Weapons\Data\Sound\bullet_ricochet_09", 0.017783, 1};
		soundHit10[]= {"\ca\Weapons\Data\Sound\bullet_ricochet_10", 0.010000, 1};
		soundHit11[]= {"\ca\Weapons\Data\Sound\bullet_ricochet_13", 0.031623, 1};
		soundHit12[]= {"\ca\Weapons\Data\Sound\bullet_ricochet_16", 0.010000, 1};
		soundHitMan1[]= {"\tg_buildings\sound\HitFleshL_01.wav", 8.316228, 1};
		soundHitMan2[]= {"\tg_buildings\sound\HitFleshS_01.wav", 8.316228, 1};
		soundHitMan3[]= {"\tg_buildings\sound\HitFleshS_02.wav", 8.316228, 1};
		soundHitMan4[]= {"\tg_buildings\sound\HitFleshS_03.wav", 8.316228, 1};
		soundHitMan5[]= {"\tg_buildings\sound\HitFleshL_02.wav", 8.316228, 1};
		soundHitMan6[]= {"\tg_buildings\sound\HitFleshL_03.wav", 8.316228, 1};
		soundHitMan7[]= {"\ca\Weapons\Data\Sound\bullet_man_hit_07", 0.316228, 1};
		soundHitArmor1[]= {"\tg_buildings\sound\HitMetalL_01.wav", 8.100000, 1};
		soundHitArmor2[]= {"\tg_buildings\sound\HitMetalS_01.wav", 8.100000, 1};
		soundHitArmor3[]= {"\tg_buildings\sound\HitMetalS_01v2.wav", 8.100000, 1};
		soundHitArmor4[]= {"\tg_buildings\sound\HitMetalS_02.wav", 8.100000, 1};
		soundHitArmor5[]= {"\ca\Weapons\Data\Sound\bullet_armor_hit_05", 0.100000, 1};
		soundHitArmor6[]= {"\ca\Weapons\Data\Sound\bullet_armor_hit_06", 0.100000, 1};
		soundHitArmor7[]= {"\ca\Weapons\Data\Sound\bullet_armor_hit_07", 0.100000, 1};
		soundHitArmor8[]= {"\ca\Weapons\Data\Sound\bullet_armor_hit_08", 0.100000, 1};
		soundHitArmor9[]= {"\ca\Weapons\Data\Sound\bullet_armor_hit_09", 0.100000, 1};
		soundHitArmor10[]= {"\ca\Weapons\Data\Sound\bullet_armor_hit_10", 0.100000, 1};
		soundHitArmor11[]= {"\ca\Weapons\Data\Sound\bullet_armor_hit_11", 0.100000, 1};
		soundHitArmor12[]= {"\ca\Weapons\Data\Sound\bullet_armor_hit_12", 0.100000, 1};
		soundHitArmor13[]= {"\ca\Weapons\Data\Sound\bullet_armor_hit_13", 0.100000, 1};
		soundHitArmor14[]= {"\ca\Weapons\Data\Sound\bullet_armor_hit_14", 0.100000, 1};
		soundHitBuilding1[]= {"\ca\Weapons\Data\Sound\bullet_ricochet_02", 0.017783, 1};
		soundHitBuilding2[]= {"\ca\Weapons\Data\Sound\bullet_ricochet_04", 0.017783, 1};
		soundHitBuilding3[]= {"\ca\Weapons\Data\Sound\bullet_ricochet_10", 0.017783, 1};
		soundHitBuilding4[]= {"\ca\Weapons\Data\Sound\bullet_ricochet_12", 0.017783, 1};
		soundHitBuilding5[]= {"\ca\Weapons\Data\Sound\bullet_ricochet_13", 0.005623, 1};
		soundHitBuilding6[]= {"\ca\Weapons\Data\Sound\bullet_ricochet_14", 0.017783, 1};
		soundHitBuilding7[]= {"\ca\Weapons\Data\Sound\bullet_ricochet_15", 0.017783, 1};
		soundHitBuilding8[]= {"\ca\Weapons\Data\Sound\bullet_ricochet_16", 0.017783, 1};
		supersonicCrackNear[]= {};
		supersonicCrackFar[]= {};
		hitGround = {"soundHit1", 0.083000, "soundHit2", 0.083000, "soundHit3", 0.083000, "soundHit4", 0.083000, "soundHit5", 0.083000, "soundHit6", 0.083000, "soundHit7", 0.083000, "soundHit8", 0.083000, "soundHit9", 0.083000, "soundHit10", 0.083000, "soundHit11", 0.083000, "soundHit12", 0.083000};
		hitMan = {"soundHitMan1", 0.143000, "soundHitMan2", 0.143000, "soundHitMan3", 0.143000, "soundHitMan4", 0.143000, "soundHitMan5", 0.143000, "soundHitMan6", 0.143000, "soundHitMan7", 0.143000};
		hitArmor = {"soundHitArmor1", 0.071000, "soundHitArmor2", 0.071000, "soundHitArmor3", 0.071000, "soundHitArmor4", 0.071000, "soundHitArmor5", 0.071000, "soundHitArmor6", 0.071000, "soundHitArmor7", 0.071000, "soundHitArmor8", 0.071000, "soundHitArmor9", 0.071000, "soundHitArmor10", 0.071000, "soundHitArmor11", 0.071000, "soundHitArmor12", 0.071000, "soundHitArmor13", 0.071000, "soundHitArmor14", 0.071000};
		hitBuilding = {"soundHitBuilding1", 0.125000, "soundHitBuilding2", 0.125000, "soundHitBuilding3", 0.125000, "soundHitBuilding4", 0.125000, "soundHitBuilding5", 0.125000, "soundHitBuilding6", 0.125000, "soundHitBuilding7", 0.125000, "soundHitBuilding8", 0.125000};
	};
};