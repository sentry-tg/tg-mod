
#include "..\variables.h"

params [["_enumeration",[]], ["_indexToSelect",0]];

private _array = [];

{ _array pushBack (_x select _indexToSelect); } forEach _enumeration;
_array