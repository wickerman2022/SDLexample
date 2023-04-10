#pragma once

#include <vector>

#include "GameObject.h"
#include "Worker.h"

using std::vector;

#define MAX_LEVEL 5

class AsphaltPlant : public GameObject
{
public:
    //Constructor & Destructor
    AsphaltPlant();
    virtual ~AsphaltPlant();

    //Other methods
    virtual void Update(double dt);     
    virtual void Render() = 0; //Render the game
    virtual void Run() = 0; //Run the game
    virtual void Exit() = 0; //Exit the game
    //Game specific methods
    virtual void ProduceAsphalt(); //Produce asphalt
    void UpgradeAsphaltPlant();
    int HireWorker(Worker *worker); //Hire a worker (if possible)
    int FireWorker(Worker *worker); //Fire a worker (if possible)
private:
    //Game specific variables
    int level; //Level of the asphalt plant
    int upgradeCost; //Cost of upgrading the asphalt plant
    int asphalt; //Amount of asphalt
    int maxAsphalt; //Maximum amount of asphalt that can be stored
    int currentProduction; //Current amount of asphalt being produced
    int maxProduction; //Maximum amount of asphalt that can be produced
    int maxWorkers; //Maximum amount of workers that can be hired
    int minWorkers; //Minimum amount of workers that need to be hired to produce asphalt
    vector <Worker*> workers; //List of workers
};