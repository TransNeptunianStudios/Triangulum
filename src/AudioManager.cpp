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

   // Load all sound effects and add them to sound map
   auto pGunShoot = Mix_LoadWAV("../resources/gun_shoot.wav");

   if (pGunShoot != 0)
   {
      m_soundMap[GUN_SHOOT] = pGunShoot;
   }
}

void AudioManager::cleanup()
{
   for (auto p : m_soundMap)
   {
      Mix_FreeChunk(p.second);
   }

   Mix_CloseAudio();
}

void AudioManager::playSound(SoundId id)
{
   auto it = m_soundMap.find(id);

   if (it != m_soundMap.end())
   {
      Mix_PlayChannel(-1, it->second, 0);
   }
}
