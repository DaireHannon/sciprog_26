#include <stdlib.h>
#include <stdio.h>
#include <math.h> 

int *allocatearray(int n)
{
  int *r;
  r = (int *) malloc(n * sizeof(int));
  return r ;
}

void fillwithones(int n, int array[n])
{
  for(int i = 0; i < n; i++)
  {
    array[i] = 1;
  }
}

void printarray(int n, int array[n])
{
    for(int i = 0; i < n-1; i++)
  {
    printf("%d,",array[i]);
  }

  printf("%d\n",array[n-1]); // Prints the last input with no comma, and adds a line break to make things look cleaner.

}

double calc_taylor_expansion_term(int n)
{
  double res ; // Let x = 1 
  res = pow(1,n)/(tgamma(n+1)) ; // n! is replaced with Gamma(n+1) as c has the gamma function but not the factorial 
  return res ;
}
int main(void) 
{
  // Section 1 Estimating e 

  int n = 0; // This is set by the user
  double *taylor_exp_terms, estimate_of_e = 0 ;
  
  printf("Enter a positive integer: ");
  if (scanf("%d", &n) != 1 || n < 0) 
  {
    printf("Invalid input\n");
    return 1;
  }
  n = n + 1 ; // I use n as an array indexer so I need to add 1 to it.

  taylor_exp_terms = (double *) malloc(n * sizeof(double));
  if(taylor_exp_terms == NULL) {printf("Error allocating taylor expansion terms array\n"); return 1 ; }

  // Assign value for term i in the array
  for(int i = 0; i < n; i++)
  {
    taylor_exp_terms[i] = (calc_taylor_expansion_term(i)) ; 
  }

  // Estimate e by continuously summing all terms, printing at each iteration
  for(int i = 0; i < n; i++)
  {
    estimate_of_e += taylor_exp_terms[i] ;
    printf("f(%d)\t=\t%.20f\n",i,estimate_of_e);
  }

  // Compare to the known value
  double e = 2.71828182845904523536028747135;
  printf("e\t=\t%.20f\n",e);


  // Comment : 
  // The terms disagree on the 16 d.p this is machine error, nothing more.

  
  free(taylor_exp_terms) ; 

  //////////////////////////////////////////
  // Section 2 Dynamic Memory Allocation  //
  //////////////////////////////////////////
  printf("\n Dynamic Memory Allocation Section \n ");


  int arrsize = 5; 
  int* array;
  array = allocatearray(arrsize) ; 

  // Checking if the allocation worked by seeing if the pointer is set to NULL
  if(array == NULL) {printf("Error allocating array\n"); return 1 ; }

  fillwithones(arrsize,array);

  printarray(arrsize,array) ; 

  free(array);

  return 0;

}