#include <stdio.h>
// f(x,n)=x−x^2 +x^3 −x^4 +⋯+(−1)^(n−1) x^n
double fn(double x, int n)
{
    if (n == 1)
        return x;
    else
        return x * (1 - fn(x, n - 1));
}

int main()
{
    double x;
    int n;

    scanf("%lf %d", &x, &n);
    printf("%.2f\n", fn(x, n));

    return 0;
}