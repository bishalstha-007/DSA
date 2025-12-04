#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n = 3, *ptr;
    int sum = 0;

    // Allocate memory for 5 integers
    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory not allocated.\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }

    printf("\nElements are:\n");
    for (i = 0; i < n; i++)
    {
        printf("ptr[%d] = %d at location %p\n", i, ptr[i], &ptr[i]);
        sum += ptr[i];
    }
    printf("Sum of elements = %d\n", sum);

    // Reallocate for 6 integers
    n = 4;
    int *temp = realloc(ptr, n * sizeof(int));
    if (temp == NULL)
    {
        printf("Memory not reallocated.\n");
        free(ptr);
        return 1;
    }
    ptr = temp;

    printf("\nEnter 1 more integer:\n");
    for (i = 3; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }

    sum = 0; // reset sum
    printf("\nReallocated elements:\n");
    for (i = 0; i < n; i++)
    {
        printf("ptr[%d] = %d at location %p\n", i, ptr[i], (void *)&ptr[i]);
        sum += ptr[i];
    }
    printf("New sum = %d\n", sum);

    free(ptr);
    return 0;
}