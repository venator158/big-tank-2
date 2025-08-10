#include "agent.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>
#ifndef FILE_IO_HPP
#define FILE_IO_HPP

class FileIO {
public:
    std::string readFile(const std::string& filename);
    std::vector<Agent> extract_mapping(const std::string& content);
    std::vector<std::vector<int>> extract_grid(const std::string& content);
};

#endif // FILE_IO_HPP