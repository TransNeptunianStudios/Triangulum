#include <iostream>
#include "graphics/GameOverMenuView.h"
#include "components/Position.h"
#include "systems/Events.h"
#include "KeyHandler.h"

using namespace entityx;

GameOverMenuView::GameOverMenuView()
: m_texture()
, m_halfLogoWidth(0.0)
, m_halfLogoHeight(0.0)
{
   m_texture.load("../images/game_over.png");

   m_halfLogoWidth = m_texture.width()/2.0;

   m_halfLogoHeight = m_texture.height()/2.0;
}

void GameOverMenuView::update(const KeyHandler &keyHandler,
                              EventManager &eventManager)
{
   if (keyHandler.isPressed(SDLK_SPACE))
   {
      eventManager.emit<EvStartGame>();
   }
}

void GameOverMenuView::draw()
{
   glBindTexture(GL_TEXTURE_2D, m_texture.glTexture());

   glEnable(GL_TEXTURE_2D);

   glBegin(GL_QUADS);

   glColor3f(1.0f, 1.0f, 1.0f);

   glTexCoord2f(0.0f, 1.0f);
   glVertex3f(-m_halfLogoWidth, m_halfLogoHeight, 0.0f);
   glTexCoord2f(1.0f, 1.0f);
   glVertex3f(m_halfLogoWidth, m_halfLogoHeight, 0.0f);
   glTexCoord2f(1.0f, 0.0f);
   glVertex3f(m_halfLogoWidth, -m_halfLogoHeight, 0.0f);
   glTexCoord2f(0.0f, 0.0f);
   glVertex3f(-m_halfLogoWidth, -m_halfLogoHeight, 0.0f);

   glEnd();

   glDisable(GL_TEXTURE_2D);
}


void GameOverMenuView::onConfirm(entityx::EventManager& eventManager){
    eventManager.emit<EvStartGame>();
}
