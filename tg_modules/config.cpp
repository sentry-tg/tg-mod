
class CfgPatches
{
	class tg_modules
	{
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {"TG_Core","TG_Objects","TG_Music"};
		requiredVersion = 0.100000;
		author = "Tiberian Genesis Team";
		url = "";
	};
};


class CfgFactionClasses {
	class NO_CATEGORY;	
	class tg_mod : NO_CATEGORY {
		displayName = "Tiberian Genesis";
		author = "Tiberian Genesis Team";
		//icon = "";
	};
};

class CfgFunctions 
{
	class TG {
		class Modules {
			class VisualizeModuleRadius3DEN { file = "\tg_modules\Modules\VisualizeModuleRadius3DEN.sqf"; };
			class ModuleTiberiumGardener { file = "\tg_modules\Modules\ModuleTiberiumGardener.sqf"; };
			class ModuleTiberiumAddSpawner { file = "\tg_modules\Modules\ModuleTiberiumAddSpawner.sqf"; };
			class ModuleTiberiumDamage { file = "\tg_modules\Modules\ModuleTiberiumDamage.sqf"; };
			class ModuleJukebox { file = "\tg_modules\Modules\ModuleJukebox.sqf"; };
			class ModuleTiberiumCrystalValue { file = "\tg_modules\Modules\ModuleTiberiumCrystalValue.sqf"; };
			class ModuleCuratorRTS { file = "\tg_modules\Modules\ModuleCuratorRTS.sqf"; };
			class ModuleTiberiumCrystalLight { file = "\tg_modules\Modules\ModuleTiberiumCrystalLight.sqf"; };
			class ModuleREADME { file = "\tg_modules\Modules\ModuleREADME.sqf"; };
			class ModuleIonCannon { file = "\tg_modules\Modules\ModuleIonCannon.sqf"; };
			class ModuleAtmosphereChanger { file = "\tg_modules\Modules\ModuleAtmosphereChanger.sqf"; };
			class ModuleIonStorm { file = "\tg_modules\Modules\ModuleIonStorm.sqf"; };
		};
		/*
		class AI {
			class ModuleAICommander { file = "\tg_modules\Modules\ModuleAICommander.sqf"; };
			class AICommanderInit { file = "\tg_modules\RTS\AICommanderInit.sqf"; };
			class AICommanderClaim { file = "\tg_modules\RTS\AICommanderClaim.sqf"; };
			class AICommanderFindByName { file = "\tg_modules\RTS\AICommanderFindByName.sqf"; };
		};*/
		class Harvester {
			class HarvesterAddCapacity { file = "\tg_modules\functions\HarvesterAddCapacity.sqf"; };
			class HarvesterCanHarvest { file = "\tg_modules\functions\HarvesterCanHarvest.sqf"; };
			class HarvesterCanUnload { file = "\tg_modules\functions\HarvesterCanUnload.sqf"; };
			class HarvesterClearActivity { file = "\tg_modules\functions\HarvesterClearActivity.sqf"; };
			class HarvesterDockToRefinery { file = "\tg_modules\functions\HarvesterDockToRefinery.sqf"; };
			class HarvesterFindRefinery { file = "\tg_modules\functions\HarvesterFindRefinery.sqf"; };
			class HarvesterFindResource { file = "\tg_modules\functions\HarvesterFindResource.sqf"; };
			class HarvesterGetCapacity { file = "\tg_modules\functions\HarvesterGetCapacity.sqf"; };
			class HarvesterGetOwner { file = "\tg_modules\functions\HarvesterGetOwner.sqf"; };
			class HarvesterGetPreviousPosition { file = "\tg_modules\functions\HarvesterGetPreviousPosition.sqf"; };
			class HarvesterGetRefineryRPP { file = "\tg_modules\functions\HarvesterGetRefineryRPP.sqf"; };
			class HarvesterHarvestOneTick { file = "\tg_modules\functions\HarvesterHarvestOneTick.sqf"; };
			class HarvesterHasActivity { file = "\tg_modules\functions\HarvesterHasActivity.sqf"; };
			class HarvesterIsEmpty { file = "\tg_modules\functions\HarvesterIsEmpty.sqf"; };
			class HarvesterIsFull { file = "\tg_modules\functions\HarvesterIsFull.sqf"; };
			class HarvesterSetActivity { file = "\tg_modules\functions\HarvesterSetActivity.sqf"; };
			class HarvesterSetCapacity { file = "\tg_modules\functions\HarvesterSetCapacity.sqf"; };
			class HarvesterSetOwner { file = "\tg_modules\functions\HarvesterSetOwner.sqf"; };
			class HarvesterSetPreviousPosition { file = "\tg_modules\functions\HarvesterSetPreviousPosition.sqf"; };
			class HarvesterUnloadOneTick { file = "\tg_modules\functions\HarvesterUnloadOneTick.sqf"; };
			class HarvesterMoveTo { file = "\tg_modules\functions\HarvesterMoveTo.sqf"; };
			class HarvesterMoveToCompleted { file = "\tg_modules\functions\HarvesterMoveToCompleted.sqf"; };
		};
		class Tiberium {
			class TiberiumAddSpawner { file = "\tg_modules\functions\TiberiumAddSpawner.sqf"; };
			class TiberiumGetSpawners { file = "\tg_modules\functions\TiberiumGetSpawners.sqf"; };
			class TiberiumGardener { file = "\tg_modules\functions\TiberiumGardener.sqf"; };
			class TiberiumGetChildrenPos { file = "\tg_modules\functions\TiberiumGetChildrenPos.sqf"; };
			class TiberiumSpawnCrystal { file = "\tg_modules\functions\TiberiumSpawnCrystal.sqf"; };
		};
		class Curator {
			class BuildingDefs { file = "\tg_modules\functions\BuildingDefs.sqf"; };
			class CuratorAddMoney { file = "\tg_modules\functions\CuratorAddMoney.sqf"; };
			class CuratorSetMoney { file = "\tg_modules\functions\CuratorSetMoney.sqf"; };
			class CuratorGetMoney { file = "\tg_modules\functions\CuratorGetMoney.sqf"; };
			class CuratorGetMaxMoney { file = "\tg_modules\functions\CuratorGetMaxMoney.sqf"; };
			class CuratorSetBuildingDefs { file = "\tg_modules\functions\CuratorSetBuildingDefs.sqf"; };
			class CuratorGetBuildingDefs { file = "\tg_modules\functions\CuratorGetBuildingDefs.sqf"; };
			class CuratorUpdateBuildingArea { file = "\tg_modules\functions\CuratorUpdateBuildingArea.sqf"; };
			class CuratorGetCanBeBuiltClasses { file = "\tg_modules\functions\CuratorGetCanBeBuiltClasses.sqf"; };
			class CuratorUpdateBuildingList { file = "\tg_modules\functions\CuratorUpdateBuildingList.sqf"; };
			class CuratorObjectPlaced { file = "\tg_modules\functions\CuratorObjectPlaced.sqf"; };
			class CuratorObjectDeleted { file = "\tg_modules\functions\CuratorObjectDeleted.sqf"; };
			class CuratorObjectSelectionChanged { file = "\tg_modules\functions\CuratorObjectSelectionChanged.sqf"; };
			class CuratorConvertMoneyToPoints { file = "\tg_modules\functions\CuratorConvertMoneyToPoints.sqf"; };
			class CuratorUpdateCuratorPoints { file = "\tg_modules\functions\CuratorUpdateCuratorPoints.sqf"; };
			class CuratorReopenDisplay { file = "\tg_modules\functions\CuratorReopenDisplay.sqf"; };
		};
		class CommonFunctions
		{
			class AnimateConstruction { file = "\tg_modules\functions\AnimateConstruction.sqf"; };
			class MakeSingletone { file = "\tg_modules\functions\MakeSingletone.sqf"; };
			class AnimationSequence { file = "\tg_modules\functions\AnimationSequence.sqf"; };
			class LerpVector { file = "\tg_modules\functions\LerpVector.sqf"; };
			class GetBoundingBoxDiscrete { file = "\tg_modules\functions\GetBoundingBoxDiscrete.sqf"; };
			class ConstructionEmerge { file = "\tg_modules\functions\ConstructionEmerge.sqf"; };
			class CheckIntersection { file = "\tg_modules\functions\CheckIntersection.sqf"; };
			class IsFlatEmpty { file = "\tg_modules\functions\IsFlatEmpty.sqf"; };
			class DistanceBetweenArrays { file = "\tg_modules\functions\DistanceBetweenArrays.sqf"; };
			class SoundQueue_Add { file = "\tg_modules\functions\SoundQueue_Add.sqf"; };
			class SoundQueue_Loop { file = "\tg_modules\functions\SoundQueue_Loop.sqf"; };
			class GetCorners { file = "\tg_modules\functions\GetCorners.sqf"; };
			class GetSyncedSide { file = "\tg_modules\functions\GetSyncedSide.sqf"; };
		};
		class Jukebox {
			class JukeboxPlayMusic { file = "\tg_modules\functions\JukeboxPlayMusic.sqf"; };
		};
	};
};

