#include <load/loadsound.h>

#include <string>

bool loadSound::loadMusic(const std::string &file, sharedPtr<Mix_Music> music)
{
    music =  sharedPtr<Mix_Music>(Mix_LoadMUS( file.c_str() ));
            if( music == nullptr )
            {
                printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
                return (false);
            }

    return (true);
}

bool loadSFX(const std::string &file, sharedPtr<Mix_Chunk> sfx)
{

    //Load sound effects
    sfx = sharedPtr<Mix_Chunk>(Mix_LoadWAV( file.c_str() ));
    if( sfx == nullptr )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        return (false);
    }


    return (true);
}
