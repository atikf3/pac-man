#include "MonsterFactory.hh"

MonsterFactory::MonsterFactory()
{

}

MonsterFactory::~MonsterFactory()
{

}

Character* MonsterFactory::Create(const std::string &className) {

    if(className == "ZombieMonster"){
        return new ZombieMonster;
    }
    else if (className == "SprinterMonster"){
    	return new SprinterMonster;
    }
    else
    {
        return nullptr;
    }
}

Character *MonsterFactory::Unserialize(const std::string &jsonStr)
{
    json object = json::parse(jsonStr);

    if (object["type"] == "ZombieMonster")
        return new ZombieMonster(object["x"], object["y"], object["life"]);
    else if (object["type"] == "SprinterMonster")
        return new SprinterMonster(object["x"], object["y"], object["life"]);
   return nullptr;
}