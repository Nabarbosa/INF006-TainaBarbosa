#include <stdio.h>

#define MAXN 500005

int a[MAXN], aux[MAXN], freq[MAXN];
int n;

long long inversoes(int e, int d) {
    if (e >= d) return 0;
    
    int m = e + (d - e) / 2;
    long long contador = inversoes(e, m) + inversoes(m + 1, d);
    
    int i = e, j = m + 1, k = e;
    while (i <= m && j <= d) {
        if (a[i] <= a[j]) {
            aux[k++] = a[i++];
        } else {
            aux[k++] = a[j++];
            contador += (m - i + 1); 
        }
    }
    while (i <= m) aux[k++] = a[i++];
    while (j <= d) aux[k++] = a[j++];
    for (i = e; i <= d; i++){
        a[i] = aux[i];
    } 

    return contador;
}

int main() {
    int num; 
    if (scanf("%d", &num) != 1) return 0;

    while (num--) {
        if (scanf("%d", &n) != 1) break; 
    
        int duplicada = 0;
        for (int i = 0; i <= n; i++){
            freq[i] = 0;
        } 

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (a[i] <= n && ++freq[a[i]] > 1) {
                duplicada = 1;
            }
        }

        if (duplicada) {
            printf("YES\n");
        } else {
            if(inversoes(0, n - 1) % 2 == 0){
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }

    return 0;
}