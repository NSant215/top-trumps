#ifndef _GAME_H_
#define _GAME_H_

#include "player.h"
#include "card.h"
#include <string>

///
// This class has methods to run a full game of Top Trumps.
// 2 players are initialised and their pointers are stored in an array.
// cards are dealt as they are created alternatingly between the players
// The game is carried out round by round, where cards are redistributed accordingly.
// The loser is the player left with no cards.
// A tie occurs if both players end up with no cards.
//
class Game
{
public:
    ///
    // initialise an instance of the game with choosing a starting player and creating cards.
    //
    Game(int num_cards, int num_attributes);

    // destructor method deletes all cards and player objects created.
    ~Game();

    // While empty_hand_check is true, execute the round function.
    // At the end, return the winner, or NULL if it is a tie.   
    Player* run_game();

    // Print the winner and number of hands won by each player.
    void finish(Player*);

private:

    // An array of pointers to the players in the game.
    Player* _players[2];

    int _num_players = 2;
    Player* _player_starting_round;

    // Store the cards to be appended to the winner's deque.
    std::deque<Card*> _cards_in_play;

    // Randomly assign one of the players to be the first one starting a round.
    void choose_starting_player();

    // Create the instances of cards with the specified number of attributes.
    // Deal them between the players.
    void create_cards(int num_cards, int num_attributes);

    // Carry out a round of the game.
    // Print the number of cards owned by each player.
    // Add the top card from each player to the cards_in_play deque.
    // Compare the cards and manage the cards appropriately.
    void play_round();

    // Get the first card pointer from the player.
    // Present the associated card and return the pointer.
    Card* draw_top_card(Player*);

    // Call get_largest_attribute for the starting player's card.
    // Compare this to the attribute for the other player's card.
    // Eeturn the winning player or NULL if there is a tie.
    Player* compare_cards();

    // Append all pointers in cards_in_play to the winner's deque.
    void manage_cards(Player*);

    // Return true if at least one player is out of cards.
    bool check_game_ended();

    // Return the winning player or a null pointer if there is a tie.
    Player* get_winner();
};

#endif