#include <iostream>
#include <sstream>
#include "SFML/Network.hpp"
#include "yaml-cpp/yaml.h"
#include "graphics/GameCompMenuView.h"
#include "graphics/FontRepository.h"
#include "ScreenSize.h"

using namespace entityx;

struct HighScoreListWrapper
{
   HighScoreList highScores;
};

void operator >> (const YAML::Node& highsScoreNode, HighScore& highScore)
{
   highsScoreNode["name"] >> highScore.name;
   highsScoreNode["score"] >> highScore.score;
}

void operator >> (const YAML::Node& highScoreListNode, HighScoreListWrapper& hList)
{
   for (unsigned i = 0; i < highScoreListNode.size(); ++i)
   {
      HighScore highScore;
      highScoreListNode[i] >> highScore;
      hList.highScores.push_back(highScore);
   }
}

HighScoreList fetchHighScoreList()
{
   HighScoreListWrapper highScoreList;

   sf::Http::Request req("/highscore.php", sf::Http::Request::Post);

   std::ostringstream oss;
   oss << "action=get_score";
   req.setBody(oss.str());

   sf::Http http("trans-neptunian-studios.com");
   sf::Http::Response resp = http.sendRequest(req);

   // check the status
   if (resp.getStatus() == sf::Http::Response::Ok)
   {
      std::string recvString(resp.getBody());

      std::istringstream iss(recvString);

      YAML::Parser parser(iss);

      YAML::Node doc;

      parser.GetNextDocument(doc);

      doc >> highScoreList;
   }

   return highScoreList.highScores;
}

void sendHighScore(const std::string& playerName, int score)
{
   sf::Http::Request req("/highscore.php", sf::Http::Request::Post);

   std::ostringstream oss;
   oss << "action=post_score&name=" << playerName << "&score=" << score;
   req.setBody(oss.str());

   sf::Http http("trans-neptunian-studios.com");
   sf::Http::Response resp = http.sendRequest(req);

   // check the status
   if (resp.getStatus() == sf::Http::Response::Ok)
   {
      // check the contents of the response
      std::cout << resp.getBody() << std::endl;
   }
   else
   {
      std::cout << "request failed" << std::endl;
   }
}

GameCompMenuView::GameCompMenuView(int score)
: m_score(score)
, m_titleText()
, m_statusText()
, m_scoreText()
, m_playNameText()
, m_highScoreTextList()
, m_scoreView(FontRepository::getMenuFont(), 30)
, m_state(GCS_FetchingHighScore)
, m_highScoreListFuture()
, m_sendHighScoreFuture()
, m_highScoreList()
, m_insertedAtIndex(-1)
{
   m_titleText.setFont(FontRepository::getMenuFont());
   m_titleText.setCharacterSize(40);
   updateText(m_titleText, "Game Completed");

   m_statusText.setFont(FontRepository::getMenuFont());
   m_statusText.setCharacterSize(30);

   m_scoreText.setFont(FontRepository::getMenuFont());
   m_scoreText.setCharacterSize(30);
   updateText(m_scoreText, "Score:");

   m_playNameText.setFont(FontRepository::getMenuFont());
   m_playNameText.setCharacterSize(30);

   m_scoreView.setAlign(1);
}

void GameCompMenuView::update(EventManager &events, double dt)
{
   switch (m_state) {
   case GCS_FetchingHighScore:
      updateText(m_statusText, "Fetching high score...");
      m_insertedAtIndex = -1;
      m_highScoreList.clear();
      m_highScoreListFuture = std::async(fetchHighScoreList);
      m_state = GCS_W4HighScore;
      break;
   case GCS_W4HighScore:
      if (m_highScoreListFuture.valid())
      {
         m_highScoreList = m_highScoreListFuture.get();
         if (!m_highScoreList.empty())
         {
            if (checkHighScore())
            {
               m_state = GCS_W4PlayerNameInput;
               updateText(m_statusText, "Enter name:");
            }
            else
            {
               m_state = GCS_W4ConfirmNoHighScore;
               updateText(m_statusText, "No new high score");
            }
         }
         else
         {
            updateText(m_statusText, "Unable to get high score");
            m_state = GCS_FetchingFailed;
         }
      }
      break;
   case GCS_FetchingFailed:
      break;
   case GCS_W4PlayerNameInput:
      break;
   default:
      break;
   }
}

void GameCompMenuView::draw(sf::RenderWindow& window)
{
   switch (m_state)
   {
   case GCS_FetchingHighScore:
   case GCS_W4HighScore:
   case GCS_W4ConfirmNoHighScore:
   case GCS_FetchingFailed:
      m_titleText.setPosition(ScreenSize::width()*0.5,
                              ScreenSize::height()*0.33);

      m_statusText.setPosition(ScreenSize::width()*0.5,
                               ScreenSize::height()*0.5);

      window.draw(m_titleText);

      window.draw(m_statusText);

      break;
   case GCS_W4PlayerNameInput:
      m_titleText.setPosition(ScreenSize::width()*0.5,
                              ScreenSize::height()*0.33);

      m_statusText.setPosition(ScreenSize::width()*0.5,
                               ScreenSize::height()*0.5);

      m_playNameText.setPosition(ScreenSize::width()*0.5,
                                 ScreenSize::height()*0.5 + 50);

      window.draw(m_titleText);

      window.draw(m_statusText);

      window.draw(m_playNameText);

      break;
   case GCS_ShowHighScore:
   {

      m_titleText.setPosition(ScreenSize::width()*0.5,
                              ScreenSize::height()*0.1);

      window.draw(m_titleText);

      float offset = 0.0;
      for (size_t i = 0; i < m_highScoreTextList.size(); ++i)
      {
         m_highScoreTextList[i].first.setPosition(ScreenSize::width()*0.35,
                                                  ScreenSize::height()*0.2+offset);

         m_highScoreTextList[i].second.setPosition(ScreenSize::width()*0.65,
                                                   ScreenSize::height()*0.2+offset);

         if (m_insertedAtIndex == i)
         {
            m_highScoreTextList[i].first.setColor(sf::Color(7, 127, 31));
            m_highScoreTextList[i].second.setColor(sf::Color(7, 127, 31));
         }

         window.draw(m_highScoreTextList[i].first);
         window.draw(m_highScoreTextList[i].second);

         offset += 30.0;
      }
      break;
   }
   default:
      break;
   }
}

