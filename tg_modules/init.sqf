
// executed before the player is loaded

[] spawn {
	waitUntil {isPlayer player && !isNull (findDisplay 46)};
	systemChat "tg_modules init";
};

// executed after the player is loaded and 'player' variable is defined