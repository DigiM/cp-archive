#include <bits/stdc++.h>
using namespace std;

void prx(bool x) {
    if (x) {
        printf("Ya");
    } else {
        printf("Tidak");
    }
}

void solve() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    bool isminus = false;
    if ((a+b)%2) {
        isminus = true;
    }
    bool ismore = false;
    bool isless = false;
    if (a+d > 0) {
        ismore = true;
    }
    if (b+c > 0) {
        isless = true;
    }
    prx(isminus && ismore);
    printf(" ");
    prx(isminus && isless);
    printf(" ");
    prx(!isminus && isless);
    printf(" ");
    prx(!isminus && ismore);
    printf("\n");
}

int main() {
    int qt;
    scanf("%d", &qt);

    for (int q = 0; q < qt; q++) {
        solve();
    }
}