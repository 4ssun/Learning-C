#include <stdio.h>
#include <stdlib.h>

/* Faça um programa em C que receba o salário atual de um funcionário de uma empresa e calcule o salário atualizado de acordo com a faixa salarial:
Para o salário menor ou igual a 2.500 o aumento será de 21.45%
Para o salário maior do que 2500, mas menor de 5500 o aumento será de 13,55%
Para salário maior ou igual a 5500 o aumento será de 10,5%
*/
int main()
{
    double Salario, Atualizado;
    char nome[30];
    printf("Qual o seu nome?\n");
    fgets(nome, sizeof(nome), stdin);
    printf("Olá %s, vamos prosseguir com o cálculo.\n", nome);

    printf("Qual seu salário atual?\n");
    scanf("%f", &Salario);

    if (Salario <= 2500.0)
    {
        Atualizado = Salario + Salario * 21.45 / 100;
    }
    else
    {
        if (Salario < 5500.0)
        {
            Atualizado = Salario + Salario * 13.55 / 100;
        }
        else
        {
            Atualizado = Salario + Salario * 10.5 / 100;
        }
    }

    printf("%s, seu salário atualizado será de R$ %.2f\n", nome, Atualizado);

    system("pause");
    return 0;
}