
params ["_curator"];
private _curatorMaxMoney = _curator call TG_fnc_CuratorGetMaxMoney;
private _curatorMoney = _curator call TG_fnc_CuratorGetMoney;

[[_curator, _curatorMoney / _curatorMaxMoney], {
	params ["_curator", "_setPointsTo"];
	_curator addCuratorPoints (_setPointsTo - curatorPoints _curator);
}] remoteExec ["call", 2];
