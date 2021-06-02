
#include "..\variables.h"

//-- Adds or removes money from curator and updates curatorPoints accordingly

params ["_curator", "_money"];

private _curatorMaxMoney = _curator call TG_fnc_CuratorGetMaxMoney;
private _curatorMoney = _curator call TG_fnc_CuratorGetMoney;
[_curator, (_curatorMoney + _money) min _curatorMaxMoney] call TG_fnc_CuratorSetMoney;

if (_curatorMoney + _money >= _curatorMaxMoney) then {
	(["eva_silos_needed", "cabal_silos_needed"] # (_curator getVariable [CURATOR_SIDE, 0])) call TG_fnc_SoundQueue_Add;
};

private _pointsAdded = [_money, _curatorMaxMoney] call TG_fnc_CuratorConvertMoneyToPoints;
if ( _pointsAdded + curatorPoints _curator > 1 ) then {
	_pointsAdded = 1 - curatorPoints _curator;
};
if ( _pointsAdded + curatorPoints _curator < 0 ) then {
	_pointsAdded = - curatorPoints _curator;
};
[_curator, _pointsAdded] remoteExec ["addCuratorPoints", 2];
