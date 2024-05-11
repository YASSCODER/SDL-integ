/**

* @file minimap.c
*/
#include "minimap.h"

void init_map(minimap *m)
{
    m->map = IMG_Load("minimap.png");
    m->minijoueur = IMG_Load("perso1.png");
    m->positionmap.x = 0;
    m->positionmap.y = 0;
    m->positionminijoueur.x = 20;
    m->positionminijoueur.y = 113;
}

void MAJMinimap( minimap *m)
{
    SDL_Rect posJoueurABS;
  
    posJoueurABS.x = m->pos_joueur.x + m->camera.x;
    posJoueurABS.y = m->pos_joueur.y + m->camera.y;
    m->positionminijoueur.x = (posJoueurABS.x * 15 / 100) ;
    m->positionminijoueur.y = (posJoueurABS.y * 20 / 100) ;
}

void afficherminimap(minimap m, SDL_Surface *screen)
{
    SDL_BlitSurface(m.map, NULL, screen, &m.positionmap);
    SDL_BlitSurface(m.minijoueur, NULL, screen, &m.positionminijoueur);
}