class CfgMaterials {
	class Water {
		class Stage1 {
			texture = "tg_buildings\gdi\data\gdi_tibwater_nofhq.paa";
			uvSource = "texWaterAnim";
			
			class uvTransform {
				aside[] = {0, 1, 0};
				up[] = {1, 0, 0};
				dir[] = {0, 0, 1};
				pos[] = {0.3, 0.4, 0};
			};
		};
		
		class Stage2 {
			texture = "tg_buildings\gdi\data\gdi_silo_tibwater.paa";
			uvSource = "none";
		};
		
		class Stage3 {
			texture = "#(ai,16,64,1)waterirradiance(16)";
			uvSource = "none";
		};
	};
	
	class Shore {
		class Stage1 {
			texture = "tg_buildings\gdi\data\gdi_tibwater_nofhq.paa";
			uvSource = "texWaterAnim";
			
			class uvTransform {
				aside[] = {0, 1, 0};
				up[] = {1, 0, 0};
				dir[] = {0, 0, 1};
				pos[] = {0.3, 0.4, 0};
			};
		};
		
		class Stage2 {
			texture = "tg_buildings\gdi\data\gdi_silo_tibwater.paa";
			uvSource = "none";
		};
		
		class Stage3 {
			texture = "#(ai,16,64,1)waterirradiance(16)";
			uvSource = "none";
		};
	};
	
	class ShoreFoam {
		class Stage1 {
			texture = "tg_buildings\gdi\data\gdi_tibwater_nofhq.paa";
			uvSource = "texWaterAnim";
			
			class uvTransform {
				aside[] = {0, 1, 0};
				up[] = {1, 0, 0};
				dir[] = {0, 0, 1};
				pos[] = {0.3, 0.4, 0};
			};
		};
		
		class Stage2 {
			texture = "tg_buildings\gdi\data\gdi_silo_tibwater.paa";
			uvSource = "none";
		};
		
		class Stage3 {
			texture = "#(ai,16,64,1)waterirradiance(16)";
			uvSource = "none";
		};
	};
};
