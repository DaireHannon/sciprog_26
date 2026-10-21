# Practical 6
Practical 6 uses a makefile to compile a program capable of doing matrix multiplication:

## Running the makefile
In the location with the makefile run the command ```make`` to create the application,

To run the application use
``./main``

To remove the reset back to the beginning use
`` make clean``

## Files

### main.c
this file creates the three matrixes A,B,C and initialises them to 
$A_{i,j} = i + j $ , $B_{i,j} = i-j$ and $C_{i,j} = 0$
It then calls ``matmult()`` which is stored in matmult.c to preform matrix multiplication. 
Computing $C = AB$

### utils.h 
utils.h is the header file linking the two .c files together, containing only the definition for matmult() which is defined in matmult.c
