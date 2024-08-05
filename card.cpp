#include <iostream>
#include <cstdlib>
#include "card.h"
#include <algorithm>

Card::Card(int num_attributes, int seed) 
{
    ///
    // srand chooses the seed from which the rand function generates random numbers.
    // For the seed to be different for every card, we pass a seed value which is set on dealing the cards.
    // The time parameter is still needed to ensure cards produced in different games also vary.
    //
    srand(time(NULL) + seed);
    int max;
    max = 100; // max random number value
    
    char letters[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    
    ///
    // Pick random numbers to store as attribute values in the _attributes list
    // Store letters to act as names for the attributes.
    //
    for (int i = 0; i < num_attributes; ++i) 
    {
        int val = rand()%max;
        _attributes.push_back(val);
        _names.push_back(letters[i]);
    }
    calc_largest();
}

void Card::print_attributes() 
{
    for (int i = 0; i < _attributes.size(); ++i)
    {
        std::cout << _names[i] << ": " << _attributes[i] << std::endl;
    }
}

int Card::get_largest_attr_index()
{
    return _largest;
}

int Card::get_value(int index)
{
    return _attributes[index];
}


void Card::calc_largest()
{
    _largest = std::max_element(_attributes.begin(),_attributes.end()) - _attributes.begin();
}