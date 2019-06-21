#include <iostream>
#include "engine/graphicsengine.h"
#include "engine/inputengine.h"

using namespace std;

int main( int argc, char* args[] )
{
    sharedPtr<graphicsEngine> gEngine(new graphicsEngine);
    sharedPtr<inputEngine> iEngine(new inputEngine);

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
