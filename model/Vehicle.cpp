#include "Vehicle.h"

Vehicle::Vehicle()
{
    //ctor
}

Vehicle::~Vehicle()
{
    //dtor
}

void Vehicle::HireDriver(Worker* driver)
{
    this->driver = driver;
}

void Vehicle::FireDriver()
{
    this->driver = NULL;
}

void Vehicle::Refuel(int amount)
{
    this->fuel += amount;
}
// Path: Vehicle.cpp