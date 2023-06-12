#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Definição da estrutura da pilha
struct PILHA
{
    int num;
    PILHA *prox;
};

// Função para criar um novo nó da pilha
PILHA* criarNo(int valor)
{
    PILHA* novo = (PILHA*)malloc(sizeof(PILHA));
    novo->num = valor;
    novo->prox = NULL;
    return novo;
}

// Função para empilhar um elemento na pilha
void empilhar(PILHA** topo, int valor)
{
    PILHA* novo = criarNo(valor);
    novo->prox = *topo;
    *topo = novo;
}

// Função para desempilhar um elemento da pilha
int desempilhar(PILHA** topo)
{
    if (*topo == NULL)
    {
        printf("A pilha está vazia.\n");
        return -1;
    }

    PILHA* temp = *topo;
    *topo = (*topo)->prox;
    int valor = temp->num;
    free(temp);
    return valor;
}

// Função para converter um número decimal para binário
void decimalParaBinario(int numero)
{
    PILHA* topo = NULL;

    // Caso especial quando o número é 0
    if (numero == 0)
    {
        empilhar(&topo, 0);
    }
    else
    {
        // Realiza a conversão do número decimal para binário
        while (numero > 0)
        {
            int resto = numero % 2;
            empilhar(&topo, resto);
            numero = numero / 2;
        }
    }

    // Imprime os dígitos binários armazenados na pilha
    printf("Binário: ");
    while (topo != NULL)
    {
        int digito = desempilhar(&topo);
        printf("%d", digito);
    }
    printf("\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int numero;

    // Solicita ao usuário que digite um número decimal
    printf("Digite um número decimal: ");
    scanf("%d", &numero);

    // Converte o número decimal para binário e imprime o resultado
    decimalParaBinario(numero);

    return 0;
}

