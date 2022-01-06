/*
 * Program #2
 * cssc4861
 * Arthur Vo
*/
#include "p2.h"

/* This function reads m, n, and p from the datafile.  
    It then allocates the correct amount of memory required for matrices
    A, B, and C.
    Then matrices A and B are filled from the datafile.
    The values for m, n, and p are passed by reference, and are
    thus filled in by this function
    PARAMETERS in order are:
    int **      matrix A
    int **      matrix B
    int **      matrix C    
    int *       m   The number of rows in matrix A
    int *       n   The number of columns in matrix A and
                    The number of rows in matrix B
    int *       p   The number of columns in matrix B
    char *      The name of the datafile, from the command line
*/
void read_matrices(int **A, int **B, int **C, int *m, int *n, int *p, char *file){
    FILE *fp = fopen(file, "r");
    int i, j;

    fscanf(fp, "%d %d %d", m, n, p);

    /* Allocate memory space for arrays */
    *A = (int *)malloc((*m) * (*n) * sizeof(int));
    *B = (int *)malloc((*n) * (*p) * sizeof(int));
    *C = (int *)malloc((*m) * (*p) * sizeof(int));

    /* Allocate memory space for arrays */
    for(i = 0; i < *m; i++){
        for(j = 0; j < *n; j++){
            fscanf(fp, "%d", (*A + (i * (*n) + j)));
        }
    }
    
    for(i = 0; i < *n; i++){
        for(j = 0; j < *p; j++){
            fscanf(fp, "%d", (*B + (i * (*p) + j)));
        }
    }
    fclose(fp);
}

/*  This function prints a matrix.  Rows and columns should be preserved.
    PARAMETERS in order are:
    int *       The matrix to print
    int         The number of rows in the matrix
    int         The number of columns in the matrix
*/   
void print_matrix(int *matrix, int m, int n){
    int i, j;

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("%4d ", *(matrix + (i*n + j)));
        }
        printf("\n");
    }
}

/*  The two matrices A and B are multiplied, and matrix C contains the
    result.
    PARAMETERS in order are:
    int *       Matrix A
    int *       Matrix B
    int *       Matrix C
    int         m
    int         n
    int         p
*/   
void mult_matrices(int *A, int *B, int *C, int m, int n, int p){
    int i, j, k;
    for(i = 0; i < m; i++)
        for(j = 0; j < p; j++){
            *(C + i * p + j) = 0;
            for(k = 0; k < n; k++)
                *(C + i * p + j) +=  *(A + i * n + k) * *(B + k * p + j);
        }
}

/*
    Main method will first read in matrices A and B from the input file
    specified in the command line argument. Matrix A and B will be 
    printed, and multiplied together using matrix multiplication to get
    the reslutant Matrix C, which will then be printed.
*/
int main(int argc, char **argv){
    int *A, *B, *C, m, n, p;

    read_matrices(&A, &B, &C, &m, &n, &p, *(argv+1));
    
    printf("Matrix A contents:\n");
    print_matrix(A, m, n);

    printf("\nMatrix B contents:\n");
    print_matrix(B, n, p);

    mult_matrices(A, B, C, m, n, p);

    printf("\nMatrix A * B is:\n");
    print_matrix(C, m, p);

    return 0;
}