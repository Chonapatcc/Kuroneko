#include <bits/stdc++.h>
using namespace std;
#include "Info.h"
#include "Vehicle.h"
#include "Garage.h"


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