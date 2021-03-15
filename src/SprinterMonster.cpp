#include "SprinterMonster.hh"

SprinterMonster::SprinterMonster()
{
    SetLife(25);
}

SprinterMonster::~SprinterMonster()
{
}

void SprinterMonster::Update()
{
    TimeManager &tm = TimeManager::GetInstance();
    this->SetX(this->GetX() + (tm.GetElapsedTime() / 200.0));
	this->SetY(this->GetY() + (tm.GetElapsedTime() / 200.0));
}
