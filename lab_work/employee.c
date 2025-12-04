#include <stdio.h>
#include <string.h>

struct employee
{
    char name[50], address[50];
    int age;
    float salary;
};

int main() {
    int n, i;
    float total=0, avg ;

    printf("Enter the number:");
    scanf("%d", &n);

    struct employee e[n];

    for (i=0; i<n; i++) {
        printf("Name:");
        scanf("%s",e[i].name);-

        printf("Address:");
        scanf("%s",e[i].address);

        printf("Age:");
        scanf("%d",&e[i].age);

        printf("Salary:");
        scanf("%f",&e[i].salary);

        total+= e[i].salary;
    }

    avg = total / n;
    printf("Average salary of %d employee is %.2f", n, avg);
    return 0;

}