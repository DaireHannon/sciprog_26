#include <math.h>
#include <stdio.h>

int main (){
	int N = 12 ;
	double grid[N]; // Arrays for grid and the function
	double a = 0,
	       b = M_PI/3,
	       sum = 0, 
		Analytical_res;
	sum += tan(a) + tan(b) ;
	for(int idx = 0 ; idx < N - 1; idx ++){
	grid[idx] = a + ((b-a)/(N)) * idx ; 
	}	
	for(int idx = 0;idx < N - 1;idx ++) // Loop sums up contributions from the area of every rectangle
	{
		sum += 2* tan(grid[idx]) ; 
	}
	sum *= (b-a)/(2*N);
	Analytical_res = log(2)	;
	printf("Numerical Result = %f \nAnalytical Results %f \n",sum,Analytical_res);
	return 0;
}
