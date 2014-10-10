#include "graphics/GameCompMenuView.h"

using namespace entityx;

GameCompMenuView::GameCompMenuView()
: m_texture()
, m_halfLogoWidth(0.0)
, m_halfLogoHeight(0.0)
{
   m_texture.load("../images/game_complete.png");

   m_halfLogoWidth = m_texture.width()/2.0;

   m_halfLogoHeight = m_texture.height()/2.0;
}

void GameCompMenuView::update(const KeyHandler &keyHandler,
                              EventManager &eventManager)
{
}

void GameCompMenuView::draw()
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


void GameCompMenuView::onConfirm(EventManager& eventManager)
{
}

void GameCompMenuView::onCancel(EventManager& eventManager)
{
}
