#include <stdio.h>

long long mdc(long long a, long long b) {
    while (b) {
        a %= b;
        long long temp = a;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    long long a, b, x, y;

    if (scanf("%lld %lld %lld %lld", &a, &b, &x, &y) != 4) return 0;

    long long divisor_comum = mdc(x, y);
    x /= divisor_comum;
    y /= divisor_comum;

    long long quantidade_w = a / x;
    long long quantidade_h = b / y;

    long long resultado = (quantidade_w < quantidade_h) ? quantidade_w : quantidade_h;

    printf("%lld\n", resultado);

    return 0;
}