#define private		0
#define protected		1
#define public		2

#define true	1
#define false	0

#define ReadAndWrite		0
#define ReadAndCreate		1
#define ReadOnly		2
#define ReadOnlyVerified		3

enum {
	DESTRUCTENGINE = 2,
	DESTRUCTDEFAULT = 6,
	DESTRUCTWRECK = 7,
	DESTRUCTTREE = 3,
	DESTRUCTTENT = 4,
	STABILIZEDINAXISX = 1,
	STABILIZEDINAXESXYZ = 4,
	STABILIZEDINAXISY = 2,
	STABILIZEDINAXESBOTH = 3,
	DESTRUCTNO = 0,
	STABILIZEDINAXESNONE = 0,
	DESTRUCTMAN = 5,
	DESTRUCTBUILDING = 1,
};

#include "cfgModels.hpp"

class CfgPatches {
	class tg_buildings {
		requiredAddons[] = {};
		requiredVersion = 0.1;
		units[] = {"gdi_g"};
		weapons[] = {};
		magazines[] = {};
	};
};

class CfgVehicles {
	class Car_F;	// External class reference
	class House_F;	// External class reference
	class Sound;	// External class reference
	class ThingX;	// External class reference
	class Animationsources;	// External class reference
	
	class gdi_cy : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_GDI_CY";
		armor = 2000;
		accuracy = 1000;

		//animate[] = {{"gdi_Fan1", 1}, {"gdi_Fan2", 1}, {"gdi_Fan3", 1}, {"gdi_TurnLight", 1}};
		//numberOfDoors = 4;

		editorcategory = "tg";
		editorSubcategory = "gdi_buildings";
		editorPreview = "\tg_buildings\ico\gdi_cy.paa";
		model = \tg_buildings\gdi\model\gdi_conyard.p3d;


		aggregateReflectors[] =
		{
			{"Light_1", "Light_2", "Light_3", "Light_4","Light_5", "Light_6", "Light_7"}
		};

		class MarkerLights
		{
			class Light1
			{
				color[] = {2500, 4000, 6000};
				ambient[] = {0.01, 0.0, 0.0};
				intensity = 0.1;
				name = "Light1";
				useFlare = 1;
				flareSize = 1.7;
				flareMaxDistance = 1000;
				activeLight = 1;

				blinking			= true;					/// lets make it blinking to show how patterns work
				blinkingPattern[]	= {6.25, 1.0};			// 0.25 s flash, 1.25 s period
				blinkingStartsOn	= true;					/// pattern starts with length of the first flash
				blinkingPatternGuarantee	= true;			/// use this to guarantee all blinks of the patter to be done
															/// doesn't guarantee the length of pattern if true 
															/// (e.g. because of blinks shorter than a frame would take a frame to be seen)

				dayLight = 1;
				drawLight = 1;
				
				class Attenuation {
					start = 0;
					constant = 10;
					linear = 15;
					quadratic = 25;
					hardLimitStart = 5;
					hardLimitEnd = 6;
				};
			};
			class Light2: Light1 {
				name = "Light2";
				blinkingPattern[]	= {5.25, 2.0};			// 0.25 s flash, 1.25 s period			
			};
			class Light3: Light1 {
				name = "Light3";
				blinkingPattern[]	= {4.25, 3.0};			// 0.25 s flash, 1.25 s period		
			};
			class Light4: Light1 {
				name = "Light4";
				blinkingPattern[]	= {3.25, 4.0};			// 0.25 s flash, 1.25 s period			
			};
			class Light5: Light1 {
				name = "Light5";
				blinkingPattern[]	= {2.25, 5.0};			// 0.25 s flash, 1.25 s period			
			};
			class Light6: Light1 {
				name = "Light6";
				blinkingPattern[]	= {1.25, 6.0};			// 0.25 s flash, 1.25 s period			
			};
			class Light7: Light1 {
				name = "Light7";
				blinkingPattern[]	= {0.25, 7.0};			// 0.25 s flash, 1.25 s period			
			};
			class Light8: Light1 {
				name = "Light8";
				blinkingPattern[]	= {0.25, 1.0};			// 0.25 s flash, 1.25 s period			
			};
			class Light9: Light1 {
				name = "Light9";
				blinkingPattern[]	= {0.25, 1.0};			// 0.25 s flash, 1.25 s period			
			};
};
		class Reflectors
		{
			class Light_1
			{
				color[]				= {2500,4000,6000};
				ambient[]			= {2.5,4,6};
				intensity			= 2;
				size				= 1;					/// size of the light point seen from distance
				innerAngle			= 100;					/// angle of full light
				outerAngle			= 165;					/// angle of some light
				coneFadeCoef		= 4;					/// attenuation of light between the above angles

				position			= "Light_1_pos";		/// memory point for start of the light and flare
				direction			= "Light_1_dir";		/// memory point for the light direction
				hitpoint			= "Light_1_hitpoint";	/// point(s) in hitpoint lod for the light (hitPoints are created by engine)
				selection			= "Light_1_hide";		/// selection for artificial glow around the bulb, not much used any more

				useFlare			= true;
				flareSize			= 2;
				flareMaxDistance	= 130;

				class Attenuation
				{
					start			= 0;
					constant		= 0;
					linear			= 0;
					quadratic		= 0.3;

