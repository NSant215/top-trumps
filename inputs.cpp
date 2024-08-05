#include "inputs.h"


bool check_integer(std::string input)
{
    // Check if each character of the input is an integer. If any aren't, return false.
    for (int i = 0; i < input.size(); ++i)
    {
    if (isdigit(input[i]) == false)
        {
        std::cout << "Inputs must be positive integers. Please enter a value again.\n" << std::endl;
        return false;
        }
    }
    return true;
}

int get_input_num(std::string input_name, int max_val)
{
    std::string input;
    int N = -1; // If the function returns -1, an error has occurred.
    bool bad_input = true;

    // Repeatedly request for a new input until the input satisfies validity requirements.
    while (bad_input)
    {
        // This will not accept inputs such as 5.0, only inputs such as 5.
        std::cout << "Enter a number of "<<input_name<<" to play with. It must be no more than "<<max_val<< std::endl;
        std::cin >> input;
        bool is_integer = check_integer(input);
        if (is_integer)
        {
            N = std::stoi(input);
            if (N > 0 and N <= max_val)
            {
                bad_input = false;
            }
            else
            {
                std::cout << "You must enter a positive integer no more than "<<max_val<< std::endl;
            }
        }
    }
    // Return the input value once it is a valid value.
    return N;
}