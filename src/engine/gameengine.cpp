#include "engine/gameengine.h"
#include "engine/graphicsengine.h"
#include "engine/inputengine.h"

gameEngine::gameEngine()  // constructor
{
    quitGame = false;
    graphicsEInitialized = false;
    inputEInitialized = false;
    titleLoaded = false;
}
gameEngine::~gameEngine() = default;;  // destructor


sharedPtr<graphicsEngine> gameEngine::getGraphicsE() const  // retrieves the value of graphicsE
{
    return (graphicsE);
}
void gameEngine::setGraphicsE(const sharedPtr<graphicsEngine> &set)  // sets the value of graphicsE
{
    graphicsE = set;
}


sharedPtr<inputEngine> gameEngine::getInputE() const  // retrieves the value of inputE
{
    return (inputE);
}
void gameEngine::setInputE(const sharedPtr<inputEngine> &set)  // sets the value of inputE
{
    inputE = set;
}

bool gameEngine::getQuitGame() const  // retrieves the value of quitGame
{
    return (quitGame);
}
void gameEngine::setQuitGame(const bool &set)  // sets the value of quitGame
{
    quitGame = set;
}

bool gameEngine::getGraphicsEInitialized() const  // retrieves the value of graphicsEInitialized
{
    return (graphicsEInitialized);
}
void gameEngine::setGraphicxEInitialized(const bool &set)  // sets the value of graphicsEInitialied
{
    graphicsEInitialized = set;
}

bool gameEngine::getInputEInitialized() const  // retrieves the value of inputEInitialized
{
    return (inputEInitialized);
}
void gameEngine::setInputEInitialized(const bool &set)  // sets the value of inputEInitialized
{
    inputEInitialized = set;
}

bool gameEngine::getTitleLoaded() const  // retrieves the value of titleLoaded
{
    return (titleLoaded);
}
void gameEngine::setTitleLoaded(const bool &set)  // sets the value of titleLoaded
{
    titleLoaded = false;
}

bool gameEngine::initialize()  // initializes the game engine
{
   sharedPtr<graphicsEngine> tempGraphicsE(new graphicsEngine);
   graphicsE = tempGraphicsE;

   sharedPtr<inputEngine> tempInputE(new inputEngine);
   inputE = tempInputE;

    //Start up SDL and create window

    if (!graphicsEInitialized)
    {
        if( !graphicsE->initialize() )
        {
            printf( "Failed to initialize!\n" );
        }
        else
        {
            graphicsEInitialized = true;
        }
    }
    else
    {

    }

    if (!inputEInitialized)
    {
        if( !inputE->initialize() )
        {
            printf( "Failed to initialize!\n" );
        }
        else
        {
            inputEInitialized = true;
        }
    }
    else
    {

    }

    loadTitle();

    return(true);
}

bool gameEngine::loadTitle()  // loads the title screen
{
    //Load media
    if (!titleLoaded)
    if( !graphicsE->loadMedia("King-Arthur-Logo.png") )
    {
        printf( "Failed to load media!\n" );
    }
    else
    {
        titleLoaded = true;
    }

    return (true);
}

bool gameEngine::loop()  // loops through game engine logic
{
    //Handle events on queue
    while( SDL_PollEvent( &event ) != 0 )
    {
        //User requests quit
        if( event.type == SDL_QUIT )
        {
            quitGame = true;
        }
    }
    return (true);
}
