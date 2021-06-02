
#include "..\variables.h"

if !(isNull(findDisplay ZEUS_DISPLAY_IDD)) then {
	findDisplay ZEUS_DISPLAY_IDD closeDisplay 2;
	waitUntil { isNull (findDisplay ZEUS_DISPLAY_IDD) };
	openCuratorInterface;
};