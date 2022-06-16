#include <ctime>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string>

struct RGB
{
    int R, G, B;
};

int randomChoice()
{
    srand((unsigned) time(0));
    int result = 1 + (rand() % 2);
    return result;
}

int randomColorNumber()
{
    srand((unsigned) time(0));
    int result = 1 + (rand() % 255);
    return result;
}

void SetBackgroundColor(const RGB& aColor)
{
    std::string modifier = "\x1b[48;2;" + std::to_string(aColor.R) + ";" + std::to_string(aColor.G) + ";" + std::to_string(aColor.B) + "m";
    printf(modifier.c_str());
}

void SetForegroundColor(const RGB& aColor)
{
    std::string modifier = "\x1b[38;2;" + std::to_string(aColor.R) + ";" + std::to_string(aColor.G) + ";" + std::to_string(aColor.B) + "m";
    printf(modifier.c_str());
}

int main()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);

    std::cout << "Generating Color \n";

    RGB color;

    color.R = int(randomColorNumber());
    std::cout << color.R << std::endl;

    Sleep(randomColorNumber() * 50 * randomChoice());
    
    color.G = int(randomColorNumber());
    std::cout << color.G << std::endl;

    Sleep(randomColorNumber() * 50 * randomChoice());

    color.B = int(randomColorNumber());
    std::cout << color.B << std::endl;

    if (color.R < 255/2)
        color.R = color.R * randomChoice();

    if (color.G < 255/2)
        color.G = color.G * randomChoice();

    if (color.B < 255/2)
        color.B = color.B * randomChoice();

    if (color.R > 255)
        color.R = 255;
    
    if (color.G > 255)
        color.G = 255;
    
    if (color.B > 255)
        color.B = 255;

    SetForegroundColor({ color.R, color.G, color.B });

    std::cout << "ColorCode: " << '[' << color.R << ", " << color.G << ", " << color.B << ']' << "\n";

    SetForegroundColor({ 255, 255, 255 });

    int nil;
    std::cin >> nil;

    return 0;
}
