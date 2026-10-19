#include <stdio.h>

void fibonacci(int *a, int *b){
    	int temp = *a + *b;   
	*a = *b ;
	*b = temp;
}

int main(void)
{

	int n = 0, a = 0, b = 1;
	printf("Enter a positive integer: ");
    	if (scanf("%d", &n) != 1 || n < 0) 
	{
        	printf("Invalid input\n");
        	return 1;
    	}

	printf("0");
    	for(int i = 0; i <= n ; i++)
	{
		if(i > 0)
		{
			printf(",%d",b);
        		fibonacci(&a, &b);
		}
    	}
	printf("\n");
   	return 0;


}
