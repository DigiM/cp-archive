#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int INF = 1e9;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

bool isNotPrime[1000005];

void sieve() {
    isNotPrime[0] = true;
    isNotPrime[1] = true;
    for (int i = 2; i*i <= 1000000; i++) {
        if (!isNotPrime[i]) {
            for (int j = i*i; j <= 1000000; j+=i) {
                isNotPrime[j] = true;
            }
        }
    }
}

int bit[1000005];

void add(int x, int val) {
    for (int i = x; i <= 1000000; i += (i&-i)) {
        bit[i] += val;
    }
}

int get(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= (i&-i)) {
        // printf("i: %d\n", i);
        ret += bit[i];
        // printf("ret: %d\n", ret);
    }
    return ret;
}

void solve() {
    sieve();
    add(1, 1);
    for (int i = 2; i <= 1000000; i++) {
        if (isNotPrime[i]) continue;
        add(i, 1);
        if (i <= 1000) add(i*i, -1);
    }

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        // printf("blok\n");
        printf("%d\n", get(x));
    }
}

int main() {
    int qt = 1;
    // scanf("%d", &qt);
    for (int q = 0; q < qt; q++) {
        // printf("Case #%d: ", q+1);
        solve();
    }
}