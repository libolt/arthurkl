#ifndef _GAMEENGINE_H_
#define _GAMEENGINE_H_

#include "SDL.h"

#include "utilities/typedefs.h"

class graphicsEngine;
class inputEngine;
class soundEngine;

class gameEngine
{
public:
    gameEngine();  // constructor
    ~gameEngine();  // destructor

    sharedPtr<graphicsEngine> getGraphicsE() const;  // retrieves the value of graphicsE
    void setGraphicsE(const sharedPtr<graphicsEngine> &set);  // sets the value of graphicsE

    sharedPtr<inputEngine> getInputE() const;  // retrieves the value of inputE
    void setInputE(const sharedPtr<inputEngine> &set);  // sets the value of inputE

    sharedPtr<soundEngine> getSoundE() const;  // retrieves the value of soundE
    void setSoundE(const sharedPtr<soundEngine> &set);  // sets the value of soundE

    bool getQuitGame() const;  // retrieves the value of quitGame
    void setQuitGame(const bool &set);  // sets the value of quitGame

    bool getGraphicsEInitialized() const;  // retrieves the value of graphicsEInitialized
    void setGraphicxEInitialized(const bool &set);  // sets the value of graphicsEInitialied

    bool getInputEInitialized() const;  // retrieves the value of inputEInitialized
    void setInputEInitialized(const bool &set);  // sets the value of inputEInitialized

    bool getSoundEInitialized() const;  // retrieves the value of soundEInitialized
    void setSoundEInitialized(const bool &set);  // sets the value of soundEInitialized

    bool getTitleLoaded() const;  // retrieves the value of titleLoaded
    void setTitleLoaded(const bool &set);  // sets the value of titleLoaded

    bool initialize();  // initializes the game engine

    bool loadTitle();  // loads the title screen

    bool loop();  // loops through game engine logic

private:

    // Engines
    sharedPtr<graphicsEngine> graphicsE;
    sharedPtr<inputEngine> inputE;
    sharedPtr<soundEngine> soundE;

    // Event handler
    SDL_Event event;

    bool quitGame; // stores whether or not to quit the game
    bool graphicsEInitialized;  // stores whether the graphics engien has been initialized
    bool inputEInitialized;  // stores whether the input engine has been initialized
    bool soundEInitialized;  // stores whether the sound engine has been initialized

    bool titleLoaded;  // stores whether title image has been loaded

};

#endif // _GAMEENGINE_H_
