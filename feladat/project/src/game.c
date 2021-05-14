
#include "game.h"

#include "scene.h"




#include <GL/glut.h>



#include <obj/load.h>

#include <obj/draw.h>

/**
 * Returns the index of the closest hexa tile to the mouse
 */
int getClosest(Game* game, float x, float y) {
    int closest = -1;

    int i;
    float distance = 100000;
    for (i = 0; i < 100; i++) {
        float temp = (x-game->SetHexaCoords[i][0])*(x-game->SetHexaCoords[i][0]) + (y-game->SetHexaCoords[i][1])*(y-game->SetHexaCoords[i][1]);
			if (distance < temp) {
        closest = i;
		}
	}
return closest;
}

/**
* Returns a tile's surrounding tiles coordinates
*/
void getRangeCoordinates(Game* game, int indexOfHexa) {
    int i = 0;
    game->ClosestSetHexaSurround[0][0]=game->SetHexaCoords[indexOfHexa][0]+0.25;
    game->ClosestSetHexaSurround[0][1]=game->SetHexaCoords[indexOfHexa][1]+0.5;

    game->ClosestSetHexaSurround[1][0]=game->SetHexaCoords[indexOfHexa][0]+0.5;
    game->ClosestSetHexaSurround[1][1]=game->SetHexaCoords[indexOfHexa][1]+0.0;

    game->ClosestSetHexaSurround[2][0]=game->SetHexaCoords[indexOfHexa][0]+0.25;
    game->ClosestSetHexaSurround[2][1]=game->SetHexaCoords[indexOfHexa][1]-0.5;

    game->ClosestSetHexaSurround[3][0]=game->SetHexaCoords[indexOfHexa][0]-0.25;
    game->ClosestSetHexaSurround[3][1]=game->SetHexaCoords[indexOfHexa][1]+0.5;

    game->ClosestSetHexaSurround[4][0]=game->SetHexaCoords[indexOfHexa][0]-0.5;
    game->ClosestSetHexaSurround[4][1]=game->SetHexaCoords[indexOfHexa][1]+0.0;

    game->ClosestSetHexaSurround[5][0]=game->SetHexaCoords[indexOfHexa][0]-0.25;
    game->ClosestSetHexaSurround[5][1]=game->SetHexaCoords[indexOfHexa][1]-0.5;



}

/**
* Checks if mouse is in a tile's surrounding tiles
*/
void checkMouseValidRange(Game* game, float x, float y) {

    //implement switch(true)?
    int i;
    for (i = 0; i <6; i++) {
        if (x > game->ClosestSetHexaSurround[i][0]-0.25 && x < game->ClosestSetHexaSurround[i][0]+0.25 &&
                y > game->ClosestSetHexaSurround[i][1]-0.25 && y < game->ClosestSetHexaSurround[i][1]+0.25)
        {
            game->CurrentHexaX=game->ClosestSetHexaSurround[i][0];
            game->CurrentHexaY=game->ClosestSetHexaSurround[i][1];
            //draw model on center (indexed already)
            //pushmatrix, translate to x,y, load model, popmatrix
            break;
        }
        else {
            //possibly draw on mouse center?
            game->CurrentHexaX=x;
            game->CurrentHexaY=y;
        }
    }
}

/**

 * Rotates active Hexa tile

 */

void rotateCurrentHexa(Game* game) {

    float temp = game->CurrentHexaTypes[5];

    int i;

    for (i = 5; i >0; i++) {

        game->CurrentHexaTypes[i]=game->CurrentHexaTypes[i-1];

    }

    game->CurrentHexaTypes[0]= temp;



    //rotate object(s) by 60 degree

}

