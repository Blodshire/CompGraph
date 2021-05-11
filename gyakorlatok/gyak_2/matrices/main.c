#include "matrix.h"
#include <math.h>

int main(int argc, char* argv[])
{
	float a[3][3] = {
        { 1.0f, -2.0f,  3.0f},
        { 5.0f, -3.0f,  0.0f},
        {-2.0f,  1.0f, -4.0f}
    };
	float b[3][3];
	float b2[3][3];
	float c[3][3];
	float c2[3][3];
	float d[3][3];
	float d2[3][3];
	float transM[3][3];
	
	float point[3]={
		3.0f,
		2.0f,
		1.0f
	};

    init_zero_matrix(b);
    b[1][1] =  8.0f;
    b[2][0] = -3.0f;
    b[2][2] =  5.0f;
	/*
    print_matrix(a);
    print_matrix(b);
    
    add_matrices(a, b, c);

    print_matrix(c);
	
	init_identity_matrix(c);
	
	print_matrix(c);
	
	multiply_matrix_by_scalar(b, 7);
	
	print_matrix(b);
	*/
	//identity matrix is the same from left or right when multiplying with it
	multiply_matrices(a, b, b);
	
	print_matrix(a);
	
	init_scale_matrix(a, 1, 1);
	init_rotation_matrix(b, 2*M_PI);
	init_translate_matrix(c, 4, 4);
	init_translate_matrix(d, -4, -4);
	
	//print_matrix(a);
	//print_matrix(b);
	//print_matrix(c);
	//print_matrix(d);
	print_point(point);
	
	multiply_matrices(d2, d, c);
	//print_matrix(d2);
	multiply_matrices(c2, d2, b);
	//print_matrix(c2);
	multiply_matrices(b2, c2, a);
	//print_matrix(b2);
	multiply_matrices(transM, a, b2);
	
	transform_point(point, transM);
	
	print_point(point);
	

	return 0;
}

