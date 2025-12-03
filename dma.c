#include<stdio.h>
#include<stdlib.h>
int main() {
    int i, n, *ptr ;
    printf("Enter the number of elements:");
    scanf("%d", &n) ;
    
    // malloc
    ptr = (int*) malloc(n*sizeof(int));

    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        return 1;
    }

    for(i=0; i<n; i++) {
        scanf("%d", &ptr[i]);
    }

    printf("The elements are:\n");
    
    for(i=0; i<n; i++) {
        printf("ptr[%d] = %d at location of %d\n", i, ptr[i], &ptr[i]);
    }

    free(ptr);
    return 0 ;
}