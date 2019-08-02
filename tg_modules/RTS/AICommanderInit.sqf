
params ["_logic", "_side", "_name", "_preset"];

SystemChat str _this;


//------------------------------------------------------//
//	Adding this commander to the list of AI commanders	//
//------------------------------------------------------//

if ( isNil{ TG_AICOMMANDERS } ) then {
	TG_AICOMMANDERS = [];
};

if ( TG_AICOMMANDERS findIf { _x # 0 == _name } >= 0 ) exitWith {
	["A commander with name %1 already exists!", _name] call BIS_fnc_Error;
};

TG_AICOMMANDERS pushBack [_name, _side];

//----------------------------------------------------------------------//
//	Reading preset data from config and saving it to local variables	//
//----------------------------------------------------------------------//

_properties = configProperties [ConfigFile >> "CfgTGAITemplates" >> _preset] apply { [format ['_%1', configName _x], getNumber _x] };
params _properties;  

/*	^ Creates variables according to how they were defined in config.

	_maxTurrets
	_maxTanks
	_maxInfantry
	_incomeMultiplier
	_maxWalls
	_priorityWalls
	_priorityTurrets
	_priorityTanks
	_priorityInfantry
	_aggression
*/

//------------------------------------------------------------------//
//	Defining local variables as global ones to provide interface	//
//------------------------------------------------------------------//

_Harvesters = [];
_Buildings = [];
_EnergyBalance = [];
_BuildingQueue = [];
_Groups = [];

call compile format ["
	if ( isNil { TG_%1_Harvesters } ) then { TG_%1_Harvesters = [] }; 
	_Harvesters = TG_%1_Harvesters;
", _name];	

call compile format ["
	if ( isNil { TG_%1_Buildings } ) then { TG_%1_Buildings = [] }; 
	_Buildings = TG_%1_Buildings;
", _name];

call compile format ["
	if ( isNil { TG_%1_EnergyBalance } ) then { TG_%1_EnergyBalance = [] }; 
	_EnergyBalance = TG_%1_EnergyBalance;
", _name];

call compile format ["
	if ( isNil { TG_%1_BuildingQueue } ) then { TG_%1_BuildingQueue = [] }; 
	_BuildingQueue = TG_%1_BuildingQueue;
", _name];

call compile format ["
	if ( isNil { TG_%1_Groups } ) then { TG_%1_Groups = [] }; 
	_Groups = TG_%1_Groups;
", _name];

//--------------//
//	Main Loop	//
//--------------//

while { !isNull _logic } do 
{
	//	Check if building is available
	_canBuild =  { _x isKindOf "TG_ConstructionYard" } count _Buildings > 0 ;	// TODO update cfgVehicles with this KindOf 
	if !( _canBuild ) then 
	{
		//	Check if any MCVs are under control
		_MCV = objNull;
		{
			_MCVs = units _x select { typeOf _x == "nod_mcv" || typeOf _x == "gdi_mcv" };
			if ( count _MCVs > 0 ) exitWith { _MCV = _MCVs # 0; };
		} 
		forEach _Groups;
		//	Deploy MCV 
		if !( isNull _MCV ) then {
			
		};
	} else {
		//	Check if there is enough energy
		_energyBalance = 0;
		{ _energyBalance = _energyBalance + _x # 1 } forEach _Buildings;
		_EnergyBalance set [0, _energyBalance];
		
		//	Not enough energy
		if ( _energyBalance < 0 ) then {
			//	Check if any power plants are being built
			_powerPlantsInProgress = _BuildingQueue select { _x # 0 isKindOf "TG_Powerplant" }; //	TODO update cfgVehicles with this KindOf
			if !() then {
				[_side, "PowerPlant"] call TG_fnc_QueueBuildingOrder;
			};
		} 
		//	Enough energy
		else {
			
		
		};
		
		
	
	};
	
	
	
	
	
};

