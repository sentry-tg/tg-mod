
#include "..\variables.h"

#define JUKEBOX_PRESET_ALL 0
#define JUKEBOX_PRESET_ONLY_STEALTH 1
#define JUKEBOX_PRESET_ONLY_ACTION 2
#define JUKEBOX_PRESET_CUSTOM 3

_logic = _this select 0;
_units = _this select 1;
_activated = _this select 2;

/* A little hack to make the logic have a nice string-friendly name */
_logicName = format ["TG_ModuleJukebox_%1", round random 1000000];
_logic call compile ( _logicName + "=_this" );

/* Retreiving variables stored in the module */
_announceTracks = ( _logic getVariable ["AnnounceTracks", 0] ) == 1;
_stopMusic = ( _logic getVariable ["StopMusic", 0] ) == 1;
_startCondition = compile ( _logic getVariable ["StartCondition", "true"] );
_stopCondition = compile ( _logic getVariable ["StopCondition", "false"] );
_loopConditions = ( _logic getVariable ["LoopConditions", 0] ) == 1;
_DisableACEVolumeUpdate = ( _logic getVariable ["DisableACEVolumeUpdate", 0] ) == 1;
_presetMode = _logic getVariable ["Preset", 0];
_customTracks = _logic getVariable ["CustomTracks", ""];

_aceEnabled = isClass (configFile >> "CfgPatches" >> "ace_main");

if ( _aceEnabled && _DisableACEVolumeUpdate ) then {
	{
		WaitUntil { sleep 1; !isNil{ ace_hearing_disableVolumeUpdate }};
		ace_hearing_disableVolumeUpdate = false;
	}
	remoteExec ["spawn", 0, True];
};

/* Construct a track pool based on selected preset */
_pool = [];

switch _presetMode do {
	case JUKEBOX_PRESET_ALL: {
		_pool = [
			"TG_TimeBomb", "TG_Pharotek", "TG_LoneTrooper", "TG_Scouting", "TG_Infrared", "TG_Flurry", "TG_Mutants", "TG_Gloom", "TG_Heroism", "TG_Approach", "TG_DuskHour", "TG_TheDefense", "TG_MadRap", "TG_Valves", "TG_WhatLurks", "TG_Score", "TG_IonStorm", "TG_NodCrush", "TG_RedSky", "TG_TiberianSun_MapTheme", "TG_Elusive", "TG_Hacker", "TG_Infiltration", "TG_LinkUp", "TG_KillingMachine", "TG_RainInTheNight", "TG_SlaveToTheSystem", "TG_DeployMachines"
		];
		
		/* Conforming to EA demands... */
		_logic setVariable [LOGIC_JUKEBOX_FORCE_ANNOUNCE, true];
	};
	case JUKEBOX_PRESET_ONLY_STEALTH: {
		_pool = [
			"TG_Infiltration", "TG_RainInTheNight", "TG_Approach", "TG_DuskHour", "TG_Gloom", "TG_IonStorm", "TG_LoneTrooper", "TG_NodCrush", "TG_RedSky", "TG_TheDefense", "TG_TimeBomb", "TG_WhatLurks"
		];
		
		/* Conforming to EA demands... */
		_logic setVariable [LOGIC_JUKEBOX_FORCE_ANNOUNCE, true];
	};
	case JUKEBOX_PRESET_ONLY_ACTION: { 
		_pool = [
			"TG_KillingMachine", "TG_LinkUp", "TG_SlaveToTheSystem", "TG_DeployMachines", "TG_Elusive", "TG_Hacker", "TG_Flurry", "TG_Heroism", "TG_Infrared", "TG_MadRap", "TG_Mutants", "TG_Pharotek", "TG_Score", "TG_Scouting", "TG_TiberianSun_MapTheme", "TG_Valves"
		];
		
		/* Conforming to EA demands... */
		_logic setVariable [LOGIC_JUKEBOX_FORCE_ANNOUNCE, true];
	};
	case JUKEBOX_PRESET_CUSTOM: { 
		_pool = call compile _customTracks; 
	};
	default {};
};

/* This check mainly fires if the user screwed up when entering Custom track pool */
if !( _pool isEqualType [] ) exitWith {
	["Invalid track list for Jukebox: '%1'. Exiting...", _pool] call BIS_fnc_error;
};
if !( _pool isEqualTypeAll "" ) exitWith {
	["Invalid track list for Jukebox: '%1'. Exiting...", _pool] call BIS_fnc_error;
};

/* This check fires if one or more tracks doesn't exist in the CfgMusic */
{
	if !(isClass (configFile >> "CfgMusic" >> _x)) then {
		["CfgMusic does not contain '%1', missing addon or was it removed?", _x] call BIS_fnc_error;
	};
} 
forEach _pool;

/* Adding weights */
_poolWeighted = [];
_poolWeighted resize ( count _pool * 2 );

for [{_i = 0},{_i < count _poolWeighted },{ _i = _i + 1}] do {
	_poolWeighted set [_i, [_pool # round ( _i / 2 ), 1.0] select ( _i % 2 == 1 )];
};

/* Store the track pool in the Logic namespace */
_logic setVariable [LOGIC_JUKEBOX_TRACKS_POOL, _poolWeighted];

while { true } do 
{
	/* Wait until a user-defined condition is true */
	WaitUntil { sleep 1; call _startCondition }; 
	
	[_logic] call TG_fnc_JukeboxPlayMusic;

	/* Add event handler that starts another track once the current one ends */
	_code = compile format ["[%1] call TG_fnc_JukeboxPlayMusic;", _logicName];
	_id = addMusicEventHandler ["MusicStop", _code];

	if ( _id == -1 ) exitWith {
		["Error: addMusicEventHandler returned -1"] call BIS_fnc_error;
	};

	/* Wait until a user-defined condition is true */
	WaitUntil { sleep 1; call _stopCondition };

	removeMusicEventHandler ["MusicStop", _id];

	/* If enabled, stop the currently playing track */
	if ( _stopMusic ) then {
		[3,0] remoteExec ["fadeMusic", 0];
		sleep 3;
		[""] remoteExec ["playMusic", 0];
		[0,1] remoteExec ["fadeMusic", 0];
	};
	
	if !( _loopConditions ) exitWith {};

};

deleteVehicle _logic;
