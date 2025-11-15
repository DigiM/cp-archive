#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll x;
    scanf("%lld", &x);
    ll y = x;
    bool flip = false;
    if (x%2) {
        x--;
        flip = true;
    }

    ll ans = 0;
    while (x > 0) {
        if (x < 4) {
            x-=2;
            ans++;
            // printf("00\n");
        } else if (x == 4) {
            x-=3;
            ans+=2;
        } else if (x%4 == 0) {
            x-=2;
            ans++;
        } else if (x%2 == 0) {
            ans+=(x>>=1);
            x--;
        }
        // printf("ans: %lld\n", ans);
    }
    if (flip) {
        ans = y-ans;
    }
    printf("%lld\n", ans);
}

int main() {
    int qt;
    scanf("%d", &qt);

    for (int q = 0; q < qt; q++) {
        solve();
    }
}