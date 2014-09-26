#ifndef MENU_H
#define MENU_H

#include "entityx/Entity.h"
#include "components/IMenu.h"

struct Menu : public entityx::Component<Menu>
{
   Menu(const IMenuSP& _spMenu);

   IMenuSP spMenu;
};

#endif // MENU_H
