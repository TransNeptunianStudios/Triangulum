#include "AudioManager.h"

AudioManager::AudioManager()
: m_soundMap()
{
}

void AudioManager::init()
{
   if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
   {
      // ASSERT
   }

   loadSoundEffect("../resources/gun_shoot.wav", GUN_SHOOT);
   loadSoundEffect("../resources/ship_explosion.wav", SHIP_EXPLOSION);
   loadSoundEffect("../resources/asteroid_hit.wav", ASTEROID_HIT);
   loadSoundEffect("../resources/asteroid_explosion.wav", ASTEROID_EXPLOSION);

   loadMusic("../resources/Space Fighter Loop.mp3");
}

void AudioManager::cleanup()
{
   for (auto p : m_soundMap)
   {
      Mix_FreeChunk(p.second);
   }

   Mix_FreeMusic(m_music);

   Mix_CloseAudio();
}

void AudioManager::playSound(SoundId id)
{
   auto it = m_soundMap.find(id);

   if (it != end(m_soundMap))
   {       
      Mix_VolumeChunk(it->second, MIX_MAX_VOLUME*0.6);
      Mix_PlayChannel(-1, it->second, 0);
   }
}

void AudioManager::playMusic()
{
    if(m_music != nullptr)
    {
        Mix_PlayMusic(m_music, -1); // -1 = loop forever
    }
}

void AudioManager::pauseMusic()
{
    printf("ONCE\n");
    if( !Mix_PausedMusic() )
    {
        Mix_PauseMusic();
    }
    else
    {
        Mix_ResumeMusic();
    }
}

void AudioManager::loadSoundEffect(const std::string& fileName, SoundId id)
{
   auto pSound = Mix_LoadWAV(fileName.c_str());

   if (pSound != 0)
   {
      m_soundMap[id] = pSound;
   }
}

void AudioManager::loadMusic(const std::string &fileName)
{
    m_music = Mix_LoadMUS(fileName.c_str());
}
