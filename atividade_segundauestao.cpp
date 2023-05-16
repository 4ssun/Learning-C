#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h" // Não salvei como filaVetor e sim apenas como fila.h !!!!
#define fim 21600 // 6 horas de expediente no banco

int clienteChegou(void);
int transacao(void);

// programa principal
int main()
{
    int guiches[3], crono = 0, n_cliente = 0, i;
    float t_espera = 0.0;
    Fila fila;

    srand(time(NULL));

    inicFila(&fila); // 1) iniciar a fila

    for (i = 0; i < 3; i++)
        guiches[i] = 0; // 2) iniciar os guiches de valor zero

    
    while (crono < fim || !filaVazia(&fila)) // 3) Enquanto não terminar o expediente ou fila com gente:
    {
        if (clienteChegou() && crono < fim) // a) se um cliente chegou e não terminou o expediente, entra na fila
        {
            insereFila(&fila, crono);
            n_cliente++;
        }

        for (i = 0; i < 3; i++)
        {
            if (guiches[i] == 0 && !filaVazia(&fila)) // b) Para 3 guiches: Se há guichê livre e a fila não está vazia, clientes saem da fila e vão ser atendidos
            {
                int inicio_fila = removeFila(&fila);
                int tempo_espera = crono - inicio_fila;
                t_espera += tempo_espera;

                int tempo_transacao = transacao();
                guiches[i] = tempo_transacao;
            }
        }

        for (i = 0; i < 3; i++) // c) Para 3 guiches: Decrementar o tempo de uso de cada guichê ocupado
        {
            if (guiches[i] > 0)
                guiches[i]--;
        }

        crono++; // d) incrementar o cronômetro
    }

    // 4) Mostrar os resultados
    printf("Total de clientes atendidos: %d\n", n_cliente);
    printf("Tempo médio de espera na fila: %.2f segundos\n", t_espera / n_cliente);
    printf("Tempo extra de expediente: %d segundos\n", crono - fim);

    system("pause");
    return 0;
}

// subprograma como função para simular chegada de um cliente
int clienteChegou(void)
{
    int num;
    num = rand() % 30;
    if (num == 0) // probabilidade de chegar um cliente é 1/30
        return 1;
    else
        return 0;
}

// subprograma como função para operação de transação

int transacao(void)
{
    int num = rand() % 3;
    if (num == 0)
        return 60; // efetuar um saque - 60 segundos
    else if (num == 1)
        return 90; // efetuar um depósito - 90 segundos
    else if (num == 2)
        return 120; // efetuar um pagamento - 120 segundos
}

