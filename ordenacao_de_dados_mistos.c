#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    double x, y, d;
} Ponto;

int main() {
    int n;
    if (scanf("%d ", &n) != 1) return 0; 

    while (n--) {
        char linha[2000], str[100][50];
        int ints[100], ni = 0, ns = 0, nf = 0, np = 0;
        double floats[100];
        Ponto p[100];

        fgets(linha, 2000, stdin);
        char *token = strtok(linha, " \n\r");

        while (token) {
            if (token[0] == '(') {
                sscanf(token, "(%lf,%lf)", &p[np].x, &p[np].y);
                p[np].d = sqrt(p[np].x * p[np].x + p[np].y * p[np].y);
                np++;
            } else if (strchr(token, '.')) {
                floats[nf++] = atof(token);
            } else if ((token[0] >= '0' && token[0] <= '9') || (token[0] == '-' && token[1] >= '0')) {
                ints[ni++] = atoi(token);
            } else {
                strcpy(str[ns++], token);
            }
            token = strtok(NULL, " \n\r");
        }

        
        for(int i=0; i<ns-1; i++) for(int j=0; j<ns-i-1; j++) if(strcmp(str[j], str[j+1]) > 0) { char t[50]; strcpy(t, str[j]); strcpy(str[j], str[j+1]); strcpy(str[j+1], t); }
        for(int i=0; i<ni-1; i++) for(int j=0; j<ni-i-1; j++) if(ints[j] > ints[j+1]) { int t = ints[j]; ints[j] = ints[j+1]; ints[j+1] = t; }
        for(int i=0; i<nf-1; i++) for(int j=0; j<nf-i-1; j++) if(floats[j] > floats[j+1]) { double t = floats[j]; floats[j] = floats[j+1]; floats[j+1] = t; }
        for(int i=0; i<np-1; i++) for(int j=0; j<np-i-1; j++) if(p[j].d > p[j+1].d) { Ponto t = p[j]; p[j] = p[j+1]; p[j+1] = t; }

    
        printf("str:");
        for (int i = 0; i < ns; i++) printf("%s%s", (i == 0 ? "" : " "), str[i]);

        printf(" int:");
        for (int i = 0; i < ni; i++) printf("%s%d", (i == 0 ? "" : " "), ints[i]);

        printf(" float:");
        for (int i = 0; i < nf; i++) printf("%s%.2lf", (i == 0 ? "" : " "), floats[i]);

        printf(" p:");
        for (int i = 0; i < np; i++) printf("%s(%.1lf,%.1lf)", (i == 0 ? "" : " "), p[i].x, p[i].y);
        
        printf("\n");
    }
    return 0;
}