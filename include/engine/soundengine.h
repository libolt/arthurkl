#ifndef _SOUNDENGINE_H_
#define _SOUNDENGINE_H_

#include "SDL_mixer.h"

#include <memory>

class soundEngine
{
    public:
    bool init(void);

    private:
    std::shared_ptr<Mix_Music> music;
    std::shared_ptr<Mix_Chunk> scratch;
    std::shared_ptr<Mix_Chunk> high;
    std::shared_ptr<Mix_Chunk> medium;
    std::shared_ptr<Mix_Chunk> low;
};

#endif // _SOUNDENGINE_H_
