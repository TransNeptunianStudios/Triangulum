#include <iostream>
#include <sstream>
#include "SFML/Network.hpp"
#include "yaml-cpp/yaml.h"
#include "utils/HighScoreManager.h"
#include "Release.h"

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

HighScoreManager::HighScoreManager()
: m_highScoreList()
, m_playerName("")
, m_score(-1)
{
}

bool HighScoreManager::downloadHighScoreList()
{
   m_playerName = "";
   m_score = -1;

   m_highScoreList.clear();

   HighScoreListWrapper highScoreList;

   sf::Http::Request req("/highscore.php", sf::Http::Request::Post);

   std::ostringstream oss;
   oss << "action=get_score";
   req.setBody(oss.str());

   sf::Http http("trans-neptunian-studios.com");
   sf::Http::Response resp = http.sendRequest(req, sf::seconds(10.0));

   // check the status
   if (resp.getStatus() == sf::Http::Response::Ok)
   {
      std::string recvString(resp.getBody());

      std::istringstream iss(recvString);

      YAML::Parser parser(iss);

      YAML::Node doc;

      parser.GetNextDocument(doc);

      doc >> highScoreList;

      m_highScoreList = highScoreList.highScores;

      return true;
   }
   else
   {
      return false;
   }
}

bool HighScoreManager::uploadHighScore()
{
   if (IS_IN_BETA)
   {
      // We don't want to upload score while in beta!
      return true;
   }
   
   if (m_playerName == "" || m_score == -1)
   {
      return false;
   }

   sf::Http::Request req("/highscore.php", sf::Http::Request::Post);

   std::ostringstream oss;
   oss << "action=post_score&name=" << m_playerName << "&score=" << m_score;
   req.setBody(oss.str());

   sf::Http http("trans-neptunian-studios.com");
   sf::Http::Response resp = http.sendRequest(req, sf::seconds(10.0));

   // check the status
   if (resp.getStatus() == sf::Http::Response::Ok)
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool HighScoreManager::isHighScore(int score) const
{
   if (score == 0)
   {
      return false;
   }

   if (m_highScoreList.size() < 10)
   {
      return true;
   }

   for (const auto& highScore : m_highScoreList)
   {
      if (score > highScore.score)
      {
         return true;
      }
   }

   return false;
}

int HighScoreManager::insertHighScore(const std::string& playerName, int score)
{
   HighScore h;
   h.name = playerName;
   h.score = score;

   int insertedAtIndex = -1;

   for (size_t i = 0; i < m_highScoreList.size(); ++i)
   {
      if (h.score > m_highScoreList[i].score)
      {
         m_highScoreList.insert(begin(m_highScoreList) + i, h);

         if (m_highScoreList.size() > 10)
         {
            m_highScoreList.pop_back();
         }

         insertedAtIndex = i;

         break;
      }
   }

   if (insertedAtIndex == -1 && m_highScoreList.size() < 10)
   {
      m_highScoreList.push_back(h);
      insertedAtIndex = m_highScoreList.size()-1;
   }


   if (insertedAtIndex != -1)
   {
      m_playerName = playerName;
      m_score = score;
   }

   return insertedAtIndex;
}

const HighScoreList HighScoreManager::getHighScoreList() const
{
   return m_highScoreList;
}
