#include "AnimationFactory.h"

AnimationFactory::AnimationFactory()
{
}

Animator AnimationFactory::spaceShipDeathAnimation()
{
   Animator animation;
   animation.coordList.push_back(sf::IntRect(32*0, 32*2, 32, 32));
   animation.coordList.push_back(sf::IntRect(32*1, 32*2, 32, 32));
   animation.coordList.push_back(sf::IntRect(32*2, 32*2, 32, 32));
   animation.coordList.push_back(sf::IntRect(32*3, 32*2, 32, 32));
   animation.coordList.push_back(sf::IntRect(32*4, 32*2, 32, 32));
   animation.coordList.push_back(sf::IntRect(0, 0, 0, 0));
   animation.style = AS_RUN_ONCE;
   animation.timePerFrame = 1000.0/6.0;
   return animation;
}

Animator AnimationFactory::spaceShipIdleAnimation()
{
   Animator animation;
   animation.coordList.push_back(sf::IntRect(32*0, 32*0, 32, 32));
   animation.coordList.push_back(sf::IntRect(32*1, 32*0, 32, 32));
   animation.style = AS_LOOP;
   animation.timePerFrame = 200.0/2.0;
   return animation;
}

Animator AnimationFactory::spaceShipTurnLeftAnimation()
{
   Animator animation;
   animation.coordList.push_back(sf::IntRect(32*0, 32*3, 32, 32));
   animation.coordList.push_back(sf::IntRect(32*1, 32*3, 32, 32));
   animation.coordList.push_back(sf::IntRect(32*2, 32*3, 32, 32));
   animation.style = AS_RUN_ONCE;
   animation.timePerFrame = 1000.0/3.0;
   return animation;
}

Animator AnimationFactory::spaceShipTurnRightAnimation()
{
   Animator animation;
   animation.coordList.push_back(sf::IntRect(32*0, 32*4, 32, 32));
   animation.coordList.push_back(sf::IntRect(32*1, 32*4, 32, 32));
   animation.coordList.push_back(sf::IntRect(32*2, 32*4, 32, 32));
   animation.style = AS_RUN_ONCE;
   animation.timePerFrame = 1000.0/3.0;
   return animation;
}

Animator AnimationFactory::asteroidDeathAnimation()
{
    Animator animation;
    animation.coordList.push_back(sf::IntRect(32*1, 32*1, 32, 32));
    animation.coordList.push_back(sf::IntRect(32*2, 32*1, 32, 32));
    animation.coordList.push_back(sf::IntRect(32*3, 32*1, 32, 32));
    animation.style = AS_RUN_ONCE;
    animation.timePerFrame = 500.0/3.0;
    return animation;
}

Animator AnimationFactory::asteroidBossDeathAnimation()
{
    Animator animation;
    animation.coordList.push_back(sf::IntRect(32*7, 32*3, 96, 96));
    animation.coordList.push_back(sf::IntRect(32*7, 32*6, 96, 96));
    animation.coordList.push_back(sf::IntRect(32*10, 32*0, 96, 96));
    animation.coordList.push_back(sf::IntRect(32*10, 32*3, 96, 96));
    animation.coordList.push_back(sf::IntRect(32*10, 32*6, 96, 96));
    animation.coordList.push_back(sf::IntRect(0, 0, 0, 0));
    animation.style = AS_RUN_ONCE;
    animation.timePerFrame = 1500.0/5.0;
    return animation;
}

Animator AnimationFactory::enemyOneIdleAnimation()
{
    Animator animation;
    animation.coordList.push_back(sf::IntRect(32*0, 32*6, 32, 32));
    animation.coordList.push_back(sf::IntRect(32*1, 32*6, 32, 32));
    animation.style = AS_LOOP;
    animation.timePerFrame = 200.0/2.0;
    return animation;
}

Animator AnimationFactory::enemyOneDeathAnimation()
{
    Animator animation;
    animation.coordList.push_back(sf::IntRect(32*2, 32*6, 32, 32));
    animation.coordList.push_back(sf::IntRect(32*3, 32*6, 32, 32));
    animation.coordList.push_back(sf::IntRect(32*4, 32*6, 32, 32));
    animation.coordList.push_back(sf::IntRect(32*5, 32*6, 32, 32));
    animation.style = AS_RUN_ONCE;
    animation.timePerFrame = 200.0/2.0;
    return animation;
}
