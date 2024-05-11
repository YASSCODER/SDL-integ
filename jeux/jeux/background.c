/**

* @file background.c
*/
#include "background.h"

/**
* @brief To initialize the background b .
* @param b the background
* @return Nothing
*/
void initBackground(Background *B)  
{

  B->PositionBg.x = 0;  
  B->PositionBg.y = 0; 
  B->camera.x = 0;  
  B->camera.y = 185;  
  B->camera.w = 1500;  
  B->camera.h = 700;  

  B->frame = 1;  

  char string[20];  
  int i;  

  for (i = 1; i <=8; i++)  
  {
    sprintf(string, "background/b%d.png", i); 
    B->BgImg[i] = IMG_Load(string);  
  }

 

  B->vies = IMG_Load("HEARTS.png");  
  B->posVie1.x = 0;  
  B->posVie1.y = 250;  
   
  B->vie = 100;  

  B->posVie2.x = 749;  
  B->posVie2.y = 26;  
  B->posVie2.w = 84;  
  B->posVie2.h = 213;  

  TTF_Init();  
  B->police = TTF_OpenFont("font/font.ttf", 40);  

  B->score = 0;  
  B->posScore.x = 10;  
  B->posScore.y = 450;  
}

/**
* @brief To show the background b .
* @param scren the screen
* @param B the background
* @return Nothing
*/
void affBackground(Background *B, SDL_Surface *screen)
{
 
  SDL_BlitSurface(B->BgImg[B->frame], &(B->camera), screen, &(B->PositionBg));

 
  SDL_BlitSurface(B->vies, &(B->posVie2), screen, &(B->posVie1));

  
  if (B->vie >= 100)
  {
    B->posVie2.x = 749;
    B->posVie2.y = 26;
    B->posVie2.w = 84;
    B->posVie2.h = 213;
  }
  if (B->vie >= 85 && B->vie < 100)
  {
    B->posVie2.x = 633;
    B->posVie2.y = 26;
    B->posVie2.w = 84;
    B->posVie2.h = 213;
  }
  if (B->vie >= 75 && B->vie < 85)
  {
    B->posVie2.x = 516;
    B->posVie2.y = 26;
    B->posVie2.w = 84;
    B->posVie2.h = 213;
  }
  if (B->vie >= 50 && B->vie < 75)
  {
    B->posVie2.x = 402 ;
    B->posVie2.y = 26;
    B->posVie2.w = 84;
    B->posVie2.h = 213;
  }
  if (B->vie >= 25 && B->vie < 50)
  {
    B->posVie2.x = 172;
    B->posVie2.y = 39;
    B->posVie2.w = 87;
    B->posVie2.h = 208;
  }
  if (B->vie >= 0 && B->vie < 25)
  {
    B->posVie2.x = 59;
    B->posVie2.y = 39;
    B->posVie2.w = 87;
    B->posVie2.h = 208;
  }

  
  SDL_Color couleur = {0, 0, 0};

 
  char s[20];
  sprintf(s, "Score: %d", B->score);

  
  B->scores = TTF_RenderText_Blended(B->police, s, couleur);

  
  SDL_BlitSurface(B->scores, NULL, screen, &(B->posScore));
}


void animerBack(Background *B)
{
 
  if (B->frame == 7)
    B->frame = 0;

  
  B->frame++;
}

/**
* @brief To scroll the background 
* @param b the background
* @param direction the direction
* @param pas the step

* @return Nothing
*/
void scrolling (Background * b, int direction , int pas)
{
  
  if (direction == 1)
  {
    if (( b->camera.x < 8500 ))
    {
      b->camera.x += pas;
    }
  }
  else if (direction == -1)
  {
    if (b->camera.x > 0 )
    {
      if(b->camera.x-pas >=0)
      b->camera.x -= pas;
    }
    else b->camera.x=0;
  }
  
  
}


void freeBackground(Background *B)
{
  for (int i = 0; i < 8; i++)
  {
    SDL_FreeSurface(B->BgImg[i]);
  }
  
  SDL_FreeSurface(B->vies);
  SDL_FreeSurface(B->scores);
  Mix_FreeMusic(B->music);
}


 
