#ifndef IOBSERVABLE_HH_
#define IOBSERVABLE_HH_

#include "IObserver.hh"
#include <list>

class IObservable {
    protected:
        std::list<IObserver*> _observers;
    public:
        virtual ~IObservable() {}
        virtual void AddObserver(IObserver *observer) = 0;
        virtual void RemoveObserver(IObserver *observer) = 0;
};

#endif