#include <stdio.h>
#include <stdlib.h>

// Declara��o de subprogramas
void Conversaoint(char a[], int b[]);
int Contadigitos(char a[]);
int Digito1(int num[]);
int Digito2(int num[], int Di);

// Programa principal
int main() {
    char CPF[12];
    int num_CPF[11];

    printf("Digite um CPF sem pontos e/ou tracos: ");
    fgets(CPF, sizeof(CPF), stdin);

    // Converter CPF para um vetor de inteiros
    Conversaoint(CPF, num_CPF);

    // Verificar o primeiro d�gito
    int primeiroDigito = Digito1(num_CPF);

    // Verificar o segundo d�gito
    int segundoDigito = Digito2(num_CPF, primeiroDigito);

    // Verificar se o CPF � v�lido
    if (primeiroDigito == num_CPF[9] && segundoDigito == num_CPF[10]) {
        printf("CPF valido!\n");
    } else {
        printf("CPF invalido!\n");
    }

    return 0;
}

// Fun��o para contar d�gitos do CPF
int Contadigitos(char a[]) {
    int cont = 0, i = 0;

    while (a[i] != '\0' && a[i] != '\n') {
        if (a[i] >= '0' && a[i] <= '9') {
            cont++;
        }
        i++;
    }

    return cont;
}

// Procedimento para converter de string para inteiro
void Conversaoint(char a[], int b[]) {
    int i;

    for (i = 0; i < 11; i++) {
        if (a[i] >= '0' && a[i] <= '9') {
            b[i] = (int)(a[i] - '0'); // Converter char para int
        }
    }
}

// Fun��o para retornar o primeiro d�gito verificador
int Digito1(int num[]) {
    int tabela[] = {10, 9, 8, 7, 6, 5, 4, 3, 2};
    int soma = 0;

    for (int i = 0; i < 9; i++) {
        soma += num[i] * tabela[i];
    }

    int resto = soma % 11;
    int primeiroDigito;

    if (resto < 2) {
        primeiroDigito = 0;
    } else {
        primeiroDigito = 11 - resto;
    }

    return primeiroDigito;
}


// Fun��o para retornar o segundo d�gito verificador
int Digito2(int num[], int Di) {
    int tabela[] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
    int soma = 0;

    for (int i = 0; i < 10; i++) {
        soma += num[i] * tabela[i];
    }

    soma += Di * tabela[9];

    int resto = soma % 11;
    int segundoDigito;

    if (resto < 2) {
        segundoDigito = 0;
    } else {
        segundoDigito = 11 - resto;
    }

    return segundoDigito;
}

// Professor, meu c�digo continua dando erro na valida��o dos dois ultimos digitos, j� fiz e refiz, fui em Stackoverflow, chatgpt e n�o achei o motivo, tudo declarado direito e com seus valores corretos, mas ainda quando dou um CPF V�lido e real o programa retorna falso!

