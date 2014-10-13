#include <fstream>
#include <iostream>
#include "yaml-cpp/yaml.h"
#include "utils/LevelLoader.h"

void operator >> (const YAML::Node& vectorNode, sf::Vector2f& vec)
{
   vectorNode[0] >> vec.x;
   vectorNode[1] >> vec.y;
}

void operator >> (const YAML::Node& enemyNode, EnemyData& enemy)
{
   enemyNode["type"] >> enemy.type;
   enemyNode["ai"] >> enemy.ai;
   enemyNode["gun"] >> enemy.gun;
   enemyNode["level_offset"] >> enemy.levelOffset;
   enemyNode["start_x_pos"] >> enemy.startXPos;
}

void operator >> (const YAML::Node& obstacleNode, ObstacleData& obstacle)
{
   obstacleNode["type"] >> obstacle.type;
   obstacleNode["level_offset"] >> obstacle.levelOffset;
   obstacleNode["start_x_pos"] >> obstacle.startXPos;
   obstacleNode["rotation"] >> obstacle.rotation;
   obstacleNode["speed"] >> obstacle.speed;
}

void operator >> (const YAML::Node& backgroundNode, BackgroundData& background)
{
   backgroundNode["file"] >> background.fileName;
   backgroundNode["scroll_speed"] >> background.scrollSpeed;
}

void operator >> (const YAML::Node& levelNode, LevelData& level)
{
   levelNode["background"] >> level.background;

   levelNode["scroll_speed"] >> level.scrollSpeed;

   const YAML::Node& bossNode = levelNode["boss"];
   bossNode["type"] >> level.boss.type;

   const YAML::Node& obstaclesNode = levelNode["obstacles"];
   for (unsigned i = 0; i < obstaclesNode.size(); ++i)
   {
      ObstacleData obstacle;
      obstaclesNode[i] >> obstacle;
      level.obstacles.push_back(obstacle);
   }

   const YAML::Node& enemiesNode = levelNode["enemies"];
   for (unsigned i = 0; i < enemiesNode.size(); ++i)
   {
      EnemyData enemy;
      enemiesNode[i] >> enemy;
      level.enemies.push_back(enemy);
   }
}

LevelLoader::LevelLoader()
{
}

bool LevelLoader::load(int nr, LevelData& level)
{
   std::stringstream ss;
   ss << "../resources/levels/level";
   ss << nr;
   ss << ".yaml";

   try
   {
      std::ifstream fin(ss.str());
      YAML::Parser parser(fin);
      YAML::Node doc;
      parser.GetNextDocument(doc);
      doc >> level;
   }
   catch(YAML::ParserException& e)
   {
       std::cout << e.what() << "\n";
       return false;
   }

   return true;
}
