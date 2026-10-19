#include <stdio.h>
#include <math.h>

#define N 181   // x = -0.9, -0.89, ..., 0.9

// Method 1: Maclaurin series
double artanh1(double x, double delta){
    double sum = 0.0;
    double power = x;      // holds x^(2n+1)
    double term;
    int n = 0;

    do {
        term = power / (2*n + 1);
        sum = sum + term;
        power = power * x * x;   // next odd power 
        n++;
    } while (fabs(term) >= delta);

    return sum;
}

// Method 2: natural logarithms 
double artanh2(double x){
    return 0.5 * (log(1.0 + x) - log(1.0 - x));
}

int main(void){
    double delta, x, diff, rel, maxrel = 0.0;
    double r1[N], r2[N];
    int i, agree = 0;

    printf("Enter a positive real number delta: ");
    if (scanf("%lf", &delta) != 1 || delta <= 0.0) {
        printf("Invalid input\n");
        return 1;
    }

    // Calculate with both methods and store in separate arrays 
    for (i = 0; i < N; i++) {
        x = (i - 90) * 0.01;      // avoids adding 0.01 repeatedly 
        r1[i] = artanh1(x, delta);
        r2[i] = artanh2(x);
    }

    // Compare the two methods to 10 significant figures 
    printf("\n%6s %18s %18s %12s\n", "x", "series", "logs", "abs diff");
    for (i = 0; i < N; i++) {
        x = (i - 90) * 0.01;
        diff = fabs(r1[i] - r2[i]);

        if (r2[i] != 0.0) rel = diff / fabs(r2[i]);
        else              rel = diff;

        if (rel > maxrel) maxrel = rel;
        if (rel < 5.0e-11) agree++;   // same to 10 s.f. 

        printf("%6.2f %18.10e %18.10e %12.3e\n", x, r1[i], r2[i], diff);
    }

    printf("\nPoints agreeing to 10 significant figures: %d of %d\n", agree, N);
    printf("Largest relative difference: %.3e\n", maxrel);

    return 0;
}
