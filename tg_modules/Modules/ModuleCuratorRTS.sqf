
#include "..\variables.h"

#define DEF_RSC_TITLE_DISPLAY_EMPTY "RscTitleDisplayEmpty"
#define DEF_CURATOR_OBJECT_REGISTERED_HANDLER "CuratorObjectRegisteredHandler"
#define DEF_BIS_FNC_CURATORPINGED_DONE "bis_fnc_curatorPinged_done"
#define DEF_FORCED "forced"
#define DEF_BIRD "bird"
#define DEF_ADMIN_VAR "adminVar"
#define DEF_OWNER "owner"
#define DEF_ADDONS "Addons"
#define DEF_NAME "name"
#define DEF_CHANNELS "channels"
#define DEF_SHOW_NOTIFICATION "showNotification"
#define DEF_BIRD_TYPE "birdType"

_logic = _this select 0;
_units = _this select 1;
_activated = _this select 2;

if (_activated) then {

	//--- Terminate when not created on the server
	if (!isserver && local _logic && isnull (getassignedcuratorunit _logic)) exitwith {
		[format ["%1 is trying to create curator logic ModuleCurator_F",profilename],"bis_fnc_error",false] call bis_fnc_mp;
		deletevehicle _logic;
	};

	//--- Get curator owner
	_ownerVar = _logic getvariable [DEF_OWNER,""];
	_ownerUID = parsenumber _ownerVar;
	if (cheatsenabled) then {
		_ownerVarArray = toarray _ownerVar;
		_ownerVarArray resize 3;
		if (tostring _ownerVarArray == "DEV") then {_ownerUID = 1;};
	};
	if (_ownerVar == "" && !ismultiplayer) then {
		["Curator owner not defined, player used instead in singleplayer."] call bis_fnc_error;
		_ownerVar = player call bis_fnc_objectvar;
	};
	if (_ownerUID > 0 && !ismultiplayer) then {
		_ownerVar = player call bis_fnc_objectvar;
	};
	_isAdmin = _ownerVar == "#adminLogged" || _ownerVar == "#adminVoted";

	//--- Wipe out the variable so clients can't access it
	_logic setvariable [DEF_OWNER,nil];

	//--- Server
	if (isserver) then {

		//--- Prepare admin variable
		_adminVar = "";
		if (_isAdmin) then {
			_letters = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"];
			_adminVar = "admin_";
			for "_i" from 0 to 9 do {_adminVar = _adminVar + (_letters call bis_fnc_selectrandom);};
			_logic setvariable [DEF_ADMIN_VAR,_adminVar,true];
		};
		
		
		//--- Get allowed addons
		_addonsType = _logic getvariable [DEF_ADDONS,3];
		_addons = [];
		switch _addonsType do {

			//--- All (including unofficial ones)
			case 3: {
				_cfgPatches = configfile >> "cfgpatches";
				for "_i" from 0 to (count _cfgPatches - 1) do {
					_class = _cfgPatches select _i;
					if (isclass _class) then {_addons set [count _addons,configname _class];};
				};
				_addons call bis_fnc_activateaddons;
				removeallcuratoraddons _logic;
				_logic addcuratoraddons _addons;
			};

			//--- All active
			case 2: {};

			//--- All mission
			case 1: {
				_addonsList = [];
				{
					_addonsList = _addonsList + (unitaddons typeof _x);
				} foreach (entities "all");
				removeallcuratoraddons _logic;
				_logic addcuratoraddons _addonsList;
			};

			//--- None
			case 0: {
				removeallcuratoraddons _logic;
			};
		};

		//--- Handle ownership
		[_logic,_ownerVar,_ownerUID,_adminVar] spawn {
			scriptname "BIS_fnc_moduleCurator: Owner";

			_logic = _this select 0;
			_ownerVar = _this select 1;
			_ownerUID = _this select 2;
			_adminVar = _this select 3;

			if (_adminVar != "") then {_ownerVar = _adminVar;};

			_forced = _logic getvariable [DEF_FORCED,0] > 0;
			_name = _logic getvariable [DEF_NAME,""];
			if (_name == "") then {_name = localize "STR_A3_curator";};

			//--- Wait until mission starts
			waituntil {time > 0};

			//--- Refresh addon list, so it's broadcasted to clients
			_addons = curatoraddons _logic;
			removeAllCuratorAddons _logic;
			_logic addcuratoraddons _addons;

			while {true} do {
				//--- Wait for player to become Zeus
				switch true do {
					case (_ownerUID > 0): {
						waituntil {
							sleep 0.01;
							{getplayeruid _x == _ownerVar} count playableunits > 0 || isnull _logic
						};
					};
					default {
						waituntil {isplayer (missionnamespace getvariable [_ownerVar,objnull]) || isnull _logic};
					};
				};
				if (isnull _logic) exitwith {};

				//--- Assign
				_player = objnull;
				switch true do {
					case (_ownerUID > 0): {
						{
							if (getplayeruid _x == _ownerVar) exitwith {_player = _x;};
						} foreach playableunits;
					};
					default {
						_player = missionnamespace getvariable [_ownerVar,objnull];
					};
				};

				waituntil {unassigncurator _logic; isnull (getassignedcuratorunit _logic) || isnull _logic};
				waituntil {_player assignCurator _logic; getassignedcuratorunit _logic == _player || isnull _logic};
				if (isnull _logic) exitwith {};

				//--- Add radio channels
				{
					_x radiochanneladd [_player];
				} foreach (_logic getvariable [DEF_CHANNELS,[]]);

				//--- Sent notification to all assigned players
				if (_logic getvariable [DEF_SHOW_NOTIFICATION,true]) then {
					{
						if (isplayer _x) then {
							[["CuratorAssign",[_name,name _player]],"bis_fnc_showNotification",_x] call bis_fnc_mp;
						};
					} foreach (curatoreditableobjects _logic);
				};

				[_logic,"curatorUnitAssigned",[_logic,_player]] call bis_fnc_callscriptedeventhandler;

				//--- Forced interface
				//if (_forced) then {
				//	[[true,true],"bis_fnc_forceCuratorInterface",_player] call bis_fnc_mp;
				//};

				//--- Wait for player to stop being Zeus
				switch true do {
					case (_ownerUID > 0): {
						waituntil {
							sleep 0.01;
							{getplayeruid _x == _ownerVar} count playableunits == 0 || isnull _logic
						};
					};
					default {
						waituntil {_player != missionnamespace getvariable [_ownerVar,objnull] || isnull _logic};
					};
				};
				if (isnull _logic) exitwith {};

				//--- Add radio channels
				{
					_x radiochannelremove [_player];
				} foreach (_logic getvariable [DEF_CHANNELS,[]]);

				//--- Unassign
				waituntil {unassigncurator _logic; isnull (getassignedcuratorunit _logic) || isnull _logic};
				if (isnull _logic) exitwith {};
			};
		};

		//--- Create bird
		_birdType = _logic getvariable [DEF_BIRD_TYPE,"eagle_f"];
		if (_birdType != "") then {
			_bird = createvehicle [_birdType,[100,100,100],[],0,"none"];
			_logic setvariable [DEF_BIRD,_bird,true];
		};

		//--- Activated all future addons
		_addons = [];
		{
			if (typeof _x == "ModuleCuratorAddAddons_F") then {
				_paramAddons = call compile ("[" + (_x getvariable [DEF_ADDONS,""]) + "]");
				{
					if !(_x in _addons) then {_addons set [count _addons,_x];};
					{
						if !(_x in _addons) then {_addons set [count _addons,_x];};
					} foreach (unitaddons _x);
				} foreach _paramAddons;
			};
		} foreach (synchronizedobjects _logic);
		_addons call bis_fnc_activateaddons;

		//--- Locality changed
		_logic addeventhandler [
			"local",
			{
				_logic = _this select 0;
				_bird = _logic getvariable [DEF_BIRD,objnull];
				_bird setowner owner _logic;
			}
		];
	};

	//--- Player
	if (hasinterface) then {
		waituntil {local player};
		_serverCommand = if (_ownerVar == "#adminLogged") then {"#shutdown"} else {"#kick"};

		//--- Black effect until the interface is open
		_forced = _logic getvariable [DEF_FORCED,0] > 0;
		if (_forced) then {
			_isCurator = switch true do {
				case (_ownerUID > 0): {
					getplayeruid player == _ownerVar
				};
				case (_isAdmin): {
					isserver || servercommandavailable _serverCommand
				};
				default {
					player == missionnamespace getvariable [_ownerVar,objnull]
				};
			};
			if (_isCurator) then {
				[true,true] spawn bis_fnc_forceCuratorInterface;
				//("RscDisplayCurator" call bis_fnc_rscLayer) cuttext ["","black in",1e10];
			};
		};

		//--- Check if player is server admin
		if (_isAdmin) then {
			_adminVar = _logic getvariable [DEF_ADMIN_VAR,""];
			_logic setvariable [DEF_ADMIN_VAR,nil];
			if (isserver) then {
				//--- Host
				missionnamespace setvariable [_adminVar,player];
			} else {
				//--- Client
				[_logic,_adminVar,_serverCommand] spawn {
					scriptname "BIS_fnc_moduleCurator: Admin check";

					_logic = _this select 0;
					_adminVar = _this select 1;
					_serverCommand = _this select 2;
					while {true} do {
						waituntil {sleep 0.1; servercommandavailable _serverCommand};
						missionnamespace setvariable [_adminVar,player];
						publicvariable _adminVar;
						_respawn = player addeventhandler ["respawn",format ["%1 = _this select 0; publicvariable '%1';",_adminVar]];

						waituntil {sleep 0.1; !servercommandavailable _serverCommand};
						missionnamespace setvariable [_adminVar,objnull];
						publicvariable _adminVar;
						player removeeventhandler ["respawn",_respawn];
					};
				};
			};
		};

		[_logic] spawn {
			_logic = _this select 0;
			sleep 1;
			waituntil {alive player};

			//--- Show warning when Zeus key is not assigned
			if (count (actionkeys "curatorInterface") == 0) then {
				[
					format [
						localize "str_a3_cfgvehicles_modulecurator_f_keyNotAssigned",
						(["IGUI","WARNING_RGB"] call bis_fnc_displaycolorget) call bis_fnc_colorRGBAtoHTML
					]
				] call bis_fnc_guiMessage;
			};

			//--- Show hint about pinging for players
			if (
				isnil {profilenamespace getvariable DEF_BIS_FNC_CURATORPINGED_DONE}
				&&
				{isTutHintsEnabled}
				&&
				{isnull getassignedcuratorlogic player}
				&&
				{player in curatoreditableobjects _logic}
			) then {
				sleep 0.5;
				[["Curator","Ping"]] call bis_fnc_advHint;
			};
		};

		//--- Add local event handlers
		_logic addeventhandler ["curatorFeedbackMessage",{_this call bis_fnc_showCuratorFeedbackMessage;}];
		_logic addeventhandler ["curatorPinged",{_this call bis_fnc_curatorPinged;}];
		_logic addeventhandler ["curatorObjectPlaced",{_this call bis_fnc_curatorObjectPlaced;}];
		_logic addeventhandler ["curatorObjectEdited",{_this call bis_fnc_curatorObjectEdited;}];
		_logic addeventhandler ["curatorWaypointPlaced",{_this call bis_fnc_curatorWaypointPlaced;}];

		_logic addeventhandler ["curatorObjectDoubleClicked",{(_this select 1) call bis_fnc_showCuratorAttributes;}];
		_logic addeventhandler ["curatorGroupDoubleClicked",{(_this select 1) call bis_fnc_showCuratorAttributes;}];
		_logic addeventhandler ["curatorWaypointDoubleClicked",{(_this select 1) call bis_fnc_showCuratorAttributes;}];
		_logic addeventhandler ["curatorMarkerDoubleClicked",{(_this select 1) call bis_fnc_showCuratorAttributes;}];

		player call bis_fnc_curatorRespawn;
		
		///////////////////////////////////////////////////////////
		
		
		private _fnc_getOwner = {
			params ["_module"];

			if ( typeOf _module == "SideBLUFOR_F" ) exitWith { WEST };
			if ( typeOf _module == "SideOPFOR_F" ) exitWith { EAST };
			if ( typeOf _module == "SideResistance_F" ) exitWith { RESISTANCE };

			_side = sideLogic;

			{
				if ( typeOf _x == "SideBLUFOR_F" ) exitWith { _side = WEST };
				if ( typeOf _x == "SideOPFOR_F" ) exitWith { _side = EAST };
				if ( typeOf _x == "SideResistance_F" ) exitWith { _side = RESISTANCE };
			}
			forEach synchronizedObjects _module;

			_side
		};

		//-- Global definitions
		GDI = west; siGDI = 0;
		NOD = east; siNOD = 1;
		BuildingDefs = [];
		CONYARD_COST = 0;

		_curator = _logic;
		_curatorSide = player call TG_fnc_GetSyncedSide;
		_curatorSi = if (_curatorSide isEqualTo GDI) then [{siGDI},{siNOD}];
		_curator setVariable [CURATOR_SIDE, _curatorSi];

		//-- Filling BuildingDefs from config
		{
			private _amountOfBuildings = count _x;
			private _array = [];
			for "_i" from 0 to (_amountOfBuildings - 1) do
			{
				private _cfgBuilding = _x select _i;
				
				private _configName = configName _cfgBuilding;
				call compile (_configName + " = " + str(_i));
				
				private _Name = getText (_cfgBuilding >> "Name");
				private _Cost = getNumber (_cfgBuilding >> "Cost");
				private _BuildTime = getNumber (_cfgBuilding >> "BuildTime");
				private _Limit = getNumber (_cfgBuilding >> "Limit");
				private _RPP = getArray (_cfgBuilding >> "ReadyProductPos");
				private _BuildingType = getText (_cfgBuilding >> "BuildingType");
				private _Dir = getNumber (_cfgBuilding >> "Direction");
				private _GS = getArray (_cfgBuilding >> "GlobalScripts");
				private _SS = getArray (_cfgBuilding >> "ServerScripts");
				private _Energy = getNumber (_cfgBuilding >> "Energy");
				private _TechLevel = getNumber (_cfgBuilding >> "TechLevel");
				private _Picture = getText (_cfgBuilding >> "Picture");
				private _Needs = getArray (_cfgBuilding >> "Needs");
				private _MarkerType = getText (_cfgBuilding >> "MarkerType");
				private _Storage = getNumber (_cfgBuilding >> "Storage");
				
				private _def = [_configName, _Name, _Cost, _BuildTime, _Limit, _RPP, _BuildingType, _Dir, _GS, _SS, _Energy, _TechLevel, _Picture, _Needs, _MarkerType, _Storage];
				_array pushBack _def;
				
				//-- Store conyard cost into a global variable
				if (_configName == "GDI_ConstructionYard") then { 
					CONYARD_COST = _Cost;
				};
			};
			BuildingDefs pushBack [_forEachIndex, _array];
		}
		forEach [
			missionConfigFile >> "CfgTGBuildingDefinitions" >> "GDI",
			missionConfigFile >> "CfgTGBuildingDefinitions" >> "NOD"
		];

		/* Only activated addons can be added (i.e., addons preloaded by the mission). All official addons are activated by default, but unofficial ones are activated only when an object contained in such addon is present in the mission. If that's not the case, you can use activateAddons or BIS_fnc_activateAddons to activate them. This is however possible only at the mission start - on the fly activation is not possible */

		//_curator remoteExec ["removeAllCuratorAddons", 2];
		[CURATOR_ADDONS] remoteExec ["activateAddons", 2];
		[_curator, CURATOR_ADDONS] remoteExec ["addCuratorAddons", 2];


		[_curator, (BuildingDefs # _curatorSi) # 1] call TG_fnc_CuratorSetBuildingDefs;

		private _id = _curator addEventHandler [
			"CuratorObjectRegistered",
			{
				params ['_curator', '_input'];
				
				private _canBeBuiltClasses = [_curator] call TG_fnc_CuratorGetCanBeBuiltClasses;
					
				private _costs = [];
				{
					private _cost = [_x in _canBeBuiltClasses,0];
					_costs = _costs + [_cost];
				}
				forEach _input; 
				_costs
			}
		];
		_curator setVariable [DEF_CURATOR_OBJECT_REGISTERED_HANDLER, _id];

		_curator addEventHandler ["CuratorObjectPlaced", {_this call TG_fnc_CuratorObjectPlaced}];
		_curator addEventHandler ["CuratorObjectDeleted", {_this call TG_fnc_CuratorObjectDeleted}];
		_curator addEventHandler ["CuratorObjectSelectionChanged", {_this call TG_fnc_CuratorObjectSelectionChanged}];

		//-- Give enough money to build a conyard
		[_curator, CONYARD_COST] call TG_fnc_CuratorSetMoney;
		//_curator addCuratorPoints -1;
		
		//-- Disable editing of the placed object for Zeus
		[_curator] spawn {
			params ["_curator"];
			waitUntil {time > 1};
			[_curator, {
				_this setCuratorCoef ["edit",-1000000];
			}] remoteExec ["call", 2]; 
		};


		//-- Give player money after conyard is built for first time
		[_curator] spawn {
			params ["_curator"];
			private _buildingDefs = _curator call TG_fnc_CuratorGetBuildingDefs;
			private _buildingClasses = [_buildingDefs, SELECT_BUILDING_TYPE] call TG_fnc_BuildingDefs;
			private _conyardClasses = _buildingDefs select {toLowerANSI (_x # SELECT_CONFIG_NAME) in (CONYARD_CONFIG_NAMES apply {toLowerANSI _x})} apply { _x # SELECT_BUILDING_TYPE };
			
			waitUntil {
				sleep 1;  
				private _curatorBuildingClasses = curatorEditableObjects _curator select { typeOf _x in _buildingClasses && alive _x } apply { typeOf _x };
				count ( _curatorBuildingClasses arrayIntersect _conyardClasses ) > 0
			};
			[_curator, INITIAL_MONEY] call TG_fnc_CuratorAddMoney;
		};


		//-- Draw money on the screen
		_curator spawn {
			params ["_curator"];
			
			if (isNil{ uiNamespace getVariable DEF_RSC_TITLE_DISPLAY_EMPTY }) then {
				"CommanderGUI" cutRsc [DEF_RSC_TITLE_DISPLAY_EMPTY, "PLAIN"];
			};
			
			private _ctrl = objNull; 
			
			while {true} do {
				if (isNull _ctrl) then {
					private _display = uiNamespace getVariable DEF_RSC_TITLE_DISPLAY_EMPTY;
					_ctrl = _display ctrlCreate ["RscStructuredText", -1];
					_ctrl ctrlSetBackgroundColor [0,0,0,0];
					_ctrl ctrlSetFont "EtelkaMonospacePro"; 
					_ctrl ctrlSetTextColor [1, 1, 1, 1];
					_ctrl ctrlSetPosition [0.3, 0.0, MONEY_WIDTH, MONEY_HEIGHT];
				};
				private _balance = _curator call TG_fnc_CuratorGetMoney;
				_ctrl ctrlSetStructuredText parseText format ["<t size='%2' align='center'>$%1</t>", _balance, MONEY_FONT_SIZE];
				_ctrl ctrlCommit 0;
				sleep 0.1;
			};
		};
	};
};







