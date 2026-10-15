#include <stdio.h>
#include <math.h>
float degtorad(float arg);

int main(void){
        int N = 12 ;
        double tans[N] , rad[N]; 
/*
	    rad[i] stores the radian value for point i on the grid,		
	    tans[i] stores the value tan(rad[i]) for each rad value i
*/
        double a = 0,
               b = 60,
	       step_size = (b-a)/(N),
               sum = 0,
               Analytical_res;
	
	for (int idx = 0 ; idx < N ; idx ++) {
		double deg = a + idx*step_size ; 
		rad[idx] = degtorad( deg ) ; // This computes the radian values and stores them in an array without storing the degree values 
		tans[idx] = tan(rad[idx]) ;
	}
        sum += tans[0] + tans[N-1] ;
        for(int idx = 1;idx < N - 2; idx ++) // Loop sums up contributions from the area of every rectangle
        {
                sum += 2* tan(rad[idx]) ;
        }
        sum *= ( rad[N-1] - rad[0] )/(2*N);
        Analytical_res = log(2) ;
        printf("Numerical Result = %f \nAnalytical Results %f \n",sum,Analytical_res);
        return 0;
}

// Function takes in a value in degrees and converts it to radians
float degtorad(float arg) {
	return ( (M_PI*arg)/180.0 ) ; 
}
