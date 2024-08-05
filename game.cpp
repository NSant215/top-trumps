#include <iostream>
#include "game.h"
#include <cstdlib>
#include <algorithm>
#include <cassert>

Game::Game(int num_cards, int num_attributes)
{
    // Declare players participating and store them in the players array.
    Player* player_A = new Player("Player A");
    Player* player_B = new Player("Player B");
    _players[0] = player_A;
    _players[1] = player_B;
    
    choose_starting_player();
    create_cards(num_cards, num_attributes);
    _cards_in_play = {};
    
}

Game::~Game()
{
    // necessary if both players end with no cards.
    for (auto & card: _cards_in_play)
    {
        delete card;
    }

    // Delete each player object made. The player destructors handle deletion of cards in their deques.
    for (auto & player: _players)
    {
        delete player;
    }
    std::cout << "Game ended." << std::endl;
}

Player* Game::run_game()
{
    while(check_game_ended() == false)
    {
        play_round();
    }
    return get_winner();
}

void Game::finish(Player* winner)
{
    // Output the name of the winner and the number of hands won by each player.
    if (winner == NULL) 
    {
        std::cout << "It is a tie!" << std::endl;
    }
    else
    {
        std::string winner_name = winner->get_name();
        std::cout << "The winner is: " << winner_name << std::endl;
    }

    for (auto & player: _players)
    {
        int wins = player->get_hands_won();
        std::string name = player->get_name();

        std::cout << name << " has won " << wins << " hands." << std::endl;
    }
}

void Game::choose_starting_player()
{
    // Choose 0 or 1 randomly to pick the starting player randomly.
    srand(time(NULL));
    int chosen = rand()%_num_players;

    _player_starting_round = _players[chosen];
    std::cout << "\nThe player starting is: " << _player_starting_round->get_name() << std::endl;
}

void Game::create_cards(int num_cards, int num_attributes)
{
    // Stores the index of the player currently being dealt a card.
    int deal_to = 0;

    // Deal one card to each player. Repeat until all cards have been dealt.
    for (int i = 0; i < num_cards; i++)
    {
        Card* new_card = new Card(num_attributes, i);
        deal_to = i%_num_players;
        _players[deal_to]->add_card(new_card);
    }
}

void Game::play_round()
{
    // Print the number of cards owned by each player as a check on the progress of the game.
    for (auto & player: _players)
    {
        std::string name = player->get_name();
        int player_num_cards = player->number_of_cards();
        std::cout << name << " has " << player_num_cards << " cards." << std::endl;
    }

    // Get and append the top card pointers from eaach player to the cards_in_play deque.
    for(int i = 0; i<_num_players; i++)
    {
        Card* new_card = draw_top_card(_players[i]);
        _cards_in_play.push_front(new_card);
    }

    int size = _cards_in_play.size();
    std::cout << "cards in play: " << size << std::endl;

    Player* winner = compare_cards();
    // no cards should be moved if the outcome was a tie
    if (winner != NULL)
    {
        _player_starting_round = winner;
        manage_cards(_player_starting_round);
    }
}


Card* Game::draw_top_card(Player* player)
{
    Card* new_card = player->draw_card();

    // Present the card.
    std::string name = player->get_name();
    std::cout << name << " card: " << std::endl;
    new_card->print_attributes();

    return new_card;
}

Player* Game::compare_cards()
{
    // Choose the attribute index to be used for comparison according to the starting player.
    int index;
    if (_player_starting_round == _players[0])
    {
        index = _cards_in_play[0]->get_largest_attr_index();
    }
    else
    {
        index = _cards_in_play[1]->get_largest_attr_index();
    }

    // Create a list of card values in play and the names associated with the players playing.
    std::vector<int> card_values;
    std::vector<std::string> names;
    for(int i = 0; i < _num_players; i++)
    {
        card_values.push_back(_cards_in_play[i]->get_value(index));
        names.push_back(_players[i]->get_name());
    }

    std::cout<<"Value for "<<names[0]<<": "<<card_values[0]<<". Value for "<<names[1]<<": "<<card_values[1]<<std::endl;

    // if more than two players added, then we could find the maximum element in the list
    // This would add complication in the handling of a tie event.
    if (card_values[0] > card_values[1])
    {
        std::cout<<names[0]<<" has won this round.\n"<<std::endl;
        _players[0]->won_hand();
        return _players[0];
    }
    else if (card_values[1] > card_values[0])
    {
        std::cout<<names[1]<<" has won this round.\n"<<std::endl;
        _players[1]->won_hand();
        return _players[1];
    } 
    else
    {
        std::cout<<"This round is a tie.\n"<<std::endl;
        return NULL;
    }
}

void Game::manage_cards(Player* winner)
{
    // transfer cards in _cards_in_play to the winner.
    for (auto & card: _cards_in_play)
    {
        winner->add_card(card);
        _cards_in_play.pop_front();
    }
     assert(_cards_in_play.size() == 0);
}

bool Game::check_game_ended()
{
    for(auto & player: _players)
    {
        if (player->number_of_cards() == 0)
        {
            return true;
        }
    }
    return false;
}

// This method would require more thought if there were more than 2 players.
Player* Game::get_winner()
{
    if(_players[0]->number_of_cards() == 0 and _players[1]->number_of_cards() == 0)
    {
        return NULL;
    }
    else if (_players[0]->number_of_cards() == 0)
    {
        return _players[1];
    }
    else
    {
        return _players[0];
    }
}