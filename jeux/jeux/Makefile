prog:main.o minimap.o player.o background.o
	gcc main.o minimap.o  player.o background.o -o prog -lSDL_image -lSDL_ttf -lSDL_mixer -lSDL -lm 
main.o:main.c
	gcc -c main.c 
background.o:background.c
	gcc -c background.c
minimap.o:minimap.c
	gcc -c minimap.c
player.o:player.c
	gcc -c player.c 