class CfgVehicles {
	
	class Logic;
	class Module_F: Logic
	{
		class AttributesBase
		{
			class Default;
			class Edit; // Default edit box (i.e., text input field)
			class Combo; // Default combo box (i.e., drop-down menu)
			class Checkbox; // Default checkbox (returned value is Bool)
			class CheckboxNumber; // Default checkbox (returned value is Number)
			class ModuleDescription; // Module description
			class Units; // Selection of units on which the module is applied
		};
		// Description base classes
		class ModuleDescription
		{
			class Anything;
			class AnyBrain;
		};
	};
	
	class TG_Module : Module_F {
		author = "Tiberian Genesis Team";
		scope = 1;
		is3DEN = 0;
		displayName = "Tiberian Genesis Module";
		category = "tg_mod";
	};
	
	// +++++++++++++++++++++++++++++++++++ \\
	// 				 Tiberium			   \\
	// +++++++++++++++++++++++++++++++++++ \\
	
	class TG_ModuleTiberiumGardener : TG_Module {
		_generalMacro = "TG_ModuleTiberiumGardener";
		scope = 2;
		isDisposable = 1; // 1 if modules is to be disabled once it's activated (i.e., repeated trigger activation won't work)
		isGlobal = 0; // 0 for server only execution, 1 for global execution, 2 for persistent global execution
		displayName = "Tiberium Gardener";
		function = "TG_fnc_ModuleTiberiumGardener";
		class ModuleDescription : ModuleDescription {
			description = "This module is required for Tiberium crystals to be grown. Configures Tiberium growth. This is a global module, so place only one per mission. If you add a Tiberium spawner without placing Tiberium Gardener Module, you will get an error message at the start of mission.";
		};
		class Arguments {
			class GrowthSleep {
				displayName = "Tiberium spread speed";
				description = "Minimum time in seconds before planting a new crystal";
				typeName = "NUMBER";
				defaultValue = 1;
			};
			class GrowthRndSleep {
				displayName = "Random time addition";
				description = "A random addition to the value from the field above";
				typeName = "NUMBER";
				defaultValue = 1;
			};
			class CrystalDistance {
				displayName = "Minimum distance between crystals";
				description = "Greater values will spawn crystals further from each other";
				typeName = "NUMBER";
				defaultValue = 2;
			};
			class HideObjectRadius {
				displayName = "Terrain objects removal";
				description = "Upon being planted, the crystals will remove all terrain objects (bushes, rocks, small trees) in this radius";
				typeName = "NUMBER";
				defaultValue = 6;
			};
			class SteepnessLimit {
				displayName = "Maximum steepness";
				description = "Tiberium will grow until it encounters a slope. Increasing this value will allow Tiberium to grow up- and downhill more eagerly. Value in range [0-1]";
				typeName = "NUMBER";
				defaultValue = 0.2;
			};
			class ChildrenPerFather {
				displayName = "Children count";
				description = "Each Tiberium crystal will spawn this amount of children before going dormant";
				typeName = "NUMBER";
				defaultValue = 2;
			};
			class GreenTiberiumPhaseTime {
				displayName = "Green Tiberium phase time";
				description = "Time needed for the seedling to grow into a medium crystal, and for a medium to turn into a fully matured crystal";
				typeName = "NUMBER";
				defaultValue = 32;
			};
			class BlueTiberiumPhaseTime {
				displayName = "Blue Tiberium phase time";
				description = "Time needed for the seedling to grow into a medium crystal, and for a medium to turn into a fully matured crystal";
				typeName = "NUMBER";
				defaultValue = 64;
			};
			class PurpleTiberiumPhaseTime {
				displayName = "Purple Tiberium phase time";
				description = "Time needed for the seedling to grow into a medium crystal, and for a medium to turn into a fully matured crystal";
				typeName = "NUMBER";
				defaultValue = 128;
			};
			class RedTiberiumPhaseTime {
				displayName = "Red Tiberium phase time";
				description = "Time needed for the seedling to grow into a medium crystal, and for a medium to turn into a fully matured crystal";
				typeName = "NUMBER";
				defaultValue = 128;
			};
		};
	};
	
