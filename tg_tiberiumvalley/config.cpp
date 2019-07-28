class CfgPatches {
	class tg_tiberiumvalley {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		fileName = "tg_tiberiumvalley.pbo";
		author = "Tiberian Genesis";
		requiredAddons[] = {"A3_Data_F", "A3_Roads_F", "A3_Structures_F", "A3_Map_Data"};
		newRoadsShape = "tg_tiberiumvalley\data\roads\roads.shp";
	};
};

class CfgVehicles {};

class CfgWorlds {
	class DefaultWorld {
		class Weather {
			class Overcast;	// External class reference
		};
	};
	
	class CAWorld : DefaultWorld {
		class Grid {};
		class DayLightingBrightAlmost;	// External class reference
		class DayLightingRainy;	// External class reference
		class DefaultClutter;	// External class reference
		
		class Weather : Weather {
			class Lighting;	// External class reference
			
			class Overcast : Overcast {
				class Weather1;	// External class reference
				class Weather2;	// External class reference
				class Weather3;	// External class reference
				class Weather4;	// External class reference
				class Weather5;	// External class reference
				class Weather6;	// External class reference
			};
		};
	};
	class DefaultLighting;	// External class reference
	

	class tg_tiberiumvalley : CAWorld {

		cutscenes[] = {};
		description = "C&C Tiberium Valley";
		worldName = "tg_tiberiumvalley\tg_tiberiumvalley.wrp";
		longitude = 65;	// positive is east
		latitude = -34;	// positive is south
		envTexture = "A3\Data_f\env_land_ca.paa";
		pictureMap = "tg_tiberiumvalley\data\pictureMap_ca.paa";
		pictureShot = "tg_tiberiumvalley\data\ui_Schultz_ca.paa";
		plateFormat = "A#$-####";
		plateLetters = ABCDEGHIKLMNOPRSTVXZ;
		author = "Tiberian Genesis";
		ilsPosition[] = {4772, 10923, 24.7};
		ilsDirection[] = {0, 0.08, -1};
		ilsTaxiOff[] = {4772, 10923, 4772, 11801, 4780, 11809, 4833, 11809, 4841, 11801, 4841, 11323};
		ilsTaxiIn[] = {4841, 11323, 4841, 11018, 4833, 11010, 4780, 11010, 4772, 11028, 4772, 11073};
		enableTracks = 1;
		enableFootsteps = 1;
		enableBloodSplashes = 1;
		newRoadsShape = "tg_tiberiumvalley\data\roads\roads.shp";
		
		class OutsideTerrain {
			satellite = "tg_tiberiumvalley\data\s_satout_co.paa";
			enableTerrainSynth = 1;
			
			class Layers {
				class Layer0 {
					nopx = "tg_tiberiumvalley\data\tk_hlina_nopx.paa";
					texture = "tg_tiberiumvalley\data\tk_hlina_co.paa";
				};
			};
		};
		
		class HDRNewPars {
			minAperture = 1e-005;
			maxAperture = 256;
			apertureRatioMax = 4;
			apertureRatioMin = 10;
			bloomImageScale = 1;
			bloomScale = 0.15;
			bloomExponent = 1.3;
			bloomLuminanceOffset = 0.75;
			bloomLuminanceScale = 0.75;
			bloomLuminanceExponent = 0.75;
			tonemapMethod = 1;
			tonemapShoulderStrength = 6.8;
			tonemapLinearStrength = 0.8;
			tonemapLinearAngle = 0.8;
			tonemapToeStrength = 0.6;
			tonemapToeNumerator = 2.35;
			tonemapToeDenominator = 8;
			tonemapLinearWhite = 4;
			tonemapExposureBias = 1;
			tonemapLinearWhiteReinhard = "2.5f";
			nvgApertureStandard = 0.11;
			nvgApertureMin = 0.1;
			nvgApertureMax = 5.5;
			nvgStandardAvgLum = 0.5;
			nvgLightGain = 0.1;
			nvgTransition = 1;
			nvgTransitionCoefOn = "40.0f";
			nvgTransitionCoefOff = "0.01f";
			nightShiftMinAperture = 0;
			nightShiftMaxAperture = 0.002;
			nightShiftMaxEffect = 0.6;
			nightShiftLuminanceScale = 600;
			eyeAdaptFactorLight = 3;
			eyeAdaptFactorDark = 1.3;
		};
		
