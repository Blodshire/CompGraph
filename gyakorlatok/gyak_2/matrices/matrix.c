#include "matrix.h"

#include <stdio.h>
#include <math.h>

void init_zero_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix[i][j] = 0.0;
        }
    }
}

void init_identity_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
			if(i==j){
				matrix[i][j] = 1.0;
			}
			else{
				matrix[i][j] = 0.0;
			}
            
        }
    }
}

void multiply_matrix_by_scalar(float matrix[3][3], float scalar)
{
	int i;
    int j;
	

	for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
			
				matrix[i][j] = matrix[i][j]*scalar;   
        
    }
}
}

void multiply_matrices(float result[3][3], const float left[3][3] , const float right[3][3] )
{
	int i;
    int j;
	int k;
	for( i = 0; i < 3; ++i){
		for (j = 0; j < 3; ++j) {
			result[i][j] = 0;
			for (k = 0; k < 3; ++k) {
				result[i][j]+=left[i][k]*right[k][j];
			}	
		}
	}
}
void print_matrix(const float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf("%4.4f ", matrix[i][j]);
        }
        printf("\n");
    }
	printf("\n");
}

void init_scale_matrix(float a[3][3],float lambda, float mu){
	
	int i;
    int j;
	
	float m[3][3]={
	    { lambda, 0.0f,  0.0f},
        { 0.0f, mu,  0.0f},
        {0.0f,  0.0f, 1.0f}
    };
	for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            a[i][j] = m[i][j];
        }
    }
}

void init_translate_matrix(float a[3][3],float dx, float dy)
{
	
	int i;
    int j;
	
	float m[3][3]={
	    { 1.0, 0.0f,  dx},
        { 0.0f, 1.0f,  dy},
        {0.0f,  0.0f, 1.0f}
    };
	for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            a[i][j] = m[i][j];
        }
    }
}

void init_rotation_matrix(float a[3][3],float alpha)
{
	int i;
    int j;
	
	float m[3][3] = {
	    { cos(alpha), -sin(alpha),  0.0f},
        { sin(alpha), cos(alpha),  0.0f},
        {0.0f,  0.0f, 1.0f}
    };
	for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            a[i][j] = m[i][j];
        }
    }
}

void add_matrices(const float a[3][3], const float b[3][3], float c[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void transform_point(float point[3], const float transM[3][3])
{
	int i;
    int j;
	for( i = 0; i < 3; ++i){
		float temp=0;
		for (j = 0; j < 3; ++j) {
			temp+=transM[i][j] * point[j];
		}
	    point[i]=temp;
		}
}

void print_point(const float point[3]){
	int i;
        for (i = 0; i < 3; ++i) {
            printf("%lf ", point[i]);
			printf("\n");
        }
		printf("\n");
}


