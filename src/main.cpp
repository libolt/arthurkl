#include <iostream>
#include "graphicsengine.h"

using namespace std;

int main( int argc, char* args[] )
{
    sharedPtr<graphicsEngine> gEngine(new graphicsEngine);
    //Start up SDL and create window
    if( !gEngine->initialize() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !gEngine->loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            gEngine->updateWindow();
        }
    } //Free resources and close SDL
    gEngine->close();
    return 0;
}
