#include "components/DeathSentence.h"

DeathSentence::DeathSentence()
: timeToExecution(0.0)
, haveBeenPrepared(false)
{
}

DeathSentence::DeathSentence(double _timeToExecution)
: timeToExecution(_timeToExecution)
, haveBeenPrepared(false)
{
}
