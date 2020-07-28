
params [["_constructions", [], [[objNull]]], ["_height", 0, [0]], ["_time", 0, [0]], ["_deltaTime", 0, [0]], ["_backwards", false]];

{
	[_x, _height, _time, _deltaTime, _backwards] spawn {
		params ["_construction", "_height", "_time", "_deltaTime", "_backwards"];
		private _posEnd = getPos _construction;
		private _posStart = [_posEnd # 0, _posEnd # 1, _posEnd # 2 - _height];
		if (_backwards) then {
			private _temp = _posEnd;
			_posEnd = _posStart;
			_posStart = _temp;
		};
		private _startTime = time;
		private _endTime = _startTime + _time;
		while {time < _endTime} do {
			_construction setPos [_posStart # 0, _posStart # 1, linearConversion [_startTime, _endTime, time, _posStart # 2, _posEnd # 2, true]];
			sleep _deltaTime;
		};
		_construction setPos _posEnd; 
	};
}
forEach _constructions;