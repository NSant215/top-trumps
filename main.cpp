#include <iostream>
#include <cstdlib>
#include <cassert>
#include "card.h"
#include "player.h"
#include "game.h"
#include "inputs.h"

int main()
{
  // get values for N cards and M attributes from user input
  int num_cards = get_input_num("cards", 20);
  int num_attributes = get_input_num("attributes", 10);

  // This is to ensure the user inputs were properly validated.
  assert(num_cards != -1 and num_attributes != -1);

  // Initialise the game instance with the number of cards and attributes decided by the user.
  Game top_trumps(num_cards, num_attributes);

  // Run the game and present the winner at the end.
  Player* winner = top_trumps.run_game();
  top_trumps.finish(winner);

  // This is to explicitly have the user just press enter to end the program.
  int c = 0;
  while (c != '\n')
  {
    std::cin.clear();
    std::cin.ignore();
    std::cout << "Press enter to end: ";
    c = std::cin.get();
  }

  return 0;
}