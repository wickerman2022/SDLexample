#pragma once

//Class definition for GameObject
//This is an abstract class (pure virtual destructor)
class GameObject
{
public:
    //Constructor & Destructor
    GameObject() {};
    virtual ~GameObject() = 0; //Pure virtual destructor

    //Other methods
    virtual void Update(double dt) = 0;
    virtual void Render() = 0;
};