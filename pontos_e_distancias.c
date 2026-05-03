#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int x, y;
    double dist_origem;
} Ponto;

double calcular_distancia(Ponto a, Ponto b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    getchar(); 

    while (n--) {
        char linha[5000]; 
        
        if (fgets(linha, sizeof(linha), stdin) != NULL) {
            linha[strcspn(linha, "\n")] = 0; 
        } else {
            break;
        }
        
        Ponto p[100];
        int qtd = 0;
        
        char *ptr = strstr(linha, "("); 
        
        while (ptr != NULL && sscanf(ptr, "(%d,%d)", &p[qtd].x, &p[qtd].y) == 2) {
            p[qtd].dist_origem = sqrt(p[qtd].x * p[qtd].x + p[qtd].y * p[qtd].y);
            qtd++;
            ptr = strchr(ptr + 1, '('); 
        }

        if (qtd == 0) continue;

        double total_dist = 0;
        for (int i = 0; i < qtd - 1; i++) {
            total_dist += calcular_distancia(p[i], p[i+1]);
        }
        
        double shortcut = calcular_distancia(p[0], p[qtd-1]);

        for (int i = 0; i < qtd - 1; i++) {
            for (int j = 0; j < qtd - i - 1; j++) {
                if (p[j].dist_origem > p[j+1].dist_origem) {
                    Ponto temp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = temp;
                }
            }
        }

        printf("points");
        for (int i = 0; i < qtd; i++) {
            printf(" (%d,%d)", p[i].x, p[i].y);
        }
        printf(" distance %.2lf shortcut %.2lf\n", total_dist, shortcut);
    }

    return 0;
}