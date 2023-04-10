#pragma once

#include "GameObject.h"
#include <string>

//Enum for worker type
enum WORKER_TYPE
{
    WORKER_TYPE_NONE = 0,
    WORKER_TYPE_ASPHALT_PLANT,
    WORKER_TYPE_TRUCK_DRIVER,
    WORKER_TYPE_ASPAHALT_PAVER_DRIVER,
    WORKER_TYPE_ASPAHALT_ROLLER_DRIVER,
    WORKER_TYPE_ROAD_CONSTRUCTION
};

class Worker: public GameObject
{
public:
    //Constructor & Destructor
    Worker();
    virtual ~Worker();

    //Other methods
    virtual void Update(double dt);
    virtual void Render();
private:
    std::string name; // Name of worker
    WORKER_TYPE type; // Type of worker
    int salary; // Salary of worker
    int workHours; // Work hours of worker
    int workDays; // Work days of worker
};
