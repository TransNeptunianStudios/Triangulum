#ifndef DEATHSENTENCE_H
#define DEATHSENTENCE_H

#include "entityx/Entity.h"

struct DeathSentence : public entityx::Component<DeathSentence>
{
   DeathSentence();

   DeathSentence(double _timeToExecution);

   double timeToExecution;
};

#endif // DEATHSENTENCE_H