		class Lighting : DefaultLighting {
			groundReflection[] = {0.132, 0.133, 0.122};
			moonObjectColorFull[] = {550, 500, 450, 1};
			moonHaloObjectColorFull[] = {20, 20, 20, 0.5};
			moonsetObjectColor[] = {275, 250, 225, 1};
			moonsetHaloObjectColor[] = {10, 10, 10, 0.25};
			
			class ThunderBoltLight {
				diffuse[] = {0, 205, 0};
				ambient[] = {0, 205, 0};
				intensity = 120000;
				
				class Attenuation {
					start = 0;
					constant = 0;
					linear = 0;
					quadratic = 1;
				};
			};
			starEmissivity = 0;
		};
		
		class DayLightingBrightAlmost : DayLightingBrightAlmost {
			deepNight[] = {8, {{0.98, 0.85, 0.8}, 8.37+(-4)}, {{0.08, 0.09, 0.11}, 6.42+(-4)}, {{0.87, 0.47, 0.25}, 7.87+(-4)}, {{0.09, 0.09, 0.1}, 6.89+(-4)}, {{0.5, 0.4, 0.4}, 8.9+(-4)}, {{0.88, 0.51, 0.24}, 10.88+(-4)}, 1};
			fullNight[] = {8, {{0.98, 0.85, 0.8}, 8.37+(-4)}, {{0.08, 0.09, 0.11}, 6.42+(-4)}, {{0.87, 0.47, 0.25}, 7.87+(-4)}, {{0.09, 0.09, 0.1}, 6.89+(-4)}, {{0.5, 0.4, 0.4}, 8.9+(-4)}, {{0.88, 0.51, 0.24}, 10.88+(-4)}, 1};
			sunMoon[] = {8, {{0.98, 0.85, 0.8}, 8.37+(-4)}, {{0.08, 0.09, 0.11}, 6.42+(-4)}, {{0.87, 0.47, 0.25}, 7.87+(-4)}, {{0.09, 0.09, 0.1}, 6.89+(-4)}, {{0.5, 0.4, 0.4}, 8.9+(-4)}, {{0.88, 0.51, 0.24}, 10.88+(-4)}, 1};
			earlySun[] = {8, {{0.98, 0.85, 0.8}, 8.37+(-4)}, {{0.08, 0.09, 0.11}, 6.42+(-4)}, {{0.87, 0.47, 0.25}, 7.87+(-4)}, {{0.09, 0.09, 0.1}, 6.89+(-4)}, {{0.5, 0.4, 0.4}, 8.9+(-4)}, {{0.88, 0.51, 0.24}, 10.88+(-4)}, 1};
			sunrise[] = {8, {{0.98, 0.85, 0.8}, 8.37+(-4)}, {{0.08, 0.09, 0.11}, 6.42+(-4)}, {{0.87, 0.47, 0.25}, 7.87+(-4)}, {{0.09, 0.09, 0.1}, 6.89+(-4)}, {{0.5, 0.4, 0.4}, 8.9+(-4)}, {{0.88, 0.51, 0.24}, 10.88+(-4)}, 1};
			earlyMorning[] = {8, {{0.98, 0.85, 0.8}, 8.37+(-4)}, {{0.08, 0.09, 0.11}, 6.42+(-4)}, {{0.87, 0.47, 0.25}, 7.87+(-4)}, {{0.09, 0.09, 0.1}, 6.89+(-4)}, {{0.5, 0.4, 0.4}, 8.9+(-4)}, {{0.88, 0.51, 0.24}, 10.88+(-4)}, 1};
			midMorning[] = {8, {{0.98, 0.85, 0.8}, 8.37+(-4)}, {{0.08, 0.09, 0.11}, 6.42+(-4)}, {{0.87, 0.47, 0.25}, 7.87+(-4)}, {{0.09, 0.09, 0.1}, 6.89+(-4)}, {{0.5, 0.4, 0.4}, 8.9+(-4)}, {{0.88, 0.51, 0.24}, 10.88+(-4)}, 1};
			morning[] = {8, {{0.98, 0.85, 0.8}, 8.37+(-4)}, {{0.08, 0.09, 0.11}, 6.42+(-4)}, {{0.87, 0.47, 0.25}, 7.87+(-4)}, {{0.09, 0.09, 0.1}, 6.89+(-4)}, {{0.5, 0.4, 0.4}, 8.9+(-4)}, {{0.88, 0.51, 0.24}, 10.88+(-4)}, 1};
			noon[] = {8, {{0.98, 0.85, 0.8}, 8.37+(-4)}, {{0.08, 0.09, 0.11}, 6.42+(-4)}, {{0.87, 0.47, 0.25}, 7.87+(-4)}, {{0.09, 0.09, 0.1}, 6.89+(-4)}, {{0.5, 0.4, 0.4}, 8.9+(-4)}, {{0.88, 0.51, 0.24}, 10.88+(-4)}, 1};
		};
		
