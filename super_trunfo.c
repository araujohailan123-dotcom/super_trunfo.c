#include <stdio.h>

struct Carta {
    char estado;
    char codigo[5];
    char nomecidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontoturistico;
    float densidade;
    float pibPerCapita;
    float superPoder;
};

float calcularDensidade(unsigned long int populacao, float area) {
    return (float)populacao / area;
}

float calcularPibPerCapita(float pib, unsigned long int populacao) {
    return pib / (float)populacao;
}

float calcularSuperPoder(struct Carta c) {
    return (float)c.populacao +
           c.area +
           c.pib +
           c.pontoturistico +
           c.pibPerCapita +
           (1.0f / c.densidade);
}

int main() {

    struct Carta carta1, carta2;

    // Carta 1
    printf("=-= Cadastro da Carta 01 =-=\n");
    printf("Estado: ");
    scanf(" %c", &carta1.estado);

    printf("Codigo: ");
    scanf("%4s", carta1.codigo);

    printf("Nome da cidade: ");
    scanf(" %49[^\n]", carta1.nomecidade);

    printf("Populacao: ");
    scanf("%lu", &carta1.populacao);

    printf("Area: ");
    scanf("%f", &carta1.area);

    printf("PIB: ");
    scanf("%f", &carta1.pib);

    printf("Pontos turisticos: ");
    scanf("%d", &carta1.pontoturistico);

    carta1.densidade = calcularDensidade(carta1.populacao, carta1.area);
    carta1.pibPerCapita = calcularPibPerCapita(carta1.pib, carta1.populacao);
    carta1.superPoder = calcularSuperPoder(carta1);

    // Carta 2
    printf("\n=-= Cadastro da Carta 02 =-=\n");
    printf("Estado: ");
    scanf(" %c", &carta2.estado);

    printf("Codigo: ");
    scanf("%4s", carta2.codigo);

    printf("Nome da cidade: ");
    scanf(" %49[^\n]", carta2.nomecidade);

    printf("Populacao: ");
    scanf("%lu", &carta2.populacao);

    printf("Area: ");
    scanf("%f", &carta2.area);

    printf("PIB: ");
    scanf("%f", &carta2.pib);

    printf("Pontos turisticos: ");
    scanf("%d", &carta2.pontoturistico);

    carta2.densidade = calcularDensidade(carta2.populacao, carta2.area);
    carta2.pibPerCapita = calcularPibPerCapita(carta2.pib, carta2.populacao);
    carta2.superPoder = calcularSuperPoder(carta2);

    // Comparações
    printf("\n=== Comparacao de Cartas ===\n");

    printf("Populacao: Carta 1 venceu (%d)\n",
           carta1.populacao > carta2.populacao);

    printf("Area: Carta 1 venceu (%d)\n",
           carta1.area > carta2.area);

    printf("PIB: Carta 1 venceu (%d)\n",
           carta1.pib > carta2.pib);

    printf("Pontos Turisticos: Carta 1 venceu (%d)\n",
           carta1.pontoturistico > carta2.pontoturistico);

    printf("Densidade Populacional: Carta 1 venceu (%d)\n",
           carta1.densidade < carta2.densidade);

    printf("PIB per Capita: Carta 1 venceu (%d)\n",
           carta1.pibPerCapita > carta2.pibPerCapita);

    printf("Super Poder: Carta 1 venceu (%d)\n",
           carta1.superPoder > carta2.superPoder);

    return 0;
}