	class TG_ModuleTiberiumCrystalLight : TG_Module {
		_generalMacro = "TG_ModuleTiberiumCrystalLight";
		scope = 2;
		is3DEN = 1;
		displayName = "Spawn Tiberium Light";
		function = "TG_fnc_ModuleTiberiumCrystalLight";
		class ModuleDescription : ModuleDescription {
			description = "Spawns Tiberium light wherever the module is placed, or attaches lights to synced objects. Arma supports only a few concurrent lights being on screen at a time, so be humble with the amount of lights you place, otherwise the lights will start flickering. This module is intended to use in situations where you have only a few crystals (1-5 crystals inside a room or a cave, etc) and you can afford adding a light to every single crystal in that space.";
			sync[] = {"Anything"};
			class Anything : Anything {
				optional = 0;
			};
		};
		class Arguments {
			class CrystalColor {
				displayName = "Tiberium type";
				description = "Select color of the Tiberium light";
				typeName = "NUMBER";
				class values {
					class TiberiumGreen {
						name = "Green Tiberium";
						value = 0;
						default = 1;
					};
					class TiberiumBlue {
						name = "Blue Tiberium";
						value = 1;
					};
					class TiberiumPurple {
						name = "Purple Tiberium";
						value = 2;
					};
					class TiberiumRed {
						name = "Red Tiberium";
						value = 3;
					};
				};
			};
			class Brightness {
				displayName = "Light brightness";
				description = "The default value is recommended for single crystals.";
				typeName = "NUMBER";
				defaultValue = 0.07;
			};
			class AttachToSynced {
				displayName = "Attach light to synced objects";
				description = "If true, light will be created and attached to all synced objects. If false, light will be created and attached to the module.";
				typeName = "BOOL";
				defaultValue = "false"; 
			};
		};
	};
	
