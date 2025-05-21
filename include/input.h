#pragma once
#include <SDL2/SDL.h>
#include "game.h"
#include "config.h"

bool handle_events(Game& game, bool& is_running, bool& paused, const Config& config);
