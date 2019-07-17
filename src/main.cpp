#include <iostream>
#include "engine/gameengine.h"
#include "engine/graphicsengine.h"
#include "engine/inputengine.h"

using namespace std;

int main( int argc, char* args[] )
{
    sharedPtr<gameEngine> gameE(new gameEngine);

    //Start up the gameEngine
    if( !gameE->initialize() )
    {
        printf( "Failed to initialize!\n" );
    }
    gameE->getGraphicsE()->updateWindow();

    while (!gameE->getQuitGame())
    {
        std::cout << "blah" << endl;
        gameE->loop();
        gameE->getInputE()->processInput();
    }
    //Free resources and close SDL
    gameE->getGraphicsE()->close();

    return 0;
}
