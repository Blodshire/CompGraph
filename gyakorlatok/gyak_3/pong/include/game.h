#ifndef GAME_H
#define GAME_H

#include "ball.h"
#include "pad.h"
#include "GL/glut.h"

/**
 * Game state representation
 */
typedef struct Game
{
    Ball ball;
    Pad left_pad;
    Pad right_pad;
    int width;
    int height;
	int point_left;
	int point_right;
} Game;

/**
 * Resize the game and update positions.
 */
void resize_game(Game* game, int width, int height);

/**
 * Restart the game.
 */
void restart_game(Game* game);

/**
 * Update the state of the game.
 * @param time elapsed time in seconds
 */
void update_game(Game* game, double time);

/**
 * Move the left pad to the given position.
 */
void move_left_pad(Game* game, float position);

/**
 * Move the right pad to the given position.
 */
void move_right_pad(Game* game, float position);

        /**
 * Draw a character string.
 *
 * @param x        The x position
 * @param y        The y position
 * @param z        The z position
 * @param string   The character string
 */

    

#endif /* GAME_H */