		class DayLightingRainy : DayLightingRainy {
			deepNight[] = {8, {{0.98, 0.85, 0.8}, 8.37+(-4)}, {{0.08, 0.09, 0.11}, 6.42+(-4)}, {{0.87, 0.47, 0.25}, 7.87+(-4)}, {{0.09, 0.09, 0.1}, 6.89+(-4)}, {{0.5, 0.4, 0.4}, 8.9+(-4)}, {{0.88, 0.51, 0.24}, 10.88+(-4)}, 1};
			fullNight[] = {8, {{0.98, 0.85, 0.8}, 8.37+(-4)}, {{0.08, 0.09, 0.11}, 6.42+(-4)}, {{0.87, 0.47, 0.25}, 7.87+(-4)}, {{0.09, 0.09, 0.1}, 6.89+(-4)}, {{0.5, 0.4, 0.4}, 8.9+(-4)}, {{0.88, 0.51, 0.24}, 10.88+(-4)}, 1};
			sunMoon[] = {8, {{0.98, 0.85, 0.8}, 8.37+(-4)}, {{0.08, 0.09, 0.11}, 6.42+(-4)}, {{0.87, 0.47, 0.25}, 7.87+(-4)}, {{0.09, 0.09, 0.1}, 6.89+(-4)}, {{0.5, 0.4, 0.4}, 8.9+(-4)}, {{0.88, 0.51, 0.24}, 10.88+(-4)}, 1};
			earlySun[] = {8, {{0.98, 0.85, 0.8}, 8.37+(-4)}, {{0.08, 0.09, 0.11}, 6.42+(-4)}, {{0.87, 0.47, 0.25}, 7.87+(-4)}, {{0.09, 0.09, 0.1}, 6.89+(-4)}, {{0.5, 0.4, 0.4}, 8.9+(-4)}, {{0.88, 0.51, 0.24}, 10.88+(-4)}, 1};
			sunrise[] = {8, {{0.98, 0.85, 0.8}, 8.37+(-4)}, {{0.08, 0.09, 0.11}, 6.42+(-4)}, {{0.87, 0.47, 0.25}, 7.87+(-4)}, {{0.09, 0.09, 0.1}, 6.89+(-4)}, {{0.5, 0.4, 0.4}, 8.9+(-4)}, {{0.88, 0.51, 0.24}, 10.88+(-4)}, 1};
			earlyMorning[] = {8, {{0.98, 0.85, 0.8}, 8.37+(-4)}, {{0.08, 0.09, 0.11}, 6.42+(-4)}, {{0.87, 0.47, 0.25}, 7.87+(-4)}, {{0.09, 0.09, 0.1}, 6.89+(-4)}, {{0.5, 0.4, 0.4}, 8.9+(-4)}, {{0.88, 0.51, 0.24}, 10.88+(-4)}, 1};
			midMorning[] = {8, {{0.98, 0.85, 0.8}, 8.37+(-4)}, {{0.08, 0.09, 0.11}, 6.42+(-4)}, {{0.87, 0.47, 0.25}, 7.87+(-4)}, {{0.09, 0.09, 0.1}, 6.89+(-4)}, {{0.5, 0.4, 0.4}, 8.9+(-4)}, {{0.88, 0.51, 0.24}, 10.88+(-4)}, 1};
			morning[] = {8, {{0.98, 0.85, 0.8}, 8.37+(-4)}, {{0.08, 0.09, 0.11}, 6.42+(-4)}, {{0.87, 0.47, 0.25}, 7.87+(-4)}, {{0.09, 0.09, 0.1}, 6.89+(-4)}, {{0.5, 0.4, 0.4}, 8.9+(-4)}, {{0.88, 0.51, 0.24}, 10.88+(-4)}, 1};
			noon[] = {8, {{0.98, 0.85, 0.8}, 8.37+(-4)}, {{0.08, 0.09, 0.11}, 6.42+(-4)}, {{0.87, 0.47, 0.25}, 7.87+(-4)}, {{0.09, 0.09, 0.1}, 6.89+(-4)}, {{0.5, 0.4, 0.4}, 8.9+(-4)}, {{0.88, 0.51, 0.24}, 10.88+(-4)}, 1};
		};
		skyColorInfluencesFogColor = 0;
		
