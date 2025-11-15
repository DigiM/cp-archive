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

const int NMAX = 1e6;

vector<pii> prefix_xor;
int comp[NMAX+5];
int sum[NMAX+5];
int cnt[NMAX+5];

bool cmp(pii a, pii b) {
    return a.se < b.se;
}

void solve() {
    prefix_xor.clear();

    printf("\n");

    int n; scanf("%d", &n);
    ll ans_minus_zero = 0;
    int cumm = 0;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        prefix_xor.push_back(mp(x, i));
        if (i) prefix_xor[i].fi ^= prefix_xor[i-1].fi;

        if (x == 0) cumm++;
        else if (cumm > 0) {
            ans_minus_zero += cumm-1;
            cumm = 0;
        }
    }
    if (cumm > 0) ans_minus_zero += cumm-1;
    
    sort(prefix_xor.begin(), prefix_xor.end());
    int curr = 0;
    for (int i = 0; i < n; i++) {
        pii now = prefix_xor[i];
        if (i && now.fi != prefix_xor[i-1].fi) curr++;
        comp[now.se] = curr;
    }
    for (int i = 0; i < curr+1; i++) {
        cnt[i] = 0;
    }
    if (prefix_xor[0].fi == 0) cnt[0]++;
    sort(prefix_xor.begin(), prefix_xor.end(), cmp);

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (ll)i * (n-i+1);
    }
    printf("ans: %lld\n", ans);
    for (int i = 0; i < n; i++) {
        ans -= cnt[comp[i]]; cnt[comp[i]]++;
        printf("ans[%d]: %lld\n", i, ans);
    }
    ans -= ans_minus_zero;


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

/* 


*/