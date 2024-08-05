#include "player.h"
#include <iostream>

Player::Player(std::string name)
{
    _hands_won = 0;
    _cards = {};
    _name = name;
}

Player::~Player()
{
    for(auto & card: _cards)
    {
        delete card;
    }
}

// Get the pointer for the first card. remove the pointer from the list and return it.
Card* Player::draw_card()
{
    Card* new_card = _cards[0];
    _cards.pop_front();
    return new_card;
}

void Player::won_hand()
{
    ++_hands_won; // Increment the number by one.
}

void Player::add_card(Card* new_card)
{
    _cards.push_back(new_card); // This adds a card to the end of the deque.
}