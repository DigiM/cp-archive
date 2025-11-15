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

void solve() {
    int n;
    scanf("%d", &n);

    int ans = 0;
    int prev = -1;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        if (i) {
            ans = max(ans, abs(prev-x));
        }
        prev = x;
    }
    printf("%d\n", ans);
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