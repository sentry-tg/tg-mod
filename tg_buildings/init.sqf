
// executed before the player is loaded


[] spawn {
	waitUntil {sleep 1;isPlayer player && !isNull (findDisplay 46)};
};

// executed after the player is loaded and 'player' variable is defined