
#define TG_ADDON_DEPENDENCY_MUSIC "tg_music"

class CfgPatches
{
	class tg_modules
	{
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {"tg_core", "tg_obj"};
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
			class ModuleTiberiumGardener {
				file = "\tg_modules\Modules\ModuleTiberiumGardener.sqf";
			};
			class ModuleTiberiumAddSpawner {
				file = "\tg_modules\Modules\ModuleTiberiumAddSpawner.sqf";
			};
			class VisualizeModuleRadius3DEN {
				file = "\tg_modules\Modules\VisualizeModuleRadius3DEN.sqf";
			};
			class ModuleTiberiumDamage {
				file = "\tg_modules\Modules\ModuleTiberiumDamage.sqf";
			};
			class ModuleAICommander {
				file = "\tg_modules\Modules\ModuleAICommander.sqf";
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
		/*
		class JukeBox 
		{
			class JukeboxAddPlayer {
				file = "\tg_modules\functions\Jukebox.sqf";
				requiredAddons[] = {TG_ADDON_DEPENDENCY_MUSIC};
			};
		};
		*/
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
				defaultValue = 3;
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
	
	/*
	class TG_ModuleJukebox_Base : TG_Module {
		//requiredAddons[] = {TG_ADDON_DEPENDENCY_MUSIC};
		isDisposable = 1; // 1 if modules is to be disabled once it's activated (i.e., repeated trigger activation won't work)
		isGlobal = 0; // 0 for server only execution, 1 for global execution, 2 for persistent global execution
	};
	
	class TG_ModuleJukeboxAddPlayer : TG_ModuleJukebox_Base {
		_generalMacro = "TG_ModuleJukeboxAddPlayer";
		scope = 2;
		displayName = "Add Jukebox";
		function = "";
		class ModuleDescription : ModuleDescription {
			description = "";
			sync[] = {};
		};
		class Attributes : AttributesBase {
			class TrackSelection: Combo {
				property = "ModuleJukeboxAddPlayer_TrackSelection";
				displayName = "Track selection"; // Argument label
				tooltip = "How the new track is selected. Random Weighted means the tracks that haven't been played for a while will have a better chance of selection"; // Tooltip description
				typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
				defaultValue = "0"; // Default attribute value. WARNING: This is an expression, and its returned value will be used 
				class Values {
					class Random {
						name = "Random Wighted";
						value = 0;
						default = 1;
					};
				};
			};
			class Enabled : CheckboxNumber { //["Default"]
				property = "ModuleJukeboxAddPlayer_Enabled";
				displayName = "Enabled";
				tooltip = "Synced objects will start playing music immediately after mission start";
				typeName = "NUMBER";
				defaultValue = 0;
			};
			class SameStation : CheckboxNumber { //["Default"]
				property = "ModuleJukeboxAddPlayer_SameStation";
				displayName = "Same station";
				tooltip = "If enabled, all synced objects will always be playing the same track";
				typeName = "NUMBER";
				defaultValue = 0;
			};
			class Radius : Edit {
				property = "ModuleJukeboxAddPlayer_Radius";
				displayName = "Radius";
				tooltip = "Maximum distance from the emitter at which the the music is audible";
				typeName = "NUMBER";
				defaultValue = 30;
			};
		};
	};
	*/
	
	/*
	class TG_ModuleCommander : TG_Module {
		_generalMacro = "TG_ModuleCommander";
		scope = 2;
		is3DEN = 1;
		displayName = "AI Commander";
		function = "TG_fnc_ModuleCommander";
		isDisposable = 1; // 1 if modules is to be disabled once it's activated (i.e., repeated trigger activation won't work)
		isGlobal = 0; // 0 for server only execution, 1 for global execution, 2 for persistent global execution

		class Attributes : AttributesBase {
			class CommanderName : Edit {
				property = "TG_ModuleCommander_Name";
				displayName = "Name (optional)";
				tooltip = "Must be unique. Use '['%COMMANDERNAME%', this] call TG_fnc_CommanderClaim;' in init fields of units you want to be controlled by this commander";
				defaultValue = "format['Commander%1', round random 1000000]";
			};
			
			class Side: Combo
  			{
				// Unique property, use "<moduleClass>_<attributeClass>" format to make sure the name is unique in the world
				property = "TG_ModuleCommander_Side";
				displayName = "Side"; // Argument label
				tooltip = "Side of this AI commander"; // Tooltip description
				typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
				defaultValue = "0"; // Default attribute value. WARNING: This is an expression, and its returned value will be used (50 in this case)
				class Values
				{
					class WEST {
						name = "GDI (BLUFOR)";
						value = 0;
						default = 1;
					};
					class EAST {
						name = "NOD (OPFOR)";
						value = 1;
					};
					class GUER {
						name = "Independent";
						value = 2;
					};
				};
			};
			
			class Preset: Combo
  			{
				// Unique property, use "<moduleClass>_<attributeClass>" format to make sure the name is unique in the world
				property = "TG_ModuleCommander_Difficulty";
				displayName = "Preset"; // Argument label
				tooltip = "How difficult it is to defeat this AI"; // Tooltip description
				typeName = "STRING"; // Value type, can be "NUMBER", "STRING" or "BOOL"
				defaultValue = "Normal"; // Default attribute value. WARNING: This is an expression, and its returned value will be used (50 in this case)
				class Values
				{
					class Easy {
						name = "Easy";
						value = "Easy";
					};
					class Normal {
						name = "Normal";
						value = "Normal";
						default = 1;
					};
					class Hard {
						name = "Hard";
						value = "Hard";
					};
					class Impossible {
						name = "Impossible";
						value = "Impossible";
					};
				};
			};
			class Radius: Edit
  			{
				property = "TG_ModuleCommander_Radius";
				
				displayName = "Claim radius";
				tooltip = "Everything within this radius will be claimed as a property of this commander. Units and vehicles will be taken under control, buildings captured and recolored according to commander's color scheme (if applicable)";
				typeName = "NUMBER";
				defaultValue = 0;
			};	
			class ModuleDescription : ModuleDescription {};
		};
		class ModuleDescription : ModuleDescription {
			description = "AI Commander module. Will take control of all synced entities, entities within Claim Radius, or entities with '['%COMMANDERNAME%', this] call TG_fnc_CommanderClaim;' in their init field. ";
			sync[] = {"Anything"}; // Array of synced entities (can contain base classes)
		};
		
	};
	*/
};
/*
class CfgTGAITemplates 
{
	class Default {
		maxWalls = 10;
		maxTurrets = 5;
		maxTanks = 10;
		maxInfantry = 50;
		priorityWalls = 1;
		priorityTurrets = 1;
		priorityTanks = 1; 
		priorityInfantry = 1;
		aggression = 1; // real priority = [tanks|inf] * aggression 
		incomeMultiplier = 1;
	};
	class Easy : Default {
		maxTurrets = 2;
		maxTanks = 5;
		maxInfantry = 30;
		incomeMultiplier = 0.5;
	};
	class Normal : Default { };
	class Hard : Default {
		incomeMultiplier = 1.5;
	};
	class Impossible : Default {
		maxTurrets = 10;
		maxTanks = 20;
		maxInfantry = 100;
		incomeMultiplier = 2;
	};
	
}; */