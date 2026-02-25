// ==========================================================
// SUPER TRUNFO - PAISES FICTICIOS (VERSAO INTERMEDIARIA)
// Linguagem: C++
// Autor: SeuNome
// Descricao: Menu interativo com switch e comparacao de cartas
// ==========================================================

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// ==========================================================
// ESTRUTURA DA CARTA
// ==========================================================

struct Carta
{
    string pais;
    string codigo;
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;

    float densidade;
};

// ==========================================================
// CALCULAR DENSIDADE DEMOGRAFICA
// ==========================================================

void calcularDensidade(Carta &c)
{
    c.densidade = c.populacao / c.area;
}

// ==========================================================
// MOSTRAR MENU
// ==========================================================

void mostrarMenu()
{
    cout << "\n====== SUPER TRUNFO ======\n";
    cout << "Escolha o atributo para comparacao:\n";
    cout << "1 - Populacao\n";
    cout << "2 - Area\n";
    cout << "3 - PIB\n";
    cout << "4 - Pontos Turisticos\n";
    cout << "5 - Densidade Demografica\n";
    cout << "Opcao: ";
}

// ==========================================================
// FUNCAO PRINCIPAL
// ==========================================================

int main()
{

    // ======================================================
    // CARTAS FIXAS (PAISES FICTICIOS)
    // ======================================================

    Carta carta1 = {
        "Zetherland",
        "ZT01",
        700000,
        350000.0,
        900000000.0,
        25};

    Carta carta2 = {
        "Arkadia",
        "AR02",
        500000,
        200000.0,
        600000000.0,
        30};

    // calcular densidade

    calcularDensidade(carta1);
    calcularDensidade(carta2);

    int opcao;

    mostrarMenu();
    cin >> opcao;

    cout << fixed << setprecision(2);

    // ======================================================
    // SWITCH MENU
    // ======================================================

    switch (opcao)
    {

    case 1:

        cout << "\nComparacao por Populacao\n";

        cout << carta1.pais << ": " << carta1.populacao << endl;
        cout << carta2.pais << ": " << carta2.populacao << endl;

        if (carta1.populacao > carta2.populacao)
        {

            cout << "Vencedor: " << carta1.pais << endl;
        }
        else if (carta2.populacao > carta1.populacao)
        {

            cout << "Vencedor: " << carta2.pais << endl;
        }
        else
        {

            cout << "Empate!\n";
        }

        break;

    case 2:

        cout << "\nComparacao por Area\n";

        cout << carta1.pais << ": " << carta1.area << endl;
        cout << carta2.pais << ": " << carta2.area << endl;

        if (carta1.area > carta2.area)
        {

            cout << "Vencedor: " << carta1.pais << endl;
        }
        else if (carta2.area > carta1.area)
        {

            cout << "Vencedor: " << carta2.pais << endl;
        }
        else
        {

            cout << "Empate!\n";
        }

        break;

    case 3:

        cout << "\nComparacao por PIB\n";

        cout << carta1.pais << ": " << carta1.pib << endl;
        cout << carta2.pais << ": " << carta2.pib << endl;

        if (carta1.pib > carta2.pib)
        {

            cout << "Vencedor: " << carta1.pais << endl;
        }
        else if (carta2.pib > carta1.pib)
        {

            cout << "Vencedor: " << carta2.pais << endl;
        }
        else
        {

            cout << "Empate!\n";
        }

        break;

    case 4:

        cout << "\nComparacao por Pontos Turisticos\n";

        cout << carta1.pais << ": " << carta1.pontosTuristicos << endl;
        cout << carta2.pais << ": " << carta2.pontosTuristicos << endl;

        if (carta1.pontosTuristicos > carta2.pontosTuristicos)
        {

            cout << "Vencedor: " << carta1.pais << endl;
        }
        else if (carta2.pontosTuristicos > carta1.pontosTuristicos)
        {

            cout << "Vencedor: " << carta2.pais << endl;
        }
        else
        {

            cout << "Empate!\n";
        }

        break;

    case 5:

        cout << "\nComparacao por Densidade Demografica\n";

        cout << carta1.pais << ": " << carta1.densidade << endl;
        cout << carta2.pais << ": " << carta2.densidade << endl;

        // REGRA INVERTIDA

        if (carta1.densidade < carta2.densidade)
        {

            cout << "Vencedor: " << carta1.pais << endl;
        }
        else if (carta2.densidade < carta1.densidade)
        {

            cout << "Vencedor: " << carta2.pais << endl;
        }
        else
        {

            cout << "Empate!\n";
        }

        break;

    default:

        cout << "\nOpcao invalida!\n";
    }

    return 0;
}
