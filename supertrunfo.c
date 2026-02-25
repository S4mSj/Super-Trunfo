// ==========================================================
// SUPER TRUNFO - LOCALIDADES FICTÍCIAS
// Linguagem: C++
// Autor: SeuNome
// Descrição: Comparação de duas cartas utilizando um atributo
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
    string estado;
    string codigo;
    string cidade;
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;

    float densidade;
    float pibPerCapita;
};

// ==========================================================
// FUNÇÃO PARA CALCULAR ATRIBUTOS DERIVADOS
// ==========================================================

void calcularDados(Carta &c)
{
    c.densidade = c.populacao / c.area;
    c.pibPerCapita = c.pib / c.populacao;
}

// ==========================================================
// FUNÇÃO PARA EXIBIR CARTA
// ==========================================================

void exibirCarta(Carta c)
{
    cout << "\n=============================\n";
    cout << "Estado: " << c.estado << endl;
    cout << "Codigo: " << c.codigo << endl;
    cout << "Cidade: " << c.cidade << endl;
    cout << "Populacao: " << c.populacao << endl;
    cout << "Area: " << c.area << " km²" << endl;
    cout << "PIB: " << c.pib << endl;
    cout << "Pontos Turisticos: " << c.pontosTuristicos << endl;
    cout << fixed << setprecision(2);
    cout << "Densidade Populacional: " << c.densidade << endl;
    cout << "PIB per Capita: " << c.pibPerCapita << endl;
}

// ==========================================================
// FUNÇÃO PRINCIPAL
// ==========================================================

int main()
{

    // ======================================================
    // CARTAS FICTÍCIAS
    // ======================================================

    Carta carta1;
    carta1.estado = "Reino Solaris";
    carta1.codigo = "RS01";
    carta1.cidade = "Lumina";
    carta1.populacao = 500000;
    carta1.area = 250.5;
    carta1.pib = 900000000;
    carta1.pontosTuristicos = 15;

    Carta carta2;
    carta2.estado = "Império Nebulus";
    carta2.codigo = "IN02";
    carta2.cidade = "Nebur";
    carta2.populacao = 800000;
    carta2.area = 500.8;
    carta2.pib = 1200000000;
    carta2.pontosTuristicos = 10;

    // ======================================================
    // CALCULANDO DADOS
    // ======================================================

    calcularDados(carta1);
    calcularDados(carta2);

    // ======================================================
    // EXIBINDO CARTAS
    // ======================================================

    cout << "===== CARTA 1 =====";
    exibirCarta(carta1);

    cout << "\n===== CARTA 2 =====";
    exibirCarta(carta2);

    // ======================================================
    // ESCOLHA DO ATRIBUTO PARA COMPARAÇÃO
    // ALTERE AQUI SE QUISER COMPARAR OUTRO
    // ======================================================

    string atributo = "PIB per capita";

    cout << "\n=====================================\n";
    cout << "Comparacao de cartas (Atributo: " << atributo << ")\n\n";

    cout << "Carta 1 - " << carta1.cidade << ": "
         << carta1.pibPerCapita << endl;

    cout << "Carta 2 - " << carta2.cidade << ": "
         << carta2.pibPerCapita << endl;

    // ======================================================
    // LOGICA DE COMPARACAO
    // ======================================================

    if (carta1.pibPerCapita > carta2.pibPerCapita)
    {

        cout << "\nResultado: Carta 1 ("
             << carta1.cidade
             << ") venceu!\n";
    }
    else if (carta2.pibPerCapita > carta1.pibPerCapita)
    {

        cout << "\nResultado: Carta 2 ("
             << carta2.cidade
             << ") venceu!\n";
    }
    else
    {

        cout << "\nResultado: Empate!\n";
    }

    return 0;
}
