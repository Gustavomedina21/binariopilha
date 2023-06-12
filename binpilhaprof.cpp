#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Defini��o da estrutura da pilha
struct PILHA
{
    int num;
    PILHA *prox;
};

// Fun��o para criar um novo n� da pilha
PILHA* criarNo(int valor)
{
    PILHA* novo = (PILHA*)malloc(sizeof(PILHA));
    novo->num = valor;
    novo->prox = NULL;
    return novo;
}

// Fun��o para empilhar um elemento na pilha
void empilhar(PILHA** topo, int valor)
{
    PILHA* novo = criarNo(valor);
    novo->prox = *topo;
    *topo = novo;
}

// Fun��o para desempilhar um elemento da pilha
int desempilhar(PILHA** topo)
{
    if (*topo == NULL)
    {
        printf("A pilha est� vazia.\n");
        return -1;
    }

    PILHA* temp = *topo;
    *topo = (*topo)->prox;
    int valor = temp->num;
    free(temp);
    return valor;
}

// Fun��o para converter um n�mero decimal para bin�rio
void decimalParaBinario(int numero)
{
    PILHA* topo = NULL;

    // Caso especial quando o n�mero � 0
    if (numero == 0)
    {
        empilhar(&topo, 0);
    }
    else
    {
        // Realiza a convers�o do n�mero decimal para bin�rio
        while (numero > 0)
        {
            int resto = numero % 2;
            empilhar(&topo, resto);
            numero = numero / 2;
        }
    }

    // Imprime os d�gitos bin�rios armazenados na pilha
    printf("Bin�rio: ");
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

    // Solicita ao usu�rio que digite um n�mero decimal
    printf("Digite um n�mero decimal: ");
    scanf("%d", &numero);

    // Converte o n�mero decimal para bin�rio e imprime o resultado
    decimalParaBinario(numero);

    return 0;
}

