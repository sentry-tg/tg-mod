if (isServer) then {

_powerplant = _this select 0;

			_smoke1 = "#particlesource" createVehicleLocal getpos _powerplant;
			_smoke1 attachTo [_powerplant,[0,0,0],"Smoke_Effect_01"];
			_pos = getPos _smoke1;
			deleteVehicle _smoke1;
			_smoke1 = "#particlesource" createVehicleLocal getpos _powerplant;
			_smoke1 setPos _pos;
			_smoke1 setParticleClass "MediumDestructionSmoke";