void GameCompMenuView::onConfirm(EventManager& eventManager)
{
   if (m_state == GCS_W4PlayerNameInput)
   {
      insertNewScore();

      // send highscore to server
      m_sendHighScoreFuture = std::async(sendHighScore, m_playNameText.getString(), m_score);

      updateText(m_titleText, "High score");

      updateHighScoreTextList();

      m_state = GCS_ShowHighScore;
   }
   else if (m_state == GCS_W4ConfirmNoHighScore)
   {
      updateText(m_titleText, "High score");

      updateHighScoreTextList();

      m_state = GCS_ShowHighScore;
   }
   else if (m_state == GCS_ShowHighScore)
   {
      if (m_sendHighScoreFuture.valid())
      {
         m_sendHighScoreFuture.get();
         // Restart game!?
      }
   }
}

void GameCompMenuView::onKey(sf::Keyboard::Key key)
{
   if (m_state == GCS_W4PlayerNameInput)
   {
      sf::String playerName(m_playNameText.getString());
      if (key >= sf::Keyboard::A && key <= sf::Keyboard::Z)
      {
         if (playerName.getSize() < 8)
         {
           playerName += convertKey(key);
         }
      }
      else if (key == sf::Keyboard::BackSpace)
      {
         if (playerName.getSize() > 0)
         {
            playerName.erase(playerName.getSize()-1);
         }
      }
      updateText(m_playNameText, playerName);
   }
}

void GameCompMenuView::updateText(sf::Text& text, const std::string& string)
{
   text.setString(string);

   sf::FloatRect bounds(text.getLocalBounds());
   text.setOrigin(bounds.width/2.0, bounds.height/2.0);
}

bool GameCompMenuView::checkHighScore()
{
   if (m_highScoreList.size() < 10)
   {
      return true;
   }

   for (auto& highScore : m_highScoreList)
   {
      if (m_score > highScore.score)
      {
         return true;
      }
   }

   return false;
}

void GameCompMenuView::insertNewScore()
{
   HighScore h;
   h.name = m_playNameText.getString();
   h.score = m_score;

   for (size_t i = 0; i < m_highScoreList.size(); ++i)
   {
      if (h.score > m_highScoreList[i].score)
      {
         m_highScoreList.insert(begin(m_highScoreList) + i, h);

         m_insertedAtIndex = i;

         if (m_highScoreList.size() > 10)
         {
            m_highScoreList.pop_back();
         }

         return;
      }
   }

   if (m_highScoreList.size() < 10)
   {
      m_insertedAtIndex = m_highScoreList.size();
      m_highScoreList.push_back(h);
   }
}

void GameCompMenuView::updateHighScoreTextList()
{
   m_highScoreTextList.clear();

   for (auto& highScore : m_highScoreList)
   {
      std::stringstream ss;

      ss << highScore.score;

      m_highScoreTextList.push_back(NameScoreText(sf::Text(highScore.name, FontRepository::getMenuFont(), 20),
                                                  sf::Text(ss.str(), FontRepository::getMenuFont(), 20)));
   }
}

std::string GameCompMenuView::convertKey(sf::Keyboard::Key key)
{
   std::string str;
   switch (key)
   {
   case sf::Keyboard::A: return "A";
   case sf::Keyboard::B: return "B";
   case sf::Keyboard::C: return "C";
   case sf::Keyboard::D: return "D";
   case sf::Keyboard::E: return "E";
   case sf::Keyboard::F: return "F";
   case sf::Keyboard::G: return "G";
   case sf::Keyboard::H: return "H";
   case sf::Keyboard::I: return "I";
   case sf::Keyboard::J: return "J";
   case sf::Keyboard::K: return "K";
   case sf::Keyboard::L: return "L";
   case sf::Keyboard::M: return "M";
   case sf::Keyboard::N: return "N";
   case sf::Keyboard::O: return "O";
   case sf::Keyboard::P: return "P";
   case sf::Keyboard::Q: return "Q";
   case sf::Keyboard::R: return "R";
   case sf::Keyboard::S: return "S";
   case sf::Keyboard::T: return "T";
   case sf::Keyboard::U: return "U";
   case sf::Keyboard::V: return "V";
   case sf::Keyboard::W: return "W";
   case sf::Keyboard::X: return "X";
   case sf::Keyboard::Y: return "Y";
   case sf::Keyboard::Z: return "Z";
   defualt:
      break;
   }

   return "";
}
