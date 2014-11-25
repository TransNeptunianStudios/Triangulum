#ifndef LEVELLOADER_H
#define LEVELLOADER_H

#include "SFML/System/Vector2.hpp"

struct PickUpData
{
   std::string type;
   double levelOffset;
   double startXPos;
};

struct EnemyData
{
   std::string type;
   std::string ai;
   double levelOffset;
   double startXPos;
   sf::Vector2f speed;
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
   std::vector<PickUpData> pickUps;
};

class LevelLoader
{
public:

   LevelLoader();

   static bool load(int nr, LevelData& level);
};

#endif // LEVELLOADER_H
