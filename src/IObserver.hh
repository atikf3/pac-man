#ifndef IOBSERVER_HH_
#define IOBSERVER_HH_

#include "IObservable.hh"

class IObservable;

class IObserver {
    public:
        virtual ~IObserver() {}
        virtual void Notify(IObservable *observable) = 0; 
};

#endif