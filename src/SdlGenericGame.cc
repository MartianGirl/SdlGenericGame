#include <iostream>
#include <SDL2/SDL.h>

// Main function
int main(int argc, char *argv[])
{
    // Initialize graphics, sound, input...
    //
    // I'm going to use SDL2 for all of these. So maybe there is a single
    // point of initialization...
    // However, should I create separate objects in order to separate
    // the functions (audio, graphics) for the system?
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }


    // Initialize logic (computer simulation)

    // Main loop

    // Cleanup
    SDL_Quit();

    return 0;
}

// vim: et:sw=4:ts=4
