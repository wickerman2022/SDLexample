#pragma once

#include <iostream>
#include <string>

#include "GameObject.h"

//Customer class inherits from GameObject class that stores the company 
class Customer : public GameObject
{
public:
    //Constructor & Destructor
    Customer();
    ~Customer();

    //Other methods
    void Update(double dt);
    void Render();

    //Getters & Setters
    std::string GetCompanyName();
    void SetCompanyName(std::string companyName);

private:
    //Customer properties
    std::string companyName;
};

