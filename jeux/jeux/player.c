/**

* @file player.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>

#include "player.h"



/**
* @brief To initialize the player  .
* @param p the player
* @return Nothing
*/
void init_Perso(Personne *p)
{

    p->allMvt = IMG_Load("sprites/sprite.png");
    if(p->allMvt==NULL)
    {
        printf("CAN'T LOAD IMAGE");
    }

    p->frame = 0;
   
    
    p->heroPos.x = 100;
    p->heroPos.y = Ground;

    p->left = 0;
    p->right = 0;
    p->down = 0;
    p->jump = 0;
    

    p->herosprite.x=0;
    p->herosprite.y=38; 
    p->herosprite.w=133;
    p->herosprite.h=198;

    p->velocity = 0;
    p->speed = 0;

    p->xStep = 0;
    p->yStep = 0;
    p->direction =0;
    p->last_direction=1;
    p->col=0;
    p->VarX=0;


}
/**
* @brief To show the player
* @param screen the screen
* @param p the player
* @return Nothing
*/
void afficherPerso(Personne p, SDL_Surface *screen)
{
    SDL_BlitSurface(p.allMvt, &p.herosprite, screen, &p.heroPos);
}
void Animation_simple(Personne *p)
{
    
    if(p->last_direction == 1 && p->frame>=10)
    {
        if(p->herosprite.y!=38)
        {
            p->herosprite.x=0;
            p->herosprite.y=38;
            p->herosprite.w = 133;
            p->herosprite.h = 198;
        }
        p->herosprite.x+=315;
        if(p->herosprite.x > 1260)
        {
            p->herosprite.x=0;
        }
        p->frame=0;
    }
    else if(p->last_direction == -1 && p->frame>=10)
    {
        if(p->herosprite.y!=276 && p->frame>=1)
        {
            p->herosprite.x=0;
            p->herosprite.y=276;
            p->herosprite.w = 133;
            p->herosprite.h = 198;
        }
        p->herosprite.x+=315;
        if(p->herosprite.x >1260)
        {
             p->herosprite.x=0;
        }
        p->frame=0;
    }

}

void movePerso(Personne *hero)

{
    if (hero->right == 0 && hero->left == 0)
    {
        hero->velocity = 0;
        hero->speed =0;
        hero->xStep=0;
    }
    else{
        if (hero->direction == 1 || hero->direction == -1)
        {
            if (hero->right == 1 && hero->left==0 )
            {

                hero->xStep = 0.5 * hero->velocity  + hero->speed;
                if(hero->xStep >6)
                {
                    hero->xStep=6;
                }
                
                if (hero->velocity < 8)
                {
                    hero->velocity += 0.5;
                }
                else{
                    hero->velocity=8;
                }
                if(hero->speed <2)
                {
                    hero->speed += 0.2;
                }
                else{
                    hero->speed=2;
                }



                hero->heroPos.x += hero->xStep; 

            }

            else if (hero->left == 1 && hero->right ==0)
            {
                hero->xStep = 0.5 * hero->velocity  + hero->speed ;
                if(hero->xStep >6)
                {
                    hero->xStep=6;
                }
                hero->heroPos.x -= hero->xStep;
                if (hero->velocity < 8)
                {
                    hero->velocity += 0.5;
                }
                else{
                    hero->velocity=8;
                }
                if(hero->speed <2)
                {
                    hero->speed += 0.2;
                }
                else{
                    hero->speed=3;
                }

                 hero->heroPos.x -= hero->xStep;
            }
        }
    }
    
}
void jumpHeroMvt(Personne *hero)
{
    
	int y;
	int Amp = -185;
	float delta = -4 * Amp;
	float x = (sqrt(delta) / 2);
	if ((hero->jump == 1) )
	{
		hero->VarX++;
		
	}
	y = (int)((hero->VarX - x) * (hero->VarX - x) + Amp);
    hero->direction_y=y;
   
	if (y >= 0)
	{
		y = 0;
		hero->VarX = 0;
		hero->jump = 0;
		
	}
	hero->heroPos.y = (int)y + Ground;
}
void runAnimation(Personne *h)
{
    if(h->direction == 1 && h->frame>=10)
    {
        if(h->herosprite.y!=523)
        {
            h->herosprite.x=0;
            h->herosprite.y=523;
            h->herosprite.w = 133;
            h->herosprite.h = 198;
        }
        h->herosprite.x+=333;
        if(h->herosprite.x > 2331)
        {
            h->herosprite.x=333;
        }
        h->frame=0;
    }
    else if(h->direction == -1 && h->frame>=10)
    {
        if(h->herosprite.y!=772)
        {
            h->herosprite.x=2324;
            h->herosprite.y=772;
            h->herosprite.w = 133;
            h->herosprite.h = 198;
        }
        h->herosprite.x-=332;
        if(h->herosprite.x < 0)
        {
            h->herosprite.x=2324;
        }
        h->frame=0;
    }
}

void jumpAnimation(Personne *h)
{
    if(h->direction == 1 && h->frame>=10)
    {
        if(h->herosprite.y!=963)
        {
            h->herosprite.x=1104;
            h->herosprite.y=963;
            h->herosprite.w = 183;
            h->herosprite.h = 215;
        }
        h->herosprite.x+=374;
        if(h->herosprite.x > 1852 || h->herosprite.x<1104)
        {
            h->herosprite.x=1104;
        }
        h->frame=0;
    }
    else if(h->direction == -1 && h->frame>=10)
    {
        if(h->herosprite.y!=1289)
        {
            h->herosprite.x=354;
            h->herosprite.y=1289;
            h->herosprite.w = 155;
            h->herosprite.h = 206;
        }
        h->herosprite.x+=353;
        if(h->herosprite.x > 1060 || h->herosprite.x<354)
        {
            h->herosprite.x=354;
        }
        h->frame=0;
    }

}

