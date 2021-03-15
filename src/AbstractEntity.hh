#ifndef ABSTRACT_ENTITY_HH
#define ABSTRACT_ENTITY_HH

#include "ISerializable.hh"

class AbstractEntity : ISerializable
{
    public:
        AbstractEntity();
        virtual ~AbstractEntity() {};

        virtual void Update() = 0;
        virtual void Draw() = 0;

        virtual std::string Serialize() = 0;
};
#endif