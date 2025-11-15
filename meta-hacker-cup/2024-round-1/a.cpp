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

    double mx = 1e9;
    double mn = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        mn = max(mn, double(i+1) / b);
        mx = min(mx, double(i+1) / a);
        if (fabs(mx - mn) > EPS && mx < mn) {
            printf("-1\n");
            for (int j = i+1; j < n; j++) {
                scanf("%d%d", &a, &b);
            }
            return;
        }
        // printf("mx: %lf, mn: %lf\n", mx, mn);
    }

    printf("%lf\n", mn);
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