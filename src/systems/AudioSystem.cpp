#include "systems/AudioSystem.h"
#include "AudioManager.h"

using namespace entityx;

AudioSystem::AudioSystem(AudioManager &audioManager)
: m_audioManager(audioManager)
, m_musicMute(false)
{
}

void AudioSystem::configure(EventManager& eventManager)
{
   eventManager.subscribe<EvPlaySound>(*this);
   eventManager.subscribe<EvMusicVolume>(*this);
}

void AudioSystem::update(EntityManager& entities,
                         EventManager& events,
                         double dt)
{
}

void AudioSystem::receive(const EvPlaySound& playSound)
{
    m_audioManager.playSound(playSound.id);
}

void AudioSystem::receive(const EvMusicVolume &musicVolume)
{
        m_audioManager.setMusicVolume(musicVolume.vol);
}
