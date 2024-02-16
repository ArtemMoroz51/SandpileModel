#include "..\lib\SandPile.h"
void CreatFile(Pile sand_pile, std::string direction_file) {
    std::string name_file;
    if (direction_file != "") {
        name_file = "/image";
    }
    else {
        name_file = "image";
    }

    const int width = sand_pile.m;
    const int height = sand_pile.n;
    Image image(width, height);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (sand_pile.sand_pile[y][x] > 4) {
                image.SetColor(4, x, y);
                continue;
            }
            image.SetColor(Color(sand_pile.sand_pile[y][x]), x, y);
        }
    }
    image.Export(direction_file +   name_file + std::to_string(sand_pile.number_of_iteration) + ".bmp");
}