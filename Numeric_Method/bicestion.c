#include <stdio.h>
#include <math.h>

// Define the function using macro
#define f(x) ((x)*(x)*(x) - (x) - 2)

int main() {
    double a, b, c;
    double fa, fb, fc;
    double error = 0.0001;   // tolerance mentioned at first
    int maxIter = 100, i = 1;

    // Input interval
    printf("Enter interval [a, b]: ");
    scanf("%lf %lf", &a, &b);

    fa = f(a);
    fb = f(b);

    if (fa * fb > 0) {
        printf("Invalid interval: f(a) and f(b) must have opposite signs.\n");
        return -1;
    }

    printf("\ni\t a\t b\t c\t f(c)\n");

    while (i <= maxIter) {
        c = (a + b) / 2.0;
        fc = f(c);

        printf("%d\t%.6f\t%.6f\t%.6f\t%.6f\n", i, a, b, c, fc);

        if (fabs(fc) < error) {
            printf("\nRoot found at x = %.6f\n", c);
            break;
        }

        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }

        i++;
    }

    if (i > maxIter) {
        printf("\nMethod did not converge within max iterations.\n");
    }

    return 0;
}