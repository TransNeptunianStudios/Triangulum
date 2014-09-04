#include <stdio.h>
#include <cstdlib>

#include <SDL2/SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char* args[])
{
	//Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO ) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		std::exit(EXIT_FAILURE);
	}


	SDL_Window* window = SDL_CreateWindow("Space-Shooter",
						      			  SDL_WINDOWPOS_UNDEFINED,
						      			  SDL_WINDOWPOS_UNDEFINED,
						      			  SCREEN_WIDTH,
						      			  SCREEN_HEIGHT,
						      			  SDL_WINDOW_SHOWN);

	if(window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		bool quit = false;

		SDL_Event event;

		//The surface contained by the window
		SDL_Surface* screenSurface = SDL_GetWindowSurface( window );

	    while(!quit)
	    {
			/* Poll for events */
			while(SDL_PollEvent(&event))
			{
			    
			    switch(event.type)
			    {
			        /* Keyboard event */
			        /* Pass the event data onto PrintKeyInfo() */
			        case SDL_KEYDOWN:
			        	if (event.key.keysym.sym == SDLK_ESCAPE)
			        	{
			        		quit = true;
			        	}
			            break;
			        /* SDL_QUIT event (window close) */
			        case SDL_QUIT:
			            quit = true;
			            break;
			        default:
			            break;
			    }
			}


			//Fill the surface white
			SDL_FillRect(screenSurface,
						 NULL,
						 SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));
			
			//Update the surface
			SDL_UpdateWindowSurface(window);

			SDL_Delay(50);
		}
	}

	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}