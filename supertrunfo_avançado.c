#include <stdio.h>

int main() {

    // Estrutura dos dados das cartas
    char estado1, estado2;
    char cod1[4], cod2[4];
    char nome1[50], nome2[50];

    unsigned long int pop1, pop2;
    float area1, area2;
    float pib1, pib2;
    int pt1, pt2;

    // Atributos calculados
    float dens1, dens2;
    float pibcap1, pibcap2;
    float super1, super2;

    // ===============================
    // LEITURA DOS DADOS DA CARTA 1
    // ===============================
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Código da carta: ");
    scanf("%s", cod1);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nome1);

    printf("População: ");
    scanf("%lu", &pop1);

    printf("Área (km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pt1);


    // ===============================
    // LEITURA DOS DADOS DA CARTA 2
    // ===============================
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Código da carta: ");
    scanf("%s", cod2);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nome2);

    printf("População: ");
    scanf("%lu", &pop2);

    printf("Área (km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pt2);


    // ===============================
    // CÁLCULOS
    // ===============================

    dens1 = pop1 / area1;
    dens2 = pop2 / area2;

    pibcap1 = (pib1 * 1e9) / pop1;
    pibcap2 = (pib2 * 1e9) / pop2;

    // SUPER PODER:
    // soma dos atributos + PIB per capita + inverso da densidade
    super1 = (float)pop1 + area1 + pib1 + (float)pt1 + pibcap1 + (1.0f / dens1);
    super2 = (float)pop2 + area2 + pib2 + (float)pt2 + pibcap2 + (1.0f / dens2);


    // ===============================
    // COMPARAÇÕES
    // ===============================

    int cPop        = (pop1 > pop2);
    int cArea       = (area1 > area2);
    int cPib        = (pib1 > pib2);
    int cPT         = (pt1 > pt2);
    int cDens       = (dens1 < dens2);   // MENOR densidade vence!
    int cPibCap     = (pibcap1 > pibcap2);
    int cSuper      = (super1 > super2);


    // ===============================
    // RESULTADOS
    // ===============================

    printf("\n=== Comparação de Cartas ===\n");

    printf("População: Carta %d venceu (%d)\n", cPop ? 1 : 2, cPop);
    printf("Área: Carta %d venceu (%d)\n", cArea ? 1 : 2, cArea);
    printf("PIB: Carta %d venceu (%d)\n", cPib ? 1 : 2, cPib);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", cPT ? 1 : 2, cPT);

    printf("Densidade Populacional: Carta %d venceu (%d)\n",
            cDens ? 1 : 2, cDens);

    printf("PIB per Capita: Carta %d venceu (%d)\n",
            cPibCap ? 1 : 2, cPibCap);

    printf("Super Poder: Carta %d venceu (%d)\n",
            cSuper ? 1 : 2, cSuper);


    return 0;
}
