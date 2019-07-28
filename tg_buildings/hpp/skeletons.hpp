class Rotation
{
	type = "rotation";
	memory = 1;
	minValue = 0;
	maxValue = 1;
	angle0 = 0;
	angle1 = 1;
};

class CfgSkeletons
{
	class Tank; //Define base class.
	class TG_Default
	{
		isDiscrete = 1;
		skeletonInherit = "";
		skeletonBones[] = {};
	};

	class TG_Skeleton : TG_Default
	{
		isDiscrete = 1;
		skeletonInherit = "TG_Default";
		skeletonBones[] = 
		{
                  	"con_turnlight","",
			"con_fan3","",
			"con_fan2","",
			"con_fan1",""		
		};
	};

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
	class TG_Default 
	{
		sectionsInherit = "";
		sections[] = {};
		skeletonName = "";
	};
	class TG_Buildings: TG_Default
	{
		sectionsInherit = "TG_Default";
		sections[] = 
		{
			"con_turnlight",
			"con_fan3",
			"con_fan2",
			"con_fan1"
		};
		skeletonName = "TG_Skeleton";
	};
	
        class gdi_conyard: TG_Buildings 
           {
              class Animations
		{
			class Fan1
			{
				type = "rotation";
				animPeriod = 2;
				selection = "con_fan1";
				axis = "osa_fan1";
				angle0 = 0;
				minValue = 0;
				maxValue = 1;
				source = "time";
				sourceAddress = "loop";
				angle1 = rad 360";
			};
                        class Fan2
			{
				type = "rotation";
				animPeriod = 2;
				selection = "con_fan2";
				axis = "osa_fan2";
				angle0 = 0;
				minValue = 0;
				maxValue = 1;
				source = "time";
				sourceAddress = "loop";
				angle1 = rad 360";
			};
                        class Fan3
			{
				type = "rotation";
				animPeriod = 2;
				selection = "con_fan3";
				axis = "osa_fan3";
				angle0 = 0;
				minValue = 0;
				maxValue = 1;
				source = "time";
				sourceAddress = "loop";
				angle1 = rad 360";
			};
                       class TurnLight
			{
				type = "rotation";
				animPeriod = 1;
				selection = "con_turnlight";
				axis = "osa_turnlight";
				angle0 = 0;
				minValue = 0;
				maxValue = 1;
				source = "time";
				sourceAddress = "loop";
				angle1 = rad 360";
			};

		};


           };

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
			angle1 = "rad 360"; 
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
			angle1 = "rad 360"; 
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



                  class nod_conyard: gdi_conyard{};

};