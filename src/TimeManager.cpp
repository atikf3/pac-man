#include "TimeManager.hh"

TimeManager* TimeManager::instance=0;
std::chrono::time_point<std::chrono::system_clock> start, update, newUpdate;

TimeManager::TimeManager()
{
}

TimeManager::~TimeManager()
{
}

TimeManager &TimeManager::GetInstance() {
    if(!instance){
        instance = new TimeManager;
    }
    return *instance;
}

void TimeManager::Start() {
    start = std::chrono::system_clock::now();
}

void TimeManager::Update() {
    update = newUpdate;
    newUpdate = std::chrono::system_clock::now();
}

unsigned int TimeManager::GetStartedTime() const {
    unsigned int start_elapsed = std::chrono::duration_cast<std::chrono::milliseconds >
            (newUpdate-start).count();
    return start_elapsed;
}

unsigned int TimeManager::GetElapsedTime() const {
    unsigned int update_elapsed = std::chrono::duration_cast<std::chrono::milliseconds >
            (newUpdate-update).count();
    return update_elapsed;
}