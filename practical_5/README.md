# Practical 5

Contains two c scripts, fibbonnacci.c and arctanh.c 

## fibbonnacci.c 
Takes in a user input for a positive integer (called n ) and prints out that many terms of the fibbonnacci series,
starting with $F_0 = 0 , F_1 = 1 ... F_n = F_{n-2} + F_{n-1}$


## arctanh.c 
Computes arctanh(x) over the interval [-0.9,0.9] in steps of 0.01 using two methods

### Method 1 : Maclaurin Series
An approximate method given by
$
arctanh(x) = \sum_0^\infty \frac{x^{2n+1}}{2n+1}
$       
This requires a user inputted value (delta) to decide when to stop adding terms and truncate the sum

### Method 2 : Natural logs
This exact value is given by
$
arctanh(x) = \frac{1}{2} \left( \ln(1+x) - \ln(1-x)  \right)
$


The values are computed for both and they are compared to each other

