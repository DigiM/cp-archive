#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

const int INF = 1e9;
const ll MOD = 998244353;
const double EPS = 1e-9;

void solve() {
    ll a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    ll ans = a - b;
    ans %= MOD;
    c %= MOD;
    ans *= (2*c + 1) % MOD;
    ans %= MOD;
    printf("%lld\n", ans);
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int qt = 1;
    scanf("%d", &qt);
    // cin >> qt;
    
    for (int q = 0; q < qt; q++) {
        printf("Case #%d: ", q+1);
        // cout << "Case #" << q+1 << ": ";
        solve();
    }
}