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
    if(!m_musicMute)
        m_audioManager.playMusic();
}

void AudioSystem::receive(const EvPauseMusic &pauseMusic)
{
    m_musicMute = !m_musicMute;

    if(m_musicMute)
        m_audioManager.pauseMusic();
    else
        m_audioManager.playMusic();
}
