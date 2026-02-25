// ==========================================================
// SUPER TRUNFO - PAISES (VERSAO FINAL AVANCADA)
// Linguagem: C++
// Autor: SeuNome
// ==========================================================

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// ==========================================================
// ESTRUTURA
// ==========================================================

struct Carta
{
    string pais;
    int populacao;
    float area;
    float pib;
    int pontos;
    float densidade;
};

// ==========================================================
// CALCULAR DENSIDADE
// ==========================================================

void calcularDensidade(Carta &c)
{
    c.densidade = c.populacao / c.area;
}

// ==========================================================
// MOSTRAR MENU DINAMICO
// ==========================================================

void mostrarMenu(int atributoBloqueado)
{

    cout << "\nEscolha um atributo:\n";

    if (atributoBloqueado != 1)
        cout << "1 - Populacao\n";

    if (atributoBloqueado != 2)
        cout << "2 - Area\n";

    if (atributoBloqueado != 3)
        cout << "3 - PIB\n";

    if (atributoBloqueado != 4)
        cout << "4 - Pontos Turisticos\n";

    if (atributoBloqueado != 5)
        cout << "5 - Densidade Demografica\n";

    cout << "Opcao: ";
}

// ==========================================================
// OBTER VALOR ATRIBUTO
// ==========================================================

float obterValor(Carta c, int atributo)
{

    switch (atributo)
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

    default:
        return 0;
    }
}

// ==========================================================
// OBTER NOME
// ==========================================================

string nomeAtributo(int atributo)
{

    switch (atributo)
    {

    case 1:
        return "Populacao";

    case 2:
        return "Area";

    case 3:
        return "PIB";

    case 4:
        return "Pontos Turisticos";

    case 5:
        return "Densidade Demografica";

    default:
        return "Erro";
    }
}

// ==========================================================
// MAIN
// ==========================================================

int main()
{

    cout << fixed << setprecision(2);

    // ======================================================
    // CARTAS
    // ======================================================

    Carta carta1 = {"Zetherland", 800000, 400000, 900000000, 20};
    Carta carta2 = {"Arkadia", 600000, 300000, 700000000, 30};

    calcularDensidade(carta1);
    calcularDensidade(carta2);

    int attr1, attr2;

    // ======================================================
    // ESCOLHA ATRIBUTO 1
    // ======================================================

    mostrarMenu(0);
    cin >> attr1;

    // ======================================================
    // ESCOLHA ATRIBUTO 2
    // ======================================================

    mostrarMenu(attr1);
    cin >> attr2;

    if (attr1 == attr2)
    {

        cout << "\nErro: atributos iguais!\n";
        return 0;
    }

    // ======================================================
    // OBTER VALORES
    // ======================================================

    float v1_attr1 = obterValor(carta1, attr1);
    float v2_attr1 = obterValor(carta2, attr1);

    float v1_attr2 = obterValor(carta1, attr2);
    float v2_attr2 = obterValor(carta2, attr2);

    // ======================================================
    // REGRA DENSIDADE
    // ======================================================

    float soma1 = 0;
    float soma2 = 0;

    soma1 += (attr1 == 5) ? -v1_attr1 : v1_attr1;
    soma2 += (attr1 == 5) ? -v2_attr1 : v2_attr1;

    soma1 += (attr2 == 5) ? -v1_attr2 : v1_attr2;
    soma2 += (attr2 == 5) ? -v2_attr2 : v2_attr2;

    // ======================================================
    // EXIBIR RESULTADO
    // ======================================================

    cout << "\n===== RESULTADO =====\n";

    cout << "\nPais 1: " << carta1.pais << endl;
    cout << "Pais 2: " << carta2.pais << endl;

    cout << "\nAtributo 1: " << nomeAtributo(attr1) << endl;

    cout << carta1.pais << ": " << v1_attr1 << endl;
    cout << carta2.pais << ": " << v2_attr1 << endl;

    cout << "\nAtributo 2: " << nomeAtributo(attr2) << endl;

    cout << carta1.pais << ": " << v1_attr2 << endl;
    cout << carta2.pais << ": " << v2_attr2 << endl;

    // ======================================================
    // SOMA REAL
    // ======================================================

    float somaReal1 = v1_attr1 + v1_attr2;
    float somaReal2 = v2_attr1 + v2_attr2;

    cout << "\nSoma " << carta1.pais << ": " << somaReal1 << endl;
    cout << "Soma " << carta2.pais << ": " << somaReal2 << endl;

    // ======================================================
    // VENCEDOR COM OPERADOR TERNARIO
    // ======================================================

    cout << "\n";

    if (soma1 > soma2)
        cout << "Vencedor: " << carta1.pais;
    else if (soma2 > soma1)
        cout << "Vencedor: " << carta2.pais;
    else
        cout << "Empate!";

    cout << endl;

    return 0;
}
