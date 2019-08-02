#include "BIS_AddonInfo.hpp"
#include "model.cfg"

#define private		0
#define protected		1
#define public		2

class CfgPatches {
	class TG_Soldiers {
		units[] = {"NOD_Infantry", "NOD_RocketInfantry", "NOD_Flamer", "NOD_BlackHand", "GDI_LightInfantry", "GDI_Medic", "GDI_Officer"};
		weapons[] = {"NOD_Uniform", "NOD_Helmet", "NOD_Helmet2", "NOD_Helmet_Gas", "NOD_Vest", "GDI_Uniform", "GDI_Vest", "GDI_VestMedic", "GDI_Helmet", "GDI_Helmet_Medic", "GDI_Beret"};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Characters_F"};
	};
};

class CfgVehicles {
	class B_Carryall_Base;
	class B_Assaultpack_Base;
	class I_Soldier_F;
	class O_Soldier_F;
	class B_Soldier_F;
	class B_Bergen_Base;
	class O_Soldier_Base_F;
	class Bag_Base;
	
	class TG_Soldier_Base : O_Soldier_Base_F {
		_GeneralMacro = "TG_Soldier_Base";
		scope = private;
		selectionPersonality = "personality";
		identityTypes[] = {"LanguageENG_F", "Head_NATO"};
		role = "SpecialOperative";
		editorcategory = "tg";
	};
	
	class NOD_Soldier_Base : TG_Soldier_Base {
		scope = private;
		editorSubcategory = "NOD_Infantry";
		editorPreview = "\tg_Core\Data\nod.paa";
		uniformClass = "NOD_Uniform";
		hiddenSelections[] = {"Camo", "insignia"};
		hiddenSelectionsTextures[] = {"\tg_soldiers\data\NOD_2_Alpha_Co.paa"};
		model = "\A3\characters_F\blufor\b_Soldier_01.p3d";
	};
	
	class NOD_Infantry : NOD_Soldier_Base {
		scope = public;
		displayName = "NOD Light Infantry";

		linkedItems[] = {"NOD_Helmet", "NOD_Vest"};
		respawnLinkedItems[] = {"NOD_Helmet", "NOD_Vest"};
		weapons[] = {"arifle_Katiba_C_ACO_F", "Throw", "Put"};
		respawnWeapons[] = {"arifle_Katiba_C_ACO_F", "Throw", "Put"};
		magazines[] = {"30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green"};
		respawnMagazines[] = {"30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green"};
	};

	class NOD_RocketInfantry : NOD_Soldier_Base {
		scope = public;
		displayName = "NOD Rocket Infantry";
		
		linkedItems[] = {"NOD_Helmet", "NOD_Vest"};
		respawnLinkedItems[] = {"NOD_Helmet", "NOD_Vest"};
		weapons[] = {"NOD_Rocketlauncher", "Throw", "Put"};
		respawnWeapons[] = {"NOD_Rocketlauncher", "Throw", "Put"};
		magazines[] = {"NOD_Rocket_Mag", "NOD_Rocket_Mag", "NOD_Rocket_Mag", "NOD_Rocket_Mag", "NOD_Rocket_Mag", "NOD_Rocket_Mag"};
		respawnMagazines[] = {"NOD_Rocket_Mag", "NOD_Rocket_Mag", "NOD_Rocket_Mag", "NOD_Rocket_Mag", "NOD_Rocket_Mag", "NOD_Rocket_Mag"};
	};

	class NOD_Flamer : NOD_Soldier_Base {
		scope = public;
		displayName = "NOD Flamer";
		
		linkedItems[] = {"NOD_Helmet_Gas", "NOD_Vest"};
		respawnLinkedItems[] = {"NOD_Helmet_Gas", "NOD_Vest"};
		weapons[] = {"arifle_Katiba_C_ACO_F", "Throw", "Put"};
		respawnWeapons[] = {"arifle_Katiba_C_ACO_F", "Throw", "Put"};
		magazines[] = {"30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green"};
		respawnMagazines[] = {"30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green"};
	};


