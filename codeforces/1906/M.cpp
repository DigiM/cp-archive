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

priority_queue<ll> pq;

void solve() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        pq.push(x);
    }

    ll ans = 0;
    while (!pq.empty()) {
        ll x = pq.top(); pq.pop();
        if (pq.empty()) break;
        ll y = pq.top(); pq.pop();
        if (x == 1) {
            pq.push(x);
            pq.push(y);
            break;
        }
        ll tmp = (x+y)/3;
        if (y < tmp) {
            ans += y;
            pq.push(x-2*y);
            continue;
        }
        ans += tmp;
        ll asd = (x+y)%3;
        for (int i = 0; i < asd; i++) pq.push(1);
    }

    int cnt = 0;
    while (!pq.empty()) {
        pq.pop();
        cnt++;
    }

    printf("%lld\n", ans + cnt/3);
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