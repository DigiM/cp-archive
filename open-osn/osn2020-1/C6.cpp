#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    printf("%d\n", (max(0, n-k)+m-1)/m);
}

