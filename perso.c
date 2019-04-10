#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "personnage.h"

int main()
{
SDL_Surface *screen = NULL;
int done=1;
personnage perso;
background level;
background gameover;
image pause;
SDL_Event event;

initialiser_personnage(&perso);
initialiser_background_level(&level);
initialiser_pause(&pause);
initialiser_background_gameover(&gameover);

SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(640,360,0,SDL_HWSURFACE);

affichage_background_level(screen,&level);
				affichage_personnage(screen,&perso);
				SDL_Flip(screen);
	
while (done) 
	{
	

	SDL_PollEvent(&event);
	switch(event.type) {
			case SDL_QUIT: done=0;
				break;
			case SDL_KEYDOWN: {
				if(event.key.keysym.sym == SDLK_ESCAPE){
				affichage_background_level(screen,&level);
				affichage_personnage(screen,&perso);
				affichage_pause(screen,&pause);
				SDL_Flip(screen);
				SDL_Delay(5000);} 
				if(event.key.keysym.sym == SDLK_RIGHT){
				deplacer_personnage_droite (screen, &perso,&level);
				}
				if(event.key.keysym.sym == SDLK_LEFT){
				deplacer_personnage_gauche (screen,&perso,&level);
				}
				if(event.key.keysym.sym == SDLK_SPACE){
				deplacer_personnage_haut (screen, &perso,&level);
				}
				break;
			}
			case SDL_MOUSEBUTTONDOWN : {
				if (event.button.button ==  SDL_BUTTON_RIGHT)
				deplacer_personnage_droite (screen,&perso,&level);
				if (event.button.button ==  SDL_BUTTON_LEFT)
				deplacer_personnage_gauche (screen,&perso,&level);
			}
			default: {
				affichage_background_level(screen,&level);
				affichage_personnage(screen,&perso);
				SDL_Flip(screen);
			}
			}
	}
SDL_FreeSurface(perso.personnage);
SDL_FreeSurface(level.image_background);
return 0;
}
