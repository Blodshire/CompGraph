
#include "game.h"

/**
 * Returns the index of the closest hexa tile to the mouse
 */
int getClosest(float x, float y){
	int closest = -1;
	
	int i;
	float distance = 100000;
	for(i = 0; i < 100; i++){
		float temp = (x-SetHexaCoords[i][0])^2 + (y-SetHexaCoords[i][1])^2
		if(distance < temp){
			closest = i;
		}
	}
	return closest;
}

 /**
 * Returns a tile's surrounding tiles coordinates
 */
void getRangeCoordinates(int indexOfHexa){
	int i = 0;
	ClosestSetHexaSurround[0][0]=SetHexaCoords[indexOfHexa][0]+0.25;
	ClosestSetHexaSurround[0][1]=SetHexaCoords[indexOfHexa][1]+0.5;
	
	ClosestSetHexaSurround[1][0]=SetHexaCoords[indexOfHexa][0]+0.5;
	ClosestSetHexaSurround[1][1]=SetHexaCoords[indexOfHexa][1]+0.0;
	
	ClosestSetHexaSurround[2][0]=SetHexaCoords[indexOfHexa][0]+0.25;
	ClosestSetHexaSurround[2][1]=SetHexaCoords[indexOfHexa][1]-0.5;
	
	ClosestSetHexaSurround[3][0]=SetHexaCoords[indexOfHexa][0]-0.25;
	ClosestSetHexaSurround[3][1]=SetHexaCoords[indexOfHexa][1]+0.5;
	
	ClosestSetHexaSurround[4][0]=SetHexaCoords[indexOfHexa][0]-0.5;
	ClosestSetHexaSurround[4][1]=SetHexaCoords[indexOfHexa][1]+0.0;
	
	ClosestSetHexaSurround[5][0]=SetHexaCoords[indexOfHexa][0]-0.25;
	ClosestSetHexaSurround[5][1]=SetHexaCoords[indexOfHexa][1]-0.5;
	

	
}

 /**
 * Checks if mouse is in a tile's surrounding tiles
 */
void checkMouseValidRange(float x, float y){
	
	//implement switch(true)?
	int i;
	for(i = 0; i <6; i++){
	if(x > ClosestSetHexaSurround[i][0]-0.25 && x < ClosestSetHexaSurround[i][0]+0.25 &&
		y > ClosestSetHexaSurround[i][1]-0.25 && y < ClosestSetHexaSurround[i][1]+0.25)
		{
			//CurrentHexaX=ClosestSetHexaSurround[i][0]
			//CurrentHexaY=ClosestSetHexaSurround[i][1]
			//draw model on center (indexed already)
			//pushmatrix, translate to x,y, load model, popmatrix
			break;
			}
			else{
				//possibly draw on mouse center?
				//CurrentHexaX=x;
				//CurrentHexaY=y;
			}
	}
}

/**
 * Rotates active Hexa tile
 */
void rotateCurrentHexa(){
	float temp = CurrentHexaTypes[5];
	int i;
	for(i = 5; i >0; i++){
		CurrentHexaTypes[i]=CurrentHexaTypes[i-1];
	}
	currentHexaTypes[0]= temp;
	
	//rotate object(s) by 60 degree
}
 
 /**
 * Modifies an array based on surrounding tiles validity
 */
void checkForValidSurround(float x, float y){
	int i;
	int j;
	for(i = 0;i < 100;i++){
		//implement switch (true)?
		if(SetHexaCoords[i][0]==x+0.25 && SetHexaCoords[i][1]==y+0.5){
			validSurround[0]=i;
		}else{
			validSurround[0]=-1;
		}
		
		if(SetHexaCoords[i][0]==x+0.5 && SetHexaCoords[i][1]==y+0.0){
			validSurround[1]=i;
		}else{
			validSurround[1]=-1;
		}
		
		if(SetHexaCoords[i][0]==x+0.25 && SetHexaCoords[i][1]==y-0.5){
			validSurround[2]=i;
		}else{
			validSurround[2]=-1;
		}
		
		if(SetHexaCoords[i][0]==x-0.25 && SetHexaCoords[i][1]==y+0.5){
			validSurround[3]=i;
		}else{
			validSurround[3]=-1;
		}
		
		if(SetHexaCoords[i][0]==x+0.5 && SetHexaCoords[i][1]==y+0.0){
			validSurround[4]=i;
		}else{
			validSurround[4]=-1;
		}
		
		if(SetHexaCoords[i][0]==x-0.25 && SetHexaCoords[i][1]==y-0.5)
		{
			validSurround[5]=i;
		}else{
			validSurround[5]=-1;
		}
	}
}

 /**
 * Checks valid surrounding tiles adjacency, if adjacency is correct, sets tile
 */
void checkAndSetTile(){
	int i = 0;
	int checksum=0;
	for(i; i < 6; i++){
		if(validSurround[i]!=-1){
			checksum++;
			switch(i){
				case 0:
				if(SetHexaTypes[validSurround[i]][0]==CurrentHexaTypes[3]){
					checksum--;
				}
				break;
				case 1:
				if(SetHexaTypes[validSurround[i]][1]==CurrentHexaTypes[4]){
					checksum--;
				}
				break;
				case 2:
				if(SetHexaTypes[validSurround[i]][2]==CurrentHexaTypes[5]){
					checksum--;
				}
				break;
				case 3:
				if(SetHexaTypes[validSurround[i]][3]==CurrentHexaTypes[0]){
					checksum--;
				}
				break;
				case 4:
				if(SetHexaTypes[validSurround[i]][4]==CurrentHexaTypes[1]){
					checksum--;
				}
				break;
				case 5:
				if(SetHexaTypes[validSurround[i]][5]==CurrentHexaTypes[2]){
					checksum--;
				}
				break;
				
			}
		}
		if(checksum==0){
			//set tile
			//Add tile to set tiles
		}
	}
	
	
	
}
