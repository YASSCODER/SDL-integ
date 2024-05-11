
/**
* @file main.c
* @brief game 2d .
* @author Mallek
* @version 0.1
* @date Sept 04, 2023
*
* GAME 2d 
*
*/
#include "background.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "player.h"
#include "minimap.h"

int main()
{
    int quit=1;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO); 
    SDL_Event e; 
    SDL_Surface *screen, *perso; 
    screen = SDL_SetVideoMode(1500, 500, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); 


    Personne hero;
    init_Perso(&hero);

    Background B; 
    initBackground(&B); 
    ScoreInfo player;
    

    minimap map;

    init_map(&map);


    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024); // Initialize audio mixer
    B.music=Mix_LoadMUS("son.mp3");
    Mix_PlayMusic(B.music,-1);



    while (quit==1)
    {
        

        affBackground(&B, screen);
        animerBack(&B);
        
        afficherminimap(map,screen);
        afficherPerso(hero,screen);
        
        SDL_Flip(screen);


         if(SDL_PollEvent(&e))
        {
            switch(e.type)
            {
                case SDL_QUIT :
                    quit=0;
                break;
                case SDL_KEYDOWN :
                    switch(e.key.keysym.sym)
                    {
                        case SDLK_ESCAPE :
                            quit=0;
                        break;
                        case SDLK_SPACE:
                            hero.jump = 1;         
                        break;
                        case SDLK_RIGHT:
                            hero.right = 1;
                            hero.direction=1;   
                         break;

                        case SDLK_LEFT:
                          hero.left = 1;
                          hero.direction=-1;
                          
                         break;
                        case SDLK_x:
                        B.score++;
                        break;
                        case SDLK_m:
                        B.vie-=10;
                        break;
                        
                    }
                break;
                case SDL_KEYUP:
                    switch (e.key.keysym.sym)
                    {
                        case SDLK_RIGHT:
                            hero.right = 0;
                            hero.last_direction=1;



                            break;

                        case SDLK_LEFT:
                            hero.left = 0;
                            hero.last_direction=-1;
                            

                            break;
                        
                }
                break;
            }

           
            
        }

    if(hero.direction_y!=0)
    {
        
        if(185 + hero.direction_y >=0)
        B.camera.y=  185 + (hero.direction_y/2)  ;
            
        }

 
        if(hero.right == 0 && hero.left == 0)
        {
            hero.direction=0;
        }
        if(hero.direction ==0)
        {
        Animation_simple(&hero);           
        }


        else if((hero.direction ==1 || hero.direction ==-1)&& hero.jump==0 )
        {
        runAnimation(&hero);
        }
        else if((hero.direction ==1 || hero.direction ==-1)&& hero.jump==1 )
        {
            jumpAnimation(&hero);
        }
      


        if( hero.heroPos.x<1250 && hero.direction==1)
        movePerso(&hero);
        if(hero.heroPos.x>10 && hero.direction==-1)
        movePerso(&hero);
        
        
        scrolling(&B, hero.direction, hero.xStep);

        
        jumpHeroMvt(&hero);

        
        


        map.pos_joueur=hero.heroPos;
        map.camera=B.camera;
        MAJMinimap(&map);
        hero.frame++;
        
    }
    SDL_FreeSurface(screen); 
    freeBackground(&B);
    return 0;
}
