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

int arr[200005];

priority_queue<int> pq;

void solve() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        pq.push(x);
    }

    ll ans = 0;
    while (!pq.empty()) {
        int x = pq.top(); pq.pop();
        if (pq.empty()) break;
        int y = pq.top(); pq.pop();
        if (x == 1) {
            pq.push(x);
            pq.push(y);
            break;
        }
        int tmp = min(x/2, y);
        ans += tmp;
        x -= 2*tmp;
        y -= tmp;
        if (x) pq.push(x);
        if (y) pq.push(y);
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