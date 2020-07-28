
params ["_money", "_maxMoney"];
private _points = if (_maxMoney == 0) then [{0},{_money / _maxMoney}];
_points
