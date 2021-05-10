#ifndef CUBOID_H
#define CUBOID_H
#include <stdbool.h>

/**
 * Data of a cuboid object in Descartes coordinate system
 */
typedef struct Cuboid
{
	double a;
	double b;
	double c;
} Cuboid;

/**
 * Set the data of the cuboid.
 */
double setSize(Cuboid* cuboid, double x, double y, double z);

/**
 * Calculate the surface area of the cuboid.
 */
double calcSurface(const Cuboid* cuboid);


/**
 * Calculate the volume of the cuboid
 */
double calcVolume(const Cuboid* cuboid);

/**
 * Calculates whether or not the cuboid has a square side
 */
bool hasSquareSide(const Cuboid* cuboid);


#endif // CUBOID_H