	class TG_ModuleTiberiumCrystalValue : TG_Module {
		_generalMacro = "TG_ModuleTiberiumCrystalValue";
		scope = 2;
		displayName = "Tiberium Value";
		function = "TG_fnc_ModuleTiberiumCrystalValue";
		class ModuleDescription : ModuleDescription {
			description = "Sets amount of $$$ received for delivering Tiberium crystals to the Refinery. This is a global module, so place only one per mission.";
		};
		class Attributes : AttributesBase {
			class Green : Edit { //["Default"]
				property = "GreenTiberiumCost";
				displayName = "Green Tiberium";
				tooltip = "The profits from processing Tiberium crystals in Refinery. The cost is for seedling, medium and mature crystals accordingly";
				//control = "EditShort"; // For shorter input field
				defaultValue = "[192, 326, 600]";
			};
			class Blue : Edit { //["Default"]
				property = "BlueTiberiumCost";
				displayName = "Blue Tiberium";
				tooltip = "The profits from processing Tiberium crystals in Refinery. The cost is for seedling, medium and mature crystals accordingly";
				//control = "EditShort"; // For shorter input field
				defaultValue = "[384, 652, 1200]";
			};		
			class Purple : Edit { //["Default"]
				property = "PurpleTiberiumCost";
				displayName = "Purple Tiberium";
				tooltip = "The profits from processing Tiberium crystals in Refinery. The cost is for seedling, medium and mature crystals accordingly";
				//control = "EditShort"; // For shorter input field
				defaultValue = "[768, 1304, 2400]";
			};	
			class Red : Edit { //["Default"]
				property = "RedTiberiumCost";
				displayName = "Red Tiberium";
				tooltip = "The profits from processing Tiberium crystals in Refinery. The cost is for seedling, medium and mature crystals accordingly";
				//control = "EditShort"; // For shorter input field
				defaultValue = "[0, 0, 0]";
			};
		};
	};
	
	class TG_ModuleTiberiumAddSpawner : TG_Module {
		_generalMacro = "TG_ModuleTiberiumAddSpawner";
		scope = 2;
		is3DEN = 1;
		displayName = "Add Tiberium Spawner";
		function = "TG_fnc_ModuleTiberiumAddSpawner";
		class ModuleDescription : ModuleDescription {
			description = "Makes synced object(s) spawn Tiberium. If everything is right, you should see a circle being drawn around the objects you synchronized. The circle is a visual representation of the maximum radius the field can take. This module only marks objects as Tiberium spawners, the actual growth of Tiberium crystals is directed by Tiberium Gardener Module. If you place this module without having Tiberium Gardener Module, you will get an error at the start of the mission.";
			sync[] = {"Anything"};
			class Anything : Anything {
				optional = 0;
			};
		};
		class Arguments {
			class CrystalColor {
				displayName = "Tiberium type";
				description = "What Tiberium should the synced object(s) spawn";
				typeName = "NUMBER";
				class values {
					class TiberiumGreen {
						name = "Green Tiberium";
						value = 0;
						default = 1;
					};
					class TiberiumBlue {
						name = "Blue Tiberium";
						value = 1;
					};
					class TiberiumPurple {
						name = "Purple Tiberium";
						value = 2;
					};
					class TiberiumRed {
						name = "Red Tiberium";
						value = 3;
					};
				};
			};
			class Radius {
				displayName = "Field radius";
				description = "Maximum distance from the initial source of this Tiberium field. Setting to 0 disables any limits and allows Tiberium to spread uncontrollably";
				typeName = "NUMBER";
				defaultValue = 50;
			};
		};
	};
	
