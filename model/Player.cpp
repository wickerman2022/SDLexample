#include "Player.h"

Player::Player()
{
    this->money = STARTING_MONEY;
    this->score = 0;
}

Player::~Player()
{
    //dtor
}

void Player::Update(double dt)
{
    //TODO: Update player
}

void Player::Render()
{
    //TODO: Render player
}

void Player::EarnMoney(int amount)
{
    //Check if player has reached the maximum amount of money
    if (this->money < MAX_MONEY)
    {
        this->money += amount;
    } else {
        this->money = MAX_MONEY;
    }
}

void Player::SpendMoney(int amount)
{
    //Check if player has enough money
    if (this->money >= amount)
    {
        this->money -= amount;
    }
}

// Path: Player.cpp