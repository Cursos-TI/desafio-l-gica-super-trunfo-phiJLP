#include <stdio.h>
// NIVEL AVENTUREIRO
int main() {
    // Variáveis
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char cidade1[50], cidade2[50];
    unsigned long int populacao1, populacao2;
    double area1, area2, pib1, pib2;
    int pontost1, pontost2;
    double densidade1, densidade2, pib_capital1, pib_capital2;

    // Cadastro da Carta 1
    printf("Cadastro da Carta 1\n");
    printf("Estado: ");
    scanf(" %c", &estado1);
    printf("Código: ");
    scanf(" %s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área: ");
    scanf("%lf", &area1);
    printf("PIB: ");
    scanf("%lf", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontost1);

    densidade1 = (double)populacao1 / area1;
    pib_capital1 = pib1 / (double)populacao1;

    // Cadastro da Carta 2
    printf("\nCadastro da Carta 2\n");
    printf("Estado: ");
    scanf(" %c", &estado2);
    printf("Código: ");
    scanf(" %s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área: ");
    scanf("%lf", &area2);
    printf("PIB: ");
    scanf("%lf", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontost2);

    densidade2 = (double)populacao2 / area2;
    pib_capital2 = pib2 / (double)populacao2;

    // Menu de comparação
    int opcao;
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("6 - PIB Capital\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    printf("\nComparando %s e %s\n", cidade1, cidade2);

    // Comparação
    switch (opcao) {
        case 1:
            printf("População:\n");
            printf("%s: %lu\n", cidade1, populacao1);
            printf("%s: %lu\n", cidade2, populacao2);
            if (populacao1 > populacao2) {
                printf("Resultado: VENCEU!\n", cidade1);
            } else if (populacao2 > populacao1) {
                printf("Resultado: VENCEU!\n", cidade2);
            } else {
                printf("Resultado: EMPATE!\n");
            }
            break;

        case 2:
            printf("Área:\n");
            printf("%s: %.2lf\n", cidade1, area1);
            printf("%s: %.2lf\n", cidade2, area2);
            if (area1 > area2) {
                printf("Resultado: VENCEU!\n", cidade1);
            } else if (area2 > area1) {
                printf("Resultado: VENCEU!\n", cidade2);
            } else {
                printf("Resultado: EMPATE!\n");
            }
            break;

        case 3:
            printf("PIB:\n");
            printf("%s: %.2lf\n", cidade1, pib1);
            printf("%s: %.2lf\n", cidade2, pib2);
            if (pib1 > pib2) {
                printf("Resultado: VENCEU!\n", cidade1);
            } else if (pib2 > pib1) {
                printf("Resultado: VENCEU!\n", cidade2);
            } else {
                printf("Resultado: EMPATE!\n");
            }
            break;

        case 4:
            printf("Pontos Turísticos:\n");
            printf("%s: %d\n", cidade1, pontost1);
            printf("%s: %d\n", cidade2, pontost2);
            if (pontost1 > pontost2) {
                printf("Resultado: VENCEU!\n", cidade1);
            } else if (pontost2 > pontost1) {
                printf("Resultado: VENCEU!\n", cidade2);
            } else {
                printf("Resultado: EMPATE!\n");
            }
            break;

        case 5:
            printf("Densidade:\n");
            printf("%s: %.2lf\n", cidade1, densidade1);
            printf("%s: %.2lf\n", cidade2, densidade2);
            if (densidade1 < densidade2) {
                printf("Resultado: VENCEU!\n", cidade1);
            } else if (densidade2 < densidade1) {
                printf("Resultado: VENCEU!\n", cidade2);
            } else {
                printf("Resultado: EMPATE!\n");
            }
            break;

        case 6:
            printf("PIB Capital:\n");
            printf("%s: %.2lf\n", cidade1, pib_capital1);
            printf("%s: %.2lf\n", cidade2, pib_capital2);
            if (pib_capital1 > pib_capital2) {
                printf("Resultado: VENCEU!\n", cidade1);
            } else if (pib_capital2 > pib_capital1) {
                printf("Resultado: VENCEU!\n", cidade2);
            } else {
                printf("Resultado: EMPATE!\n");
            }
            break;

        default:
            printf("Opção inválida!\n");
    }

    return 0;
}
