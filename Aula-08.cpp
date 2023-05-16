#include <stdio.h>
#include <stdlib.h>
int main()
{

    char nome_func[50];
    float sal_atual, sal_atualizado;

    printf("Informe seu nome: ");
    fgets(nome_func, sizeof(nome_func), stdin);
    printf("Informe seu salario atual R$ ");
    scanf("%f", sal_atual);

    if (sal_atual <= 2500.0)
    {
        sal_atualizado = sal_atual + sal_atual * 21.45 / 100;
    }
    else
    {
        if (sal_atual < 5500.0)
        {
            sal_atualizado = sal_atual + sal_atual * 13.55 / 100;
        }
        else
        {
            sal_atualizado = sal_atual + sal_atual * 10.5 / 100;
        }
    }

    printf("Seu nome: %s", nome_func);
    printf("Seu salario atualizado R$ %.2f\n", sal_atualizado);

    system("pause");
    return 0;
}