#ifndef LEVELLOADER_H
#define LEVELLOADER_H

#include "SFML/System/Vector2.hpp"

struct EnemyData
{
   std::string type;
   std::string ai;
   std::string gun;
   double levelOffset;
   double startXPos;
};

struct ObstacleData
{
  std::string type;
  double levelOffset;
  double startXPos;
  double rotation;
  sf::Vector2f speed;
};

struct BossData
{
   std::string type;
};

struct BackgroundData
{
   std::string fileName;
   double scrollSpeed;
};

struct LevelData
{
   BackgroundData background;
   double scrollSpeed;
   BossData boss;
   std::vector<ObstacleData> obstacles;
   std::vector<EnemyData> enemies;
};

class LevelLoader
{
public:

   LevelLoader();

   static bool load(int nr, LevelData& level);
};

#endif // LEVELLOADER_H
