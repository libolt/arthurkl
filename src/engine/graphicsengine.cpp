#include "engine/graphicsengine.h"

graphicsEngine::graphicsEngine()  // constructor
{

}
graphicsEngine::~graphicsEngine() = default;  // destructor

bool graphicsEngine::initialize()  // initializes the graphics engine
{
    //Initialization flag
    bool success = true;
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() ); success = false;
    }
    else
    {
        //Create window
        sdlWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN );
        if( sdlWindow == nullptr )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            sdlScreenSurface = SDL_GetWindowSurface( sdlWindow );
        }
    }
    return success;
}

bool graphicsEngine::loadMedia()
{
    //Loading success flag
    bool success = true;
    //Load splash image
    SDL_RWops *rwop;
    rwop=SDL_RWFromFile("King-Arthur-Logo.png", "rb");
    sdlHelloWorld = IMG_LoadPNG_RW( rwop );
    if( sdlHelloWorld == nullptr )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
        success = false;
    }
    return success;
}


bool graphicsEngine::updateWindow()  // updates the contents of the windo
{
    //Apply the image
    SDL_BlitSurface( sdlHelloWorld, nullptr, sdlScreenSurface, nullptr );
    //Update the surface
    SDL_UpdateWindowSurface( sdlWindow );
    //Wait two seconds
    SDL_Delay( 2000 );

    return (true);
}
void graphicsEngine::close()
{
    //Deallocate surface
    SDL_FreeSurface( sdlHelloWorld );
    sdlHelloWorld = nullptr;
    //Destroy window
    SDL_DestroyWindow( sdlWindow );
    sdlWindow = nullptr;
    //Quit SDL subsystems
    SDL_Quit();
}

