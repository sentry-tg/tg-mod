#define _ARMA_

class CfgPatches
{
	class TG_Sounds
	{
		author = "Tiberian Genesis";
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {
			"A3_Data_F",
			"TG_Core"
			};
		requiredVersion = 0.1;
	};
};
#include "hpp\CfgSounds.hpp"
#include "hpp\CfgSoundShaders.hpp"
#include "hpp\CfgSoundSets.hpp"
#include "hpp\CfgEnvSounds.hpp"