class CfgSkeletons 
{ 
   class Tank; //Define base class.
   class vulcanBones: Tank
   {
	isDiscrete=1;
	skeletonInherit = ""; //Inherit all bones from class Car.
	skeletonBones[]=
	{
		"mainTurret","",
		"mainGun","mainTurret",
		"spin1","mainGun",
		"spin2","mainGun",
		"hlavne", "mainGun"
	};
   };

   class rpgBones: Tank
   {
	isDiscrete=1;
	skeletonInherit = ""; //Inherit all bones from class Car.
	skeletonBones[]=
	{
		"mainTurret","",
		"mainGun","mainTurret",
		"hlavne", "mainGun"
	};
   };
};
class CfgModels
{
   class Tank; //Declare base class.
   class gdi_vulcan_upgrade: Tank
   {
	sectionsInherit = "";                     
	sections[] ={"L svetlo", "P svetlo","clan","Zasleh"};
	skeletonName = "vulcanBones"; 
	class Animations 
	{
		class mainTurret
		{
      			type = "rotationY";
      			source = "mainTurret";
 			selection = "mainTurret";
			axis = "OsaVeze";
			memory = true; 
			sourceAddress = "loop";
			minValue = rad -360;
              	    	maxValue = rad 360;
                    	angle0 = rad -360; 
      			angle1 = "rad 360"; 
   		};
		class mainGun
		{
      			type = "rotationX";
      			source = "mainGun";
 			selection = "mainGun";
			axis = "OsaHlavne";
			memory = true; 
			sourceAddress = "clamp";
			minValue = "rad -60";
              	    	maxValue = "rad 60";
                    	angle0 = "rad -60"; 
			angle1 = "rad 60"; 
      		};
		class spin1
		{
      			type = "rotation";
      			source = "spinanim";
 			selection = "spin1";
			axis = "spin1axis";
			memory = true; 
			sourceAddress = "loop";
			minValue = "0";
              	    	maxValue = "1";
                    	angle0 = "0"; 
			angle1 = "2000.8"; 
      		};
		class spin2
		{
      			type = "rotation";
      			source = "spinanim";
 			selection = "spin2";
			axis = "spin2axis";
			memory = true; 
			sourceAddress = "loop";
			minValue = "0";
              	    	maxValue = "1";
                    	angle0 = "0"; 
			angle1 = "2000.8"; 
      		};
	};
    };

   class gdi_rpg_upgrade: Tank
   {
	sectionsInherit = "";                     
	sections[] ={"P svetlo","clan","Zasleh"};
	skeletonName = "rpgBones"; 
	class Animations 
	{
		class mainTurret
		{
      			type = "rotationY";
      			source = "mainTurret";
 			selection = "mainTurret";
			axis = "OsaVeze";
			memory = true; 
			sourceAddress = "loop";
			minValue = rad -360;
              	    	maxValue = rad 360;
                    	angle0 = rad -360; 
      			angle1 = "rad 360"; 
   		};
		class mainGun
		{
      			type = "rotationX";
      			source = "mainGun";
 			selection = "mainGun";
			axis = "OsaHlavne";
			memory = true; 
			sourceAddress = "clamp";
			minValue = "rad -60";
              	    	maxValue = "rad 60";
                    	angle0 = "rad -60"; 
			angle1 = "rad 60"; 
      		};
	};
    };
};

class AnimationSources
{
	class hlavne
	{
		source = "user";
		animperiod = 0;
		initPhase = 0;
	};
};

