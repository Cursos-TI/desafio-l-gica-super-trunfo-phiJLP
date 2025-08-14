#include <stdio.h>
//NIVEL MESTRE
// Função auxiliar para obter o valor do atributo
double getValue(int attr, int carta,
                unsigned long int populacao1, unsigned long int populacao2,
                double area1, double area2,
                double pib1, double pib2,
                int pontost1, int pontost2,
                double densidade1, double densidade2,
                double pib_capital1, double pib_capital2) {
    switch (attr) {
        case 1: return carta == 1 ? (double)populacao1 : (double)populacao2;
        case 2: return carta == 1 ? area1 : area2;
        case 3: return carta == 1 ? pib1 : pib2;
        case 4: return carta == 1 ? (double)pontost1 : (double)pontost2;
        case 5: return carta == 1 ? densidade1 : densidade2;
        case 6: return carta == 1 ? pib_capital1 : pib_capital2;
        default: return 0;
    }
}

// Função auxiliar para nome do atributo
const char* nomeAtributo(int attr) {
    switch (attr) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        case 6: return "PIB per Capita";
        default: return "Desconhecido";
    }
}

int main() {
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char cidade1[50], cidade2[50];
    unsigned long int populacao1, populacao2;
    double area1, area2, pib1, pib2;
    int pontost1, pontost2;
    double densidade1, densidade2, pib_capital1, pib_capital2;

    // Cadastro Carta 1
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

    // Cadastro Carta 2
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

    // Menu dinâmico para dois atributos
    int attr1, attr2;
    double valor1_c1 = 0, valor1_c2 = 0;
    double valor2_c1 = 0, valor2_c2 = 0;

    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n6 - PIB per Capita\n");
    printf("Opção: ");
    scanf("%d", &attr1);

    // Menu dinâmico: oculta o atributo já escolhido
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 6; i++) {
        if (i != attr1) {
            printf("%d - %s\n", i, nomeAtributo(i));
        }
    }

    do {
        printf("Opção: ");
        scanf("%d", &attr2);
        if (attr2 == attr1 || attr2 < 1 || attr2 > 6) {
            printf("Atributo inválido ou repetido. Tente novamente.\n");
        }
    } while (attr2 == attr1 || attr2 < 1 || attr2 > 6);

    // Obter valores dos atributos
    valor1_c1 = getValue(attr1, 1, populacao1, populacao2, area1, area2, pib1, pib2, pontost1, pontost2, densidade1, densidade2, pib_capital1, pib_capital2);
    valor1_c2 = getValue(attr1, 2, populacao1, populacao2, area1, area2, pib1, pib2, pontost1, pontost2, densidade1, densidade2, pib_capital1, pib_capital2);
    valor2_c1 = getValue(attr2, 1, populacao1, populacao2, area1, area2, pib1, pib2, pontost1, pontost2, densidade1, densidade2, pib_capital1, pib_capital2);
    valor2_c2 = getValue(attr2, 2, populacao1, populacao2, area1, area2, pib1, pib2, pontost1, pontost2, densidade1, densidade2, pib_capital1, pib_capital2);

    // Comparação individual com regra especial para densidade
    int v1 = (attr1 == 5) ? (valor1_c1 < valor1_c2 ? 1 : (valor1_c2 < valor1_c1 ? 2 : 0))
                          : (valor1_c1 > valor1_c2 ? 1 : (valor1_c2 > valor1_c1 ? 2 : 0));
    int v2 = (attr2 == 5) ? (valor2_c1 < valor2_c2 ? 1 : (valor2_c2 < valor2_c1 ? 2 : 0))
                          : (valor2_c1 > valor2_c2 ? 1 : (valor2_c2 > valor2_c1 ? 2 : 0));

    // Soma dos atributos
    double soma1 = valor1_c1 + valor2_c1;
    double soma2 = valor1_c2 + valor2_c2;

    int vencedor = (soma1 > soma2) ? 1 : (soma2 > soma1 ? 2 : 0);

    // Exibição dos resultados
    printf("\nRESULTADO DA COMPARAÇÃO\n");
    printf("Carta 1: %s\n", cidade1);
    printf("Carta 2: %s\n", cidade2);

    printf("\nAtributo 1 (%s):\n", nomeAtributo(attr1));
    printf("%s: %.2lf\n", cidade1, valor1_c1);
    printf("%s: %.2lf\n", cidade2, valor1_c2);
    printf("Vencedor: %s\n", v1 == 1 ? cidade1 : (v1 == 2 ? cidade2 : "Empate"));

    printf("\nAtributo 2 (%s):\n", nomeAtributo(attr2));
    printf("%s: %.2lf\n", cidade1, valor2_c1);
    printf("%s: %.2lf\n", cidade2, valor2_c2);
    printf("Vencedor: %s\n", v2 == 1 ? cidade1 : (v2 == 2 ? cidade2 : "Empate"));

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2lf\n", cidade1, soma1);
    printf("%s: %.2lf\n", cidade2, soma2);
    printf("Resultado final: %s\n", vencedor == 1 ? cidade1 : (vencedor == 2 ? cidade2 : "Empate!"));

    return 0;
}
