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

vector<ll> peaks;
int fata = 0;

void generate_peaks(ll now, ll add, ll asd, ll asd2, int qwe, int qwe2, int highest) {
    // 1470413321
    peaks.push_back(now);
    // printf("fata: %d, %lld %lld\n", fata++, now, add);
    // if (fata > 10) return;

    if (highest == 9) return;

    // printf("%lld %lld %lld %lld %d %d %d\n", now, add, asd, asd2, qwe, qwe2, highest);

    ll aa = add;
    ll bb = asd;
    for (int i = 0; i <= qwe; i++) {
        ll aaa = aa;
        ll bbb = asd2;
        for (int j = 0; j <= qwe2; j++) {
            generate_peaks(now + aaa, aaa, bb, bbb, qwe-i, qwe2-j, highest+1);
            aaa -= bbb; bbb *= 10;
        }
        aa -= bb; bb /= 10;
    }
}

void solve() {
    ll a, b, m;
    scanf("%lld%lld%lld", &a, &b, &m);

    ll ans = 0;
    for (int i = 0; i < (int)peaks.size(); i++) {
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

    for (int i = 1; i < 10; i++) peaks.push_back(i);
    for (int i = 1; i <= 8; i++) {
        ll x = 1;
        ll asd = 1;
        for (int j = 0; j < 2*i; j++) {
            x = 10*x + 1;
            asd = 10*asd;
        }
        ll y = 1;
        for (int j = 0; j < i; j++) {
            y = 10*y;
        }

        generate_peaks(x+y, x, asd, 1, i, i, 2);
    }

    sort(peaks.begin(), peaks.end());

    // printf("size: %d\n", peaks.size());
    // for (auto x : peaks) {
    //     printf("%lld\n", x);
    // }
    // return 0;

    int qt = 1;
    scanf("%d", &qt);
    // cin >> qt;
    
    for (int q = 0; q < qt; q++) {
        printf("Case #%d: ", q+1);
        // cout << "Case #" << q+1 << ": ";
        solve();
    }
}