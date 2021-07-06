#include <iostream>
#include<list>
#include "Car.h"
#include "DrawTable.h"
using namespace std;
using namespace CarProject;

int main()
{
    list<Car> cars = { {"fso", "polonez caro", 1995, 103.0f, 113.0f, 13.8f},
        {"fiat", "126p", 1987, 25.2f, 645.0f, 33.0f},
        {"fso", "syrena 105", 1957, 26.0f, 850.0f, 55.0f} };

    Car::ListOfCars(cars);                                //Displays the list of cars
    Car::OnTheStreet(Car::ChoseCar(), cars);

}


