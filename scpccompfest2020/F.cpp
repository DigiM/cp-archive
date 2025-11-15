#include <bits/stdc++.h>
using namespace std;

int ask(int l, int r) {
    int x;
    printf("? %d %d\n", l, r);
    fflush(stdout);
    scanf("%d", &x);
    return x;
}

vector<int> ans;

int main() {
    int n;
    scanf("%d", &n);
    int first = -1;
    int prev = 0;
    for (int i = 1; i < n; i++) {
        int x = ask(1, 1+i);
        if (first == -1) {
            first = x;
        } else {
            ans.push_back(x-prev);
        }
        prev = x;
    }
    int tmp = ask(2, n);
    printf("! %d %d", prev-tmp, first-(prev-tmp));
    for (int x : ans) {
        printf(" %d", x);
    }
    printf("\n");
}