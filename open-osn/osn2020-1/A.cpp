#include <bits/stdc++.h>
using namespace std;

void solve3() {
    scanf("%*d%*d%*d");
    int now = 0;
    for (int i = 0; i < 100000; i++) {
        int x; scanf("%d", &x);
        printf("0 1 %d %d\n", now, now+x);
        now+= x;
    }
}

void solve4() {
    for (int i = 1; i < 50000; i++) {
        printf("%d %d %d %d\n", 0, i, i, i+1);
    }
    for (int i = 50000; i-->1;) {
        printf("%d %d %d %d\n", i, 99999, i, i+1);
    }
    printf("0 99999 0 1\n");
}

void solve5() {
    int plusx = 9973;
    int plusy = 99991;

    int nowx = 0;
    for (int i = 0; i < 293; i++) {
        int nowy = 0;
        for (int j = 0; j < 311; j++) {
            printf("%d %d %d %d\n", nowx, nowx+plusx, nowy, nowy+plusy);
            nowy+= plusy;
        }
        nowx+= plusx;
    }
}

void solve9() {
    int lx = 0, rx = 46368;
    int ly = 0, rx = 28657;
    for 
}

int main() {
   solve5();
}