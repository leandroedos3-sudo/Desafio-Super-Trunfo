#include <stdio.h>

int main() {
    // Cadastrando variáveis das Cartas
    char estado1[50], codigo1[20], nome1[50];
    int populacao1, pontos1;
    float area1, pib1, densidade1;

    char estado2[50], codigo2[20], nome2[50];
    int populacao2, pontos2;
    float area2, pib2, densidade2;

    int opcao; // Vai armazenar a escolha do atributo no menu
    // cadastrando as cartas
    // --- CADASTRO DA CARTA 1 ---
    printf("Cadastro da Carta 1:\n");
    printf("Nome da Cidade: "); scanf("%s", nome1);
    printf("População: "); scanf("%d", &populacao1);
    printf("Área: "); scanf("%f", &area1);
    printf("PIB: "); scanf("%f", &pib1);
    printf("Pontos Turísticos: "); scanf("%d", &pontos1);
    densidade1 = (float)populacao1 / area1;

    // --- CADASTRO DA CARTA 2 ---
    printf("\nCadastro da Carta 2:\n");
    printf("Nome da Cidade: "); scanf("%s", nome2);
    printf("População: "); scanf("%d", &populacao2);
    printf("Área: "); scanf("%f", &area2);
    printf("PIB: "); scanf("%f", &pib2);
    printf("Pontos Turísticos: "); scanf("%d", &pontos2);
    densidade2 = (float)populacao2 / area2;

    // --- MENU INTERATIVO ---
    printf("\n--- Escolha o Atributo de Comparação ---\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    printf("\n--- RESULTADO ---\n");

    // O switch funciona como um seletor de casos baseado na escolha do usuário
    switch (opcao) {
        case 1: // Comparação por População
            printf("Atributo: População\n%s (%d) vs %s (%d)\n", nome1, populacao1, nome2, populacao2);
            if (populacao1 > populacao2) printf("Vencedor: %s\n", nome1);
            else if (populacao2 > populacao1) printf("Vencedor: %s\n", nome2);
            else printf("Empate!\n");
            break;

        case 2: // Comparação por Área
            printf("Atributo: Área\n%s (%.2f) vs %s (%.2f)\n", nome1, area1, nome2, area2);
            if (area1 > area2) printf("Vencedor: %s\n", nome1);
            else if (area2 > area1) printf("Vencedor: %s\n", nome2);
            else printf("Empate!\n");
            break;

        case 3: // Comparação por PIB
            printf("Atributo: PIB\n%s (%.2f) vs %s (%.2f)\n", nome1, pib1, nome2, pib2);
            if (pib1 > pib2) printf("Vencedor: %s\n", nome1);
            else if (pib2 > pib1) printf("Vencedor: %s\n", nome2);
            else printf("Empate!\n");
            break;

        case 4: // Comparação por Pontos Turísticos
            printf("Atributo: Pontos Turísticos\n%s (%d) vs %s (%d)\n", nome1, pontos1, nome2, pontos2);
            if (pontos1 > pontos2) printf("Vencedor: %s\n", nome1);
            else if (pontos2 > pontos1) printf("Vencedor: %s\n", nome2);
            else printf("Empate!\n");
            break;

        case 5: // Comparação por Densidade (MENOR valor vence)
            printf("Atributo: Densidade\n%s (%.2f) vs %s (%.2f)\n", nome1, densidade1, nome2, densidade2);
            if (densidade1 < densidade2) printf("Vencedor: %s\n", nome1);
            else if (densidade2 < densidade1) printf("Vencedor: %s\n", nome2);
            else printf("Empate!\n");
            break;

        default: // Caso o usuário digite um número fora de 1-5
            printf("Opção Inválida!\n");
            break;
    }

    return 0;
}
