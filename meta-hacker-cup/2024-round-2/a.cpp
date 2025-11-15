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

ll peaks[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 121, 232, 343, 454, 565, 676, 787, 898, 12321, 23432, 34543, 45654, 56785, 67876, 78987, 1234321, 2345432, 3456543, 4567654, 5678765, 6789876, 123454321, 234565432, 345676543, 456787654, 567898765, 12345654321, 23456765432, 34567876543, 45678987654, 1234567654321, 2345678765432, 3456789876543, 123456787654321, 234567898765432, 12345678987654321};

void solve() {
    ll a, b, m;
    scanf("%lld%lld%lld", &a, &b, &m);

    ll ans = 0;
    for (int i = 0; i < 45; i++) {
        if (peaks[i] >= a && peaks[i] <= b && peaks[i] % m == 0) {
            ans++;
        }
        if (peaks[i] > b) break;
    }
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