	class NOD_BlackHand : NOD_Soldier_Base {
		scope = public;
		displayName = "NOD Black Hand";
		
		linkedItems[] = {"NOD_Helmet2", "NOD_Vest"};
		respawnLinkedItems[] = {"NOD_Helmet2", "NOD_Vest"};
		weapons[] = {"arifle_Katiba_C_ACO_F", "Throw", "Put"};
		respawnWeapons[] = {"arifle_Katiba_C_ACO_F", "Throw", "Put"};
		magazines[] = {"30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green"};
		respawnMagazines[] = {"30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green", "30Rnd_65x39_Caseless_Green"};
	};

	class GDI_Soldier_Base : TG_Soldier_Base {
		scope = private;
		editorSubcategory = "GDI_Infantry";
		editorPreview = "\tg_Core\Data\gdi.paa";
		uniformClass = "GDI_Uniform";
		hiddenSelections[] = {"insignia"};
		hiddenSelectionsTextures[] = {};
		side = 1;
		model = "\tg_soldiers\gdi\model\uniform_gdi.p3d";
		
		nakedUniform = "U_BasicBody";
		modelsides[] = {3, 2, 1, 0};
	};
	
	class GDI_LightInfantry : GDI_Soldier_Base {
		scope = public;
		displayName = "GDI Light Infantry";
		
