#ifndef _GAMEENGINE_H_
#define _GAMEENGINE_H_

#include "SDL.h"

#include "typedefs.h"

class graphicsEngine;
class inputEngine;

class gameEngine
{
public:
    gameEngine();  // constructor
    ~gameEngine();  // destructor

    sharedPtr<graphicsEngine> getGraphicsE() const;  // retrieves the value of graphicsE
    void setGraphicsE(const sharedPtr<graphicsEngine> &set);  // sets the value of graphicsE

    sharedPtr<inputEngine> getInputE() const;  // retrieves the value of inputE
    void setInputE(const sharedPtr<inputEngine> &set);  // sets the value of inputE

    bool getQuitGame() const;  // retrieves the value of quitGame
    void setQuitGame(const bool &set);  // sets the value of quitGame

    bool getGraphicsEInitialized() const;  // retrieves the value of graphicsEInitialized
    void setGraphicxEInitialized(const bool &set);  // sets the value of graphicsEInitialied

    bool getInputEInitialized() const;  // retrieves the value of inputEInitialized
    void setInputEInitialized(const bool &set);  // sets the value of inputEInitialized

    bool getTitleLoaded() const;  // retrieves the value of titleLoaded
    void setTitleLoaded(const bool &set);  // sets the value of titleLoaded

    bool initialize();  // initializes the game engine

    bool loadTitle();  // loads the title screen

    bool loop();  // loops through game engine logic

private:

    sharedPtr<graphicsEngine> graphicsE;
    sharedPtr<inputEngine> inputE;
    //Event handler
    SDL_Event event;

    bool quitGame; // stores whether or not to quit the game
    bool graphicsEInitialized;  // stores whether the graphics engien has been initialized
    bool inputEInitialized;  // stores whether the input engine has been initialized
    bool titleLoaded;  // stores whether title image has been loaded

};

#endif // _GAMEENGINE_H_
