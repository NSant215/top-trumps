#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <deque>
#include "card.h"
#include <string>

// This class is used to represent a player.
// Stores the name of the player, a deque of cards and number of hands won.
class Player
{
public:
    // Initialise the player data.
    Player(std::string name);

    // Public destructor. Destroys all cards stored in the player's deque.
    ~Player();

    // Remove the first pointer from the deque and return it.
    Card* draw_card();

    // Increment the number of hands won.
    void won_hand();

    // Append a card pointer to the end of the card deque.
    void add_card(Card*);
    
    // Return the number of hands won.
    int get_hands_won() {return _hands_won;}

    // Return the number of pointers in the deque.
    int number_of_cards() {return _cards.size();}

    // Return the name of the player.
    std::string get_name() {return _name;}

private: 
    std::string _name;
    int _hands_won;
    std::deque<Card*> _cards;
};


#endif