	class TG_ModuleTiberiumDamage : TG_Module {
		_generalMacro = "TG_ModuleTiberiumDamage";
		scope = 2;
		displayName = "Tiberium Damage";
		function = "TG_fnc_ModuleTiberiumDamage";
		isDisposable = 1; // 1 if modules is to be disabled once it's activated (i.e., repeated trigger activation won't work)
		isGlobal = 0; // 0 for server only execution, 1 for global execution, 2 for persistent global execution
		class ModuleDescription : ModuleDescription {
			description = "Place this module to make Tiberium crystals damage or heal infantry. You can specify Protective Items that grant immunity from Tiberium toxins as well as objects or creatures the killed soldiers will be respawned as. In order to protect the wearer, the protective items will have to be equipped (not in inventory). The Protective Items should be an array of strings that may include headgear, goggles, uniform or vest classes.";
			sync[] = {};
		};
		class Attributes : AttributesBase {
			class Radius : Edit {
				property = "ModuleTiberiumDamage_Radius";
				displayName = "Crystal damage radius";
				tooltip = "Minimal distance from the crystal at which the unit begins to receive damage";
				typeName = "NUMBER";
				defaultValue = 6;
			};
			class Damage : Edit {
				property = "ModuleTiberiumDamage_Damage";
				displayName = "Damage per crystal";
				tooltip = "Must be a positive number. Each crystal within Radius will contribute this amount of damage to the unit's health per tick. Value of 1.0 will insta-kill the unit.";
				typeName = "NUMBER";
				defaultValue = 0.05;
			};
			class HealedClasses : Edit {
				property = "ModuleTiberiumDamage_HealedClasses";
				displayName = "Units that get healed";
				tooltip = "Array of classes of units that get healed instead of damaged. Example: ['classname1', 'classname2']";
				defaultValue = "[]";
			};
			class ProtectiveItems : Edit {
				property = "ModuleTiberiumDamage_ProtectiveItems";
				displayName = "Protective items";
				tooltip = "Array of classes of headgears, goggles, uniforms or vests that protect from Tiberium toxin damage. Will only protect while equipped (worn). Example: ['classname1', 'classname2']";
				defaultValue = "[]";
			};
			class ResurrectInfantry : CheckboxNumber { //["Default"]
				property = "ModuleTiberiumDamage_ResurrectInfantry";
				displayName = "Resurrect infantry killed by toxins";
				tooltip = "If the unit is killed by Tiberium toxins (not explosions), something or SOMEONE can be spawned in its place";
				typeName = "NUMBER";
				defaultValue = 0;
			};
			class CustomResurrect : Edit {
				property = "ModuleTiberiumDamage_CustomResurrect";
				displayName = "Custom resurrection classes";
				tooltip = "Format [['classname', side, weight],...]. All classnames must be either playable by player or be a vehicle\object! Weight is a positive probability-related number, 'heavier' classnames get spawned more often. All PRESET classes have a default weight of 1.0 and side INDEPENDENT.";
				defaultValue = "[]";
			};
			class ResurrectPreset: Combo {
				property = "ModuleTiberiumDamage_ResurrectPreset";
				displayName = "Resurrection preset"; 
				tooltip = "If the field above is too scary for you! Works in conjunction with the field above. However, the side of these preset units is hardcoded to always be INDEPENDENT (GUER).";
				typeName = "NUMBER"; 
				defaultValue = "0"; // WARNING: This is an expression, and its returned value will be used
				class Values
				{
					class Option_00 {
						name = "None";
						value = 0;
						default = 1;
					};
					class Option_01 {
						name = "Tiberian Genesis: Visceroids (does nothing right now)";
						value = 1;
					};
					class Option_02 {
						name = "Addon: Zombies and Demons by Ryan (spawn as zombie)";
						value = 2;
					};
					class Option_03 {
						name = "Addon: Max_Alien by Maxjoiner (spawn as alien)";
						value = 3;
					};
				};
			};
		};
	};
	
	class TG_ModuleCuratorRTS : TG_Module {
		_generalMacro = "TG_ModuleCuratorRTS";
		scope = 2;
		displayName = "Curator RTS";
		function = "TG_fnc_ModuleCuratorRTS";
		isDisposable = 1; // 1 if modules is to be disabled once it's activated (i.e., repeated trigger activation won't work)
		isGlobal = 2; // 0 for server only execution, 1 for global execution, 2 for persistent global execution
		
		simulation = "curator";
		vehicleClass = "Modules";
		functionPriority = 1;
		icon = "\a3\Modules_F_Curator\Data\iconCurator_ca.paa";
		portrait = "\a3\Modules_F_Curator\Data\portraitCurator_ca.paa";
		
