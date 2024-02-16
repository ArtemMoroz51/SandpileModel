#include "Parser.h"

Parser Parsing(int argc, char* argv[]) {
    Parser argument_parser;
    argument_parser.iter == 0;
    bool is_output = 0;
    argument_parser.freq = 0;
    std::strcpy(argument_parser.save_pictures, "");
    for (int i = 1; i < argc; i++) {
        char* arg = argv[i];

        if ((std::strcmp(arg, "--input") == 0) || (std::strcmp(arg, "-i") == 0)) {
            std::strcpy(argument_parser.file_name, argv[i + 1]);
        }
        else if ((std::strcmp(arg, "--output") == 0) || (std::strcmp(arg, "-o") == 0)) {
            std::strcpy(argument_parser.save_pictures, argv[i + 1]);
            is_output = 1;
        }
        else if ((std::strcmp(arg, "--max-iter") == 0) || (std::strcmp(arg, "-m") == 0)) {
            argument_parser.iter = atoll(argv[i + 1]);
        }
        else if ((std::strcmp(arg, "--freq") == 0) || (std::strcmp(arg, "-f") == 0)) {
            argument_parser.freq = atoll(argv[i + 1]);
        }
    }

    return argument_parser;
}