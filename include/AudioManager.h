#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <map>

#include "SDL_mixer.h"

#include "SoundId.h"

class AudioManager
{
public:

   AudioManager();

   void init();

   void cleanup();

   void playSound(SoundId id);

private:

   typedef std::map<SoundId, Mix_Chunk*> SoundMap;

   SoundMap m_soundMap;
};

#endif // AUDIOMANAGER_H
