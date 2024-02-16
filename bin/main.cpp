#include <iostream>
#include "..\lib\Queue.h"
#include "..\lib\BMP.h"
#include "..\lib\Parser.h"
#include "..\lib\SandPile.h"
#include "..\lib\ReadFile.h"

int main(int argc, char** argv) {
    Parser argument_parser = Parsing(argc, argv);
    InputData arguments_input = Reading(argument_parser.file_name);
    SandPile(arguments_input, argument_parser);
    return 0;   
}