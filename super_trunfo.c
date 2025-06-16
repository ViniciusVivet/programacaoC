#include <stdio.h>

struct Cidade {
    char nome[50];
    char estado[3];
    int codigo;
    unsigned long int populacao;
    float pib;
    float area;
    int pontos_turisticos;
};

// Função para calcular densidade populacional
float calcular_densidade(unsigned long int pop, float area) {
    return pop / area;
}

// Função para calcular PIB per capita
float calcular_pib_per_capita(float pib, unsigned long int pop) {
    return pib / pop;
}

// Função para calcular Super Poder
float calcular_super_poder(unsigned long int pop, float area, float pib, int pontos, float pib_capita, float densidade) {
    return (float)pop + area + pib + pontos + pib_capita + (1.0 / densidade);
}

// Função para comparar e imprimir vencedor
void comparar_atributo(char atributo[], float valor1, float valor2, int menor_vence) {
    int carta1_vence = (menor_vence) ? (valor1 < valor2) : (valor1 > valor2);
    printf("%s: Carta %d venceu (%d)\n", atributo, carta1_vence ? 1 : 2, carta1_vence);
}

int main() {
    struct Cidade cartas[4] = {
        {"São Paulo", "SP", 1, 12300000, 236000000000.0, 1521.11, 150},
        {"Rio de Janeiro", "RJ", 2, 6748000, 407000000000.0, 1182.30, 120},
        {"Salvador", "BA", 3, 2880000, 63000000000.0, 693.45, 80},
        {"Florianópolis", "SC", 4, 508826, 29700000000.0, 675.40, 70}
    };

    printf("=== Cartas Super Trunfo de Cidades ===\n\n");

    for (int i = 0; i < 4; i++) {
        printf("Carta %d: %s (%s) - Código: %d\n", i+1, cartas[i].nome, cartas[i].estado, cartas[i].codigo);
    }

    int escolha1, escolha2;
    printf("\nEscolha o número da primeira carta (1 a 4): ");
    scanf("%d", &escolha1);
    printf("Escolha o número da segunda carta (1 a 4): ");
    scanf("%d", &escolha2);

    // Ajuste dos índices
    escolha1 -= 1;
    escolha2 -= 1;

    struct Cidade c1 = cartas[escolha1];
    struct Cidade c2 = cartas[escolha2];

    // Cálculos carta 1
    float dens1 = calcular_densidade(c1.populacao, c1.area);
    float pib_cap1 = calcular_pib_per_capita(c1.pib, c1.populacao);
    float sp1 = calcular_super_poder(c1.populacao, c1.area, c1.pib, c1.pontos_turisticos, pib_cap1, dens1);

    // Cálculos carta 2
    float dens2 = calcular_densidade(c2.populacao, c2.area);
    float pib_cap2 = calcular_pib_per_capita(c2.pib, c2.populacao);
    float sp2 = calcular_super_poder(c2.populacao, c2.area, c2.pib, c2.pontos_turisticos, pib_cap2, dens2);

    // Comparações
    printf("\n=== Comparação de Cartas ===\n\n");
    comparar_atributo("População", c1.populacao, c2.populacao, 0);
    comparar_atributo("Área", c1.area, c2.area, 0);
    comparar_atributo("PIB", c1.pib, c2.pib, 0);
    comparar_atributo("Pontos Turísticos", c1.pontos_turisticos, c2.pontos_turisticos, 0);
    comparar_atributo("Densidade Populacional", dens1, dens2, 1); // menor vence
    comparar_atributo("PIB per Capita", pib_cap1, pib_cap2, 0);
    comparar_atributo("Super Poder", sp1, sp2, 0);

    return 0;
}
