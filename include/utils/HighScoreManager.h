#ifndef HIGHSCOREMANAGER_H
#define HIGHSCOREMANAGER_H

struct HighScore
{
   std::string name;
   int score;
   std::string version;
};

typedef std::vector<HighScore> HighScoreList;

class HighScoreManager
{
public:

   HighScoreManager();

   bool downloadHighScoreList();

   bool uploadHighScore();

   bool isHighScore(int score) const;

   int insertHighScore(const std::string& playerName, int score);

   const HighScoreList getHighScoreList() const;

private:

   HighScoreList m_highScoreList;

   std::string m_playerName;

   int m_score;
};

#endif // HIGHSCOREMANAGER_H
