#include "game.h"

Game::Game(int rows, int cols) : rows_(rows), cols_(cols) 
{
    grid_ = std::vector<std::vector<bool>>(rows, std::vector<bool>(cols, false));
    next_grid_ = grid_;
}

void Game::update() 
{
    for (int i = 0; i < rows_; ++i) 
    {
        for (int j = 0; j < cols_; ++j) 
        {
            int neighbors = count_neighbors(i, j);
            if (grid_[i][j]) 
            {
                next_grid_[i][j] = (neighbors == 2 || neighbors == 3);
            }
            else 
            {
                next_grid_[i][j] = (neighbors == 3);
            }
        }
    }
    grid_.swap(next_grid_);
}

void Game::toggle_cell(int row, int col) {
    if (row >= 0 && row < rows_ && col >= 0 && col < cols_) 
    {
        grid_[row][col] = !grid_[row][col];
    }
}

void Game::clear() 
{
    for (auto& row : grid_) 
    {
        std::fill(row.begin(), row.end(), false);
    }
}

const std::vector<std::vector<bool>>& Game::get_grid() const 
{
    return grid_;
}

int Game::count_neighbors(int row, int col) const 
{
    int count = 0;
    for (int i = -1; i <= 1; ++i) 
    {
        for (int j = -1; j <= 1; ++j) 
        {
            if (i == 0 && j == 0) {continue;}
            int r = row + i;
            int c = col + j;
            if (r >= 0 && r < rows_ && c >= 0 && c < cols_ && grid_[r][c]) 
            {
                ++count;
            }
        }
    }
    return count;
}