		linkedItems[] = {"GDI_Helmet", "GDI_Vest", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
		respawnLinkedItems[] = {"GDI_Helmet", "GDI_Vest", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
		weapons[] = {"arifle_MX_ACO_F", "Throw", "Put"};
		respawnWeapons[] = {"arifle_MX_ACO_F", "Throw", "Put"};
		magazines[] = {"30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag"};
		respawnMagazines[] = {"30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag"};
	};

	class GDI_DT : GDI_Soldier_Base {
		scope = public;
		displayName = "GDI Disc Thrower";
		
		backpack = "GDI_Dt_Bp";
		
		linkedItems[] = {"GDI_Helmet", "GDI_Vest"};
		respawnLinkedItems[] = {"GDI_Helmet", "GDI_Vest"};
		weapons[] = {"DiscThrow", "Put"};
		respawnWeapons[] = {"DiscThrow", "Put"};
		magazines[] = {"GDI_Discgrenade"};
		respawnMagazines[] = {"GDI_Discgrenade"};
	};

	class GDI_JJ : GDI_Soldier_Base {
		scope = public;
		displayName = "GDI Jumpjet Infantry";
		
		backpack = "GDI_Jetpack_Bp";
		
		linkedItems[] = {"GDI_Helmet", "GDI_Vest"};
		respawnLinkedItems[] = {"GDI_Helmet", "GDI_Vest"};
		weapons[] = {"arifle_MX_ACO_F", "Throw", "Put"};
		respawnWeapons[] = {"arifle_MX_ACO_F", "Throw", "Put"};
		magazines[] = {"30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag"};
		respawnMagazines[] = {"30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag"};
	};

	class GDI_Officer : GDI_Soldier_Base {
		scope = public;
		displayName = "GDI Officer";
		
		linkedItems[] = {"GDI_Beret", "GDI_Vest"};
		respawnLinkedItems[] = {"GDI_Beret", "GDI_Vest"};
		weapons[] = {"arifle_MX_ACO_F", "Throw", "Put"};
		respawnWeapons[] = {"arifle_MX_ACO_F", "Throw", "Put"};
		magazines[] = {"30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag"};
		respawnMagazines[] = {"30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag"};
	};

	class GDI_Medic : GDI_Soldier_Base {
		scope = public;
		displayName = "GDI Medic";
		
		backpack = "GDI_Medic_Bp";
		
		linkedItems[] = {"GDI_Helmet_Medic", "GDI_VestMedic"};
		respawnLinkedItems[] = {"GDI_Helmet_Medic", "GDI_VestMedic"};
		weapons[] = {"arifle_MX_ACO_F", "Throw", "Put"};
		respawnWeapons[] = {"arifle_MX_ACO_F", "Throw", "Put"};
		magazines[] = {"30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag"};
		respawnMagazines[] = {"30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag", "30Rnd_65x39_Caseless_Mag"};

		class HitPoints {
			class HitFace {
				armor = 4;
				material = -1;
				name = "face_Hub";
				passThrough = 0.1;
				radius = 0.08;
				explosionShielding = 0.1;
				minimalHit = 0.01;
			};
			
			class HitNeck : HitFace {
				armor = 4;
				material = -1;
				name = "neck";
				passThrough = 0.1;
				radius = 0.1;
				explosionShielding = 0.5;
				minimalHit = 0.01;
			};
			
			class HitHead : HitNeck {
				armor = 4;
				material = -1;
				name = "head";
				passThrough = 0.1;
				radius = 0.2;
				explosionShielding = 0.5;
				minimalHit = 0.01;
				depends = "HitFace max HitNeck";
			};
			
			class HitPelvis {
				armor = 4;
				material = -1;
				name = "pelvis";
				passThrough = 0.1;
				radius = 0.2;
				explosionShielding = 1;
				visual = "injury_Body";
				minimalHit = 0.01;
			};
			
			class HitAbdomen : HitPelvis {
				armor = 4;
				material = -1;
				name = "spine1";
				passThrough = 0.1;
				radius = 0.15;
				explosionShielding = 1;
				visual = "injury_Body";
				minimalHit = 0.01;
			};
			
			class HitDiaphragm : HitAbdomen {
				armor = 4;
				material = -1;
				name = "spine2";
				passThrough = 0.1;
				radius = 0.15;
				explosionShielding = 6;
				visual = "injury_Body";
				minimalHit = 0.01;
			};
			
			class HitChest : HitDiaphragm {
				armor = 4;
				material = -1;
				name = "spine3";
				passThrough = 0.1;
				radius = 0.15;
				explosionShielding = 6;
				visual = "injury_Body";
				minimalHit = 0.01;
			};
			
			class HitBody : HitChest {
				armor = 4000;
				material = -1;
				name = "body";
				passThrough = 0.1;
				radius = 0.16;
				explosionShielding = 6;
				visual = "injury_Body";
				minimalHit = 0.01;
				depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
			};
			
			class HitArms {
				armor = 4;
				material = -1;
				name = "arms";
				passThrough = true;
				radius = 0.1;
				explosionShielding = 1;
				visual = "injury_Hands";
				minimalHit = 0.01;
			};
			
			class HitHands : HitArms {
				armor = 4;
				material = -1;
				name = "hands";
				passThrough = true;
				radius = 0.1;
				explosionShielding = 1;
				visual = "injury_Hands";
				minimalHit = 0.01;
				depends = "HitArms";
			};
			
			class HitLegs {
				armor = 32;
				material = -1;
				name = "legs";
				passThrough = 0.6;
				radius = 0.12;
				explosionShielding = 0.8;
				visual = "injury_Legs";
				minimalHit = 0.01;
			};
		};
		armor = 8;
		armorStructural = 3.5;
		explosionShielding = 0.05;

	};

	class TG_Bag_Base : Bag_Base {
		editorcategory = "tg";
		isbackpack = 1;
		reversed = true;
	};

	class GDI_Medic_BP : TG_Bag_Base {
		scope = public;
		editorSubcategory = "GDI_Infantry";
		editorPreview = "\tg_Core\Data\gdi.paa";
		side = 1;
		mapSize = 0.6;
		icon = "iconBackpack";
		picture = "\A3\weapons_F\ammoboxes\bags\data\UI\icon_B_C_Small_Blk";
		model = "\tg_soldiers\gdi\model\medicpack.p3d";
		displayName = "GDI Medic Backpack";
		HiddenSelectionsTextures[] = {"\A3\weapons_F\ammoboxes\bags\data\backpack_Small_Co"};
		maximumLoad = 0;
		mass = 300;
	};

	class GDI_DT_BP : TG_Bag_Base {
		editorSubcategory = "GDI_Infantry";
		editorPreview = "\tg_Core\Data\gdi.paa";
		side = 1;
		mapSize = 0.6;
		icon = "iconBackpack";
		scope = public;
		picture = "\A3\weapons_F\ammoboxes\bags\data\UI\icon_B_C_Small_Blk";
		model = "\tg_soldiers\gdi\model\dtpack.p3d";
		displayName = "GDI Disc Thrower Backpack";
		HiddenSelectionsTextures[] = {"\A3\weapons_F\ammoboxes\bags\data\backpack_Small_Co"};
		maximumLoad = 0;
		mass = 300;
	};
	
	class GDI_Jetpack_BP : TG_Bag_Base {
		editorSubcategory = "GDI_Infantry";
		editorPreview = "\tg_Core\Data\gdi.paa";
		side = 1;
		mapSize = 0.6;
		icon = "iconBackpack";
		scope = public;
		picture = "\A3\weapons_F\ammoboxes\bags\data\UI\icon_B_C_Small_Blk";
		model = "\tg_soldiers\gdi\model\jetpack.p3d";
		displayName = "GDI Jetpack";
		HiddenSelectionsTextures[] = {"\A3\weapons_F\ammoboxes\bags\data\backpack_Small_Co"};
		maximumLoad = 0;
		mass = 300;
	};

};

class CfgWeapons {
	class Vest_Camo_Base;
	class VestItem;
	class ItemInfo;
	class H_HelmetB_Plain_Mcamo;
	class H_HelmetB;
	class HeadgearItem;
	class Uniform_Base;
	class UniformItem;
	class Bag_Base;
	
