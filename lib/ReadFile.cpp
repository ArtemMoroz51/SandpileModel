#include "Parser.h"
#include "ReadFile.h"

int* GetSizeOfPile(char* file_name) {
    int* size = new int[2] {0};
    std::ifstream file(file_name);
    if (!file.is_open()) {
        throw std::invalid_argument("File can't be opened.");
    }
    std::string str;
    while (std::getline(file, str)) {
        int first_tab = str.find('\t');
        int second_tab = str.find('\t', first_tab + 1);
        size[0] = std::max(size[0], std::stoi(str.substr(first_tab)));
        size[1] = std::max(size[1], std::stoi(str.substr(first_tab + 1, second_tab - first_tab - 1)));
    }
    return size;
}

InputData Reading(char* file_name) {
 
    InputData InputArgument;
    InputArgument.m = GetSizeOfPile(file_name)[0];
    InputArgument.n = GetSizeOfPile(file_name)[1];
    InputArgument.input_data = new int* [InputArgument.m];
    for (int i = 0; i < InputArgument.m; i++) {
        InputArgument.input_data[i] = new int[InputArgument.n] {0};
    }
    std::ifstream file(file_name);
    if (!file.is_open()) {
        throw std::invalid_argument("File can't be opened.");
    }
   
    std::string str;
    while (std::getline(file, str)) {
        int first_tab = str.find('\t');
        int second_tab = str.find('\t', first_tab + 1);
        InputArgument.input_data[std::stoi(str.substr(first_tab)) - 1][std::stoi(str.substr(first_tab + 1, second_tab - first_tab - 1)) - 1] = std::stoi(str.substr(second_tab + 1));
    }
    return InputArgument;
}
