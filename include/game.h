#pragma once
#include <vector>

class Game
{
public:
    Game(int rows, int cols);
    void update();
    void toggle_cell(int row, int col);
    void clear();
    const std::vector<std::vector<bool>>& get_grid() const;

private:
    int rows_;
    int cols_;
    std::vector<std::vector<bool>> grid_;
    std::vector<std::vector<bool>> next_grid_;


    int count_neighbors(int row, int col) const;
};