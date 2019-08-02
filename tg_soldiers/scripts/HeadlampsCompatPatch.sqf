
/*
	This function adds Tiberian Genesis helmets to the Headlamps addon made by Sanchez.
	
*/

params ["_mode", "_didJip"];

if !( isClass (ConfigFile >> "CfgPatches" >> "SAN_Headlamp") ) exitWith {};

_timeout = 5;

//	Wait until the variable is defined in Headlamps addon
_time = time;
waitUntil { sleep 0.5; ( time - _time > _timeout )||( !isNil{ SAN_Headlamp_Helmets } && !isNil{ SAN_fnc_findOffset } ) };

if ( isNil{ SAN_Headlamp_Helmets } || isNil{ SAN_fnc_findOffset } ) exitWith {
	//	This block is executed if Sanchez changed the name of the variable that contains applicable helmets
	systemChat "Error: Could not hookup with Headlamps addon, please report this to Tiberian Genesis team";
};

SAN_Headlamp_Helmets pushBack "GDI_Helmet";


//////////////////////////////////////////
//	Redefeniton of SAN_fnc_findOffset	//
//////////////////////////////////////////

//	First, create a global variable containing all default offsets
if ( isNil { SAN_Headlamp_Offsets } ) then {
	SAN_Headlamp_Offsets = [
		["SAN_Headlamp_v1", [0,0.08,0.02]],
		["SAN_Headlamp_v2", [0,0.07,0.015]],
		["H_HelmetSpecO_blk", [-0.091,0.049,-0.023]],
		["H_HelmetO_oucamo", [-0.089,0.049,-0.009]],
		["H_HelmetB_light", [-0.124,-0.010,0.038]],
		["H_HelmetSpecB", [-0.124,-0.060,-0.008]]
	];
};

//	Second, add new helmet to that variable
SAN_Headlamp_Offsets pushBack ["GDI_Helmet", [-0.1,0.08,0.04]];

//	At last, redefine the function to use the new global variable
SAN_fnc_findOffset = 
{
	params ["_classname"]; 
	private ["_ret", "_pos"]; 
	
	_ret = [0,0.06,0.01]; // default offset
	_pos = SAN_Headlamp_Offsets findIf { _x # 0 == _classname };
	
	if ( _pos >= 0 ) then { _ret = ( SAN_Headlamp_Offsets # _pos ) # 1 };
	
	_ret 
};	
	

 