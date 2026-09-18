#include <stdio.h>
int fact(int n)
{
    if (n < 0)
        return -1;
    if (n == 0)
        return 1;
    if (n <= 2)
        return n;
    return n * fact(n - 1);
}
int main()
{
    int n;
    scanf("%d", &n);
    int res = fact(n);
    printf("%d", res);
    return 0;
}
