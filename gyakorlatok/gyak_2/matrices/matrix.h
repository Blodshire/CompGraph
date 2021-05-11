#ifndef MATRIX_H
#define MATRIX_H

/**
 * Initializes all elements of the matrix to zero.
 */
void init_zero_matrix(float matrix[3][3]);

/**
 * Print the elements of the matrix.
 */
void print_matrix(const float matrix[3][3]);

/**
 * Multiply elements of the matrix by a scalar(float)
 */
void multiply_matrix_by_scalar(float matrix[3][3], float scalar);

/**
 * Initializes a matrix as an identity matrix.
 */
void init_identity_matrix(float matrix[3][3]);

/**
 * Multiply a 3x3 matrix by another, save result in a third matrix.
 */
void multiply_matrices(float result[3][3], const float left[3][3] , const float right[3][3] );

/**
 * Initializes a matrix as a scale transformation with lambda and mu parameters.
 */
void init_scale_matrix(float m[3][3],float lambda, float mu);

/**
 * Initializes a matrix as a translate transformation with dx and dy parameters.
 */
void init_translate_matrix(float m[3][3],float dx, float dy);

/**
 * Initializes a matrix as a rotation transformation with alpha (radian) parameters.
 */
void init_rotation_matrix(float m[3][3],float alpha);

/**                              ;
 * Add matrices.
 */
void add_matrices(const float a[3][3], const float b[3][3], float c[3][3]);

/**                              ;
 * Transforms a homogen coordinate point with a matrix as parameter
 */
void transform_point(float point[3], const float transM[3][3]);

/**                              ;
 * Prints a point with homogen coordinates
 */
void print_point(const float point[3]);


#endif // MATRIX_H

