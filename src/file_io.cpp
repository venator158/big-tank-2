#include "file_io.hpp"


using namespace std;

string FileIO::readFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Could not open file: " + filename);
    }
    
    ostringstream contentStream;
    contentStream << file.rdbuf();
    return contentStream.str();
}

vector<Agent> FileIO::extract_mapping(const string& content){
    vector<Agent> agents;
    istringstream ss(content);
    string line;

    // Skip header
    getline(ss, line);

    while (getline(ss, line)) {
        istringstream lineStream(line);
        string agent_id_str, agent_x_str, agent_y_str;
        string job_id_str, job_x_str, job_y_str;
        // Parse CSV columns
        if (getline(lineStream, agent_id_str, ',') &&
            getline(lineStream, agent_x_str, ',') &&
            getline(lineStream, agent_y_str, ',') &&
            getline(lineStream, job_id_str, ',') &&
            getline(lineStream, job_x_str, ',') &&
            getline(lineStream, job_y_str, ',')) {

            int agent_id = stoi(agent_id_str);
            int agent_x = stoi(agent_x_str);
            int agent_y = stoi(agent_y_str);
            pos agent_pos = {make_pair(agent_x, agent_y)};
            int job_id = stoi(job_id_str);
            int job_x = stoi(job_x_str);
            int job_y = stoi(job_y_str);
            pos job_pos = {make_pair(job_x, job_y)};
            int priority = agent_id;

            Agent agent(agent_id, agent_pos, job_id, job_pos, priority);
            agents.push_back(agent);
        }
    }
    return agents;
}

vector<vector<int>> FileIO::extract_grid(const string& content) {
    vector<vector<int>> grid;
    istringstream ss(content);
    string line;

    while (getline(ss, line)) {
        istringstream lineStream(line);
        string cell;
        vector<int> row;

        while (getline(lineStream, cell, ',')) {
            row.push_back(stoi(cell));
        }

    grid.push_back(row);
    }

    return grid;
}