					hardLimitStart	= 50;
					hardLimitEnd	= 65;
				};
			};
			class Light_2: Light_1
			{
				position			= "Light_2_pos";
				direction			= "Light_2_dir";
				hitpoint			= "Light_2_hitpoint";
				selection			= "Light_2_hide";
			};
			class Light_3: Light_1
			{
				position			= "Light_3_pos";
				direction			= "Light_3_dir";
				hitpoint			= "Light_3_hitpoint";
				selection			= "Light_3_hide";
			};
			class Light_4: Light_1
			{
				position			= "Light_4_pos";
				direction			= "Light_4_dir";
				hitpoint			= "Light_4_hitpoint";
				selection			= "Light_4_hide";
			};
			class Light_5: Light_1
			{
				position			= "Light_5_pos";
				direction			= "Light_5_dir";
				hitpoint			= "Light_5_hitpoint";
				selection			= "Light_5_hide";
			};
			class Light_6: Light_1
			{
				position			= "Light_6_pos";
				direction			= "Light_6_dir";
				hitpoint			= "Light_6_hitpoint";
				selection			= "Light_6_hide";
			};
			class Light_7: Light_1
			{
				position			= "Light_7_pos";
				direction			= "Light_7_dir";
				hitpoint			= "Light_7_hitpoint";
				selection			= "Light_7_hide";
			};
};


              class AnimationSources
		{

			class gdi_Fan1_source
			{
				source = "user"; //The controller is defined as a user animation.
				animPeriod = 10;  //The animation period used for this controller.
				initPhase = 0;     //Initial phase when object is created. 0 = CLOSED	
				sound = "GenericCySound";
				soundPosition = "Light2";
			};
                        class gdi_Fan2
			{
				source = "user"; //The controller is defined as a user animation.
				animPeriod = 1;  //The animation period used for this controller.
				initPhase = 0;     //Initial phase when object is created. 0 = CLOSED	
				sound = "GenericCySound";
				soundPosition = "Light4";
			};
                        class gdi_Fan3
			{
				source = "user"; //The controller is defined as a user animation.
				animPeriod = 1;  //The animation period used for this controller.
				initPhase = 0;     //Initial phase when object is created. 0 = CLOSED
				sound = "GenericCySound";
				soundPosition = "Light6";	
			};
                        class gdi_TurnLight
			{
				source = "user"; //The controller is defined as a user animation.
				animPeriod = 10;  //The animation period used for this controller.
				initPhase = 0;     //Initial phase when object is created. 0 = CLOSED		
			};		
};

class CfgAnimationSourceSounds {
	class GenericCySound {
		class cyfanloop {
			loop = 1;
			terminate = 0;
			trigger = "direction * (phase factor[0.01,0.02])";
			sound0[] = {"\tg_sounds\all\cy_fan.ogg", 1, 1, 20};
			sound[] = {"sound0", 1};
		};
		
	};
	
	class GenericPPSound {
		class turbineloop {
			loop = 1;
			terminate = 0;
			trigger = "direction * (phase factor[0.01,0.02])";
			sound0[] = {"\tg_sounds\all\powerplant.wav", 1, 1, 20};
			sound[] = {"sound0", 1};
		};
	};
};

