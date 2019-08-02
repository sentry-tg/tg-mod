
class CfgTGBuildingDefinitions 
{
	class TG_Building {
		name = "Building";
		cost = 50;
		buildTime = 10;
		limit = 0;
		readyProductPos[] = {0,0,0};
		className = "";
		energy = 0;
		techLevel = 0;
		picture = "";
		needs = "";
		markerType = "loc_Bunker";
		markerColor[] = {0.5,0.5,0.5,1};
	};
	class TG_Building_NOD : TG_Building {
		name = "NOD Building";
		markerColor[] = {1,0.5,0.5,1};
		
	};	
	class TG_Building_GDI : TG_Building {
		name = "GDI Building";
		markerColor[] = {1,1,0,1};
		
	};
	
	class TG_PowerPlant : TG_Building {
		energy = 0.8;
		markerType = "loc_Power";
	};
};