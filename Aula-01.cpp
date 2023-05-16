#include <stdio.h> /* biblioteca de entrada e saída*/
#include <stdlib.h>
int main()
{
    double num1, num2;
    double result;
    printf("Put the numbers bellow: \n");
    scanf("%d%d", &num1, &num2);
    // User will put a number type integer and num1 will receive it.
    result = num1 + num2;
    printf("%d + %d is equal to %d\n", num1, num2, result);
    system("pause");
}

/* Essa foi a primeira aula, fazendo o clássico exercício de começo de manipulação de operações matemáticas.*/