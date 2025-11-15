#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int INF = 1e9;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

bool arr[105];
int memo[105];

void solve() {
    ll n;
    scanf("%lld", &n);

    int idx = 0;
    while (n > 0) {
        arr[idx++] = n%2;
        n>>=1;
    }
    memo[0] = 1;
    for (int i = 1; i < idx; i++) {
        if (!arr[i]) {
            memo[i] = memo[i-1];
        } else {
            if (memo[i] > 1) {
                memo += 
            }
        }
    }
}

int main() {
    int qt = 1;
    scanf("%d", &qt);
    for (int q = 0; q < qt; q++) {
        // printf("Case #%d: ", q+1);
        solve();
    }
}