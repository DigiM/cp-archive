#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

const int INF = 1e9;
const int MOD = 1e9+7;
const double EPS = 1e-9;

priority_queue<int> pq;

void solve() {
    int n;
    scanf("%d", &n);

    ll tot = 0;
    int maxim = 0;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        tot += x;
        maxim = max(maxim, x);
    }
    ll ans = min(tot/3, tot - maxim);

    printf("%lld\n", ans);
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int qt = 1;
    // scanf("%d", &qt);
    // cin >> qt;
    
    for (int q = 0; q < qt; q++) {
        // printf("Case #%d: ", q+1);
        // cout << "Case #" << q+1 << ": ";
        solve();
    }
}