// =======================================================
// SUPER TRUNFO - PROJETO FINAL COMPLETO
// Linguagem: C
// =======================================================

#include <stdio.h>
#include <string.h>

// =======================================================
// STRUCT
// =======================================================

struct Carta
{
    char estado;
    char codigo[4];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos;

    float densidade;
};

// =======================================================
// CALCULAR DENSIDADE
// =======================================================

void calcularDensidade(struct Carta *c)
{
    c->densidade = c->populacao / c->area;
}

// =======================================================
// MENU DINAMICO
// =======================================================

void menu(int bloqueado)
{

    printf("\nEscolha um atributo:\n");

    if (bloqueado != 1)
        printf("1 - Populacao\n");

    if (bloqueado != 2)
        printf("2 - Area\n");

    if (bloqueado != 3)
        printf("3 - PIB\n");

    if (bloqueado != 4)
        printf("4 - Pontos Turisticos\n");

    if (bloqueado != 5)
        printf("5 - Densidade\n");

    printf("Opcao: ");
}

// =======================================================
// OBTER VALOR
// =======================================================

float valor(struct Carta c, int op)
{

    switch (op)
    {

    case 1:
        return c.populacao;

    case 2:
        return c.area;

    case 3:
        return c.pib;

    case 4:
        return c.pontos;

    case 5:
        return c.densidade;
    }

    return 0;
}

// =======================================================
// NOME ATRIBUTO
// =======================================================

char nome[5][30] = {
    "",
    "Populacao",
    "Area",
    "PIB",
    "Pontos Turisticos",
    "Densidade"};

// =======================================================
// MAIN
// =======================================================

int main()
{

    struct Carta c1, c2;

    // ===================================================
    // CADASTRO
    // ===================================================

    printf("=== CARTA 1 ===\n");

    printf("Estado: ");
    scanf(" %c", &c1.estado);

    printf("Codigo: ");
    scanf("%s", c1.codigo);

    printf("Cidade: ");
    scanf(" %[^\n]", c1.cidade);

    printf("Populacao: ");
    scanf("%d", &c1.populacao);

    printf("Area: ");
    scanf("%f", &c1.area);

    printf("PIB: ");
    scanf("%f", &c1.pib);

    printf("Pontos Turisticos: ");
    scanf("%d", &c1.pontos);

    calcularDensidade(&c1);

    printf("\n=== CARTA 2 ===\n");

    printf("Estado: ");
    scanf(" %c", &c2.estado);

    printf("Codigo: ");
    scanf("%s", c2.codigo);

    printf("Cidade: ");
    scanf(" %[^\n]", c2.cidade);

    printf("Populacao: ");
    scanf("%d", &c2.populacao);

    printf("Area: ");
    scanf("%f", &c2.area);

    printf("PIB: ");
    scanf("%f", &c2.pib);

    printf("Pontos Turisticos: ");
    scanf("%d", &c2.pontos);

    calcularDensidade(&c2);

    // ===================================================
    // ESCOLHER ATRIBUTOS
    // ===================================================

    int a1, a2;

    menu(0);
    scanf("%d", &a1);

    menu(a1);
    scanf("%d", &a2);

    if (a1 == a2)
    {

        printf("Erro: atributos iguais!\n");
        return 0;
    }

    // ===================================================
    // VALORES
    // ===================================================

    float v11 = valor(c1, a1);
    float v12 = valor(c1, a2);

    float v21 = valor(c2, a1);
    float v22 = valor(c2, a2);

    // regra densidade

    float s1 = (a1 == 5 ? -v11 : v11) + (a2 == 5 ? -v12 : v12);
    float s2 = (a1 == 5 ? -v21 : v21) + (a2 == 5 ? -v22 : v22);

    // soma real

    float soma1 = v11 + v12;
    float soma2 = v21 + v22;

    // ===================================================
    // RESULTADO
    // ===================================================

    printf("\n===== RESULTADO =====\n");

    printf("\n%s:\n", c1.cidade);
    printf("%s: %.2f\n", nome[a1], v11);
    printf("%s: %.2f\n", nome[a2], v12);
    printf("Soma: %.2f\n", soma1);

    printf("\n%s:\n", c2.cidade);
    printf("%s: %.2f\n", nome[a1], v21);
    printf("%s: %.2f\n", nome[a2], v22);
    printf("Soma: %.2f\n", soma2);

    // operador ternario

    printf("\nVencedor: %s\n",
           (s1 > s2) ? c1.cidade : (s2 > s1) ? c2.cidade
                                             : "Empate");

    return 0;
}
