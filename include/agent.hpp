#ifndef AGENT_HPP
#define AGENT_HPP

#include <utility>
#include <vector>

using namespace std;

struct pos{
    pair<int,int> position;
    pos(pair<int, int> p) : position(p) {}
};

struct Agent {
    int agent_id;
    struct pos position;
    int job_id;
    struct pos job;
    int priority;
    Agent(int agent_id, pos agent_pos, int job_id, pos job_pos, int priority)
        : agent_id(agent_id), position(agent_pos), job_id(job_id), job(job_pos), priority(priority) {}
};

#endif // AGENT_HPP