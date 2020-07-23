
class CfgPatches
{
	class tg_modules
	{
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {"tg_core", "tg_obj", "tg_music"};
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
			class VisualizeModuleRadius3DEN {
				file = "\tg_modules\Modules\VisualizeModuleRadius3DEN.sqf";
			};
			class ModuleTiberiumGardener {
				file = "\tg_modules\Modules\ModuleTiberiumGardener.sqf";
			};
			class ModuleTiberiumAddSpawner {
				file = "\tg_modules\Modules\ModuleTiberiumAddSpawner.sqf";
			};
			class ModuleTiberiumDamage {
				file = "\tg_modules\Modules\ModuleTiberiumDamage.sqf";
			};
			class ModuleAICommander {
				file = "\tg_modules\Modules\ModuleAICommander.sqf";
			};
			class ModuleJukebox {
				file = "\tg_modules\Modules\ModuleJukebox.sqf";
			};

		};
		/*
		class AI {
			class AICommanderInit {
				file = "\tg_modules\RTS\AICommanderInit.sqf";
			};
			class AICommanderClaim {
				file = "\tg_modules\RTS\AICommanderClaim.sqf";
			};
			class AICommanderFindByName {
				file = "\tg_modules\RTS\AICommanderFindByName.sqf";
			};
		};*/
		class Harvester {
			class HarvesterHarvest {
				file = "\tg_modules\functions\HarvesterHarvest.sqf";
			};
		};
		class Tiberium {
			class TiberiumAddSpawner {
				file = "\tg_modules\functions\TiberiumAddSpawner.sqf";
			};
			class TiberiumGetSpawners {
				file = "\tg_modules\functions\TiberiumGetSpawners.sqf";
			};
			class TiberiumGardener {
				file = "\tg_modules\functions\TiberiumGardener.sqf";
			};
			class TiberiumGetChildrenPos {
				file = "\tg_modules\functions\TiberiumGetChildrenPos.sqf";
			};
			class TiberiumSpawnCrystal {
				file = "\tg_modules\functions\TiberiumSpawnCrystal.sqf";
			};
		};
		class CommonFunctions
		{
			class LerpVector {
				file = "\tg_modules\functions\LerpVector.sqf";
			};
			class GetCorners {
				file = "\tg_modules\functions\GetCorners.sqf";
			};
			class GetCornersDiscrete {
				file = "\tg_modules\functions\GetCornersDiscrete.sqf";
			};
			class SinkOrEmerge {
				file = "\tg_modules\functions\SinkOrEmerge.sqf";
			};
			class CheckIntersection {
				file = "\tg_modules\functions\CheckIntersection.sqf";
			};
			class IsFlatEmpty {
				file = "\tg_modules\functions\IsFlatEmpty.sqf";
			};
		};
		class Jukebox {
			class JukeboxPlayMusic {
				file = "\tg_modules\functions\JukeboxPlayMusic.sqf";
			};
			
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
			description = "Required for Tiberium crystals to grow. Configures Tiberium growth. This is a global module, so place only one per mission";
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
	
	class TG_ModuleTiberiumCrystalValue : TG_Module {
		_generalMacro = "TG_ModuleTiberiumCrystalValue";
		scope = 2;
		displayName = "Tiberium Value";
		function = "";
		class ModuleDescription : ModuleDescription {
			description = "Set cost for Tiberium crystals. This is a global module, so place only one per mission";
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
			description = "Makes synced object(s) spawn Tiberium. The module unsyncs the object once it was added to the list of spawners";
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
			description = "Tiberium crystals deal damage to infantry";
			sync[] = {};
		};
		class Attributes : AttributesBase {
			class DamageInfantry : CheckboxNumber { //["Default"]
				property = "ModuleTiberiumDamage_EnableDamage";
				displayName = "Damage to infantry";
				tooltip = "Enable damage to infantry";
				typeName = "NUMBER";
				defaultValue = 1;
			};
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
				tooltip = "Each crystal within Radius will contribute this amount of damage to the unit's health";
				typeName = "NUMBER";
				defaultValue = 0.05;
			};
			class HealedClasses : Edit {
				property = "ModuleTiberiumDamage_HealedClasses";
				displayName = "Units that get healed by Tiberium";
				tooltip = "Array of classes of units that get healed instead of damaged";
				defaultValue = "[]";
			};
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
			description = "Module that runs on server and plays music for all connected clients";
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
};
