#ifndef ZOMBIE_MONSTER_HH
#define ZOMBIE_MONSTER_HH

#include "Character.hh"
#include "TimeManager.hh"
#include "Pacman.h"

enum direction { haut = 1, bas = 2 , gauche=3 , droite=4 };

class ZombieMonster : public Character
{
    public:
        ZombieMonster();
        ~ZombieMonster();
        void Update();
        void Move(Pacman &pacman, int map[31][28]);
        void  Mov(Pacman &pacman , int map[31][28], int adjacent , int oppose );
        void Gauche(int maps[31][28]);
        void Droit(int maps[31][28]);
        void Haut(int maps[31][28]);
        void Bas(int maps[31][28]);
        void Avance(int map[31][28]);
        bool isOnIntersec(int maps[31][28]);
        void changeDirection(double adjacent, double oppose);
        void forceDeplacement( int map[31][28],int adjacent, int oppose);
        bool forceMove=false;
        int reportMove=0;
        direction direction;


    void forceChangeDirection();
};
#endif