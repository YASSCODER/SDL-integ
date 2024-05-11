#ifndef player_H_INCLUDED
#define player_H_INCLUDED
#define Ground 250
/**
* @struct Personne
* @brief struct for Personne
*/typedef struct
{
    SDL_Surface *allMvt;
    SDL_Rect heroPos;
    
    SDL_Rect herosprite;
    int left, right, jump, attack, down;   //key stat if it pressed or not
    int frame;
    float xStep, yStep;
    float velocity, speed;
    int direction; // 0: no move 1:right move -1: left move (num kima repere fel math ) 2: up
    int direction_y;
    int last_direction; // 1 or -1 we will save the last direction  right or left 
    int col;
    float VarX;




}Personne;




void init_Perso(Personne *p);
void afficherPerso(Personne p, SDL_Surface *screen);
void Animation_simple(Personne *h);
void movePerso(Personne *hero);
void runAnimation(Personne *h);
void jumpHeroMvt(Personne *hero);
void jumpAnimation(Personne *h);



#endif