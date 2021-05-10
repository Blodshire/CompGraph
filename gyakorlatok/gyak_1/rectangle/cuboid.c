#include "cuboid.h"

#include <stdbool.h>
#include <math.h>



double setSize(Cuboid* cuboid, double x, double y, double z)
{
	
	if (x < 0.0 || y < 0.0 || z < 0.0) {
		
		cuboid->a = NAN;
		cuboid->b = NAN;
		cuboid->c = NAN;
	} else {
		cuboid->a = x;
		cuboid->b = y;
		cuboid->c = z;
		
	}
}

double calcSurface(const Cuboid* cuboid)
{
	double surface = 2 * (cuboid->a * cuboid->b ) + 
					 2 * (cuboid->a * cuboid->c ) + 
					 2 * (cuboid->c * cuboid->b );
	return surface;
}

double calcVolume(const Cuboid* cuboid)
{
	double volume = cuboid->a * cuboid->b * cuboid->c;
	return volume;
}

bool hasSquareSide(const Cuboid* cuboid)
{
	if(cuboid->a == cuboid->b || cuboid->a == cuboid->c || cuboid->b == cuboid->c){
		return true;
	}
	return false;
}
