/* Calcular aumento de salário */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int num1, num2;
    num1 = rand() % 13 + 2; // Ele vai gerar um número até 12 e soma-se 2 para atingir 14.No exemplo,estamos usando cartas.
    num2 = rand() % 13 + 2;

    if (num1 > num2)
    {
        printf("Jogador A tirou: %d e ganha de jogador B que tirou %d \n", num1, num2);
    }
    if (num2 > num1)
    {
        printf("Jogador B tirou: %d e ganha de jogador A que tirou %d \n", num2, num1);
    }
    if (num1 == num2)
    {
        printf("Numeros iguais! %d,%d \n", num1, num2);
    }
    system("pause");
    return 0;
}
