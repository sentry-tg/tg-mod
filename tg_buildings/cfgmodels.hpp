
class CfgSkeletons
{
	class Tank; //Define base class.
	class Default
	{
		isDiscrete = 1;
		skeletonInherit = "";
		skeletonBones[] = {};
	};

	class GDI_CY_Skeleton : Default
	{
		isDiscrete = 1;
		skeletonInherit = "Default";
		skeletonBones[] = 
		{

                 	"con_turnlight","",
			"con_fan3","",
			"con_fan2","",
			"con_fan1",""	
		};
	};

	class GDI_PP_Skeleton : Default
	{
		isDiscrete = 1;
		skeletonInherit = "Default";
		skeletonBones[] = 
		{
			"Turbine3","",
			"Turbine2","",
			"Turbine1",""	
		};
	};

	class GDI_G_Skeleton
	{
		isDiscrete = 1;
		skeletonInherit = "Default";
		SkeletonBones[]=
		{
			"gatepart",""
		};
	};

	class NOD_CY_Skeleton : Default
	{
		isDiscrete = 1;
		skeletonInherit = "Default";
		skeletonBones[] = 
		{

                 	"con_turnlight","",
			"con_fan3","",
			"con_fan2","",
			"con_fan1",""	
		};
	};

	class NOD_G_Skeleton
	{
		isDiscrete = 1;
		skeletonInherit = "Default";
		SkeletonBones[]=
		{
			"gatepart",""
		};
	};

	class NOD_LASF_Skeleton : Default
	{
		isDiscrete = 1;
		skeletonInherit = "Default";
		skeletonBones[] = 
		{
			"Las3","",
			"Las2","",
			"Las1",""	
		};
	};
};

class CfgModels
{
	class Default;

	class gdi_conyard: Default
	{
		skeletonName = "GDI_CY_Skeleton";
		sections[] =
		{
			"Light_1_hide",
			"Light_2_hide",
			"Light_3_hide",
			"Light_4_hide",
			"Light_5_hide",
			"Light_6_hide",
			"Light_7_hide"
		};

		sectionsInherit = "";

            class Animations
		{

			class gdi_Fan1
			{

				type = "rotation";
				selection = "con_fan1";
				axis = "osa_fan1";
				angle0 = 0;
				minValue = 0;
				maxValue = 2;
				source = "time";
				sourceAddress = "loop";
				angle1 = rad 360";
			};
                        class gdi_Fan2
			{
				type = "rotation";
				selection = "con_fan2";
				axis = "osa_fan2";
				angle0 = 0;
				minValue = 0;
				maxValue = 5;
				source = "time";
				sourceAddress = "loop";
				angle1 = rad 360";
			};
                        class gdi_Fan3
			{
				type = "rotation";
				selection = "con_fan3";
				axis = "osa_fan3";
				angle0 = 0;
				minValue = 0;
				maxValue = 2;
				source = "time";
				sourceAddress = "loop";
				angle1 = rad 360";
			};
                       class TurnLight
			{
				type = "rotation";
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

	class gdi_powerplant: Default
	{
		skeletonName = "GDI_PP_Skeleton";
		sections[] =
		{
			"Light_1_hide",
			"Light_2_hide",
			"Light_3_hide",
			"Light_4_hide",
			"Light_5_hide",
			"Light_6_hide",
			"Light_7_hide"
		};

		sectionsInherit = "";

             class Animations
		{

			class Turb1
			{
				type = "rotation";
				animPeriod = 10;
				selection = "Turbine1";
				axis = "osa_turb1";
				angle0 = 0;
				minValue = 0;
				maxValue = 10;
				source = "time";
				sourceAddress = "loop";
				angle1 = rad 360";
			};
                        class Turb2
			{
				type = "rotation";
				animPeriod = 10;
				selection = "Turbine2";
				axis = "osa_turb2";
				angle0 = 0;
				minValue = 0;
				maxValue = 10;
				source = "time";
				sourceAddress = "loop";
				angle1 = rad 360";
			};
                        class Turb3
			{
				type = "rotation";
				animPeriod = 10;
				selection = "Turbine3";
				axis = "osa_turb3";
				angle0 = 0;
				minValue = 0;
				maxValue = 10;
				source = "time";
				sourceAddress = "loop";
				angle1 = rad 360";
			};

		};
};


	class nod_laserfence: Default
	{
		skeletonName = "NOD_LASF_Skeleton";
		sections[] =
		{
			"Light_1_hide",
			"Light_2_hide",
			"Light_3_hide",
			"Light_4_hide",
			"Light_5_hide",
			"Light_6_hide",
			"Light_7_hide"
		};

