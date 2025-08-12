    #include <stdio.h>
    //NIVEL NOVATO
    int main() {
    char estado1;
    char codigo1[4];
    char cidade1[50];
    unsigned long int populacao1;
    double area1, pib1;
    int pontost1;
    double densidade1, pib_capital1;

    char estado2;
    char codigo2[4];
    char cidade2[50];
    unsigned long int populacao2;
    double area2, pib2;
    int pontost2;
    double densidade2, pib_capital2;

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

    printf("\nCarta 1\n");
    printf("Cidade: %s (%c)\n", cidade1, estado1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2lf\n", area1);
    printf("PIB: %.2lf\n", pib1);
    printf("Densidade Populacional: %.2lf\n", densidade1);
    printf("PIB per Capita: %.2lf\n", pib_capital1);

    printf("\nCarta 2\n");
    printf("Cidade: %s (%c)\n", cidade2, estado2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2lf\n", area2);
    printf("PIB: %.2lf\n", pib2);
    printf("Densidade Populacional: %.2lf\n", densidade2);
    printf("PIB per Capita: %.2lf\n", pib_capital2);

    printf("\nComparação de Cartas (Atributo: População)\n");
    printf("Carta 1 - %s (%c): %lu\n", cidade1, estado1, populacao1);
    printf("Carta 2 - %s (%c): %lu\n", cidade2, estado2, populacao2);

    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
    } 
    else if (populacao2 > populacao1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
    } 
    else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}


