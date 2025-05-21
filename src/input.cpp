#include "input.h"

bool handle_events(Game& game, bool& running, bool& paused, const Config& config) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) 
    {
        switch (event.type) 
        {
            case SDL_QUIT:
                running = false;
                return false;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) 
                {
                    case SDLK_ESCAPE:
                        running = false;
                        return false;
                    case SDLK_SPACE:
                        paused = !paused;
                        break;
                    case SDLK_c:
                        game.clear();
                        break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT) 
                {
                    int x = event.button.x;
                    int y = event.button.y;
                    int row = y / config.cell_size;
                    int col = x / config.cell_size;
                    game.toggle_cell(row, col);
                }
                break;
        }
    }
    return true;
}