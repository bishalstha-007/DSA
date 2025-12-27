#include <stdio.h>
#include <math.h>

// Define the function using macro
#define f(x) ((x) * (x) * (x) - (x) - 2)

int main()
{
    double x0, x1, x2;
    double error = 0.0001; // tolerance (stopping condition)
    int iter = 1;

    // Input two starting guesses
    printf("Enter two guesses x0 and x1: ");
    scanf("%lf %lf", &x0, &x1);

    // Loop until root is found
    while (1)
    {
        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0)); // Secant formula

        printf("Iter %d: x2 = %.6f\n", iter, x2);

        if (fabs(f(x2)) < error)
        { // check tolerance
            printf("\nRoot found at x = %.6f\n", x2);
            break;
        }

        // Update guesses
        x0 = x1;
        x1 = x2;
        iter++;
    }

    return 0;
}