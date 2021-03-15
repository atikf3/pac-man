#ifndef SPRINTER_MONSTER_HH
#define SPRINTER_MONSTER_HH

#include "Character.hh"
#include "TimeManager.hh"

class SprinterMonster : public Character
{
    public:
        SprinterMonster();
        ~SprinterMonster();
        virtual void Update();
};
#endif