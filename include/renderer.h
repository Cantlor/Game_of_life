#pragma once
#include <SDL2/SDL.h>
#include "game.h"
#include "config.h"

class Renderer 
{
public:
    Renderer(const Config& config);
    ~Renderer();

    void render(const Game& game);
    void clear_screen();

    SDL_Window* get_window() const;
    SDL_Renderer* get_renderer() const;

private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    Config config_;
};