		class Attributes : AttributesBase {
			class Owner : Edit { //["Default"]
				displayName = "Owner";
				tooltip = "Unit with access to the Zeus interface. Can be an objectâ€™s variable name, player UID, or you can use #adminLogged or #adminVoted to give access to the server admin.";
				property = "ModuleCurator_F_Owner";
			};
			class Name : Edit { //["Default"]
				displayName = "Name";
				tooltip = "Custom name displayed for other players";
				property = "ModuleCurator_F_Name";
			};
			class Forced : CheckboxNumber { //["Default"]
				displayName = "Forced interface";
				tooltip = "Open the interface by default and prevent the player from closing it.";
				property = "ModuleCurator_F_Forced";
			};
			class ModuleDescription : ModuleDescription {};
		};
		class Arguments {
			class Owner {
				displayName = "Owner";
				description = "Unit with access to the Zeus interface. Can be an objectâ€™s variable name, player UID, or you can use #adminLogged or #adminVoted to give access to the server admin.";
				defaultValue = "";
			};
			class Name {
				displayName = "Name";
				description = "Custom name displayed for other players";
				defaultValue = "";
			};
			class Forced {
				displayName = "Forced interface";
				description = "Open the interface by default and prevent the player from closing it.";
				typeName = "NUMBER";
				class values {
					class Enabled {
						name = "Enabled";
						value = 1;
					};
					class Disabled {
						name = "Disabled";
						value = 0;
						default = 1;
					};
				};
			};
		};
		
		class ModuleDescription : ModuleDescription {
			description = "";
			sync[] = {};
		};
	};
	
	// +++++++++++++++++++++++++++++++++++ \\
	// 				 Jukebox			   \\
	// +++++++++++++++++++++++++++++++++++ \\
	
	class TG_ModuleJukebox : TG_Module {
		_generalMacro = "TG_ModuleJukebox";
		scope = 2;
		displayName = "Jukebox";
		function = "TG_fnc_ModuleJukebox";
		isDisposable = 1; // 1 if modules is to be disabled once it's activated (i.e., repeated trigger activation won't work)
		isGlobal = 0; // 0 for server only execution, 1 for global execution, 2 for persistent global execution
		class ModuleDescription : ModuleDescription {
			description = "Module that runs on server and broadcasts music tracks to all connected clients. Supports conditions and can be easily scripted to play specific tracks when certain conditions are met. Has custom coded built-in mechanism that protects from repeating same tracks too often: each track has a probability to be played which increases every time the track wasn't selected. When selecting a copyrighted music preset, a copyright message will be shown in systemChat, which can not be disabled. This is one of the restrictions EA imposed on us to let us use their copyrighted content.";
			sync[] = {};
		};
		class Attributes : AttributesBase {
			class AnnounceTracks : CheckboxNumber { //["Default"]
				property = "ModuleJukebox_AnnounceTracks";
				displayName = "Announce tracks";
				tooltip = "Announce track names in system chat";
				typeName = "NUMBER";
				defaultValue = 0;
			};
			class Preset: Combo {
				property = "ModuleJukebox_Preset";
				displayName = "Preset"; // Argument label
				tooltip = "A quick way to setup the general mood of the tracks played"; // Tooltip description
				typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
				defaultValue = "0"; // Default attribute value. WARNING: This is an expression, and its returned value will be used (50 in this case)
				class Values
				{
					class AllTracks {
						name = "All Tiberian Genesis tracks";
						value = 0;
						default = 1;
					};
					class Stealth {
						name = "Stealth Tiberian Genesis tracks";
						value = 1;
					};
					class Action {
						name = "Action Tiberian Genesis tracks";
						value = 2;
					};
					class Custom {
						name = "Custom tracks";
						value = 3;
					};
				};
			};
			class CustomTracks: Edit {
				property = "ModuleJukebox_CustomTracks";
				displayName = "Custom tracks";
				tooltip = "If preset is set to Custom, the tracks from this array are played instead";
				defaultValue = "['LeadTrack01_F_EPA', 'LeadTrack04_F_EPC']";
			};	
			class StartCondition: Edit {
				property = "ModuleJukebox_StartCondition";
				displayName = "Start condition";
				tooltip = "Condition that has to be true in order for this module to start working. Condition is checked every second and only on Server";
				defaultValue = "true";
			};
			class StopCondition: Edit {
				property = "ModuleJukebox_StopCondition";
				displayName = "Stop condition";
				tooltip = "Condition that has to be true in order for this module to stop working, after which the module will delete itself. Condition is checked every second and only on Server";
				defaultValue = "false";
			};
			class LoopConditions : CheckboxNumber { //["Default"]
				property = "ModuleJukebox_LoopConditions";
				displayName = "Loop conditions";
				tooltip = "If enabled, instead of deleting itself, the module will restart after Stop Condition turned true. It allows a cycle: Start Condition -> Stop Condition -> Start Condition -> etc. Use this if you want to be able to stop and resume the work of the module";
				typeName = "NUMBER";
				defaultValue = 0;
			};
			class StopMusic : CheckboxNumber { //["Default"]
				property = "ModuleJukebox_StopMusic";
				displayName = "Stop music when finished";
				tooltip = "The track that was playing when Stop Condition evaluated true will be silenced. Uses fadeMusic.";
				typeName = "NUMBER";
				defaultValue = 0;
			};
			class DisableACEVolumeUpdate : CheckboxNumber { //["Default"]
				property = "ModuleJukebox_DisableACEVolumeUpdate";
				displayName = "Disable ACE volume update";
				tooltip = "Enable this if you are having issues with fadeMusic when running ACE (ACE prevents correct use of fadeMusic command)";
				typeName = "NUMBER";
				defaultValue = 0;
			};
		};
	};
	
