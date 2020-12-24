
params ["_mode", "_input"];

_deleteSyncedObjectsLights = {
	params ["_logic"];
	_oldSynced = _logic getVariable ["oldSynchronized", []];
	if !(_oldSynced isEqualTo []) then 
	{
		{ 
			_light = _x getVariable ["attachedLight3DEN", objNull];
			if !(isNull _light) then { deleteVehicle _light; };
			_x setVariable ["attachedLight3DEN", nil];
		} 
		forEach _oldSynced;
		_logic setVariable ["oldSynchronized", []];
	};
};

_addLightsToObjects = {
	params ["_logic", "_objects"];
	
	_brightness = _logic getVariable "Brightness";
	_crystalColor = _logic getVariable "CrystalColor";
	// green, blue, purple, red
	_crystalColor = [ [0.0,0.9,0.0], [0.0,0.0,0.9], [0.73, 0.33, 0.83], [0.9,0.0,0.0] ] # _crystalColor; 
	
	{
		_light = "#lightpoint" createVehicleLocal getPos _x;
		_light setLightBrightness _brightness;
		_light setLightAmbient _crystalColor;
		_light setLightColor _crystalColor;
		_light setLightDayLight true;
		_light setLightUseFlare false;
		_light setLightFlareSize 5;
		_light setLightFlareMaxDistance 500;//0.001;
		_light setLightAttenuation [1,1,1,1,0,2];
		
		_light attachTo [_x, [0,0,0.34]];
		_x setVariable ["attachedLight3DEN", _x];
	} forEach _objects;
	_logic setVariable ["oldSynchronized", _objects];
};

switch _mode do 
{
	case "init": {
		_logic = _input param [0,objNull,[objNull]]; // Module logic
		_isActivated = _input param [1,true,[true]]; // True when the module was activated, false when it is deactivated
		_isCuratorPlaced = _input param [2,false,[true]]; // True if the module was placed by Zeus
		
		_attachToSynced = _logic getVariable "AttachToSynced";
		_objects = [_logic];
		if (_attachToSynced) then {	
			_objects = synchronizedObjects _logic;
		};
		[_logic, _objects] call _addLightsToObjects;
	};
	// When some attributes were changed (including position and rotation)
	case "attributesChanged3DEN": {
		_logic = _input param [0,objNull,[objNull]];
		_attachToSynced = _logic getVariable "AttachToSynced";
		_objects = [_logic];
		if (_attachToSynced) then {	
			_objects = synchronizedObjects _logic;
		};
		[_logic, _objects] call _addLightsToObjects;
	};
	// When added to the world (e.g., after undoing and redoing creation)
	case "registeredToWorld3DEN": {
		_logic = _input param [0,objNull,[objNull]];
		_attachToSynced = _logic getVariable "AttachToSynced";
		_objects = [_logic];
		if (_attachToSynced) then {	
			_objects = synchronizedObjects _logic;
		};
		[_logic, _objects] call _addLightsToObjects;
	};
	// When removed from the world (i.e., by deletion or undoing creation)
	case "unregisteredFromWorld3DEN": {
		_logic = _input param [0,objNull,[objNull]];
		_logic call _deleteSyncedObjectsLights;
	};
	// When connection to object changes (i.e., new one is added or existing one removed)
	case "connectionChanged3DEN": {
		_logic = _input param [0,objNull,[objNull]];
		_attachToSynced = _logic getVariable "AttachToSynced";
		if (_attachToSynced) then 
		{	
			_logic call _deleteSyncedObjectsLights;
			[_logic, synchronizedObjects _logic] call _addLightsToObjects;
		};
	};
	// When object is being dragged
	case "dragged3DEN": {
		_logic = _input param [0,objNull,[objNull]];
	};
};

true 

