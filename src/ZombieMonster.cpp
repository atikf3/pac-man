#include "ZombieMonster.hh"

ZombieMonster::ZombieMonster()
{
    SetLife(100);
}

ZombieMonster::~ZombieMonster()
{
}

void ZombieMonster::Update()
{
    TimeManager &tm = TimeManager::GetInstance();
    this->SetX(this->GetX() + (tm.GetElapsedTime() / 1000.0));
	this->SetY(this->GetY() + (tm.GetElapsedTime() / 1000.0));
}
