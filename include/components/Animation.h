#ifndef ANIMATION_H
#define ANIMATION_H

#include <map>
#include "SFML/Graphics/Rect.hpp"
#include "entityx/Entity.h"

enum AnimationStyle
{
   AS_RUN_ONCE,
   AS_LOOP
};

enum AnimationType
{
   AT_Death,
   AT_Movement
};


typedef std::vector<sf::IntRect> SpriteCoordList;

struct Animator
{
   Animator();

   //SpriteSheetId spriteSheetId

   double elapsedTime;

   double timePerFrame;

   AnimationStyle style;

   SpriteCoordList coordList;

   size_t currentIndex;
};

typedef uint8_t Animation;

typedef std::pair<AnimationType, Animation> AnimationId;

class AnimationContainer : public entityx::Component<AnimationContainer>
{
public:

   typedef std::map<AnimationId, Animator> AnimationMap;

   typedef std::pair<Animation, Animator> ActiveAnimator;

   typedef std::map<AnimationType, ActiveAnimator> ActiveAnimatorMap;

   AnimationContainer();

   void addAnimation(const AnimationId& id, const Animator& animator);

   void setAnimation(const AnimationId& id);

   void resetAnimation(AnimationType type);

   ActiveAnimatorMap& getAnimations();

private:

   AnimationMap m_registeredAnimations;

   ActiveAnimatorMap m_activeAnimations;
};

static const Animation NoAction = 0;

// Death animation id's
static const Animation DestroyedDeathAnimation = 1;

// Movement animation id's
static const Animation IdleMovementAnimation  = 1;
static const Animation LeftMovementAnimation  = 2;
static const Animation RightMovementAnimation = 3;

#endif // ANIMATION_H
