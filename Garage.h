#include <iostream>
#include "Vehicle.h"
#ifndef GARAGE_H
#define GARAGE_H

class Garage
{
private:
    Vehicle *car;
    Vehicle *head;
    int count =0 ;
public:
    //construct
    Garage()
    {}

    Garage(std::string name , double price):car(new Vehicle(name , price))
    {
        head = car;
        car->setNext(NULL);
        car->setPrev(NULL);
        count+=1;
    }

    //destructor
    ~Garage()
    {
        delete car;
        delete head;
    }


    //setter
    void setCar(Vehicle *newcar)
    {
        car= newcar;
    }

    //getter
    Vehicle *getCar() const
    {
        return car;
    }

    Vehicle *select_car(int number)
    {
        Vehicle *car0 = head;
        for(int i =0 ; i < number-1;i++)
        {
            car0 = car0->getNext();
        }

        return car0;
    }

    int getCount()const
    {
        return count; 
    }

    //addCar
    void addCar(std::string name , double price)
    {
        Vehicle *newcar = new Vehicle(name,price);
        
        car->setNext(newcar);
        newcar->setPrev(car);
        car= newcar;
        count+=1;
    }

    //deleteCar
    void deleteCar(int number)
    {
        Vehicle *car0 = head;
        for(int i =0 ; i < number-1;i++)
        {
            car0 = car0->getNext();
        }

        Vehicle *prevcar0 = car0->getPrev();
        Vehicle *nextcar0 = car0->getNext();
        prevcar0->setNext(nextcar0) ;
        nextcar0->setPrev(prevcar0) ;

        delete car0;
        count-=1;
    }
    

};


#endif