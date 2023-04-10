#include "AsphaltPlant.h"

AsphaltPlant::AsphaltPlant()
{
    level = 1;
    upgradeCost = 100;
    asphalt = 0;
    maxAsphalt = 100;
    currentProduction = 0;
    maxProduction = 10;
    maxWorkers = 2;
    minWorkers = 1;
}

void AsphaltPlant::Update(double dt)
{
}

void AsphaltPlant::Render()
{
}

//Game specific methods
void AsphaltPlant::ProduceAsphalt()
{
    if (workers.size() >= minWorkers)
    {
        if (asphalt < maxAsphalt)
        {
            asphalt += maxProduction;
        }
    }
}

void AsphaltPlant::UpgradeAsphaltPlant()
{
    if (level < MAX_LEVEL)
    {
        level++;
    }
    switch (level)
    {
    case 2:
        upgradeCost = 200;
        maxAsphalt = 200;
        maxProduction = 20;
        maxWorkers = 3;
        minWorkers = 2;
        break;
    case 3:
        upgradeCost = 300;
        maxAsphalt = 300;
        maxProduction = 30;
        maxWorkers = 4;
        minWorkers = 3;
        break;
    case 4:
        upgradeCost = 400;
        maxAsphalt = 400;
        maxProduction = 40;
        maxWorkers = 5;
        minWorkers = 4;
        break; 
    case 5:
        upgradeCost = 0; //No more upgrades
        maxAsphalt = 500;
        maxProduction = 50;
        maxWorkers = 5;
        minWorkers = 5;
        break;
    }
}

int AsphaltPlant::HireWorker(Worker* worker)
{
    if (workers.size() < maxWorkers)
    {
        workers.push_back(worker);
        return 1;
    }
    return 0;
}

int AsphaltPlant::FireWorker(Worker* worker)
{
    for (int i = 0; i < workers.size(); i++)
    {
        if (workers[i] == worker)
        {
            workers.erase(workers.begin() + i);
            return 1;
        }
    }
    return 0;
}