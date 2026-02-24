#include <stdio.h>

struct Carta {
    char estado;
    char codigo[5];
    char nomecidade[50];
    int opcao;
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

    printf("Codigo:\n ");
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

    printf("Codigo:\n ");
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

    // ================= MENU DE COMPARAÇÃO =================

int atributo1, atributo2;
float valor1_c1 = 0, valor1_c2 = 0;
float valor2_c1 = 0, valor2_c2 = 0;
float soma1 = 0, soma2 = 0;

printf("\n=== MENU DE COMPARACAO ===\n");
printf("1 - Populacao\n");
printf("2 - Area\n");
printf("3 - PIB\n");
printf("4 - Pontos Turisticos\n");
printf("5 - Densidade Demografica\n");

printf("Escolha o PRIMEIRO atributo: ");
scanf("%d", &atributo1);

// Validação básica
if (atributo1 < 1 || atributo1 > 5) {
    printf("Opcao invalida!\n");
    return 0;
}

// ===== MENU DINÂMICO PARA SEGUNDO ATRIBUTO =====

printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");

switch(atributo1) {
    case 1:
        printf("2 - Area\n3 - PIB\n4 - Pontos Turisticos\n5 - Densidade Demografica\n");
        break;
    case 2:
        printf("1 - Populacao\n3 - PIB\n4 - Pontos Turisticos\n5 - Densidade Demografica\n");
        break;
    case 3:
        printf("1 - Populacao\n2 - Area\n4 - Pontos Turisticos\n5 - Densidade Demografica\n");
        break;
    case 4:
        printf("1 - Populacao\n2 - Area\n3 - PIB\n5 - Densidade Demografica\n");
        break;
    case 5:
        printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Pontos Turisticos\n");
        break;
}

scanf("%d", &atributo2);

// Impede escolha repetida
if (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 5) {
    printf("Opcao invalida!\n");
    return 0;
}

// ===== FUNÇÃO DE SELEÇÃO VIA SWITCH =====

switch(atributo1) {
    case 1:
        valor1_c1 = carta1.populacao;
        valor1_c2 = carta2.populacao;
        break;
    case 2:
        valor1_c1 = carta1.area;
        valor1_c2 = carta2.area;
        break;
    case 3:
        valor1_c1 = carta1.pib;
        valor1_c2 = carta2.pib;
        break;
    case 4:
        valor1_c1 = carta1.pontoturistico;
        valor1_c2 = carta2.pontoturistico;
        break;
    case 5:
        valor1_c1 = carta1.densidade;
        valor1_c2 = carta2.densidade;
        break;
}

switch(atributo2) {
    case 1:
        valor2_c1 = carta1.populacao;
        valor2_c2 = carta2.populacao;
        break;
    case 2:
        valor2_c1 = carta1.area;
        valor2_c2 = carta2.area;
        break;
    case 3:
        valor2_c1 = carta1.pib;
        valor2_c2 = carta2.pib;
        break;
    case 4:
        valor2_c1 = carta1.pontoturistico;
        valor2_c2 = carta2.pontoturistico;
        break;
    case 5:
        valor2_c1 = carta1.densidade;
        valor2_c2 = carta2.densidade;
        break;
}

// ===== REGRA ESPECIAL DENSIDADE =====

if (atributo1 == 5) {
    valor1_c1 = 1 / valor1_c1;
    valor1_c2 = 1 / valor1_c2;
}

if (atributo2 == 5) {
    valor2_c1 = 1 / valor2_c1;
    valor2_c2 = 1 / valor2_c2;
}

// ===== SOMA DOS ATRIBUTOS =====

soma1 = valor1_c1 + valor2_c1;
soma2 = valor1_c2 + valor2_c2;

// ===== EXIBIÇÃO DO RESULTADO =====

printf("\n=== RESULTADO DA RODADA ===\n");
printf("Carta 1: %s\n", carta1.nomecidade);
printf("Carta 2: %s\n\n", carta2.nomecidade);

printf("Soma dos atributos:\n");
printf("%s: %.2f\n", carta1.nomecidade, soma1);
printf("%s: %.2f\n\n", carta2.nomecidade, soma2);

// ===== OPERADOR TERNÁRIO PARA DEFINIR VENCEDOR =====

if (soma1 == soma2) {
    printf("Empate!\n");
} else {
    char *vencedor = (soma1 > soma2) ? carta1.nomecidade : carta2.nomecidade;
    printf("Vencedor: %s\n", vencedor);
}
}
}

