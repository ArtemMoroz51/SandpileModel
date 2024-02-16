#pragma once
#include "..\lib\Queue.h"
#include "..\lib\BMP.h"
#include "..\lib\Parser.h"
#include "..\lib\ReadFile.h"

#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>

struct Pile {
    int m;
    int n;
    int number_of_iteration;
    int** sand_pile;

};
void SandPile(InputData input_data, Parser parser);
int** AddStringUp(int** input_data, int m, int n);
int** AddStringDown(int** input_data, int m, int n);
int** AddColumnLeft(int** input_data, int m, int n);
int** AddColumnRight(int** input_data, int m, int n);
void CreatFile(Pile sand_pile, std::string direction_file);
