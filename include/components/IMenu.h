#ifndef IMENU_H
#define IMENU_H

#include "entityx/Event.h"

class KeyHandler;

class IMenu
{
public:

   virtual ~IMenu() {}

   virtual void update(const KeyHandler& keyHandler,
                       entityx::EventManager& eventManager) = 0;
};

typedef std::shared_ptr<IMenu> IMenuSP;

#endif // IMENU_H