		sectionsInherit = "";

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
};

	class gdi_barracks: Default
	{
		skeletonName = "GDI_CY_Skeleton";
		sections[] =
		{
			"barLight_1_hide",
			"barLight_2_hide",
			"barLight_3_hide",
			"barLight_4_hide"
		};

		sectionsInherit = "";
};

	class gdi_tiberiumrefinery: Default
	{
		skeletonName = "GDI_CY_Skeleton";
		sections[] =
		{
			"eh",
			"barLight_2_hide",
			"barLight_3_hide",
			"barLight_4_hide"
		};

		sectionsInherit = "";
};

	class gdi_tiberiumsilo: Default
	{
		skeletonName = "GDI_CY_Skeleton";
		sections[] =
		{
			"silLight_1_hide",
			"silLight_2_hide",
			"silLight_3_hide",
			"silLight_4_hide"
		};

		sectionsInherit = "";
};

	class gdi_helipad: Default
	{
		skeletonName = "GDI_CY_Skeleton";
		sections[] =
		{
			"barLight_1_hide",
			"barLight_2_hide",
			"barLight_3_hide",
			"barLight_4_hide"
		};

		sectionsInherit = "";
};

	class gdi_radar: Default
	{
		skeletonName = "GDI_CY_Skeleton";
		sections[] ={};
		sectionsInherit = "";
};

	class gdi_commandcenter: Default
	{
		skeletonName = "GDI_CY_Skeleton";
		sections[] ={};
		sectionsInherit = "";
};

	class gdi_gate:Default
	{
		skeletonName="GDI_G_Skeleton";
		sections[]={};

		class Animations
		{
		class gate
			{
		type="translationY";
		source="gdi_gate_source";
		selection="gatepart";
                sourceAddress="clamp";
                minPhase= -6.5;
                maxPhase=0;
                minValue= -6.5;
                maxValue=0;
                memory=0;
                offset0=0;
                offset1=0;
		};
	};
};

	class gdi_wall: Default
	{
		skeletonName = "GDI_CY_Skeleton";
		sections[] ={};
		sectionsInherit = "";
};
	class gdi_wall2: Default
	{
		skeletonName = "GDI_CY_Skeleton";
		sections[] ={};
		sectionsInherit = "";
};
	class gdi_repairpad: Default
	{
		skeletonName = "GDI_CY_Skeleton";
		sections[] ={};
		sectionsInherit = "";
};

	class gdi_componenttower: Default
	{
		skeletonName = "GDI_CY_Skeleton";
		sections[] ={};
		sectionsInherit = "";
};

	class nod_conyard: Default
	{
		skeletonName = "NOD_CY_Skeleton";
		sections[] =
		{
			"Light_1_hide",
			"Light_2_hide",
			"Light_3_hide",
			"Light_4_hide",
			"Light_5_hide",
			"Light_6_hide",
			"Light_7_hide"
		};

		sectionsInherit = "";

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
	class nod_handofnod: Default
	{
		skeletonName = "GDI_CY_Skeleton";
		sections[] =
		{
			"barLight_1_hide",
			"barLight_2_hide",
			"barLight_3_hide",
			"barLight_4_hide"
		};

		sectionsInherit = "";
};

	class nod_tiberiumrefinery: Default
	{
		skeletonName = "GDI_CY_Skeleton";
		sections[] =
		{
			"barLight_1_hide",
			"barLight_2_hide",
			"barLight_3_hide",
			"barLight_4_hide"
		};

		sectionsInherit = "";
};
	class nod_tiberiumsilo: Default
	{
		skeletonName = "GDI_CY_Skeleton";
		sections[] =
		{
			"silLight_1_hide",
			"silLight_2_hide",
			"silLight_3_hide",
			"silLight_4_hide"
		};

		sectionsInherit = "";
};
	class nod_wall: Default
	{
		skeletonName = "GDI_CY_Skeleton";
		sections[] ={};
		sectionsInherit = "";
};

	class nod_gate:Default
	{
		skeletonName="NOD_G_Skeleton";
		sections[]={};

		class Animations
		{
		class gate
		{
		type="translationY";
		source="nod_gate_source";
		selection="gatepart";
                sourceAddress="clamp";
                minPhase= -5.3;
                maxPhase=0;
                minValue= -5.3;
                maxValue=0;
                memory=0;
                offset0=0;
                offset1=0;
		};
	};
};

};