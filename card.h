#ifndef _CARD_H_
#define _CARD_H_

#include <vector>

// Card objects will have M attributes to be compared against.
// They will be stored in a player's card vector.
// The names vector stores the name for each attribute.
class Card 
{
public:
    // Initialises the attributes with random values. 
    // seed is used to ensure a different seed for randomisation
    Card(int num_attributes, int seed);

    // prints the attributes to the terminal on separate lines.
    void print_attributes();

    // returns the index of the largest attribute
    int get_largest_attr_index();

    // returns the value associated with the index passed in
    int get_value(int);

private: 
    // Contains the attribute values in a vector (max 10).
    std::vector<int> _attributes;

    // Contains the in-use attribute names in a vector (max 10).
    std::vector<char> _names;

    // Stores the index of the largest value.
    int _largest;

    // Calculates the largest attribute in the vector.
    void calc_largest();
};

#endif