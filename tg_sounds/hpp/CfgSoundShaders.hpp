class CfgSoundShaders
{
	class TG_RandomCrate_SoundShader
	{
		samples[] = {{"\tg_sounds\objects\randomcrate\randomcrate.ogg",1}};
		volume = 0.3;
		range = 10;
		rangeCurve[] = {{1,1},{5,0.75},{10,0}};
	};
	class TG_NOD_LaserTurret_SoundShader
	{
		samples[] = {{"\tg_sounds\nod\defense\laserturret\laser_noise.wss",1}};
		volume = 0.33;
		range = 10;
		rangeCurve[] = {{1,1},{2,0.75},{5,0}};
	};
	class TG_Tiberium_SoundShader
	{
		samples[] = {{"\tg_sounds\ambient\tiberium\tiberium.ogg",1}};
		volume = 0.3;
		range = 120;
		rangeCurve[] = {{1,1},{60,0.75},{120,0}};
	};
};