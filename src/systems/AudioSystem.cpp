#include "systems/AudioSystem.h"
#include "AudioManager.h"

using namespace entityx;

AudioSystem::AudioSystem(AudioManager &audioManager)
: m_audioManager(audioManager)
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
   m_audioManager.playSound(playSound.id);
}
