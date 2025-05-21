#include "renderer.h"

Renderer::Renderer(const Config& config) : config_(config) 
{
    SDL_Init(SDL_INIT_VIDEO);
    window_ = SDL_CreateWindow("Game of Life",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        config.window_width, config.window_height, SDL_WINDOW_SHOWN);
    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
}

Renderer::~Renderer() 
{
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    SDL_Quit();
}

void Renderer::clear_screen() 
{
    SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
    SDL_RenderClear(renderer_);
}

void Renderer::render(const Game& game) 
{
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
    const auto& grid = game.get_grid();

    for (int i = 0; i < config_.rows; ++i) 
    {
        for (int j = 0; j < config_.cols; ++j) 
        {
            if (grid[i][j]) 
            {
                SDL_Rect cell = { j * config_.cell_size, i * config_.cell_size,
                                  config_.cell_size, config_.cell_size };
                SDL_RenderFillRect(renderer_, &cell);
            }
        }
    }
    SDL_RenderPresent(renderer_);
}