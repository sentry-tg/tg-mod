
#include "..\variables.h"

params ["_pos", "_father", "_hideRadius", "_greenPhaseTime", "_bluePhaseTime", "_purplePhaseTime", "_redPhaseTime"];

//	Abort if the father has been harvested
if ( isNull _father ) exitWith {};  

//	Var set in TG_fnc_TiberiumAddSpawner
//	This trick is used to make non-crystal objects spawn Tiberium
_type = _father getVariable [SPAWNER_TIBERIUM_TYPEOF, typeOf _father];
_fieldRadius = _father getVariable SPAWNER_TIBERIUM_FIELDRADIUS;
_fieldCenter = _father getVariable SPAWNER_TIBERIUM_FIELDCENTER;

_time = _greenPhaseTime;
_phases = TIBERIUM_GREEN;
_crystalClass = TIBERIUM_GREEN # 0;

if ( _type in TIBERIUM_BLUE ) then {
	_time = _bluePhaseTime; 
	_phases = TIBERIUM_BLUE;
	_crystalClass = TIBERIUM_BLUE # 0;
};

if ( _type in TIBERIUM_PURPLE ) then {
	_time = _purplePhaseTime; 
	_phases = TIBERIUM_PURPLE;
	_crystalClass = TIBERIUM_PURPLE # 0;
};

if ( _type in TIBERIUM_RED ) then {
	_time = _redPhaseTime; 
	_phases = TIBERIUM_RED;
	_crystalClass = TIBERIUM_RED # 0;
};

//_crystal = createSimpleObject [_crystalClass, _pos];
_crystal = _crystalClass createVehicle _pos;
_crystal setPosASL _pos;
_crystal setDir (round random 360);
_dirAndUp = [vectorDir _crystal, vectorUp _crystal];

_crystal setVariable [SPAWNER_TIBERIUM_FIELDRADIUS, _fieldRadius];
_crystal setVariable [SPAWNER_TIBERIUM_FIELDCENTER, _fieldCenter];

//	Growing through phases
[_crystal, _phases, _time, _pos, _dirAndUp, _crystalClass, _fieldCenter, _fieldRadius] spawn 
{
	params ["_crystal", "_phases", "_time", "_pos", "_dirAndUp", "_crystalClass", "_fieldCenter", "_fieldRadius"];
	for [{_i = 1},{_i < count _phases},{_i = _i + 1}] do 
	{
		sleep _time;
		if ( isNull _crystal ) exitWith {};
		
		deleteVehicle _crystal;
		//_crystal = createSimpleObject [_phases # _i, _pos];
		_crystal = ( _phases # _i ) createVehicle _pos;
		
		_crystal setPosASL _pos;
		_crystal setVectorDirAndUp _dirAndUp;
		
		_crystal setVariable [SPAWNER_TIBERIUM_FIELDRADIUS, _fieldRadius];
		_crystal setVariable [SPAWNER_TIBERIUM_FIELDCENTER, _fieldCenter];
		
		if ( _i == count _phases - 1 ) then 
		{
			sleep _time;
			if ( isNull _crystal ) exitWith {}; // only spawn children if the crystal lived long enough
			[_crystal, _crystalClass, _fieldCenter, _fieldRadius]  call TG_fnc_TiberiumAddSpawner;
		};
	};
};
