//Prevent multiple inclusions of header file
#ifndef ROAD_H
#define ROAD_H

#include "GameObject.h"

class Road: public GameObject
{
public:
    //Constructor & Destructor
    Road();
    virtual ~Road();

    //Other methods
    virtual void Update(double dt);
    virtual void Render();
private:
    int length; // Length of road
    int width; // Width of road
    int asphaltThickness; // Thickness of asphalt

};

#endif // ROAD_H