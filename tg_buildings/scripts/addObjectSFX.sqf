

/*
	This script adds a sound effects to the given object. The goal was to make it possible to add SFX to different rooms within buildings, but adding sounds to another objects, including moving ones, is possible with this script as well.

	_this select 0: the object that emits sounds
		0: object in which relative space the speaker will be located
		1: array [x,y,z] of relative coordinates pointing to a specific location. Default [0,0,0]
		
	_this select 1: (optional) the distance from which the sound becomes distinguishable, default 15
	_this select 2: (optional) the sound the object emits when it starts working, an intro
	_this select 3: the sound the object emits while operating at normal 
	_this select 4: (optional) sound the object emits before going silent
	_this select 5: (optional) an interlap between 1&2, 2&3 sounds in seconds, default [0.5,0.05]
	_this select 6: (optional) function name that returns a boolean deciding whether to emit sound or not, e.g. only emit sound when the object is powered up, etc. The function input is the object from (_this select 0), output must be boolean.
	_this select 7: (optional) debug, marks the sound emitter with a yellow sphere, default False
	
	Usage:
		as = [_building, 10, ["ElectricEngineSpinUp", 16], ["ElectricEngineHumming", 6], ["ElectricEngineStop", 8]] execVM "addObjectSFX.sqf";
		as = [[_object, [0,0,1]], 5, nil, ["ElectricEngineHumming", 6], nil] execVM "addObjectSFX.sqf";
*/

params ["_object", ["_distance", 15], ["_start", []], ["_loop", []], ["_stop", []], ["_interlap", [0.5,0.05]], ["_func", ""], ["_debug", False]];

_fnc_alwaysTrue = { True };
_func = if ( count _func > 0 ) then [{ call compile _func },{ _fnc_alwaysTrue }];

_object params ["_obj", ["_relpos", [0,0,0]]];
_start params ["_sound1", ["_length1", 0]];
_loop params ["_sound2", ["_length2", 0]];
_stop params ["_sound3", ["_length3", 0]];

_speaker = _obj;

if ( _debug ) then {
	_sphere = "Sign_Sphere25cm_F" createVehicle getPos _obj;
	_sphere attachTo [_obj, _relpos];
};

/* If a certain location within the object is given, create a speaker at that location */
if !( _relpos isEqualTo [0,0,0] ) then 
{
	_center = createCenter sideLogic;
	_group = createGroup _center;
	_speaker = _group createUnit ["LOGIC", [0,0,0], [], 0, "NONE"];
	_speaker attachTo [_obj, _relpos];
	
	// 	1. get a list of all speakers attached to this object
	_attachedSpeakers = _obj getVariable ["TG_AttachedSpeakers", []];
	
	//	2. if there were none, add the first one and add an EventHandler 
	//	that will delete ALL of them upon object's destruction
	
	if (count _attachedSpeakers == 0) then {
		_obj addEventHandler ["Killed", {
			params ["_obj", "_killer"];
			_attachedSpeakers = _obj getVariable ["TG_AttachedSpeakers", []];
			{ deleteVehicle _x } forEach _attachedSpeakers;
			_obj removeEventHandler ["Killed", _thisEventHandler];
		}];
	};
	_attachedSpeakers pushBack _speaker;
	_obj setVariable ["TG_AttachedSpeakers", _attachedSpeakers, TRUE];
}; 

//systemchat format ["%1", _obj call call _func];

// The sound emitting part
while { alive _obj } do 
{
	_buildingHadBeenActive = False;
	
	// Only played when the object is becoming active
	if ( _obj call _func && alive _obj && _length1 > 0 ) then {
		_buildingHadBeenActive = True;
		_speaker say3D [_sound1, _distance];
		sleep ( _length1 - _interlap # 0 );
	};
	
	// Played as long as the object is active
	while { _obj call _func && alive _obj && _length2 > 0 } do 
	{
		_buildingHadBeenActive = True;
		_speaker say3D [_sound2, _distance];
		sleep ( _length2 - _interlap # 1 );
	};
	
	
	// Played when the object becomes inactive
	if ( _buildingHadBeenActive && alive _obj && _length3 > 0 ) then {
		_speaker say3D [_sound3, _distance];
		sleep _length3;
	};
	
	sleep 2.5;
};


