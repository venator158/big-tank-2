#include <vector>
#include <utility>
#include "agent.hpp"

#ifndef ASTAR_HPP
#define ASTAR_HPP
class AStar {
public:
    std::vector<pos> astar(pos start, pos goal, const std::vector<std::vector<int>>& grid);
};

#endif // ASTAR_HPP