	class NOD_Uniform : Uniform_Base {
		scope = public;
		displayName = "NOD Uniform";
		picture = "\tg_Core\Data\nod.paa";
		model = "\A3\characters_F\blufor\b_Soldier_01.p3d";
		
		class ItemInfo : UniformItem {
			uniformModel = "-";
			uniformClass = "NOD_Infantry";
			containerClass = "Supply40";
			mass = 40;
		};
	};

	class GDI_Uniform : Uniform_Base {
		scope = public;
		displayName = "GDI Uniform";
		picture = "\tg_Core\Data\gdi.paa";
		model = "\tg_soldiers\gdi\model\uniform_Gdi.p3d";
		
		class ItemInfo : UniformItem {
			uniformModel = "\tg_soldiers\gdi\model\uniform_Gdi.p3d";
			uniformClass = "GDI_LightInfantry";
			containerClass = "Supply40";
			mass = 40;
		};
	};
	
	class NOD_Helmet : H_HelmetB {
		scope = public;
		picture = "\tg_Core\Data\nod.paa";
		displayName = "NOD Helmet";
		model = "\tg_soldiers\nod\model\nod_helmet.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {};
		
		class ItemInfo : HeadgearItem {
			mass = 80;
			uniformModel = "\tg_soldiers\nod\model\nod_helmet.p3d";
			hiddenSelections[] = {"camo"};
			modelSides[] = {0, 3};
			
			class HitpointsProtectionInfo {
				class Head {
					hitpointName = "HitHead";
					armor = 12;
					passThrough = 0.5;
				};
				
				class Face {
					hitpointName = "HitFace";
					armor = 8;
					passThrough = 0.5;
				};
			};
		};
		subItems[] = {"Integrated_NVG_TI_1_F"};
	};

	class NOD_Helmet2 : H_HelmetB {
		scope = public;
		picture = "\tg_Core\Data\nod.paa";
		displayName = "NOD Helmet Black Hand";
		model = "\tg_soldiers\nod\model\helmet2.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {};
		
