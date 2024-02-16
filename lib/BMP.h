#pragma once
#include <string>
#include <iostream>
#include <cmath>
#include <fstream>
struct Color
{
    unsigned char color;
    Color();
    Color(int color);
    ~Color();
};

struct Image
{
    Image(int width, int height);
    ~Image();

    Color GetColor(int x, int y) const;
    void SetColor(const Color& color, int x, int y);

    void Export(const std::string& path) const;

    int m_width;
    int m_height;
    Color* m_colors;
};