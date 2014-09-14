#include "systems/AudioSystem.h"
#include "AudioManager.h"

using namespace entityx;

AudioSystem::AudioSystem(AudioManager* pAudioManager)
: m_pAudioManager(pAudioManager)
{
}

void AudioSystem::configure(EventManager& eventManager)
{
   eventManager.subscribe<PlaySound>(*this);
}

void AudioSystem::update(EntityManager& entities,
                         EventManager& events,
                         double dt)
{
}

void AudioSystem::receive(const PlaySound& playSound)
{
   m_pAudioManager->playSound(playSound.id);
}