		class ItemInfo : HeadgearItem {
			mass = 80;
			uniformModel = "\tg_soldiers\nod\model\helmet2.p3d";
			hiddenSelections[] = {"camo"};
			modelSides[] = {0, 3};
			
			class HitpointsProtectionInfo {
				class Head {
					hitpointName = "HitHead";
					armor = 12;
					passThrough = 0.5;
				};
				
				class Face {
					hitpointName = "HitFace";
					armor = 8;
					passThrough = 0.5;
				};
			};
		};
		subItems[] = {"Integrated_NVG_TI_1_F"};
	};

	class NOD_Helmet_Gas : H_HelmetB {
		scope = public;
		picture = "\tg_Core\Data\nod.paa";
		displayName = "NOD Helmet Gasmask";
		model = "\tg_soldiers\nod\model\helmet_Gas.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {};
		
		class ItemInfo : HeadgearItem {
			mass = 80;
			uniformModel = "\tg_soldiers\nod\model\helmet_Gas.p3d";
			hiddenSelections[] = {"camo"};
			modelSides[] = {0, 3};
			
			class HitpointsProtectionInfo {
				class Head {
					hitpointName = "HitHead";
					armor = 12;
					passThrough = 0.5;
				};
				
				class Face {
					hitpointName = "HitFace";
					armor = 8;
					passThrough = 0.5;
				};
			};
		};
		subItems[] = {"Integrated_NVG_TI_1_F"};
	};

	class GDI_Helmet : H_HelmetB {
		scope = public;
		author = "Tiberian Genesis Team";
		picture = "\A3\characters_F\Data\UI\icon_H_Cap_Blk_CA.paa";
		displayName = "GDI Helmet";
		model = "\tg_soldiers\gdi\model\helmet.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {};
		allowedFacewear[] = {"G_Aviator", "G_Bandanna_Aviator", "G_Bandanna_Beast", "G_Bandanna_Blk", "G_Bandanna_Khk", "G_Bandanna_Oli", "G_Bandanna_Shades", "G_Bandanna_Sport", "G_Bandanna_Tan", "G_Shades_Black", "G_Shades_Blue", "G_Shades_Red", "G_Shades_Green"};
		
		class ItemInfo : HeadgearItem {
			mass = 80;
			uniformModel = "\tg_soldiers\gdi\model\helmet.p3d";
			hiddenSelections[] = {"camo"};
			modelSides[] = {0, 3};
			
			class HitpointsProtectionInfo {
				class Head {
					hitpointName = "HitHead";
					armor = 12;
					passThrough = 0.5;
				};
				
				class Face {
					hitpointName = "HitFace";
					armor = 8;
					passThrough = 0.5;
				};
			};
		};
		subItems[] = {"Integrated_NVG_TI_1_F"};
	};

	class GDI_Beret : H_HelmetB {
		scope = public;
		author = "Tiberian Genesis Team";
		picture = "\A3\characters_F\Data\UI\icon_H_Cap_Blk_CA.paa";
		displayName = "GDI Beret";
		model = "\tg_soldiers\gdi\model\GDI_Beret.p3d";
		hiddenSelections[] = {"camo", "camo2"};
		hiddenSelectionsTextures[] = {};
		allowedFacewear[] = {"G_Aviator", "G_Bandanna_Aviator", "G_Bandanna_Beast", "G_Bandanna_Blk", "G_Bandanna_Khk", "G_Bandanna_Oli", "G_Bandanna_Shades", "G_Bandanna_Sport", "G_Bandanna_Tan", "G_Shades_Black", "G_Shades_Blue", "G_Shades_Red", "G_Shades_Green"};
		
		class ItemInfo : HeadgearItem {
			uniformModel = "\tg_soldiers\gdi\model\GDI_Beret.p3d";
			armor = 15;
			mass = 30;
			modelSides[] = {6};
			passThrough = 0.1;
			hiddenSelections[] = {"camo", "camo2"};
			hiddenSelectionsTextures[] = {};

		};
	};

