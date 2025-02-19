#include <stdio.h>

int countWays(int n) {
    if (n <= 2) {
        return n;
    }
    int a = 1, b = 2, c;
    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    printf("请输入台阶数 n：");
    scanf("%d", &n);
    int ways = countWays(n);
    printf("走 %d 个台阶有 %d 种方法。\n", n, ways);
    return 0;
}