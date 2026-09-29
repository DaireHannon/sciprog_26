#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void) {

/* Declare variables */
   int i,inum,tmp,numdigits;
   float fnum;
   char binnum[60];


/* Intialise 4-byte integer */
   inum = 16 ;// 33554431;
/* Convert to 4-byte float */
   fnum = (float) inum;


/* Convert to binary number (string)*/
   i = 0; tmp = inum;
   while (tmp > 0) {
     sprintf(&binnum[i],"%1d",tmp%2);
     tmp = tmp/2;
     i++;
   }

/* Terminate the string */
   binnum[i] = '\0'; 
       
   //reverse the String binnum
   int length, mid, j;
   char aux;
   length = strlen(binnum);
   mid = length/2;
   for(i = 0; i < mid; i++) {
       j = length-i-1;
       aux = binnum[i];
       binnum[i] = binnum[j];
       binnum[j] = aux;
    }

/* TODO: Complete the expression */
   numdigits = ceil(logf(fnum+1.0)/logf(2.0));  // Uses the formula log_y(x) = log_z(x)/log_z(y), 
	

   // The y = log2(n) says you need y digits to store (0,n-1) numbers, 
   // What I want is how many digits are needed to store the number n.
   // Hence logf(fnum+1.0). Without this fnum=16.0 would give 4, even though it should be 5 as 16 in base2 is 10000  
   
   printf("The number of digits is %d\n",numdigits);

   printf("inum=%d,  fnum=%f, inum in binary=%s\n",inum,fnum,binnum);

   return 0;
}