	class GDI_Helmet_Medic : H_HelmetB {
		scope = public;
		author = "Tiberian Genesis Team";
		picture = "\A3\characters_F\Data\UI\icon_H_Cap_Blk_CA.paa";
		displayName = "GDI Helmet Medic";
		model = "\tg_soldiers\gdi\model\helmetmedic.p3d";
		hiddenSelections[] = {"camo", "camo2"};
		hiddenSelectionsTextures[] = {};
		
		class ItemInfo : HeadgearItem {
			mass = 80;
			uniformModel = "\tg_soldiers\gdi\model\helmetmedic.p3d";
			hiddenSelections[] = {"camo"};
			modelSides[] = {0, 3};
			
			class HitpointsProtectionInfo {
				class Head {
					hitpointName = "HitHead";
					armor = 12;
					passThrough = 0.5;
				};
				
				class Face {
					hitpointName = "HitFace";
					armor = 8;
					passThrough = 0.5;
				};
			};
		};
		subItems[] = {"Integrated_NVG_TI_1_F"};
	};

	class NOD_Vest : Vest_Camo_Base {
		scope = public;
		displayName = "NOD Vest";
		picture = "\tg_Core\Data\nod.paa";
		model = "\A3\Characters_F_Beta\indep\equip_Ia_Ga_Carrier_Gl_Rig.p3d";
		hiddenSelections[] = {"camo1", "camo2"};
		hiddenSelectionsTextures[] = {"\tg_soldiers\data\NOD_Vest_1_Alpha_Co.paa", "\tg_soldiers\data\NOD_Vest_1_Gl_Alpha_Co.paa"};
		
		class ItemInfo : VestItem {
			uniformModel = "\A3\Characters_F_Beta\indep\equip_Ia_Ga_Carrier_Gl_Rig.p3d";
			containerClass = "Supply140";
			mass = 80;
			armor = 100;
			passThrough = 0.5;
			hiddenSelections[] = {"camo1", "camo2"};
		};
	};

	class GDI_Vest : Vest_Camo_Base {
		scope = public;
		displayName = "GDI Vest";
		picture = "\tg_Core\Data\gdi.paa";
		model = "\tg_soldiers\gdi\model\GDI_Vest.p3d";
		
		class ItemInfo : VestItem {
			uniformModel = "\tg_soldiers\gdi\model\GDI_Vest.p3d";
			containerClass = "Supply140";
			mass = 80;
			armor = 100;
			passThrough = 0.5;
		};
	};

	class GDI_VestMedic : Vest_Camo_Base {
		scope = public;
		displayName = "GDI Vest Medic";
		picture = "\tg_Core\Data\gdi.paa";
		model = "\tg_soldiers\gdi\model\GDI_Vest_Medic.p3d";
		
		class ItemInfo : VestItem {
			uniformModel = "\tg_soldiers\gdi\model\GDI_Vest_Medic.p3d";
			containerClass = "Supply140";
			mass = 80;
			armor = 100;
			passThrough = 0.5;
		};
	};
};

class CfgFunctions 
{
	class TG {
		
		class Init {
			class SoldiersInit {
				file = "\tg_soldiers\init.sqf";	
				postInit = 1;
			};
		};
		
		class Jetpack 
		{
			class JetpackInit {
				file = "\tg_soldiers\functions\JetpackInit.sqf";
			};
			class ableToFly {
				file = "\tg_soldiers\functions\ableToFly.sqf";	
			};
			class isUnitLanded {
				file = "\tg_soldiers\functions\isUnitLanded.sqf";	
			};
			class addJetpackControls {
				file = "\tg_soldiers\functions\addJetpackControls.sqf";	
			};
			class addJetpackEffects {
				file = "\tg_soldiers\functions\addJetpackEffects.sqf";	
			};
		};
		
		class Compatibility 
		{
			class HeadlampsInit {
				file = "\tg_soldiers\scripts\HeadlampsCompatPatch.sqf";
			};
		};
		
	};
		
};	