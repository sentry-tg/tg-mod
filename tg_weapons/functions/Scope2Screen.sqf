
if (isNil{ TG_S2S_MagLevel }) then {
	["TG", "Change_magnification", "Change scope magnification", {
		
		if (isNil{TG_S2S_MagLevel} || isNil{TG_S2S_cam}) exitWith {};
		
		TG_S2S_MagLevel = TG_S2S_MagLevel + 2;
		if (TG_S2S_MagLevel > 9) then {TG_S2S_MagLevel = 3};
		if (TG_S2S_MagLevel < 3) then {TG_S2S_MagLevel = 9};
		
		_fovMultiplier = 0;
		if (TG_S2S_MagLevel == 3) then { _fovMultiplier = .35; };
		if (TG_S2S_MagLevel == 5) then { _fovMultiplier = .22; };
		if (TG_S2S_MagLevel == 7) then { _fovMultiplier = .16; };
		if (TG_S2S_MagLevel == 9) then { _fovMultiplier = .12; };
			
		hint format ["Current mag is %1x", TG_S2S_MagLevel];
		TG_S2S_cam camSetFov _fovMultiplier / TG_S2S_MagLevel;
		TG_S2S_cam camCommit 0;
		
	}, {}, [22, [false, false, false]]] call cba_fnc_addKeybind; // 22 = 'U' button
};

_this spawn
{
	params ["_ctrl", "_magnification", ["_uiNameSpaceVarName", "TG_S2S_ctrl"]];
	
	waitUntil {isNil{TG_S2S_cam}};

	if (isNull (uiNamespace getVariable [_uiNameSpaceVarName, displayNull])) then
	{
		uiNameSpace setVariable [_uiNameSpaceVarName, _ctrl];

		disableSerialization;
		_ctrl168 = (_ctrl displayCtrl 168);
		_needToRestartTheCamera = true;

		TG_S2S_cam = "camera" camCreate [0,0,0];
		TG_S2S_cam cameraEffect ["internal", "Back", "tg_r2t_scope"];
		
		TG_S2S_MagLevel = _magnification;
		_fovMultiplier = 0;
		switch (_magnification) do {
			case 3: { _fovMultiplier = .35; }; break;
			case 5: { _fovMultiplier = .22; }; break;
			case 7: { _fovMultiplier = .16; }; break;
			case 9: { _fovMultiplier = .12; }; break;
			default {
				_fovMultiplier = 0.35;
			};
		};
		
		TG_S2S_cam camSetFov _fovMultiplier / _magnification;
		"tg_r2t_scope" setPiPEffect [3,1,1.1,1.17,0,[1,1,1,-0.01],[1,1,1,1],[0.33,0.33,0.33,0]];
		
		TG_S2S_camOffset = [-0.03,0.14,0.1];

		_id = addMissionEventHandler ["Draw3D",
		{
			//attach to cause to double camera rotation
			//should be right hand as it glued to weapon most of the time
		 	TG_S2S_cam setPosATL (player modelToWorldVisual ((player selectionPosition "leftHand") vectorAdd TG_S2S_camOffset));
			
			_w = player weaponDirection (primaryWeapon player);
		 	_r = vectorNormalized(_w vectorCrossProduct [0,0,1]);
		 	_u = _r vectorCrossProduct _w;

		 	TG_S2S_cam setVectorDirAndUp [_w ,_u];
		}];
		
		while {sleep 0.1; !isNull _ctrl168} do
		{
			if (cameraView == "internal") then 
			{
				if (_needToRestartTheCamera) then {
					TG_S2S_cam cameraEffect ["terminate","back"];
					TG_S2S_cam cameraEffect ["internal", "back", "tg_r2t_scope"];
					"tg_r2t_scope" setPiPEffect [3,1,1.1,1.17,0,[1,1,1,-0.01],[1,1,1,1],[0.33,0.33,0.33,0]];
					_needToRestartTheCamera = false;
				};
			} 
			else {
				_needToRestartTheCamera = true;
			};
		};

		uiNameSpace setVariable [_uiNameSpaceVarName, displayNull];
		removeMissionEventHandler ["draw3d", _id];
		
		TG_S2S_cam cameraEffect ["terminate","back"];
		camDestroy TG_S2S_cam;
		TG_S2S_camOffset = nil;
		TG_S2S_cam = nil;
	};
};

