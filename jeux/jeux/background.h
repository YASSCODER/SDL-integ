#ifndef DER
#define DER


#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

/**
* @struct Background
* @brief struct for background
*/
typedef struct
{
  SDL_Surface *BgImg[8];   /*!< Surface. */
  SDL_Surface *vies;  /*!< Surface. */
  SDL_Surface *scores;  /*!< Surface. */

  SDL_Rect PositionBg;
  SDL_Rect positionperso;

  SDL_Rect camera;

  SDL_Rect posVie1;
  SDL_Rect posVie2;
  SDL_Rect posScore;
  
  TTF_Font *police;

  Mix_Music *music;
  int jump_state;
  int frame;
  int vie;
  int score;

} Background;

typedef struct
{
  char name[10];
  int score;
  int time;

  SDL_Surface *first;
  SDL_Rect pos;

} ScoreInfo;


void initBackground(Background *B);
void affBackground(Background *B, SDL_Surface *screen);
void animerBack(Background *B);
void scrolling (Background * b, int direction , int pas);

void freeBackground(Background *B);

#endif
