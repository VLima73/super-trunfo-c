#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[3];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
} Carta;

void calcular_atributos(Carta *c) {
    c->densidade = c->populacao / c->area;
    c->pib_per_capita = c->pib / c->populacao;
}

void comparar_cartas(Carta c1, Carta c2, int atributo) {
    printf("\nComparação entre %s e %s\n", c1.cidade, c2.cidade);

    switch (atributo) {
        case 1:
            printf("Atributo: População\n");
            if (c1.populacao > c2.populacao)
                printf("Vencedora: %s\n", c1.cidade);
            else if (c2.populacao > c1.populacao)
                printf("Vencedora: %s\n", c2.cidade);
            else
                printf("Empate!\n");
            break;

        case 2:
            printf("Atributo: Área\n");
            if (c1.area > c2.area)
                printf("Vencedora: %s\n", c1.cidade);
            else if (c2.area > c1.area)
                printf("Vencedora: %s\n", c2.cidade);
            else
                printf("Empate!\n");
            break;

        case 3:
            printf("Atributo: PIB\n");
            if (c1.pib > c2.pib)
                printf("Vencedora: %s\n", c1.cidade);
            else if (c2.pib > c1.pib)
                printf("Vencedora: %s\n", c2.cidade);
            else
                printf("Empate!\n");
            break;

        case 4:
            printf("Atributo: Pontos Turísticos\n");
            if (c1.pontos_turisticos > c2.pontos_turisticos)
                printf("Vencedora: %s\n", c1.cidade);
            else if (c2.pontos_turisticos > c1.pontos_turisticos)
                printf("Vencedora: %s\n", c2.cidade);
            else
                printf("Empate!\n");
            break;

        case 5:
            printf("Atributo: Densidade Demográfica (menor vence)\n");
            if (c1.densidade < c2.densidade)
                printf("Vencedora: %s\n", c1.cidade);
            else if (c2.densidade < c1.densidade)
                printf("Vencedora: %s\n", c2.cidade);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Atributo inválido!\n");
    }
}

int main() {
    Carta carta1 = {"SP", "A01", "São Paulo", 12300000, 1521.11, 828.0, 25};
    Carta carta2 = {"RJ", "B02", "Rio de Janeiro", 6000000, 1200.27, 410.0, 18};

    calcular_atributos(&carta1);
    calcular_atributos(&carta2);

    int opcao;

    printf("Escolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    comparar_cartas(carta1, carta2, opcao);

    return 0;
}
