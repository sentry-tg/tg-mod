
//-- Singleton

if (isNil{ missionNameSpace getVariable "SoundQueueLimits" }) then {
	missionNameSpace setVariable ["SoundQueueLimits", [ [["eva_silos_needed", "cabal_silos_needed"],30,0] ]];
};

while {true} do 
{
	private _queue = missionNameSpace getVariable ["SoundQueue", []];
	if (count _queue > 0) then 
	{
		private _sound = _queue # 0;
		missionNameSpace setVariable ["SoundQueue", _queue select [1, (count _queue) - 1]];
		
		//-- See when was this played last time
		private _canBePlayed = true;
		{	
			private _sounds = _x # 0;
			private _minTimeBetweenPlays = _x # 1;
			private _lastTimePlayed = _x # 2;
			if ( toLowerANSI _sound in (_sounds apply {toLowerANSI _x}) && time - _lastTimePlayed < _minTimeBetweenPlays) exitWith {  
				_canBePlayed = false;
			};
		}
		forEach (missionNameSpace getVariable "SoundQueueLimits");
		
		if ( _canBePlayed ) then 
		{
			//-- Update last time played
			{	
				private _array = _x;
				private _sounds = _x # 0;
				if ( toLowerANSI _sound in (_sounds apply {toLowerANSI _x})) exitWith {  
					_array set [2, time];
				};
			}
			forEach (missionNameSpace getVariable "SoundQueueLimits");
			
			//-- Play sound
			private _audio = playSound _sound;
			if ( isNil{ _audio } ) then {
				// Laaaame
				sleep 2; 
			} else {
				// Not lame, but will ony become available since Arma 3 v1.99.146480
				waitUntil { sleep 0.1; isNil{ _audio }}; 
			};
		};
	}
	else 
	{ 
		sleep 0.3; 
	};
};