
/*
	Variables for setVariable\getVariable in format:
		Namespace_module_variable-name
*/

	// +++++++++++++++++++++++++++++++++++ \\
	// 				 MODULES			   \\
	// +++++++++++++++++++++++++++++++++++ \\
	
/* Where track pool is stored in the logic's namespace */
#define LOGIC_JUKEBOX_TRACKS_POOL "TG_TRACKS_POOL"
#define LOGIC_JUKEBOX_FORCE_ANNOUNCE "TG_FORCE_ANNOUNCE"

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

#define TG_UNIT_IS_IMMUNE_TO_TIBERIUM "TG_UNIT_IS_IMMUNE_TO_TIBERIUM"

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
#define UNITS_HARVESTER_MAX_DIST_TO_CRYSTAL 10
#define UNITS_HARVESTER_MAX_DIST_TO_REFINERY 10
#define UNITS_HARVESTER_UNLOAD_TIME 12
#define MOVE_TO_COMPLETED "reached_the_area"

	// +++++++++++++++++++++++++++++++++++ \\
	// 				 Curator			   \\
	// +++++++++++++++++++++++++++++++++++ \\

#define CURATOR_BUILDING_DEFS "buildingDefs"
#define CURATOR_SIDE "curatorSi"
#define CURATOR_MONEY "curatorMoney"
#define CURATOR_GUI_HANDLER "curatorGUIHandler"
#define CURATOR_CAN_BE_BUILT_CLASSES_PREV "canBeBuiltClassesPrev"
#define CURATOR_CLASSES_BUILT_SO_FAR "canBeBuiltClassesPrev"

//-- Used by addCuratorAddons and activateAddons 
#define CURATOR_ADDONS ["tg_buildings", "tg_defense", "tg_hover", "tg_mechs", "tg_soldiers", "tg_weapons", "tg_wheeled"]

/* Money given to player after building conyard for first time */
#define INITIAL_MONEY 3500
#define CONYARD_CONFIG_NAMES ["GDI_ConstructionYard", "NOD_ConstructionYard"]
#define HARVESTER_CLASSES ["gdi_tibharvester", "nod_tibharvester"]

//-- System constants
#define SELECT_CONFIG_NAME 0
#define SELECT_NAME 1
#define SELECT_BUILDING_COST 2
#define SELECT_BUILD_TIME 3
#define SELECT_READY_PRODUCT_POS 5
#define SELECT_BUILDING_TYPE 6
#define SELECT_DIRECTION 7
#define SELECT_GLOBAL_SCRIPTS 8
#define SELECT_SERVER_SCRIPTS 9
#define SELECT_BUILDING_NEEDS 13
#define SELECT_BUILDING_STORAGE 15
#define ZEUS_DISPLAY_IDD 312

//-- What is used as a fence around construction sites
#define FENCE_CLASS "Land_New_WiredFence_5m_F"

//-- Affects the size of the building name plate
#define BUILDING_NAME_HINT_WIDTH 0.3
#define BUILDING_NAME_HINT_HEIGHT 0.05
#define BUILDING_NAME_HINT_FONT_SIZE 0.7
#define MONEY_FONT_SIZE 1.3
#define MONEY_HEIGHT 0.1 //07
#define MONEY_WIDTH 0.4


