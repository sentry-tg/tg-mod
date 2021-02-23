
params ["_logic"];

_mainTopic = "Tiberian Genesis";
_mainTopicDesc = "TG Modules README";

player createDiarySubject [_mainTopic, _mainTopicDesc];
_moduleCfgs = configProperties [configFile >> "CfgVehicles", "isClass _x && inheritsFrom _x == (configFile >> 'CfgVehicles' >> 'TG_Module')"];

{
	_moduleName = getText(_x >> "displayName");
	_moduleDescription = getText(_x >> "ModuleDescription" >> "description");
	_moduleSync = "";
	
	if (isArray (_x >> "ModuleDescription" >> "sync")) then {
		_arrayOrValue = (_x >> "ModuleDescription" >> "sync") call BIS_fnc_GetCfgData;
		
		if !(_arrayOrValue isEqualType []) then {
			_arrayOrValue = [_arrayOrValue]; //-- Make sure it's an array
		};
		
		if (count _arrayOrValue > 0) then 
		{
			_moduleSync = "<br />Objects, that can be synchronized:";
			_moduleCfg = _x;
			
			{
				_moduleSync = _moduleSync + "<br />- " + _x;
				if (isNumber (_moduleCfg >> "ModuleDescription" >> _x >> "optional")) then {
					_optionality = ["(OPTIONAL)", "(MUST BE SYNCED)"] select getNumber (_moduleCfg >> "ModuleDescription" >> _x >> "optional");
					_moduleSync = _moduleSync + " " + _optionality;
				};
				_moduleSync = _moduleSync + "<br />";
			}
			forEach _arrayOrValue;
			
			_moduleSync = _moduleSync + "<br />";
		};
	};
	
	player createDiaryRecord [_mainTopic, [_moduleName, format ["%1<br /><br />%2", _moduleDescription, _moduleSync]]];
	
} forEach _moduleCfgs;


hint "Check your diary! Open yor Map [M], then press [J] to open your Journal!";