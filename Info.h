#include <iostream>
#ifndef INFO_H
#define INFO_H

class Info
{
private:
    std::string name;
    double price;
public:
    //constructor
    Info()
    {}

    Info(std::string name ,double price):name(name),price(price)
    {}

    //getter
    std::string getName() const
    {
        return name;
    }

    double getPrice() const
    {
        return price;
    }

    //setter

    void setName(std::string newname)
    {
        name = newname;
    }

    void setPrice(double newprice)
    {
        price = newprice;
    }

};


#endif