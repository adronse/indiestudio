/*
** EPITECH PROJECT, 2020
** error
** File description:
** error
*/

#include <fstream>
#include "../include/error.hpp"
#include <exception>
#include <stdexcept>
#include <vector>
#include <sstream>

ArgError::ArgError(std::string const& message) throw()
{
    _message = message;
}

FileError::FileError(std::string const& message) throw()
{
    _message = message;
}

FileExtensionError::FileExtensionError(std::string const& message) throw()
{
    _message = message;
}

InputErrorUser::InputErrorUser(std::string const& message) throw()
{
    _message = message;
}

LoopError::LoopError(std::string const& message) throw()
{
    _message = message;
}

std::vector<std::string> split(std::string strToSplit, char delimeter)
{
    std::stringstream ss(strToSplit);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, delimeter)) {
        splittedStrings.push_back(item);
    }
    return (splittedStrings);
}

int error_input_value(char **av, std::vector<std::string> input)
{
    int x = 0;
    int errorinputvalue = 0;
    std::string input0 = "=0";
    std::string input1 = "=1";

    for (auto& i : input) {
        std::string check0 { input[x].c_str() + input0};
        std::string check1 { input[x].c_str() + input1};
        if (check0.compare(av[x + 2]) != 0 && check1.compare(av[x + 2]) != 0)
            errorinputvalue++;
        x++;
        i = 1;
    }
    if (errorinputvalue != 0) {
        throw InputErrorUser("Not right input must be [input]=0 or [input]=1 for each input");
        return (1);
    }
    return (0);
}

void error_input(int ac, char **av, std::vector<std::string> input)
{
    int x = 0;

    for (auto& i : input) {
        x++;
        i = 1;
    }
    if (x + 2 != ac)
        throw InputErrorUser("Not enought or too much input");
}