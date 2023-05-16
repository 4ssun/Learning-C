#include <stdio.h>
#include <stdlib.h>

// Declaração de subprogramas
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

    // Verificar o primeiro dígito
    int primeiroDigito = Digito1(num_CPF);

    // Verificar o segundo dígito
    int segundoDigito = Digito2(num_CPF, primeiroDigito);

    // Verificar se o CPF é válido
    if (primeiroDigito == num_CPF[9] && segundoDigito == num_CPF[10]) {
        printf("CPF valido!\n");
    } else {
        printf("CPF invalido!\n");
    }

    return 0;
}

// Função para contar dígitos do CPF
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

// Função para retornar o primeiro dígito verificador
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


// Função para retornar o segundo dígito verificador
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

// Professor, meu código continua dando erro na validação dos dois ultimos digitos, já fiz e refiz, fui em Stackoverflow, chatgpt e não achei o motivo, tudo declarado direito e com seus valores corretos, mas ainda quando dou um CPF Válido e real o programa retorna falso!