		class Weather : Weather {
			class LightingNew {
				class Lighting0 {
					height = -0.001;
					overcast = 0.4;
					sunAngle = 2;
					sunOrMoon = 1;
					diffuse[] = {{0.77, 0.37044, 0.194}, 7.018};
					diffuseCloud[] = {{0, 0, 0}, 0.392753};
					ambient[] = {{205, 179, 139}, 7.500};
					ambientCloud[] = {{205, 179, 139}, 7.500};
					ambientMid[] = {{205, 179, 139}, 7.500};
					ambientMidCloud[] = {{205, 179, 139}, 7.500};
					groundReflection[] = {{205, 179, 139}, 4.500};
					groundReflectionCloud[] = {{205, 179, 139}, 4.500};
					bidirect[] = {0, 0, 0};
					bidirectCloud[] = {0, 0, 0};
					sky[] = {86, 61, 32};
					skyAroundSun[] = {86, 61, 32};
					fogColor[] = {86, 61, 32};
					apertureMin = 9;
					apertureStandard = 12;
					apertureMax = 20;
					standardAvgLum = 60;
					desiredLuminanceCoef = 0;
					desiredLuminanceCoefCloud = 0;
					luminanceRectCoef = 1;
					luminanceRectCoefCloud = 1;
					rayleigh[] = {0.00749, 0.01388, 0.02878};
					mie[] = {0.0046, 0.0046, 0.0046};
					cloudsColor[] = {86, 61, 32};
					swBrightness = 1;
				};
			};
			
			class Lighting : Lighting {
				class BrightAlmost : DayLightingBrightAlmost {
					overcast = 0;
				};
				
				class Rainy : DayLightingRainy {
					overcast = 1;
				};
			};
			
			class Overcast : Overcast {
				class Weather1 : Weather1 {
					sky = "A3\Map_Stratis\Data\sky_clear_gs.paa";
					horizon = "A3\Map_Stratis\Data\sky_clear_horizont_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_clear_lco.paa";
				};
				
