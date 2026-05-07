#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Aqui eu crio as "caixas" para guardar os nomes e os números das duas cidades
    char nome1[50], nome2[50];
    unsigned long int populacao1, populacao2; // Usei esse tipo para caber números bem grandes
    float area1, area2, pib1, pib2, densidade1, densidade2;
    int pontos1, pontos2;

    // Variáveis para saber qual opção o jogador escolheu e quem ganhou cada rodada
    char primeiroAtributo, segundoAtributo;
    int resultado1 = 0, resultado2 = 0;

    // Comando que ajuda a gerar números diferentes toda vez que rodar o jogo
    srand(time(0));

    // --- CADASTRO DAS CARTAS ---
    // Começo pedindo os dados da primeira cidade
    printf("Bem-vindo ao Super Trunfo!\n");
    printf("Cadastro da Carta 1 - Cidade: "); scanf("%s", nome1);
    printf("Populacao: "); scanf("%lu", &populacao1);
    printf("Area: "); scanf("%f", &area1);
    printf("PIB: "); scanf("%f", &pib1);
    printf("Pontos Turisticos: "); scanf("%d", &pontos1);
    
    // Faço o cálculo da densidade dividindo população pela área
    densidade1 = (float)populacao1 / area1;

    // Agora peço os dados da segunda cidade
    printf("\nCadastro da Carta 2 - Cidade: "); scanf("%s", nome2);
    printf("Populacao: "); scanf("%lu", &populacao2);
    printf("Area: "); scanf("%f", &area2);
    printf("PIB: "); scanf("%f", &pib2);
    printf("Pontos Turisticos: "); scanf("%d", &pontos2);
    
    densidade2 = (float)populacao2 / area2;

    // --- ESCOLHA DO PRIMEIRO ATRIBUTO ---
    // Mostro as opções para o jogador escolher o que quer comparar primeiro
    printf("\nEscolha o primeiro atributo.\n");
    printf("P. Populacao\n");
    printf("A. Area\n");
    printf("D. Densidade\n");
    printf("Escolha a comparacao (Use a letra): ");
    scanf(" %c", &primeiroAtributo); // O espaço antes do %c evita bugs no teclado

    // Uso o switch para ver qual letra o jogador digitou e fazer a comparação
    switch (primeiroAtributo) {
        case 'P': case 'p':
            printf("Voce escolheu Populacao!\n");
            // Se cidade 1 for maior que a 2, ganha 1 ponto, senão ganha 0
            resultado1 = populacao1 > populacao2 ? 1 : 0;
            break;
        case 'A': case 'a':
            printf("Voce escolheu Area!\n");
            resultado1 = area1 > area2 ? 1 : 0;
            break;
        case 'D': case 'd':
            printf("Voce escolheu Densidade!\n");
            // Aqui é diferente: ganha quem tiver o MENOR número
            resultado1 = densidade1 < densidade2 ? 1 : 0; 
            break;
    }

    // --- ESCOLHA DO SEGUNDO ATRIBUTO ---
    // Peço a segunda comparação para o jogo ficar mais emocionante
    printf("\nEscolha o segundo atributo (P, A ou D): ");
    scanf(" %c", &segundoAtributo);

    switch (segundoAtributo) {
        case 'P': case 'p':
            resultado2 = populacao1 > populacao2 ? 1 : 0;
            break;
        case 'A': case 'a':
            resultado2 = area1 > area2 ? 1 : 0;
            break;
        case 'D': case 'd':
            resultado2 = densidade1 < densidade2 ? 1 : 0;
            break;
    }

    // --- RESULTADO FINAL ---
    printf("\n--- RESULTADO FINAL ---\n");
    
    // Verifico se a primeira cidade ganhou as duas vezes (resultado1 E resultado2)
    if (resultado1 && resultado2) {
        printf("Parabens, %s venceu nos dois atributos!\n", nome1);
    } 
    // Se ela ganhou uma e perdeu a outra, os resultados serão diferentes, então empatou
    else if (resultado1 != resultado2) {
        printf("Cada cidade ganhou em um atributo. Empatou!\n");
    } 
    // Se não ganhou nada, então ela perdeu
    else {
        printf("Infelizmente, %s perdeu nas duas comparacoes!\n", nome1);
    }

    return 0;
}
