#include <iostream>
#include "Info.h"
#ifndef VEHICLE_H
#define VEHICLE_H


class Vehicle
{
private:
    Info *data;
    Vehicle *prev;
    Vehicle *next;
public:
    //constructor
    Vehicle()
    {}

    Vehicle(std::string name ,double price):data(new Info(name,price))
    {
    }

    //getter
    Info *getData() const
    {
        return data;
    }

    Vehicle *getPrev() const
    {
        return prev;
    }

    Vehicle *getNext() const
    {
        return next;
    }

    //setter

    void setData(Info *newdata)
    {
        data = newdata;
    }

    void setPrev(Vehicle *prev)
    {
        this->prev = prev;
    }

    void setNext(Vehicle *next)
    {
        this->next = next;
    }

    //print

    void print()
    {
        std::cout <<"Name : " <<data->getName()<<std::endl;
        std::cout <<"Price : "<<data->getPrice()<<std::endl;
    }
};

#endif
