#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

#define STARTING_MONEY 1000
#define MAX_MONEY 1000000

class Player: public GameObject
{
public:
    //Constructor & Destructor
    Player();
    virtual ~Player();

    //Other methods
    virtual void Update(double dt);
    virtual void Render();
    void EarnMoney(int amount);
    void SpendMoney(int amount);
private:
    int money; // Amount of money
    int score; // Score
};

#endif // PLAYER_H