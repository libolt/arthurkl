#include <load/loadsound.h>

bool loadMusic(const std::string &file, std::shared_ptr<Mix_Music> music);
bool loadSFX(const std::string &file, std::shared_ptr<Mix_Chunk> sfx);
