#include <stdio.h>
#include "utils.h"
int main(void){
	int n = 5, p = 3, q = 4 ;
	double A[n][p],B[p][q],C[n][q] ; 
	int i , j ;	

	for(i = 0;i < n ;i++)
        {
                for( j = 0 ; j < p; j++)
                {
                        A[i][j] = i+j;
                }
        }

        for(i = 0;i < p ;i++)
        {
                for( j = 0 ; j < q; j++)
                {
                        B[i][j] = i - j;
                }
        }
	
	matmult(n,p,q,A,B,C);
	printf("\n Matrix A \n");
	for(i = 0;i< n ;i++)
        {
                for( j = 0 ; j < p; j++)
                {
                        printf("%f,",A[i][j]);
                }
		printf("\n") ;
        }
	printf("\n Matrix B \n");
        for(i = 0;i< p ;i++)
        {
                for( j = 0 ; j < q; j++)
                {
                        printf("%f,",B[i][j]);
                }
                printf("\n") ;
        }
        printf("\n Matrix C \n") ;
	for(i = 0;i< n ;i++)
        {
                for( j = 0 ; j < q; j++)
                {
                        printf("%f,",C[i][j]); 
                }
		printf("\n") ;
        }
	return 0;
}
