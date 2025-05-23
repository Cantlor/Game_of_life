// main.cpp
#include <iostream>
#include <chrono>
#include <thread>
#include "renderer.h"
#include "input.h"

Config parse_args(int argc, char* argv[]) {
    Config config;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--rows" && i + 1 < argc) config.rows = std::stoi(argv[++i]);
        else if (arg == "--cols" && i + 1 < argc) config.cols = std::stoi(argv[++i]);
        else if (arg == "--fps" && i + 1 < argc) config.fps = std::stoi(argv[++i]);
    }
    config.cell_size = config.window_width / config.cols;
    return config;
}

int main(int argc, char* argv[]) {
    Config config = parse_args(argc, argv);
    Game game(config.rows, config.cols);
    Renderer renderer(config);

    bool is_running = true;
    bool paused = true;

    const int frame_delay = 1000 / config.fps;
    while (is_running) 
    {
        auto start = std::chrono::high_resolution_clock::now();

        if (!handle_events(game, is_running, paused, config))
        { 
            break;
        }
        if (!paused)
        {
            game.update();
        }

        renderer.clear_screen();
        renderer.render(game);

        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        if (elapsed < frame_delay) 
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(frame_delay - elapsed));
        }
    }
    return 0;
}
