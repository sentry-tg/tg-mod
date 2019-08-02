
params ["_name", ["_valueInsteadOfIndex", False]];

_index = TG_AICOMMANDERS findIf { _x # 0 == _name };

if ( _valueInsteadOfIndex ) exitWith {
	if ( _index >= 0 ) then {
		TG_AICOMMANDERS # _index
	} else {
		[]
	};
};

_index
