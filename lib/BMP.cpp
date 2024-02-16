#include "BMP.h"


Color::Color()
{
    color = 0;
}

Color::Color(int color)
{
    this->color = color;
}

Color::~Color()
{
}

Image::Image(int width, int height)
{
    m_width = width;
    m_height = height;
    m_colors = new Color[width * height];
}

Image::~Image()
{
}

Color Image::GetColor(int x, int y) const
{
    return m_colors[y * m_width + x];
}


void Image::SetColor(const Color& color, int x, int y)
{
    m_colors[y * m_width + x] = color;
}
void Image::Export(const std::string& path) const
{
    std::ofstream f;
    f.open(path, std::ios::out | std::ios::binary);
    if (!f.is_open())
    {
        std::cout << "File couldnt be opened";
        return;
    }
    unsigned char bmpPad[3] = { 0 };
    int paddingAmount = (m_width / 2 + m_width % 2) % 4;
    if (paddingAmount) {
        paddingAmount = 4 - paddingAmount;
    }
    const int fileHeaderSize = 14;
    const int informationHeaderSize = 40;
    const int palletSize = 64;
    const int fileSize = fileHeaderSize + informationHeaderSize + (m_width * m_height) / 2 + paddingAmount * m_height + palletSize;

    unsigned char fileHeader[fileHeaderSize];
    //File type
    fileHeader[0] = 'B';
    fileHeader[1] = 'M';
    //File size
    fileHeader[2] = fileSize;
    fileHeader[3] = fileSize >> 8;
    fileHeader[4] = fileSize >> 16;
    fileHeader[5] = fileSize >> 24;
    //Pixel data offset
    fileHeader[10] = (palletSize + fileHeaderSize + informationHeaderSize);
    fileHeader[11] = (palletSize + fileHeaderSize + informationHeaderSize) >> 8;
    fileHeader[12] = (palletSize + fileHeaderSize + informationHeaderSize) >> 16;
    fileHeader[13] = (palletSize + fileHeaderSize + informationHeaderSize) >> 24;

    unsigned char informationHeader[informationHeaderSize];

    //Header size
    informationHeader[0] = informationHeaderSize;
    informationHeader[1] = informationHeaderSize >> 8;
    informationHeader[2] = informationHeaderSize >> 16;
    informationHeader[3] = informationHeaderSize >> 24;
    //Image width
    informationHeader[4] = m_width;
    informationHeader[5] = m_width >> 8;
    informationHeader[6] = m_width >> 16;
    informationHeader[7] = m_width >> 24;
    //Image height
    informationHeader[8] = m_height;
    informationHeader[9] = m_height >> 8;
    informationHeader[10] = m_height >> 16;
    informationHeader[11] = m_height >> 24;
    //Planes
    informationHeader[12] = 1;
    informationHeader[13] = 0;
    //Bits per pixel(RGB)
    informationHeader[14] = 4;
    informationHeader[15] = 0;
    //Compression (No compression)
    informationHeader[16] = 0;
    informationHeader[17] = 0;
    informationHeader[18] = 0;
    informationHeader[19] = 0;
    //Image size(No compression)
    informationHeader[20] = 0;
    informationHeader[21] = 0;
    informationHeader[22] = 0;
    informationHeader[23] = 0;
    //X pixels per meter (Not specified)
    informationHeader[24] = 0;
    informationHeader[25] = 0;
    informationHeader[26] = 0;
    informationHeader[27] = 0;
    //Y pixels per meter (Not specified)
    informationHeader[28] = 0;
    informationHeader[29] = 0;
    informationHeader[30] = 0;
    informationHeader[31] = 0;
    //Total colors (Color in pallet)
    informationHeader[32] = 5;
    informationHeader[33] = 0;
    informationHeader[34] = 0;
    informationHeader[35] = 0;
    //Important color (Generally ignored)
    informationHeader[36] = 5;
    informationHeader[37] = 0;
    informationHeader[38] = 0;
    informationHeader[39] = 0;

    //used five colors out of sixteen
    unsigned char pallet[64];
    //white
    pallet[0] = 0xff;
    pallet[1] = 0xff;
    pallet[2] = 0xff;
    pallet[3] = 0x0;
    //Green
    pallet[4] = 0x0;
    pallet[5] = 0xff;
    pallet[6] = 0x0;
    pallet[7] = 0x0;
    //Yellow
    pallet[8] = 0x0;
    pallet[9] = 0xff;
    pallet[10] = 0xff;
    pallet[11] = 0x0;
    //violet
    pallet[12] = 0xff;
    pallet[13] = 0x0;
    pallet[14] = 0xff;
    pallet[15] = 0x0;
    //black
    pallet[16] = 0x0;
    pallet[17] = 0x0;
    pallet[18] = 0x0;
    pallet[19] = 0x0;

    f.write(reinterpret_cast<char*>(fileHeader), fileHeaderSize);
    f.write(reinterpret_cast<char*>(informationHeader), informationHeaderSize);
    f.write(reinterpret_cast<char*>(pallet), palletSize);

    for (int y = m_height - 1; y >= 0; y--) {
        for (int x = 0; x < m_width; x++) {
            unsigned char pixel1 = GetColor(x++, y).color;
            unsigned char pixel2 = GetColor(x, y).color;
            unsigned char color[] = { ((pixel1 << 4) | pixel2) };
            f.write((char*)(color), 1);
        }
        f.write(reinterpret_cast<char*>(bmpPad), paddingAmount);
    }
    f.close();
    std::cout << "File created" << '\n';
}