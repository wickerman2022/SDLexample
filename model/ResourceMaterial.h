//Prevent file from being included more than once
#ifndef RESOURCEMATERIAL_H
#define RESOURCEMATERIAL_H

#include "GameObject.h"


class ResourceMaterial: public GameObject
{
public:
    //Constructor & Destructor
    ResourceMaterial();
    virtual ~ResourceMaterial();

    //Other methods
    virtual void Update(double dt);
    virtual void Render();
private:
    int amount; // Amount of material
    int cost; // Cost of material
};

#endif // RESOURCEMATERIAL_H



