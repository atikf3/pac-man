#ifndef TIME_MANAGER_HH
#define TIME_MANAGER_HH
#include <iostream>
#include <chrono>

class TimeManager
{
    private:
        TimeManager& operator= (const TimeManager&);
        static TimeManager* instance;
    public:
        TimeManager();
        ~TimeManager();
        TimeManager (const TimeManager&);
        static TimeManager& GetInstance();
        void Start();
        void Update();
        unsigned int GetElapsedTime() const;
        unsigned int GetStartedTime() const;
};
#endif