#ifndef _LOADSOUND_H_
#define _LOADSOUND_H_

#include <memory>

#include "SDL_mixer.h"

class loadSound
{
    public:
    bool loadMusic(const std::string &file, std::shared_ptr<Mix_Music> music);
    bool loadSFX(const std::string &file, std::shared_ptr<Mix_Chunk> sfx);
    private:
};

#endif // _LOADSOUND_H_