	class TG_ModuleREADME : TG_Module {
		_generalMacro = "TG_ModuleREADME";
		scope = 2;
		displayName = "README Module (Instructions)";
		function = "TG_fnc_ModuleREADME";
		isDisposable = 1; // 1 if modules is to be disabled once it's activated (i.e., repeated trigger activation won't work)
		isGlobal = 2; // 0 for server only execution, 1 for global execution, 2 for persistent global execution
		class ModuleDescription : ModuleDescription {
			description = "Pulls module descriptions and their syncable objects from configFile and displays them as entries in your journal (if you are reading this text, you are probably already aware of that). Intended to be used only when figuring out how modules work and checking module's syncable objects. Don't forget to delete this module before sending your mission to players, because otherwise they will have entries in journal that are unrelated to gameplay.";
			sync[] = {};
		}; 
	};
	
	// +++++++++++++++++++++++++++++++++++++++ \\
	// 				 Superweapons			   \\
	// +++++++++++++++++++++++++++++++++++++++ \\
	
	class TG_IonCannon_Module : TG_Module {
		_generalMacro = "TG_IonCannon_Module";
		scope = 2;
		isDisposable = 1; // 1 if modules is to be disabled once it's activated (i.e., repeated trigger activation won't work)
		isGlobal = 1; // 0 for server only execution, 1 for global execution, 2 for persistent global execution
		displayName = "Ion Cannon";
		function = "TG_fnc_ModuleIonCannon";
		class ModuleDescription : ModuleDescription {
			description = "Module that creates Ion Beam at its coordinates.";
			sync[] = {};
		};
		class Attributes : AttributesBase {
			class beamColour : Edit {
				property = "TG_IonCannon_Module_beamColour";
				displayName = "Beam Colour";
				tooltip = "";
				defaultValue = "[0.2,0.6,1]";
			};
			class debrisColour : Edit {
				property = "TG_IonCannon_Module_debrisColour";
				displayName = "Debris Colour";
				tooltip = "";
				defaultValue = "[0.3, 0.27, 0.15]";
			};
		};
	};
	
	class TG_AtmosphereChanger_Module : TG_Module {
		_generalMacro = "TG_AtmosphereChanger_Module";
		scope = 2;
		is3DEN = 1;
		isDisposable = 1; // 1 if modules is to be disabled once it's activated (i.e., repeated trigger activation won't work)
		isGlobal = 2; // 0 for server only execution, 1 for global execution, 2 for persistent global execution
		displayName = "Atmosphere Changer";
		function = "TG_fnc_ModuleAtmosphereChanger";
		class ModuleDescription : ModuleDescription {
			description = "Module that can change how atmosphere looks like when certain conditions are met, and\or player enters certain areas.";
			sync[] = {};
		};
		class Attributes : AttributesBase {
			class Radius : Edit {
				property = "ModuleAtmosphereChanger_Radius";
				displayName = "Radius";
				tooltip = "If this is > 0, the atmospheric changes will occur only while the player is within this radius. If radius = 0, the changes are happening globally on the whole map.";
				typeName = "NUMBER";
				defaultValue = 0;
			};
			class Preset: Combo {
				property = "ModuleAtmosphereChanger_Preset";
				displayName = "Preset"; // Argument label
				tooltip = "A quick way to setup the general mood of the atmospheric changes."; // Tooltip description
				typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
				defaultValue = "0"; // Default attribute value. WARNING: This is an expression, and its returned value will be used (50 in this case)
				class Values
				{
					class TiberiumFog {
						name = "Tiberium fog";
						value = 0;
						default = 1;
					};
				};
			};
			class ColorTint: Edit {
				property = "ModuleAtmosphereChanger_ColorTint";
				displayName = "RGBA Color Tint";
				tooltip = "Format is [Red, Green, Blue, Brightness]. The bigger the color number, the more prevalent this color component will be. In other words, for the picture to have green tint, make the Green component slightly bigger than the other two.";
				defaultValue = "[1,1.2,1,1]";
			};
			class FogParams: Edit {
				property = "ModuleAtmosphereChanger_ColorTint";
				displayName = "Fog Parameters";
				tooltip = "Format is [_fogValue, _fogDecay, _fogBase]. If you don't want fog to spawn, leave this empty ([]). If you want to use module's height for _fogBase, simply don't specify the third element of the array ([_fogValue, _fogDecay]).";
				defaultValue = "[1,1.2,1,1]";
			};
			class ToxicClouds: CheckboxNumber {
				property = "ModuleAtmosphereChanger_ToxicClouds";
				displayName = "RGBA Color tint";
				tooltip = "";
				defaultValue = "1";
			};
			
