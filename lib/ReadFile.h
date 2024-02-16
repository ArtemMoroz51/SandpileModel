#pragma once

#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>

struct InputData {
    int m;
    int n;
    int** input_data;
};

int* GetSizeOfPile(char* file_name);
InputData Reading(char *file_name); 