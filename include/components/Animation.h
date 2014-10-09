#ifndef ANIMATION_H
#define ANIMATION_H

#include <map>
#include "entityx/Entity.h"

struct SpriteSheetCoordinate
{
   SpriteSheetCoordinate()
   : x(0)
   , y(0)
   , optionalSize(0)
   {
   }

   SpriteSheetCoordinate(unsigned _x, unsigned _y, int _optionalSize = 0)
   : x(_x)
   , y(_y)
   , optionalSize(_optionalSize)
   {
   }

   unsigned x, y;

   int optionalSize;
};

typedef std::vector<SpriteSheetCoordinate> CoordinateList;

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

struct Animator
{
   Animator();

   //SpriteSheetId spriteSheetId

   double elapsedTime;

   double timePerFrame;

   AnimationStyle style;

   CoordinateList coordList;

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
