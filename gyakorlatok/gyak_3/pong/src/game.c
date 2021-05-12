#include "game.h"

void resize_game(Game* game, int width, int height)
{
    game->width = width;
    game->height = height;
    game->left_pad.size = 200;
    game->right_pad.size = 200;
	game->point_left=0;
	game->point_right=0;
    restart_game(game);
}

void restart_game(Game* game)
{
    float center_x;
    float center_y;

    center_x = game->width / 2;
    center_y = game->height / 2;

    move_pad(&(game->left_pad), center_y, game->height);
    move_pad(&(game->right_pad), center_y, game->height);
    start_ball(&(game->ball), center_x, center_y);
}

void update_game(Game* game, double time)
{
    update_ball(&(game->ball), time);
    if (game->ball.x - game->ball.radius < 50) {
		
		if(game->ball.y > game->left_pad.position+game->left_pad.size || game->ball.y < game->left_pad.position){
			game->point_right+=1;
			restart_game(game);
		}else{
        game->ball.x = game->ball.radius + 50;
        game->ball.speed_x *= -1;
		/*
		printf("Left pad position:%lf\n", game->left_pad.position);
		printf("Ball position: %lf\n", game->ball.y);
		printf("test value leftset\n");
		*/
		}
		
    }
    if (game->ball.x + game->ball.radius > game->width - 50) {
		if(game->ball.y > game->right_pad.position+game->right_pad.size || game->ball.y < game->right_pad.position){
			game->point_left+=1;
			restart_game(game);
		}else{
        game->ball.x = game->width - game->ball.radius - 50;
        game->ball.speed_x *= -1;
		/*
		printf("test value rightset\n");
		
		printf("Ball position: %lf\n", game->ball.y);
		printf("Right padposition:%lf\n", game->right_pad.position);
		*/
		}
    }
    if (game->ball.y - game->ball.radius < 0) {
        game->ball.y = game->ball.radius;
        game->ball.speed_y *= -1;
		//printf("test value upset\n");
    }
    if (game->ball.y + game->ball.radius > game->height) {
        game->ball.y = game->height - game->ball.radius;
        game->ball.speed_y *= -1;
		//printf("test value downset\n");
    }
}

void move_left_pad(Game* game, float position)
{
    move_pad(&(game->left_pad), position, game->height);
}

void move_right_pad(Game* game, float position)
{
    move_pad(&(game->right_pad), position, game->height);
}