		class eventhandlers
		{
			//				[x,y,z],   distance    "soundname", seconds	
			init = "[[(_this select 0), [2.5, 18.3, 13.8]], 50, nil, ['cy_fan', 1]] execVM '\tg_buildings\scripts\addObjectSFX.sqf'";
		};
};

	
	class gdi_pp : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_GDI_PP";
		armor = 2000;
		accuracy = 1000;

		editorcategory = "tg";
		editorSubcategory = "gdi_buildings";
		editorPreview = "\tg_buildings\ico\gdi_cy.paa";
		model = \tg_buildings\gdi\model\gdi_powerplant.p3d;


		aggregateReflectors[] =
		{
			{"Light_1", "Light_2", "Light_3", "Light_4","Light_5", "Light_6", "Light_7"}
		};

		class MarkerLights
		{
			class Light1
			{
				color[] = {2500, 4000, 6000};
				ambient[] = {0.01, 0.0, 0.0};
				intensity = 0.1;
				name = "Light1";
				useFlare = 1;
				flareSize = 1.7;
				flareMaxDistance = 1000;
				activeLight = 1;

				blinking			= true;					/// lets make it blinking to show how patterns work
				blinkingPattern[]	= {6.25, 1.0};			// 0.25 s flash, 1.25 s period
				blinkingStartsOn	= true;					/// pattern starts with length of the first flash
				blinkingPatternGuarantee	= true;			/// use this to guarantee all blinks of the patter to be done
															/// doesn't guarantee the length of pattern if true 
															/// (e.g. because of blinks shorter than a frame would take a frame to be seen)

				dayLight = 1;
				drawLight = 1;
				
				class Attenuation {
					start = 0;
					constant = 10;
					linear = 15;
					quadratic = 25;
					hardLimitStart = 5;
					hardLimitEnd = 6;
				};
			};
			class Light2: Light1 {
				name = "Light2";
				blinkingPattern[]	= {5.25, 2.0};			// 0.25 s flash, 1.25 s period			
			};
			class Light3: Light1 {
				name = "Light3";
				blinkingPattern[]	= {4.25, 3.0};			// 0.25 s flash, 1.25 s period		
			};
			class Light4: Light1 {
				name = "Light4";
				blinkingPattern[]	= {3.25, 4.0};			// 0.25 s flash, 1.25 s period			
			};
			class Light5: Light1 {
				name = "Light5";
				blinkingPattern[]	= {2.25, 5.0};			// 0.25 s flash, 1.25 s period			
			};
			class Light6: Light1 {
				name = "Light6";
				blinkingPattern[]	= {1.25, 6.0};			// 0.25 s flash, 1.25 s period			
			};
			class Light7: Light1 {
				name = "Light7";
				blinkingPattern[]	= {0.25, 7.0};			// 0.25 s flash, 1.25 s period			
			};
			class Light8: Light1 {
				name = "Light8";
				blinkingPattern[]	= {0.25, 1.0};			// 0.25 s flash, 1.25 s period			
			};
			class Light9: Light1 {
				name = "Light9";
				blinkingPattern[]	= {0.25, 1.0};			// 0.25 s flash, 1.25 s period			
			};
};
		class Reflectors
		{
			class Light_1
			{
				color[]				= {2500,4000,6000};
				ambient[]			= {2.5,4,6};
				intensity			= 2;
				size				= 1;					/// size of the light point seen from distance
				innerAngle			= 100;					/// angle of full light
				outerAngle			= 165;					/// angle of some light
				coneFadeCoef		= 4;					/// attenuation of light between the above angles

				position			= "Light_1_pos";		/// memory point for start of the light and flare
				direction			= "Light_1_dir";		/// memory point for the light direction
				hitpoint			= "Light_1_hitpoint";	/// point(s) in hitpoint lod for the light (hitPoints are created by engine)
				selection			= "Light_1_hide";		/// selection for artificial glow around the bulb, not much used any more

				useFlare			= true;
				flareSize			= 2;
				flareMaxDistance	= 130;

				class Attenuation
				{
					start			= 0;
					constant		= 0;
					linear			= 0;
					quadratic		= 0.3;

					hardLimitStart	= 50;
					hardLimitEnd	= 65;
				};
			};
			class Light_2: Light_1
			{
				position			= "Light_2_pos";
				direction			= "Light_2_dir";
				hitpoint			= "Light_2_hitpoint";
				selection			= "Light_2_hide";
			};
			class Light_3: Light_1
			{
				position			= "Light_3_pos";
				direction			= "Light_3_dir";
				hitpoint			= "Light_3_hitpoint";
				selection			= "Light_3_hide";
			};
			class Light_4: Light_1
			{
				position			= "Light_4_pos";
				direction			= "Light_4_dir";
				hitpoint			= "Light_4_hitpoint";
				selection			= "Light_4_hide";
			};
			class Light_5: Light_1
			{
				position			= "Light_5_pos";
				direction			= "Light_5_dir";
				hitpoint			= "Light_5_hitpoint";
				selection			= "Light_5_hide";
			};
			class Light_6: Light_1
			{
				position			= "Light_6_pos";
				direction			= "Light_6_dir";
				hitpoint			= "Light_6_hitpoint";
				selection			= "Light_6_hide";
			};
			class Light_7: Light_1
			{
				position			= "Light_7_pos";
				direction			= "Light_7_dir";
				hitpoint			= "Light_7_hitpoint";
				selection			= "Light_7_hide";
			};
};

              class Animations
		{
			class Turb1
			{
				type = "rotation";
				animPeriod = 10;
				selection = "turbine1";
				axis = "osa_turb1";
				angle0 = 0;
				minValue = 0;
				maxValue = 1;
				source = "time";
				sourceAddress = "loop";
				angle1 = rad 360";
			};
                        class Turb2
			{
				type = "rotation";
				animPeriod = 10;
				selection = "turbine2";
				axis = "osa_turb2";
				angle0 = 0;
				minValue = 0;
				maxValue = 1;
				source = "time";
				sourceAddress = "loop";
				angle1 = rad 360";
			};
                        class Turb3
			{
				type = "rotation";
				animPeriod = 10;
				selection = "turbine3";
				axis = "osa_turb3";
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




              class AnimationSources
		{

			class Turb1
			{
				source = "user"; //The controller is defined as a user animation.
				animPeriod = 10;  //The animation period used for this controller.
				initPhase = 0;     //Initial phase when object is created. 0 = CLOSED	
			};
                        class Turb2
			{
				source = "user"; //The controller is defined as a user animation.
				animPeriod = 10;  //The animation period used for this controller.
				initPhase = 0;     //Initial phase when object is created. 0 = CLOSED		
			};
                        class Turb3
			{
				source = "user"; //The controller is defined as a user animation.
				animPeriod = 10;  //The animation period used for this controller.
				initPhase = 0;     //Initial phase when object is created. 0 = CLOSED		
			};
                       class TurnLight
			{
				source = "user"; //The controller is defined as a user animation.
				animPeriod = 1;  //The animation period used for this controller.
				initPhase = 0;     //Initial phase when object is created. 0 = CLOSED		
			};		

};

		class eventhandlers
		{
			init = "[[(_this select 0), [11.5,11,7]]] execVM '\tg_buildings\scripts\addSmokeEmitter.sqf'";
		};



	};

	class gdi_ba : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_GDI_BA";
		armor = 400;
		accuracy = 1000;

		editorcategory = "tg";
		editorSubcategory = "gdi_buildings";
		editorPreview = "\tg_buildings\ico\gdi_ba.paa";
		model = \tg_buildings\gdi\model\gdi_barracks.p3d;

		aggregateReflectors[] =
		{
			{"Light_1", "Light_2", "Light_3", "Light_4"}
		};

		class Reflectors
		{
			class Light_1
			{
				color[]				= {2500,4000,6000};
				ambient[]			= {2.5,4,6};
				intensity			= 2;
				size				= 1;					/// size of the light point seen from distance
				innerAngle			= 100;					/// angle of full light
				outerAngle			= 165;					/// angle of some light
				coneFadeCoef		= 4;					/// attenuation of light between the above angles

				position			= "Light_1_pos";		/// memory point for start of the light and flare
				direction			= "Light_1_dir";		/// memory point for the light direction
				hitpoint			= "Light_1_hitpoint";	/// point(s) in hitpoint lod for the light (hitPoints are created by engine)
				selection			= "Light_1_hide";		/// selection for artificial glow around the bulb, not much used any more

				useFlare			= true;
				flareSize			= 2;
				flareMaxDistance	= 130;

				class Attenuation
				{
					start			= 0;
					constant		= 0;
					linear			= 0;
					quadratic		= 0.3;

					hardLimitStart	= 50;
					hardLimitEnd	= 65;
				};
			};
			class Light_2: Light_1
			{
				position			= "Light_2_pos";
				direction			= "Light_2_dir";
				hitpoint			= "Light_2_hitpoint";
				selection			= "Light_2_hide";
			};
			class Light_3: Light_1
			{
				position			= "Light_3_pos";
				direction			= "Light_3_dir";
				hitpoint			= "Light_3_hitpoint";
				selection			= "Light_3_hide";
			};
			class Light_4: Light_1
			{
				position			= "Light_4_pos";
				direction			= "Light_4_dir";
				hitpoint			= "Light_4_hitpoint";
				selection			= "Light_4_hide";
			};
		};

		class eventhandlers
		{
			//				[x,y,z],   distance    "soundname", seconds	
			init = [[(_this select 0), [0.0,0.0,0.0]], 20, nil, ["autoplay", 48], nil] execVM "\tg_buildings\scripts\addObjectSFX.sqf"; 
		};
	};

	class gdi_tr : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_GDI_TR";
		armor = 1000;
		accuracy = 1000;	

		editorcategory = "tg";
		editorSubcategory = "gdi_buildings";
		editorPreview = "\tg_buildings\ico\gdi_tr.paa";

		model = \tg_buildings\gdi\model\gdi_tiberiumrefinery.p3d;

		class EventHandlers {			
			init = "[_this select 0, true, 'GREEN'] execVM ""\tg_buildings\scripts\smoke.sqf""";
			
			RegisteredToWorld3DEN = "[_this select 0, true, 'GREEN'] execVM ""\tg_buildings\scripts\smoke.sqf""";
			UnregisteredFromWorld3DEN = "[_this select 0, false] execVM ""\tg_buildings\scripts\smoke.sqf""";
		};

		aggregateReflectors[] =
		{
			{"Light_1", "Light_2"}
		};

		class MarkerLights
		{

			class Tiblight {
				name = "Tiblight";
				color[] = {0.0,0.9,0.0,1};
				ambient[] = {0.0,0.9,0.0,1};

				useFlare = 0;		
				flareSize = 0;
				flareMaxDistance = 1000;

				activeLight = 1;
				drawLight = 1;
				dayLight = 1;

				brightness = 1.3;
				blinking = 0;
				displayName = "Tiblight";
			};

			class Light1
			{
				color[] = {2500, 4000, 6000};
				ambient[] = {0.01, 0.0, 0.0};
				intensity = 0.1;
				name = "Light1";
				useFlare = 1;
				flareSize = 1.7;
				flareMaxDistance = 1000;
				activeLight = 1;

				blinking			= true;					/// lets make it blinking to show how patterns work
				blinkingPattern[]	= {0.25, 1.5};			// 0.25 s flash, 1.25 s period	
				blinkingStartsOn	= true;					/// pattern starts with length of the first flash
				blinkingPatternGuarantee	= true;			/// use this to guarantee all blinks of the patter to be done
															/// doesn't guarantee the length of pattern if true 
															/// (e.g. because of blinks shorter than a frame would take a frame to be seen)

				dayLight = 1;
				drawLight = 1;
				
				class Attenuation {
					start = 0;
					constant = 10;
					linear = 15;
					quadratic = 25;
					hardLimitStart = 5;
					hardLimitEnd = 6;
				};
			};
			class Light2: Light1 {
				name = "Light2";
				blinkingPattern[]	= {0.25, 1.5};			// 0.25 s flash, 1.25 s period			
			};
};
		class Reflectors
		{
			class Light_1
			{
				color[]				= {2500,4000,6000};
				ambient[]			= {2.5,4,6};
				intensity			= 2;
				size				= 0;					/// size of the light point seen from distance
				innerAngle			= 100;					/// angle of full light
				outerAngle			= 165;					/// angle of some light
				coneFadeCoef		= 4;					/// attenuation of light between the above angles

				position			= "Light_1_pos";		/// memory point for start of the light and flare
				direction			= "Light_1_dir";		/// memory point for the light direction
				hitpoint			= "Light_1_hitpoint";	/// point(s) in hitpoint lod for the light (hitPoints are created by engine)
				selection			= "Light_1_hide";		/// selection for artificial glow around the bulb, not much used any more

				useFlare			= true;
				flareSize			= 2;
				flareMaxDistance	= 130;

				class Attenuation
				{
					start			= 0;
					constant		= 0;
					linear			= 0;
					quadratic		= 0.3;

					hardLimitStart	= 50;
					hardLimitEnd	= 65;
				};
			};
			class Light_2: Light_1
			{
				position			= "Light_2_pos";
				direction			= "Light_2_dir";
				hitpoint			= "Light_2_hitpoint";
				selection			= "Light_2_hide";
			};
};

};

	class gdi_ts : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_GDI_TS";
		armor = 200;
		accuracy = 1000;	

		editorcategory = "tg";
		editorSubcategory = "gdi_buildings";
		editorPreview = "\tg_buildings\ico\gdi_ts.paa";

		model = \tg_buildings\gdi\model\gdi_tiberiumsilo.p3d;


		class eventhandlers
		{
			init = "[(_this select 0), 40, ['ElectricEngineSpinUp', 16], ['ElectricEngineHumming', 6], ['ElectricEngineStop', 8], [0.5,0.05]] execVM '\tg_buildings\scripts\addObjectSFX.sqf'";
		};

		class MarkerLights
		{

			class Tiblight {
				name = "Tiblight";
				color[] = {0.0,0.9,0.0,1};
				ambient[] = {0.0,0.9,0.0,1};

				useFlare = 0;		
				flareSize = 0;
				flareMaxDistance = 1000;

				activeLight = 1;
				drawLight = 1;
				dayLight = 1;

				brightness = 1.35;
				blinking = 0;
				displayName = "Tiblight";
			};
};
};

	class gdi_r : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_GDI_R";
		armor = 1000;
		accuracy = 1000;	

		editorcategory = "tg";
		editorSubcategory = "gdi_buildings";
		editorPreview = "\tg_core\Data\gdi.paa";

		model = \tg_buildings\gdi\model\gdi_radar.p3d;

	};

	class gdi_wf : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_GDI_WF";
		armor = 1000;
		accuracy = 1000;	

		editorcategory = "tg";
		editorSubcategory = "gdi_buildings";
		editorPreview = "\tg_core\Data\gdi.paa";

		model = \tg_buildings\gdi\model\gdi_warfactory.p3d;

	};

	class gdi_hp : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_GDI_HP";
		armor = 500;
		accuracy = 1000;	

		editorcategory = "tg";
		editorSubcategory = "gdi_buildings";
		editorPreview = "\tg_buildings\ico\gdi_hp.paa";

		model = \tg_buildings\gdi\model\gdi_helipad.p3d;
	};

	class gdi_cc : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_GDI_CC";
		armor = 300;
		accuracy = 1000;	

		editorcategory = "tg";
		editorSubcategory = "gdi_buildings";
		editorPreview = "\tg_core\Data\gdi.paa";

		model = \tg_buildings\gdi\model\gdi_commandcenter.p3d;
	};

	class gdi_rp : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_GDI_RP";
		armor = 300;
		accuracy = 1000;	

		editorcategory = "tg";
		editorSubcategory = "gdi_buildings";
		editorPreview = "\tg_buildings\ico\gdi_rp.paa";

		model = \tg_buildings\gdi\model\gdi_repairpad.p3d;
	};

	class gdi_ct : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_GDI_CT";
		armor = 250;
		accuracy = 1000;
	
		editorcategory = "tg";
		editorSubcategory = "gdi_buildings";
		editorPreview = "\tg_buildings\ico\gdi_ct.paa";

		model = \tg_buildings\gdi\model\gdi_componenttower.p3d;
	};

	class gdi_w : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_GDI_W";
		armor = 150;
		accuracy = 1000;	

		editorcategory = "tg";
		editorSubcategory = "gdi_buildings";
		editorPreview = "\tg_buildings\ico\gdi_w.paa";

		model = \tg_buildings\gdi\model\gdi_wall.p3d;
	};

	class gdi_w2 : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_GDI_W2";
		armor = 150;
		accuracy = 1000;	

		editorcategory = "tg";
		editorSubcategory = "gdi_buildings";
		editorPreview = "\tg_buildings\ico\gdi_w2.paa";

		model = \tg_buildings\gdi\model\gdi_wall2.p3d;
	};

	class gdi_w3 : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_GDI_W3";
		armor = 150;
		accuracy = 1000;	

		editorcategory = "tg";
		editorSubcategory = "gdi_buildings";
		editorPreview = "\tg_buildings\ico\gdi_w2.paa";

		model = \tg_buildings\gdi\model\gdi_wall3.p3d;
	};

	class gdi_gt : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_GDI_GT";
		armor = 150;
		accuracy = 1000;	

		editorcategory = "tg";
		editorSubcategory = "gdi_buildings";
		editorPreview = "\tg_buildings\ico\gdi_w2.paa";

		model = \tg_buildings\gdi\model\gdi_guardtower.p3d;
	};

	class gdi_g : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_GDI_G";
		armor = 200;
		accuracy = 1000;

		numberOfDoors = 1;

		editorcategory = "tg";
		editorSubcategory = "gdi_buildings";
		editorPreview = "\tg_core\Data\gdi.paa";
		model = \tg_buildings\gdi\model\gdi_gate.p3d;

		class eventhandlers
		{
			init = "(_this select 0) execVM '\tg_buildings\scripts\GateAutoOpen.sqf'";
		};


		class AnimationSources {
			class gdi_gate_source {
				source = "user";
				animPeriod = 0.1;
				initPhase = 0;
			};
		};
	};


	class nod_cy : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_NOD_CY";
		armor = 2000;
		accuracy = 1000;

		editorcategory = "tg";
		editorSubcategory = "nod_buildings";
		editorPreview = "\tg_core\Data\nod.paa";

		model = \tg_buildings\nod\model\nod_conyard.p3d;


		aggregateReflectors[] =
		{
			{"Light_1", "Light_2", "Light_3", "Light_4","Light_5", "Light_6", "Light_7"}
		};

		class MarkerLights
		{
			class Light1
			{
				color[] = {109, 2, 2};
				ambient[] = {109, 2, 2};
				intensity = 5.1;
				name = "Light1";
				useFlare = 1;
				flareSize = 1.7;
				flareMaxDistance = 1000;
				activeLight = 1;

				blinking			= true;					/// lets make it blinking to show how patterns work
				blinkingPattern[]	= {6.25, 1.0};			// 0.25 s flash, 1.25 s period
				blinkingStartsOn	= true;					/// pattern starts with length of the first flash
				blinkingPatternGuarantee	= true;			/// use this to guarantee all blinks of the patter to be done
															/// doesn't guarantee the length of pattern if true 
															/// (e.g. because of blinks shorter than a frame would take a frame to be seen)

				dayLight = 1;
				drawLight = 1;
				
				class Attenuation {
					start = 0;
					constant = 10;
					linear = 15;
					quadratic = 25;
					hardLimitStart = 5;
					hardLimitEnd = 6;
				};
			};
			class Light2: Light1 {
				name = "Light2";
				blinkingPattern[]	= {5.25, 2.0};			// 0.25 s flash, 1.25 s period			
			};
			class Light3: Light1 {
				name = "Light3";
				blinkingPattern[]	= {4.25, 3.0};			// 0.25 s flash, 1.25 s period		
			};
			class Light4: Light1 {
				name = "Light4";
				blinkingPattern[]	= {3.25, 4.0};			// 0.25 s flash, 1.25 s period			
			};
			class Light5: Light1 {
				name = "Light5";
				blinkingPattern[]	= {2.25, 5.0};			// 0.25 s flash, 1.25 s period			
			};
			class Light6: Light1 {
				name = "Light6";
				blinkingPattern[]	= {1.25, 6.0};			// 0.25 s flash, 1.25 s period			
			};
			class Light7: Light1 {
				name = "Light7";
				blinkingPattern[]	= {0.25, 7.0};			// 0.25 s flash, 1.25 s period			
			};
			class Light8: Light1 {
				name = "Light8";
				blinkingPattern[]	= {0.25, 1.0};			// 0.25 s flash, 1.25 s period			
			};
			class Light9: Light1 {
				name = "Light9";
				blinkingPattern[]	= {0.25, 1.0};			// 0.25 s flash, 1.25 s period			
			};
};
		class Reflectors
		{
			class Light_1
			{
				color[]				= {2500, 4000, 6000};
				ambient[]			= {2.5,4,6};
				intensity			= 2;
				size				= 1;					/// size of the light point seen from distance
				innerAngle			= 100;					/// angle of full light
				outerAngle			= 165;					/// angle of some light
				coneFadeCoef		= 4;					/// attenuation of light between the above angles

				position			= "Light_1_pos";		/// memory point for start of the light and flare
				direction			= "Light_1_dir";		/// memory point for the light direction
				hitpoint			= "Light_1_hitpoint";	/// point(s) in hitpoint lod for the light (hitPoints are created by engine)
				selection			= "Light_1_hide";		/// selection for artificial glow around the bulb, not much used any more

				useFlare			= true;
				flareSize			= 2;
				flareMaxDistance	= 130;

				class Attenuation
				{
					start			= 0;
					constant		= 0;
					linear			= 0;
					quadratic		= 0.3;

					hardLimitStart	= 50;
					hardLimitEnd	= 65;
				};
			};
			class Light_2: Light_1
			{
				position			= "Light_2_pos";
				direction			= "Light_2_dir";
				hitpoint			= "Light_2_hitpoint";
				selection			= "Light_2_hide";
			};
			class Light_3: Light_1
			{
				position			= "Light_3_pos";
				direction			= "Light_3_dir";
				hitpoint			= "Light_3_hitpoint";
				selection			= "Light_3_hide";
			};
			class Light_4: Light_1
			{
				position			= "Light_4_pos";
				direction			= "Light_4_dir";
				hitpoint			= "Light_4_hitpoint";
				selection			= "Light_4_hide";
			};
			class Light_5: Light_1
			{
				position			= "Light_5_pos";
				direction			= "Light_5_dir";
				hitpoint			= "Light_5_hitpoint";
				selection			= "Light_5_hide";
			};
			class Light_6: Light_1
			{
				position			= "Light_6_pos";
				direction			= "Light_6_dir";
				hitpoint			= "Light_6_hitpoint";
				selection			= "Light_6_hide";
			};
			class Light_7: Light_1
			{
				position			= "Light_7_pos";
				direction			= "Light_7_dir";
				hitpoint			= "Light_7_hitpoint";
				selection			= "Light_7_hide";
			};
};

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


              class AnimationSources
		{

			class Fan1
			{
				source = "user"; //The controller is defined as a user animation.
				animPeriod = 1;  //The animation period used for this controller.
				initPhase = 0;     //Initial phase when object is created. 0 = CLOSED	
			};
                        class Fan2
			{
				source = "user"; //The controller is defined as a user animation.
				animPeriod = 1;  //The animation period used for this controller.
				initPhase = 0;     //Initial phase when object is created. 0 = CLOSED		
			};
                        class Fan3
			{
				source = "user"; //The controller is defined as a user animation.
				animPeriod = 1;  //The animation period used for this controller.
				initPhase = 0;     //Initial phase when object is created. 0 = CLOSED		
			};
                        class TurnLight
			{
				source = "user"; //The controller is defined as a user animation.
				animPeriod = 1;  //The animation period used for this controller.
				initPhase = 0;     //Initial phase when object is created. 0 = CLOSED		
			};		
};



	};
	
	class nod_hon : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_NOD_HON";
		armor = 400;
		accuracy = 1000;

		editorcategory = "tg";
		editorSubcategory = "nod_buildings";
		editorPreview = "\tg_core\Data\nod.paa";

		model = \tg_buildings\nod\model\nod_handofnod.p3d;

		aggregateReflectors[] =
		{
			{"Light_1"}
		};

		class MarkerLights
		{
			class Light1
			{
				color[] = {109, 2, 2};
				ambient[] = {109, 2, 2};
				intensity = 5.1;
				name = "Light1";
				useFlare = 1;
				flareSize = 1.2;
				flareMaxDistance = 1000;
				activeLight = 1;

				blinking			= false;					/// lets make it blinking to show how patterns work
				blinkingPattern[]	= {6.25, 1.0};			// 0.25 s flash, 1.25 s period
				blinkingStartsOn	= true;					/// pattern starts with length of the first flash
				blinkingPatternGuarantee	= true;			/// use this to guarantee all blinks of the patter to be done
															/// doesn't guarantee the length of pattern if true 
															/// (e.g. because of blinks shorter than a frame would take a frame to be seen)

				dayLight = 1;
				drawLight = 1;
				
				class Attenuation {
					start = 0;
					constant = 10;
					linear = 15;
					quadratic = 25;
					hardLimitStart = 5;
					hardLimitEnd = 6;
				};
			};
			class Light2: Light1 {
				name = "Light2";
				blinkingPattern[]	= {5.25, 2.0};			// 0.25 s flash, 1.25 s period			
			};
			class Light3: Light1 {
				name = "Light3";
				blinkingPattern[]	= {4.25, 3.0};			// 0.25 s flash, 1.25 s period		
			};
			class Light4: Light1 {
				name = "Light4";
				blinkingPattern[]	= {3.25, 4.0};			// 0.25 s flash, 1.25 s period			
			};
			class Light5: Light1 {
				name = "Light5";
				blinkingPattern[]	= {2.25, 5.0};			// 0.25 s flash, 1.25 s period			
			};
			class Light6: Light1 {
				name = "Light6";
				blinkingPattern[]	= {1.25, 6.0};			// 0.25 s flash, 1.25 s period			
			};
			class Light7: Light1 {
				name = "Light7";
				blinkingPattern[]	= {0.25, 7.0};			// 0.25 s flash, 1.25 s period			
			};
			class Light8: Light1 {
				name = "Light8";
				blinkingPattern[]	= {0.25, 1.0};			// 0.25 s flash, 1.25 s period			
			};
			class Light9: Light1 {
				name = "Light9";
				blinkingPattern[]	= {0.25, 1.0};			// 0.25 s flash, 1.25 s period			
			};
};
		class Reflectors
		{
			class Light_1
			{
				color[]				= {2500, 4000, 6000};
				ambient[]			= {2.5,4,6};
				intensity			= 2;
				size				= 1;					/// size of the light point seen from distance
				innerAngle			= 100;					/// angle of full light
				outerAngle			= 165;					/// angle of some light
				coneFadeCoef		= 4;					/// attenuation of light between the above angles

				position			= "Light_1_pos";		/// memory point for start of the light and flare
				direction			= "Light_1_dir";		/// memory point for the light direction
				hitpoint			= "Light_1_hitpoint";	/// point(s) in hitpoint lod for the light (hitPoints are created by engine)
				selection			= "Light_1_hide";		/// selection for artificial glow around the bulb, not much used any more

				useFlare			= true;
				flareSize			= 2;
				flareMaxDistance	= 130;

				class Attenuation
				{
					start			= 0;
					constant		= 0;
					linear			= 0;
					quadratic		= 0.3;

					hardLimitStart	= 50;
					hardLimitEnd	= 65;
				};
			};
};


	};

	class nod_tr : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_NOD_TR";
		armor = 1000;
		accuracy = 1000;	

		editorcategory = "tg";
		editorSubcategory = "nod_buildings";
		editorPreview = "\tg_core\Data\nod.paa";

		model = \tg_buildings\nod\model\nod_tiberiumrefinery.p3d;
	};

	class nod_pp : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_NOD_PP";
		armor = 1000;
		accuracy = 1000;	

		editorcategory = "tg";
		editorSubcategory = "nod_buildings";
		editorPreview = "\tg_core\Data\nod.paa";

		model = \tg_buildings\nod\model\nod_powerplant.p3d;
	};

	class nod_ts : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_NOD_TS";
		armor = 250;
		accuracy = 1000;	

		editorcategory = "tg";
		editorSubcategory = "nod_buildings";
		editorPreview = "\tg_core\Data\nod.paa";

		model = \tg_buildings\nod\model\nod_tiberiumsilo.p3d;

		class eventhandlers
		{
			init = "[(_this select 0), 40, ['ElectricEngineSpinUp', 16], ['ElectricEngineHumming', 6], ['ElectricEngineStop', 8], [0.5,0.05]] execVM '\tg_buildings\scripts\addObjectSFX.sqf'";
		};

			class MarkerLights
		{

			class Tiblight {
				name = "Tiblight";
				color[] = {0.0,0.9,0.0,1};
				ambient[] = {0.0,0.9,0.0,1};

				useFlare = 0;		
				flareSize = 0;
				flareMaxDistance = 1000;

				activeLight = 1;
				drawLight = 1;
				dayLight = 1;

				brightness = 1.35;
				blinking = 0;
				displayName = "Tiblight";
			};
};
};

	class nod_r : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_NOD_R";
		armor = 1000;
		accuracy = 1000;	

		editorcategory = "tg";
		editorSubcategory = "nod_buildings";
		editorPreview = "\tg_core\Data\nod.paa";

		model = \tg_buildings\nod\model\nod_radar.p3d;
	};

	class nod_w : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_NOD_W";
		armor = 1000;
		accuracy = 1000;

		keepInEPESceneAfterDeath = 1;	

		editorcategory = "tg";
		editorSubcategory = "nod_buildings";
		editorPreview = "\tg_core\Data\nod.paa";

		model = \tg_buildings\nod\model\nod_wall.p3d;
	};

	class nod_g : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_NOD_G";
		armor = 1500;
		accuracy = 1000;

		numberOfDoors = 1;

		editorcategory = "tg";
		editorSubcategory = "nod_buildings";
		editorPreview = "\tg_core\Data\nod.paa";
		model = \tg_buildings\nod\model\nod_gate.p3d;

		class eventhandlers
		{
			init = "(_this select 0) execVM '\tg_buildings\scripts\GateAutoOpen.sqf'";
		};

		class AnimationSources {
			class nod_gate_source {
				source = "user";
				animPeriod = 0.2;
				initPhase = 0;
			};
		};
	};

	class nod_lf : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_NOD_LF";
		armor = 150;
		accuracy = 1000;	

		editorcategory = "tg";
		editorSubcategory = "nod_buildings";
		editorPreview = "\tg_core\Data\nod.paa";

		model = \tg_buildings\nod\model\nod_laserfence.p3d;

             class Animations
		{
			class Las1
			{
				type = "rotation";
				animPeriod = 2;
				selection = "Las1";
				axis = "osa_las1";
				angle0 = 0;
				minValue = 0;
				maxValue = 1;
				source = "time";
				sourceAddress = "loop";
				angle1 = rad 360";
			};
                        class Las2
			{
				type = "rotation";
				animPeriod = 2;
				selection = "Las2";
				axis = "osa_las2";
				angle0 = 0;
				minValue = 0;
				maxValue = 1;
				source = "time";
				sourceAddress = "loop";
				angle1 = rad 360";
			};
                        class Las3
			{
				type = "rotation";
				animPeriod = 2;
				selection = "Las3";
				axis = "osa_las3";
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


              class AnimationSources
		{

			class Las1
			{
				source = "user"; //The controller is defined as a user animation.
				animPeriod = 1;  //The animation period used for this controller.
				initPhase = 0;     //Initial phase when object is created. 0 = CLOSED	
			};
                        class Las2
			{
				source = "user"; //The controller is defined as a user animation.
				animPeriod = 1;  //The animation period used for this controller.
				initPhase = 0;     //Initial phase when object is created. 0 = CLOSED		
			};
                        class Las3
			{
				source = "user"; //The controller is defined as a user animation.
				animPeriod = 1;  //The animation period used for this controller.
				initPhase = 0;     //Initial phase when object is created. 0 = CLOSED		
			};
                        class TurnLight
			{
				source = "user"; //The controller is defined as a user animation.
				animPeriod = 1;  //The animation period used for this controller.
				initPhase = 0;     //Initial phase when object is created. 0 = CLOSED		
			};		
};


		class eventhandlers
		{
			init="[_this select 0,_this select 1] execVM ""\tg_buildings\scripts\LasF.sqf""";   
		};



	};



	class civ_sp : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_CIV_SP";
		armor = 100;
		accuracy = 1000;

		editorcategory = "tg";
		editorSubcategory = "civ_buildings";
		editorPreview = "\tg_core\Data\nod.paa";

		model = \tg_buildings\civ\model\civ_solar.p3d;
	};

	class civ_sub : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_CIV_SUB";
		armor = 150;
		accuracy = 1000;

		editorcategory = "tg";
		editorSubcategory = "civ_buildings";
		editorPreview = "\tg_core\Data\nod.paa";

		model = \tg_buildings\civ\model\civ_sub.p3d;
	};

	class civ_tank : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_CIV_TANK";
		armor = 150;
		accuracy = 1000;

		editorcategory = "tg";
		editorSubcategory = "civ_buildings";
		editorPreview = "\tg_core\Data\nod.paa";

		model = \tg_buildings\civ\model\civ_tank.p3d;
	};

	class civ_of1 : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_CIV_OF1";
		armor = 400;
		accuracy = 1000;

		editorcategory = "tg";
		editorSubcategory = "civ_buildings";
		editorPreview = "\tg_core\Data\nod.paa";

		model = \tg_buildings\civ\model\civ_office1.p3d;
	};

	class civ_of2 : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_CIV_OF2";
		armor = 400;
		accuracy = 1000;

		editorcategory = "tg";
		editorSubcategory = "civ_buildings";
		editorPreview = "\tg_core\Data\nod.paa";

		model = \tg_buildings\civ\model\civ_office2.p3d;
	};

	class civ_lp1 : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_CIV_LP1";
		armor = 50;
		accuracy = 1000;

		editorcategory = "tg";
		editorSubcategory = "civ_buildings";
		editorPreview = "\tg_core\Data\nod.paa";

		model = \tg_buildings\civ\model\civ_lightpost1.p3d;
	};

	class civ_lp2 : House_F {
		scope = public;
		scopeCurator = public;
		displayName = "$STR_CIV_LP2";
		armor = 50;
		accuracy = 1000;

		editorcategory = "tg";
		editorSubcategory = "civ_buildings";
		editorPreview = "\tg_core\Data\nod.paa";

		model = \tg_buildings\civ\model\civ_lightpost2.p3d;
	};
};


class CfgFunctions 
{
	class Tiberian_Genesis {
		class Main 
		{
			class init {
				file = "\tg_buildings\init.sqf";	
				postInit = 1;
			};
		};
	};
};	