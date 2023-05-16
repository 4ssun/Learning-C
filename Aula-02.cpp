#include <stdio.h>
#include <stdlib.h>
int main()
{
    double Sal_Future, current;
    double raise;
    printf("What's your present salary\n");
    scanf("%f", &current);
    raise = current * 0.125;
    Sal_Future = current + raise;
    printf("your new payment will be: %.2f \n", Sal_Future);
    system("pause");
    return 0;
}