#include "TimeManager.hh"

using namespace std::chrono;

TimeManager TimeManager::tm;

TimeManager::TimeManager() {}
TimeManager::~TimeManager() {}

TimeManager& TimeManager::GetInstance() {
//    if(!instance){
//        instance = new TimeManager;
//    }
//    return *instance;
//    static TimeManager _;
    return tm;
}

void TimeManager::Start() {
    start = system_clock::now();
    up = up2 = start;
}

void TimeManager::Update() {
    up = up2;
    up2 = system_clock::now();
}

unsigned int TimeManager::GetElapsedTime() const {
    return up2 != start ? duration_cast<seconds>(up2 - up).count() : 0 ;
}

unsigned int TimeManager::GetStartedTime() const {
    return duration_cast<seconds>(up2 - start).count();
}
