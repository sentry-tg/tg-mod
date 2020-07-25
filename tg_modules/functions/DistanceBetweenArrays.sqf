/* ----------------------------------------------------------------------------
Function: TG_fnc_DistanceBetweenArrays

Description:
	Returns distance between closest elements of two arrays of elements.
	
Parameters:
    _array1 - Contains a set of elements to process [Array of positions or objects].
    _array2 - Contains a set of elements to process [Array of positions or objects].
    _verbose - Changes the output format of the function, from number (when False) to 
		[_minDistance, [_closestFromArray1, _closestFromArray2], [_index1, _index2]] (when True) [Boolean].
	
Returns:
    Distance, or [_minDistance, [_closestFromArray1, _closestFromArray2], [_index1, _index2]]
	if _verbose is set to True.

Examples:
	(begin example)
	_array1 = [_unit1, _unit2, _unit3];
	_array2 = [_unit4, _unit5, _unit6];
	_distance = [_array1, _array2] call TG_fnc_DistanceBetweenArrays;
	(end)

Author:
    kaydol
---------------------------------------------------------------------------- */

params [["_array1", []], ["_array2", []], ["_verbose", false, [true]], ["_distance2D", false, [true]]];

_closestFromArray1 = objNull;
_closestFromArray2 = objNull;
_minDistance = -1;
_index1 = -1;
_index2 = -1;

if (count _array1 > 0 && count _array2 > 0) then 
{
	_minDistance = ( _array1 select 0 ) distance ( _array2 select 0 );
	{
		_elem = _x;
		_temp = _forEachIndex;
		{
			_dist = if (_distance2D) then [{_elem distance2D _x},{_elem distance _x}];
			if ( _dist <= _minDistance ) then {
				_minDistance = _dist; 
				if ( _verbose ) then {
					_closestFromArray1 = _elem; 
					_closestFromArray2 = _x; 
					_index1 = _temp;
					_index2 = _forEachIndex;
				};
			};
		} 
		forEach _array2;
	}
	forEach _array1;
};

if ( _verbose ) exitWith {
	[_minDistance, [_closestFromArray1, _closestFromArray2], [_index1, _index2]]
};

_minDistance
 