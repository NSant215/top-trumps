#ifndef _INPUTS_H_
#define _INPUTS_H_

#include <iostream>
#include <cstdlib>


// a function to check if inputs are integers by making sure all characters inputted are numbers
bool check_integer(std::string input);

// This function handles validation of user input.
// The input name and max value are used to format output and control the maximum value the input can take.
int get_input_num(std::string input_name, int max_val);

#endif