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
    int n, m;
    scanf("%d%d", &n, &m);

    if (n < m) {
        printf("NO\n");
        return;
    }
    
    if (n < 2*m - 2) {
        printf("YES\n");
        return;
    }

    if (n % 2 == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

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