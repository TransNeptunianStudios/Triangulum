#include "systems/AudioSystem.h"
#include "AudioManager.h"

using namespace entityx;

AudioSystem::AudioSystem(AudioManager &audioManager)
: m_audioManager(audioManager)
{
}

void AudioSystem::configure(EventManager& eventManager)
{
   eventManager.subscribe<EvPlaySound>(*this);
   eventManager.subscribe<EvPlayMusic>(*this);
   eventManager.subscribe<EvPauseMusic>(*this);
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

void AudioSystem::receive(const EvPlayMusic &playMusic)
{
    m_audioManager.playMusic();
}

void AudioSystem::receive(const EvPauseMusic &pauseMusic)
{
    m_audioManager.pauseMusic();
}
