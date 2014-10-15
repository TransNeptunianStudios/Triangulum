#include "graphics/FontRepository.h"

sf::Font FontRepository::m_menuFont;
sf::Font FontRepository::m_hudFont;

FontRepository::FontRepository()
{
}

void FontRepository::load()
{
   m_menuFont.loadFromFile("../resources/fonts/akashi.ttf");
   m_hudFont.loadFromFile("../resources/fonts/munro_small.ttf");
}

const sf::Font &FontRepository::getMenuFont()
{
   return m_menuFont;
}

const sf::Font &FontRepository::getHudFont()
{
   return m_hudFont;
}
