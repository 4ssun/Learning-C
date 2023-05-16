#include <stdio.h>
#include <math.h>

double calcularParcelas(double valorEmprestimo, double juro, int numMeses);
double calcularPotencia(double base, int expoente);

int main() {
    double valorEmprestimo, juro;
    int numMeses;

    printf("Informe o valor do emprestimo: ");
    scanf("%lf", &valorEmprestimo);

    printf("Informe o juro (em percentual): ");
    scanf("%lf", &juro);

    printf("Informe o numero de meses para pagar: ");
    scanf("%d", &numMeses);

    double valorParcela = calcularParcelas(valorEmprestimo, juro, numMeses);

    printf("Valor das parcelas iguais é de R$ %.2lf\n", valorParcela);

    return 0;
}

double calcularParcelas(double valorEmprestimo, double juro, int numMeses) {
    double taxaJuro = juro / 100.0;
    double parcelaIgual = valorEmprestimo * (calcularPotencia((1 + taxaJuro), numMeses) * taxaJuro) / (calcularPotencia((1 + taxaJuro), numMeses) - 1);
    return parcelaIgual;
}

double calcularPotencia(double base, int expoente) {
    double resultado = 1.0;
    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }
    return resultado;
}

