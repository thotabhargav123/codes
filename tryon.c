#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    // int n = 10;
    // double m = 100.26;
    // printf("The numbers are %d and %10.2f \n", n, m);
    // double a, b, c, d;
    // printf("Enter the four numbers: ");
    // scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    // // printf("The numbers are %f and %f and %f and  %f", a, b, c, d);
    // char sstring[100];
    // printf("Enter the string \n");
    // fgets(sstring, 100, stdin);
    // int len = strlen(sstring);
    // printf("%s", sstring);
    // printf("The lenght of string is %d", len);
    char a, b;
    printf("Enter first Number:");
    scanf("%c", &a);
    printf("Enter second Number:");
    getchar();
    scanf("%c", &b);
    printf("The result is %c %c", a, b);
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
}