#ifndef CHARACTER_HH
#define CHARACTER_HH

#include "AbstractEntity.hh"
#include "IObservable.hh"
#include "IObserver.hh"

#include "json.hpp"

using json = nlohmann::json;

class Character : public AbstractEntity, public IObservable
{
    private:
        double _x;
        double _y;
        int _life;
        std::string _type;
    public:
        virtual ~Character() = 0;

        virtual void Update();
        virtual void Draw();
    
        double GetX() const;
        void SetX(double);
        double GetY() const;
        void SetY(double);

        int GetLife() const;
        void SetLife(int);

        virtual void AddObserver(IObserver *observer) override;
        virtual void RemoveObserver(IObserver *observer) override;

        virtual std::string Serialize();
};
#endif