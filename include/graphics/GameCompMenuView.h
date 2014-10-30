#ifndef GAMECOMPMENUVIEW_H
#define GAMECOMPMENUVIEW_H

#include <future>
#include <vector>
#include "SFML/Graphics/Text.hpp"
#include "components/AbstractMenu.h"
#include "graphics/ScoreView.h"

struct HighScore
{
   std::string name;
   int score;
};

typedef std::vector<HighScore> HighScoreList;

class GameCompMenuView
      : public AbstractMenu
{
public:

   GameCompMenuView(int score);

   void update(entityx::EventManager& events, double dt);

   void draw(sf::RenderWindow& window);

   void onConfirm(entityx::EventManager& eventManager);

   void onKey(sf::Keyboard::Key key);

private:

   void updateText(sf::Text& text, const std::string& string);

   bool checkHighScore();

   void insertNewScore();

   void updateHighScoreTextList();

   std::string convertKey(sf::Keyboard::Key key);

   enum GameCompState
   {
      GCS_FetchingHighScore,
      GCS_W4HighScore,
      GCS_FetchingFailed,
      GCS_W4ConfirmNoHighScore,
      GCS_W4PlayerNameInput,
      GCS_ShowHighScore,
   };

   int m_score;

   sf::Text m_titleText;

   sf::Text m_statusText;

   sf::Text m_scoreText;

   sf::Text m_playNameText;

   ScoreView m_scoreView;

   GameCompState m_state;

   typedef std::pair<sf::Text, sf::Text> NameScoreText;

   std::vector<NameScoreText> m_highScoreTextList;

   std::future<HighScoreList> m_highScoreListFuture;

   std::future<void> m_sendHighScoreFuture;

   HighScoreList m_highScoreList;

   int m_insertedAtIndex;
};

#endif // GAMECOMPMENUVIEW_H
