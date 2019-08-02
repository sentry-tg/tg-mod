
waitUntil { sleep 1; isPlayer player };

while { True } do {
	waitUntil { sleep 1; alive player && player call TG_fnc_ableToFly };
	_script1 = player remoteExec ["TG_fnc_addJetpackEffects", 0, True];
	_script2 = [] spawn TG_fnc_addJetpackControls;
	waitUntil { sleep 1; scriptDone _script2 };
};