/**
* Modifies an array based on surrounding tiles validity
*/
void checkForValidSurround(Game* game) {
    float x = game->CurrentHexaX;
    float y = game->CurrentHexaY;
    int i;
    int j;
    for (i = 0;i < 100;i++) {
        //implement switch (true)?
        if (game->SetHexaCoords[i][0]==x+0.25 && game->SetHexaCoords[i][1]==y+0.5) {
            game->validSurround[0]=i;
        } else {
            game->validSurround[0]=-1;
        }

        if (game->SetHexaCoords[i][0]==x+0.5 && game->SetHexaCoords[i][1]==y+0.0) {
            game->validSurround[1]=i;
        } else {
            game->validSurround[1]=-1;
        }

        if (game->SetHexaCoords[i][0]==x+0.25 && game->SetHexaCoords[i][1]==y-0.5) {
            game->validSurround[2]=i;
        } else {
            game->validSurround[2]=-1;
        }

        if (game->SetHexaCoords[i][0]==x-0.25 && game->SetHexaCoords[i][1]==y+0.5) {
            game->validSurround[3]=i;
        } else {
            game->validSurround[3]=-1;
        }

        if (game->SetHexaCoords[i][0]==x+0.5 && game->SetHexaCoords[i][1]==y+0.0) {
            game->validSurround[4]=i;
        } else {
            game->validSurround[4]=-1;
        }

        if (game->SetHexaCoords[i][0]==x-0.25 && game->SetHexaCoords[i][1]==y-0.5)
        {
            game->validSurround[5]=i;
        } else {
            game->validSurround[5]=-1;
        }
    }
}

/**
* Checks valid surrounding tiles adjacency, if adjacency is correct, sets tile
*/
void checkAndSetTile(Game* game) {
    int i = 0;
    int temp;
    int checksum=0;
    for (i; i < 6; i++) {
        if (game->validSurround[i]!=-1) {
            temp=game->validSurround[i];
            checksum++;
            switch (i) {
            case 0:

                if (game->SetHexaTypes[temp][0]==game->CurrentHexaTypes[3]) {
                    checksum--;
                }
                break;
            case 1:
                if (game->SetHexaTypes[temp][1]==game->CurrentHexaTypes[4]) {
                    checksum--;
                }
                break;
            case 2:
                if (game->SetHexaTypes[temp][2]==game->CurrentHexaTypes[5]) {
                    checksum--;
                }
                break;
            case 3:
                if (game->SetHexaTypes[temp][3]==game->CurrentHexaTypes[0]) {
                    checksum--;
                }
                break;
            case 4:
                if (game->SetHexaTypes[temp][4]==game->CurrentHexaTypes[1]) {
                    checksum--;
                }
                break;
            case 5:
                if (game->SetHexaTypes[temp][5]==game->CurrentHexaTypes[2]) {
                    checksum--;
                }
                break;

            }
        }
        if (checksum==0) {
            //set tile
            //Add tile to set tiles
        }
    }
}
void randomizeTile(Game* game) {
    int i;
    for (i = 0; i < 6; i++) {
        int num = (rand() %
                   (0 - 6 + 1)) + 0;
        game->CurrentHexaTypes[i]=num;
    }
}



void drawTile(Game* game) {

    glPushMatrix();
    float x=game->CurrentHexaX;
    float y=game->CurrentHexaY;

    //GlTranslatef(x,y,0);

    draw_hexas(0,0);

    int i;

    for (i = 0; i < 6; i++) {

        switch (i) {

        case 0:
            //offset to UR
            drawType(game->CurrentHexaTypes[i]);


        case 1:
            //offset to MR
            drawType(game->CurrentHexaTypes[i]);

            break;

        case 2:
            //offset to LR
            drawType(game->CurrentHexaTypes[i]);

            break;

        case 3:
            //offset to UL
            drawType(game->CurrentHexaTypes[i]);

            break;

        case 4:
            //offset to ML
            drawType(game->CurrentHexaTypes[i]);

            break;

        case 5:
            //offset to LL
            drawType(game->CurrentHexaTypes[i]);

            break;



        }
        glPopMatrix();
    }


}

void drawType(int type) {

    switch (type) {



    case 0:



        //draw type 0 on centre

        //white flag



        break;



    case 1:



        //draw type 1

        //red flag

        break;



    case 2:



        //draw type 2

        //blue flag



        break;



    case 3:



        //draw type 3

        //green flag

        break;



    case 4:



        //draw type 4

        //purple flag

        break;



    case 5:



        //draw type 5

        //yellow flag

        break;



    }
	printf("heh");


}