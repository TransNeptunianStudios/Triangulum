#include "Game.h"

int main(int argc, char* args[])
{
   Game game;
   game.init();
   game.run();
   
/*   sf::TcpSocket socket;

   sf::Socket::Status status = socket.connect(sf::IpAddress("81.169.187.71"), 9895);

   if (status != sf::Socket::Done)
   {
      std::cout << "Couldn't connect!" << std::endl;
   }

   std::string msg("{ \"action\": \"get\" }");
   socket.send(msg.c_str(), msg.size());

   char recvBuffer[1024];
   std::size_t bytesReceived = 0;
   socket.receive(recvBuffer, sizeof(recvBuffer), bytesReceived);

   std::cout << "Highscore list: " << std::endl;
   std::cout << recvBuffer << std::endl;

   std::string recvString(recvBuffer);

   std::istringstream iss(recvString);

   YAML::Parser parser(iss);

   YAML::Node doc;

   parser.GetNextDocument(doc);

   HighscoreList hList;

   doc >> hList;

   sf::sleep(sf::seconds(2.0));

   msg = "{ \"action\": \"add\", \"name\": \"Erik\", \"score\": 9 }";
   socket.send(msg.c_str(), msg.size());

   sf::sleep(sf::seconds(2.0));

   socket.disconnect();
   
   
   sf::Http::Request req("/test.php", sf::Http::Request::Post);
   
   std::ostringstream oss;
   oss << "name=micke&score=321";
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
   }*/
   
	return 0;
}