				class Weather7 : Weather1 {
					sky = "A3\Map_Stratis\Data\sky_clear_gs.paa";
					horizon = "A3\Map_Stratis\Data\sky_clear_horizont_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_clear_lco.paa";
				};
				
				class Weather2 : Weather2 {
					sky = "A3\Map_Stratis\Data\sky_clear_gs.paa";
					horizon = "A3\Map_Stratis\Data\sky_clear_horizont_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_almostclear_lco.paa";
				};
				
				class Weather3 : Weather3 {
					sky = "A3\Map_Stratis\Data\sky_clear_gs.paa";
					horizon = "A3\Map_Stratis\Data\sky_clear_horizont_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_cloudy_lco.paa";
				};
				
				class Weather4 : Weather4 {
					sky = "A3\Map_Stratis\Data\sky_clear_gs.paa";
					horizon = "A3\Map_Stratis\Data\sky_clear_horizont_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_cloudy_lco.paa";
				};
				
				class Weather5 : Weather5 {
					sky = "A3\Map_Stratis\Data\sky_clear_gs.paa";
					horizon = "A3\Map_Stratis\Data\sky_clear_horizont_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_overcast_lco.paa";
				};
				
				class Weather6 : Weather6 {
					sky = "A3\Map_Stratis\Data\sky_clear_gs.paa";
					horizon = "A3\Map_Stratis\Data\sky_clear_horizont_sky.paa";
					skyR = "A3\Map_Stratis\Data\sky_overcast_lco.paa";
				};
			};
		};
		
		class SimulWeather {
			noiseTexture = "a3\data_f\noise_raw.paa";
			numKeyframesPerDay = 48;
			windSpeedCoef = "10.0f";
			moonIrradianceCoef = "10.0f";
			fadeMaxDistanceKm = 1000;
			fadeMaxAltitudeKm = 15;
			fadeNumAltitudes = 8;
			fadeNumElevations = 8;
			fadeNumDistances = 8;
			fadeEarthTest = 1;
			autoBrightness = 0;
			autoBrightnessStrength = 0.1;
			cloudGridWidth = 96;
			cloudGridLength = 96;
			cloudGridHeight = 16;
			helperGridElevationSteps = 24;
			helperGridAzimuthSteps = 15;
			helperEffectiveEarthRadius = 1000000;
			helperCurvedEarth = 1;
			helperAdjustCurvature = 0;
			helperNumLayers = 120;
			helperMaxDistance = 160000;
			helperNearCloudFade = 0.1;
			helperChurn = 100;
			cloudWidth = 40000;
			cloudLength = 40000;
			wrapClouds = 1;
			noiseResolution = 8;
			noisePeriod = 4;
			opticalDensity = 0.5;
			alphaSharpness = 0.88;
			selfShadowScale = 0.935;
			mieAsymmetry = 0.5087;
			minimumLightElevationDegrees = 6;
			directLightCoef = 1;
			indirectLightCoef = 0.04;
			fogStart = 0;
			fogEnd = 50000;
			fogHeight = 2000;
			
			class DefaultKeyframe {
				rayleigh[] = {0.00749, 0.01388, 0.02878};
				mie[] = {0.0046, 0.0046, 0.0046};
				haze = 30;
				hazeBaseKm = 1;
				hazeScaleKm = 0.2;
				hazeEccentricity = 1;
				brightnessAdjustment = 1;
				cloudiness = 0.6;
				cloudBaseKm = 0.2;
				cloudHeightKm = 7;
				directLight = 1;
				indirectLight = 1;
				ambientLight = 0.2;
				noiseOctaves = 4.3;
				noisePersistence = 0.535;
				fractalAmplitude = 2.3;
				fractalWavelength = 240;
				extinction = 8.4;
				diffusivity = 0.001;
				churn = 10;
				rainEffectStrength = 1;
			};
			
