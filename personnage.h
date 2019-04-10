#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct {
	SDL_Surface *personnage;
	SDL_Surface *jump;
	SDL_Surface *droite[4];
	SDL_Surface *gauche[4];
	SDL_Rect position_personnage;
	}personnage;



typedef struct {
	SDL_Surface *image;
	SDL_Rect position_image;
	}image;

typedef struct {
	SDL_Surface *image_background;
	SDL_Rect positionbackground;
	}background;

void initialiser_personnage(personnage *perso);
void affichage_personnage(SDL_Surface *screen,personnage *perso);
void initialiser_background_level(background *level);
void affichage_background_level(SDL_Surface *screen,background *level);
void initialiser_background_gameover(background *gameover);
void affichage_background_gameover(SDL_Surface *screen,background *gameover);
void initialiser_pause(image *pause);
void affichage_pause(SDL_Surface *screen,image *pause);
void initialiser_fire(image *fire);
void affichage_fire(SDL_Surface *screen,image *fire);

void deplacer_personnage_droite (SDL_Surface *screen,personnage *perso, background *level, image *fire, int *i);
void deplacer_personnage_gauche (SDL_Surface *screen,personnage *perso, background *level, image *fire, int *i);
void deplacer_personnage_haut (SDL_Surface *screen,personnage *perso, background *level, image *fire);

#endif
