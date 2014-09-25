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

   if (it != end(m_soundMap))
   {
      Mix_PlayChannel(-1, it->second, 0);
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