			class Overcast {
				class Weather1 : DefaultKeyframe {
					overcast = 0;
					cloudiness = 0.55;
					diffusivity = 0.001;
					extinction = 3.9;
					seqFileKeyframe = 0;
				};
				
				class Weather2 : DefaultKeyframe {
					overcast = 0.2;
					cloudiness = 0.58;
					diffusivity = 0.001;
					extinction = 4.3;
					seqFileKeyframe = 0;
				};
				
				class Weather3 : DefaultKeyframe {
					overcast = 0.4;
					cloudiness = 0.63;
					diffusivity = 0.001;
					extinction = 6;
					seqFileKeyframe = 3;
				};
				
				class Weather4 : DefaultKeyframe {
					overcast = 0.6;
					cloudiness = 0.75;
					diffusivity = 0.001;
					extinction = 7;
					seqFileKeyframe = 4;
				};
				
				class Weather5 : DefaultKeyframe {
					overcast = 0.8;
					cloudiness = 0.83;
					diffusivity = 0.001;
					extinction = 7.3;
					cloudBaseKm = 0.2;
					cloudHeightKm = 8;
					seqFileKeyframe = 4;
				};
				
				class Weather6 : DefaultKeyframe {
					overcast = 1;
					cloudiness = 0.9;
					diffusivity = 0.001;
					extinction = 8.3;
					cloudBaseKm = 0.2;
					cloudHeightKm = 10;
					seqFileKeyframe = 4;
				};
			};
		};
		hazeDistCoef = 0.1;
		hazeFogCoef = 0.98;
		hazeBaseHeight = 0;
		hazeBaseBeta0 = 6e-005;
		hazeDensityDecay = 0.0001;
		horizonParallaxCoef = 0;
		horizonFogColorationStart = "0.8f";
		skyFogColorationStart = "0.7f";
		skyObject = "A3\Map_Stratis\data\obloha.p3d";
		horizontObject = "A3\Map_Stratis\data\horizont.p3d";
		skyTexture = "A3\Map_Stratis\data\sky_semicloudy_sky.paa";
		skyTextureR = "A3\Map_Stratis\data\sky_semicloudy_lco.paa";
		
		class Grid : Grid {
			offsetX = 0;
			offsetY = 8192;
			
			class Zoom1 {
				zoomMax = 0.15;
				format = "XY";
				formatX = 000;
				formatY = 000;
				stepX = 100;
				stepY = -100;
			};
			
			class Zoom2 {
				zoomMax = 0.85;
				format = "XY";
				formatX = "00";
				formatY = "00";
				stepX = 1000;
				stepY = -1000;
			};
			
			class Zoom3 {
				zoomMax = 1e+030;
				format = "XY";
				formatX = "0";
				formatY = "0";
				stepX = 10000;
				stepY = -10000;
			};
		};
		startTime = 13:37;
		startDate = 28/5/2035;
		startWeather = 0;
		startFog = 0;
		forecastWeather = 0;
		forecastFog = 0;
		centerPosition[] = {4096, 4096, 300};
		seagullPos[] = {1800, 150, 1800};
		
		class Sea {
			seaTexture = "a3\data_f\seatexture_co.paa";
			seaMaterial = "#water";
			shoreMaterial = "#shore";
			shoreFoamMaterial = "#shorefoam";
			shoreWetMaterial = "#shorewet";
			WaterMapScale = 20;
			WaterGrid = 50;
			MaxTide = 0;
			MaxWave = 0.25;
			SeaWaveXScale = 2.0/50;
			SeaWaveZScale = 1.0/50;
			SeaWaveHScale = 1;
			SeaWaveXDuration = 5000;
			SeaWaveZDuration = 10000;
		};
		
		class Underwater {
			noWaterFog = -0.3;
			fullWaterFog = 0.1;
			deepWaterFog = 60;
			waterFogDistanceNear = 0;
			waterFogDistance = 50;
			waterColor[] = {0, 0.05, 0.053};
			deepWaterColor[] = {0, 0.05, 0.053};
			surfaceColor[] = {0, 0, 0};
			deepSurfaceColor[] = {0, 0, 0};
		};
		
