
#define MODE_RANDOM 1
#define MODE_RANDOM_WEIGHTED 0
#define TRACK_POOL ["", "", "", "", "", ""]

_mode = param [0,"",[""]];
_input = param [1,[],[[]]];

[_mode, _input, "Synced"] call TG_fnc_VisualizeModuleRadius3DEN;

switch _mode do {
	// Default object init
	case "init": 
	{
		_logic = _input param [0,objNull,[objNull]]; // Module logic
		_isActivated = _input param [1,true,[true]]; // True when the module was activated, false when it's deactivated
		_isCuratorPlaced = _input param [2,false,[true]]; // True if the module was placed by Zeus
		
		_TrackSelectionMode = _logic getVariable "TrackSelection";
		_Enabled = _logic getVariable "Enabled";
		_SameStation = _logic getVariable "SameStation";
		_Radius = _logic getVariable "Radius";
		
		_increment = 1.0 / count TRACK_POOL;
		
		_weights = [];
		_weights resize count TRACK_POOL;
		_weights apply { 1 };
		
		while {} do 
		{
			// Modify weights
			if (_TrackSelectionMode == MODE_RANDOM_WEIGHTED) then 
			{
				// Increase all the weights by the increment
				_weights apply { (_x > 1.0)? 1.0 : _x + _increment };
				
				// Select the next track
				_newTrack = TRACK_POOL selectRandomWeighted _weights;
				_i = TRACK_POOL findIf { _x == _newTrack };
				_weights set [_i, 0];
			};
			
			_synced = synchronizedObjects _logic;
			{
				[_x, _newTrack, _Radius] call TG_fnc_JukeboxAddPlayer;
			} 
			forEach _synced;
		};
		//_logic synchronizeObjectsRemove _synced;
	};
	
	default {};
};

true
