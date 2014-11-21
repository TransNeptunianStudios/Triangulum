#ifndef DEATHSENTENCE_H
#define DEATHSENTENCE_H

#include "entityx/Entity.h"

struct DeathSentence : public entityx::Component<DeathSentence>
{
   DeathSentence();

   DeathSentence(double _timeToExecution);

   double timeToExecution;
   bool haveBeenPrepared; // Death animations, guns removed, last meal ordered.
};

#endif // DEATHSENTENCE_H
