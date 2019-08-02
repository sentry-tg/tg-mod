
params ["_pos", "_father", "_hideRadius", "_greenPhaseTime", "_bluePhaseTime", "_purplePhaseTime"];

//	Abort if the father has been harvested
if ( isNull _father ) exitWith {};  

//	Var set in TG_fnc_TiberiumAddSpawner
//	This trick is used to make non-crystal objects spawn Tiberium
_type = _father getVariable ["TG_TypeOf", typeOf _father];
_fieldRadius = _father getVariable "TG_FieldRadius";
_fieldCenter = _father getVariable "TG_FieldCenter";

_green = [
	"TG_TiberiumGreen_1_Seedling",
	"TG_TiberiumGreen_1_Medium",
	"TG_TiberiumGreen_1"
];

_blue = [
	"TG_TiberiumBlue_1_Seedling",
	"TG_TiberiumBlue_1_Medium",
	"TG_TiberiumBlue_1"
];

_purple = [
	"TG_TiberiumPurple_1_Seedling",
	"TG_TiberiumPurple_1_Medium",
	"TG_TiberiumPurple_1"
];

_time = _greenPhaseTime;
_phases = _green;
_crystalClass = _green # 0;

if ( _type in _blue ) then {
	_time = _bluePhaseTime; 
	_phases = _blue;
	_crystalClass = _blue # 0;
};

if ( _type in _purple ) then {
	_time = _purplePhaseTime; 
	_phases = _purple;
	_crystalClass = _purple # 0;
};


//_crystal = createSimpleObject [_crystalClass, _pos];
_crystal = _crystalClass createVehicle _pos;
_crystal setPosASL _pos;
_crystal setDir (round random 360);
_dirAndUp = [vectorDir _crystal, vectorUp _crystal];

_crystal setVariable ["TG_FieldRadius", _fieldRadius];
_crystal setVariable ["TG_FieldCenter", _fieldCenter];

//	Growing through phases
[_crystal, _phases, _time, _pos, _dirAndUp, _crystalClass, _fieldCenter, _fieldRadius] spawn 
{
	params ["_crystal", "_phases", "_time", "_pos", "_dirAndUp", "_crystalClass", "_fieldCenter", "_fieldRadius"];
	for [{_i = 1},{_i < count _phases},{_i = _i + 1}] do {
		sleep _time;
		if ( isNull _crystal ) exitWith {};
		deleteVehicle _crystal;
		//_crystal = createSimpleObject [_phases # _i, _pos];
		_crystal = ( _phases # _i ) createVehicle _pos;
		_crystal setPosASL _pos;
		_crystal setVectorDirAndUp _dirAndUp;
		_crystal setVariable ["TG_FieldRadius", _fieldRadius];
		_crystal setVariable ["TG_FieldCenter", _fieldCenter];
		if ( _i == count _phases - 1 ) then {
			[_crystal, _crystalClass, _fieldCenter, _fieldRadius]  call TG_fnc_TiberiumAddSpawner;
		};
	};
};
