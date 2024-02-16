#pragma once
#include <cstring>
#include <string>
struct Parser {
    char file_name[256];
    char save_pictures[256];
    long long iter = 0;
    long long freq = 0;
};
Parser Parsing(int argc, char* argv[]);
