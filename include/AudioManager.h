#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <map>
#include <string>

#include "SoundId.h"

class AudioManager
{
public:

   AudioManager();

   void init();

   void cleanup();

   void playSound(SoundId id);

   void playMusic();

   void pauseMusic();

private:

   void loadSoundEffect(const std::string& fileName, SoundId id);

   void loadMusic(const std::string& fileName);

   typedef std::map<SoundId, Mix_Chunk*> SoundMap;

   SoundMap m_soundMap;

   Mix_Music* m_music;
};

#endif // AUDIOMANAGER_H
