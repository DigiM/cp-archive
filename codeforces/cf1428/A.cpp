#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int INF = 1e9;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

void solve() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int ans = 0;
    if (a != c && b != d) {
        ans += 2;
    }
    ans += abs(a-c);
    ans += abs(b-d);
    printf("%d\n", ans);
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int qt = 1;
    scanf("%d", &qt);
    for (int q = 0; q < qt; q++) {
        // printf("Case #%d: ", q+1);
        solve();
    }
}