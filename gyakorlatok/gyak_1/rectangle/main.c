#include "cuboid.h"
#include <stdbool.h>


#include <stdio.h>

int main(int argc, char* argv[])
{
	Cuboid cuboid;
	double area, volume;
	
	setSize(&cuboid, 4, 10, 4);
	area = calcSurface(&cuboid);
	volume= calcVolume(&cuboid);
	
	printf("Cuboid surface area: %lf\n", area);
	printf("Cuboid volume: %lf\n", volume);
	printf("Cuboid has a square side: %\n");
	printf(hasSquareSide(&cuboid) ? "true" : "false");
	return 0;
}