		class SeaWaterShaderPars {
			refractionMoveCoef = 0.03;
			minWaterOpacity = 0;
			waterOpacityDistCoef = 0.4;
			underwaterOpacity = 0.5;
			waterOpacityFadeStart = 60;
			waterOpacityFadeLength = 120;
		};
		causticsEnabled = 1;
		causticsTextureMask = "A3\data_f\caustics\caustics_anim_%03d.paa";
		causticsTextureCount = 32;
		causticsTextureArea = "4.0f";
		causticsTextureAreaDeep = "65.0f";
		causticsTextureChangeInterval = "0.09f";
		causticsDistanceLimit = "80.0f";
		causticsDepthLimit = "50.0f";
		causticsDepthFadeCoef = "1.0f";
		causticsTextureDepthGranularity = "3.0f";
		causticsBrightnessCoef = "20.0f";
		
		class ReplaceObjects {};
		
		class Sounds {
			sounds[] = {};
		};
		
		class Animation {
			vehicles[] = {};
		};
		minTreesInForestSquare = 3;
		minRocksInRockSquare = 3;
		
		class clutter {};
		
		class Ambient {};
		
		class Names {};
	};
};

class CfgSurfaces {
	class Default {};
	
	class Water {};
	
	class tg_desertground : Default {
		access = ReadOnly;
		files = "tg_desertground_*";
		character = "Empty";
		soundEnviron = "dirt";
		soundHit = "soft_ground";
		rough = 0.01;
		dust = 0.5;
		lucidity = 1;
		grassCover = 0.0;
		surfaceFriction = 1.4;
		restitution = 0.19;
		maxSpeedCoef = 1.0;
		maxClutterColoringCoef = 1.35;
	};
	
	class tg_cliff : Default {
		access = ReadOnly;
		files = "tg_cliff_*";
		character = "Empty";
		soundEnviron = "dirt";
		soundHit = "soft_ground";
		rough = 0.09;
		dust = 0.5;
		lucidity = 1;
		grassCover = 0.0;
		surfaceFriction = 1.4;
		restitution = 0.19;
		maxSpeedCoef = 0.9;
		maxClutterColoringCoef = 1.35;
	};
	
	class tg_tiberium : Default {
		access = ReadOnly;
		files = "tg_tiberium_*";
		character = "Empty";
		soundEnviron = "dirt";
		soundHit = "soft_ground";
		rough = 0.09;
		dust = 0.5;
		lucidity = 1;
		grassCover = 0.0;
		surfaceFriction = 1.4;
		restitution = 0.19;
		maxSpeedCoef = 0.9;
		maxClutterColoringCoef = 1.35;
	};

	class tg_tiberiumb : Default {
		access = ReadOnly;
		files = "tg_tiberiumb_*";
		character = "Empty";
		soundEnviron = "dirt";
		soundHit = "soft_ground";
		rough = 0.09;
		dust = 0.5;
		lucidity = 1;
		grassCover = 0.0;
		surfaceFriction = 1.4;
		restitution = 0.19;
		maxSpeedCoef = 0.9;
		maxClutterColoringCoef = 1.35;
	};
	
	class tg_desertground2 : Default {
		access = ReadOnly;
		files = "tg_desertground2_*";
		character = "Empty";
		soundEnviron = "dirt";
		soundHit = "soft_ground";
		rough = 0.09;
		dust = 0.5;
		lucidity = 1;
		grassCover = 0.0;
		surfaceFriction = 1.4;
		restitution = 0.19;
		maxSpeedCoef = 0.9;
		maxClutterColoringCoef = 1.35;
	};
};


class CfgMissions {
	class Cutscenes {};
};

class CfgWorldList {
	class tg_tiberiumvalley {};
};