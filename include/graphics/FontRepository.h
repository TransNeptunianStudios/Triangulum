#ifndef FONTREPOSITORY_H
#define FONTREPOSITORY_H

#include "SFML/Graphics/Font.hpp"

class FontRepository
{
public:

   FontRepository();

   static void load();

   static const sf::Font& getMenuFont();

   static const sf::Font& getHudFont();

private:

   static sf::Font m_menuFont;

   static sf::Font m_hudFont;
};

#endif // FONTREPOSITORY_H
