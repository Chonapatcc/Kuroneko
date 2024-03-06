#include <bits/stdc++.h>
using namespace std;

class Info
{
private:
    string name;
    double price;
public:
    //constructor
    Info()
    {}

    Info(string name ,double price):name(name),price(price)
    {}

    //getter
    string getName() const
    {
        return name;
    }

    double getPrice() const
    {
        return price;
    }

    //setter

    void setName(string newname)
    {
        name = newname;
    }

    void setPrice(double newprice)
    {
        price = newprice;
    }

};

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

    Vehicle(string name ,double price):data(new Info(name,price))
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
        cout <<"Name : " <<data->getName()<<endl;
        cout <<"Price : "<<data->getPrice()<<endl;
    }
};

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

    Garage(string name , double price):car(new Vehicle(name , price))
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
    void addCar(string name , double price)
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


int main()
{

    Garage garage1("Car1",100);

    garage1.addCar("Car2",200);

    garage1.addCar("Car3",300);

    garage1.deleteCar(2);
    for(int i =1 ; i <=garage1.getCount(); i ++)
    {
        garage1.select_car(i)->print();
    }


}