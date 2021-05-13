#ifndef GAME_H
#define GAME_H


#include "GL/glut.h"

/**
 * Game state representation
 */
typedef struct Game
{
	
	//could set these two into two "classes", SetHexa and CurrentHexa, hope it's not a problem
	int SetHexaCounter;
    float SetHexaCoords[100][2];
	float SetHexaTypes[100][6];
	float ClosestSetHexaSurround[6][2] ;
	float CurrentHexaTypes[6] ;
	float CurrentHexaX;
	float CurrentHexaY;
	float validSurround[6];
} Game;

/**
 * Returns the index of the closest hexa tile to the mouse
 */
int getClosest(float x, float y);

 /**
 * Returns a tile's surrounding tiles coordinates
 */
void getRangeCoordinates(int indexOfHexa);

 /**
 * Checks if mouse is in a tile's surrounding tiles
 */
void checkMouseValidRange(float x, float y, float ClosestHexaSurround[10][6]);

/**
 * Rotates active Hexa tile
 */
void rotateCurrentHexa(float CurrentHexaTypes[6]);
 
 /**
 * Modifies an array based on surrounding tiles validity
 */
void checkForValidSurround(float x, float y);

 /**
 * Checks valid surrounding tiles adjacency, if adjacency is correct, sets tile
 */
void checkAndSetTile();
#endif /* GAME_H */
