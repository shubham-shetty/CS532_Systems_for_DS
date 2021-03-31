#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define n 1000
// 1. ijk
// 1. jki
// 1. kij
// 1. ikj
// 1. kji
// 1. jik

double A[n][n];
double B[n][n];
double C[n][n];

int main() {

    //populate the matrices with random values between 0.0 and 1.0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            A[i][j] = (double) rand() / (double) RAND_MAX;
            B[i][j] = (double) rand() / (double) RAND_MAX;
            C[i][j] = 0;
        }
    }

    struct timespec start, end;
    double time_spent;

    //matrix multiplication

    //ijk
    /*
    clock_gettime(CLOCK_REALTIME, &start);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    */

    //jki
    /*
    clock_gettime(CLOCK_REALTIME, &start);
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    */

    //kij
    /*
    clock_gettime(CLOCK_REALTIME, &start);
    for (int k = 0; k < n; k++) { 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
             
                C[i][j] += A[i][k] * B[k][j];
            
        }
    }}
    */

    //ikj
    /*
    clock_gettime(CLOCK_REALTIME, &start);
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    */

    //kji
    /*
    clock_gettime(CLOCK_REALTIME, &start);
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    */

    //jik
    
    clock_gettime(CLOCK_REALTIME, &start);
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    

    clock_gettime(CLOCK_REALTIME, &end);
    time_spent = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("Elapsed time in seconds: %f \n", time_spent);
    return 0;
}
