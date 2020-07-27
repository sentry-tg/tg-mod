
/*
	Variables for setVariable\getVariable in format:
		Namespace_module_variable-name
*/

	// +++++++++++++++++++++++++++++++++++ \\
	// 				 MODULES			   \\
	// +++++++++++++++++++++++++++++++++++ \\
	
/* Where track pool is stored in the logic's namespace */
#define LOGIC_JUKEBOX_TRACKS_POOL "TG_TRACKS_POOL"

	// +++++++++++++++++++++++++++++++++++ \\
	// 				 Tiberium			   \\
	// +++++++++++++++++++++++++++++++++++ \\
	
/* Stores the type of tiberium this object spawns */
#define SPAWNER_TIBERIUM_TYPEOF "TG_TypeOf"
/* Stores the center of the tiberium field this object belongs to */
#define SPAWNER_TIBERIUM_FIELDCENTER "TG_FieldCenter"
/* Stores the radius of the tiberium field this object belongs to */
#define SPAWNER_TIBERIUM_FIELDRADIUS "TG_FieldRadius"

/* 	
	The name of the global variable that, if defined, 
	prevents other modules of this type to operate, 
	effectively enforcing a singleton pattern 
*/
#define MISSION_MODULE_GARDENER "TG_ModuleTiberiumGardener"
#define MISSION_MODULE_TIBERIUM_CRYSTAL_VALUE "TG_ModuleTiberiumCrystalValue"
#define MISSION_MODULE_TIBERIUM_DAMAGE "TG_ModuleTiberiumDamage"


/* A global variable that stores all tiberium spawners, used by harvesters */
#define MISSION_TIBERIUM_SPAWNERS "TG_TiberiumSpawners"
/* A class from which all tiberium crystals are inherited */
#define TIBERIUM_ROOT_CLASS "TG_Tiberium"
/* Classes, as well as phases of each color of tiberium */
#define TIBERIUM_GREEN ["TG_TiberiumGreen_1_Seedling","TG_TiberiumGreen_1_Medium","TG_TiberiumGreen_1"]
#define TIBERIUM_BLUE ["TG_TiberiumBlue_1_Seedling","TG_TiberiumBlue_1_Medium","TG_TiberiumBlue_1"]
#define TIBERIUM_PURPLE ["TG_TiberiumPurple_1_Seedling","TG_TiberiumPurple_1_Medium","TG_TiberiumPurple_1"]
#define TIBERIUM_RED ["TG_TiberiumRed_1_Seedling","TG_TiberiumRed_1_Medium","TG_TiberiumRed_1"]

	// +++++++++++++++++++++++++++++++++++ \\
	// 				 Harvester			   \\
	// +++++++++++++++++++++++++++++++++++ \\

#define UNITS_HARVESTER_ACTIVITY "Activity"
#define UNITS_HARVESTER_ACTIVITY_IDLE 0
#define UNITS_HARVESTER_ACTIVITY_STANDBY 1
#define UNITS_HARVESTER_OWNER "Owner"
#define UNITS_HARVESTER_CAPACITY "Capacity"
#define UNITS_HARVESTER_MAXCAPACITY "MaxCapacity"
#define UNITS_HARVESTER_PREVIOUS_POSITION "PreviousPosition"
#define UNITS_HARVESTER_PREVIOUS_POSITION_SEARCH_RADIUS 100
#define UNITS_HARVESTER_REFINERY_ROOT_CLASS "Land_dp_mainFactory_F"
#define UNITS_HARVESTER_UNLOAD_TIME 12

	// +++++++++++++++++++++++++++++++++++ \\
	// 				 Curator			   \\
	// +++++++++++++++++++++++++++++++++++ \\

#define CURATOR_BUILDING_DEFS "buildingDefs"

