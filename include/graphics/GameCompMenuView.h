#ifndef GAMECOMPMENUVIEW_H
#define GAMECOMPMENUVIEW_H

#include "SFML/Graphics/Text.hpp"
#include "components/AbstractMenu.h"
#include "graphics/ScoreView.h"
#include "utils/HighScoreManager.h"

class GameCompMenuView
      : public AbstractMenu
{
public:

   GameCompMenuView(const std::string& menuTitle, int score);

   void update(entityx::EventManager& events, double dt);

   void draw(sf::RenderWindow& window);

   void onConfirm(entityx::EventManager& eventManager);

   void onKey(sf::Keyboard::Key key);

   void onCancel(entityx::EventManager &eventManager);
private:

   void updateText(sf::Text& text, const std::string& string);

   void updateHighScoreTextList();

   std::string convertKey(sf::Keyboard::Key key);

   enum GameCompState
   {
      GCS_Init,
      GCS_FetchingHighScore,
      GCS_FetchingFailed,
      GCS_W4ConfirmNoHighScore,
      GCS_W4PlayerNameInput,
      GCS_ShowHighScore,
   };

   int m_score;

   sf::Text m_titleText;

   sf::Text m_statusText;

   sf::Text m_infoText;

   sf::Text m_scoreText;

   sf::Text m_playNameText;

   ScoreView m_scoreView;

   GameCompState m_state;

   typedef std::pair<sf::Text, sf::Text> NameScoreText;

   std::vector<NameScoreText> m_highScoreTextList;

   HighScoreManager m_highScoreManager;

   int m_insertedAtIndex;
};

#endif // GAMECOMPMENUVIEW_H