			class StartCondition: Edit {
				property = "ModuleAtmosphereChanger_StartCondition";
				displayName = "Start condition";
				tooltip = "Condition that has to be true in order for this module to start working. Condition is checked every second, locally.";
				defaultValue = "true";
			};
			class StopCondition: Edit {
				property = "ModuleAtmosphereChanger_StopCondition";
				displayName = "Stop condition";
				tooltip = "Condition that has to be true in order for this module to stop working, after which the module will delete itself. Condition is checked every second, locally.";
				defaultValue = "false";
			};
			class LoopConditions : CheckboxNumber { //["Default"]
				property = "ModuleAtmosphereChanger_LoopConditions";
				displayName = "Loop conditions";
				tooltip = "If enabled, instead of deleting itself, the module will restart after Stop Condition turned true. It allows a cycle: Start Condition -> Stop Condition -> Start Condition -> etc. Use this if you want to be able to stop and resume the work of the module.";
				typeName = "NUMBER";
				defaultValue = 1;
			};
		};
	};
	
	class TG_IonStorm_Module : TG_Module {
		_generalMacro = "TG_IonStorm_Module";
		scope = 2;
		is3DEN = 1;
		isDisposable = 1; // 1 if modules is to be disabled once it's activated (i.e., repeated trigger activation won't work)
		isGlobal = 1; // 0 for server only execution, 1 for global execution, 2 for persistent global execution
		displayName = "Ion Storm";
		function = "TG_fnc_ModuleIonStorm";
		class ModuleDescription : ModuleDescription {
			description = "";
			sync[] = {};
		};
		class Attributes : AttributesBase {
			class Radius : Edit {
				property = "ModuleIonStorm_Radius";
				displayName = "Radius";
				tooltip = "Radius of the Ion Storm";
				typeName = "NUMBER";
				defaultValue = 200;
			};
			class Rain: CheckboxNumber {
				property = "ModuleIonStorm_Rain";
				displayName = "Rain";
				tooltip = "Enables rain during Ion Storm.";
				typeName = "NUMBER";
				defaultValue = "1";
			};
			class HitProbability: Edit {
				property = "ModuleIonStorm_HitProbability";
				displayName = "Bolt hit probability";
				tooltip = "Number from 0 to 1. 0 is completely random, inaccurate bolts, while 1 represents bolts striking only buildings \ vehicles \ units.";
				typeName = "NUMBER";
				defaultValue = "0.5";
			};
			class ConstantTimeBetweenBolts: Edit {
				property = "ModuleIonStorm_ConstantTimeBetweenBolts";
				displayName = "Constant delay betwen bolts";
				tooltip = "Time in seconds between bolts of lightning.";
				typeName = "NUMBER";
				defaultValue = "1";
			};
			class RandomAdditionTimeBetweenBolts: Edit {
				property = "ModuleIonStorm_RandomAdditionTimeBetweenBolts";
				displayName = "Random delay between bolts";
				tooltip = "Random delay between bolts. The total time = constant + from 0 to random sec.";
				typeName = "NUMBER";
				defaultValue = "3";
			};
			class NumberOfBolts: Edit {
				property = "ModuleIonStorm_NumberOfBolts";
				displayName = "Number of bolts";
				tooltip = "Set to 0 if you want to control the length of the Ion Storm by Conditions below instead.";
				typeName = "NUMBER";
				defaultValue = "20";
			};
			
			class StartCondition: Edit {
				property = "ModuleIonStorm_StartCondition";
				displayName = "Start condition";
				tooltip = "Condition that has to be true in order for this module to start working. Condition is checked every second, locally.";
				defaultValue = "true";
			};
			class StopCondition: Edit {
				property = "ModuleIonStorm_StopCondition";
				displayName = "Stop condition";
				tooltip = "Condition that has to be true in order for this module to stop working, after which the module will delete itself. Condition is checked every second, locally.";
				defaultValue = "false";
			};
			class LoopConditions : CheckboxNumber { 
				property = "ModuleIonStorm_LoopConditions";
				displayName = "Loop conditions";
				tooltip = "If enabled, instead of deleting itself, the module will restart after Stop Condition turned true. It allows a cycle: Start Condition -> Stop Condition -> Start Condition -> etc. Use this if you want to be able to stop and resume the work of the module.";
				typeName = "NUMBER";
				defaultValue = 0;
			};
		};
	};
};
