
/*
	Variables for setVariable\getVariable in format:
		Namespace_module_variable-name
*/

	// +++++++++++++++++++++++++++++++++++ \\
	// 				 Jukebox			   \\
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

/* A global variable that stores all tiberium spawners, used by harvesters */
#define MISSION_TIBERIUM_SPAWNERS "TG_TiberiumSpawners"

	// +++++++++++++++++++++++++++++++++++ \\
	// 				 Harvester			   \\
	// +++++++++++++++++++++++++++++++++++ \\

#define HARVESTER_TIBERIUM_CURRENTLOAD "TG_curLoad"