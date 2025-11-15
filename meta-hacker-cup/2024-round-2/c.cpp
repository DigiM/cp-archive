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

int bita[805][805];

void inc_c(int r, int c, int n, int m) {
    for (int i = c; i <= m; i += (i & -i)) {
        bita[r][i]++;
    }
}

void inc(int r, int c, int n, int m) {
    r++; c++;
    for (int i = r; i <= n; i += (i & -i)) {
        inc_c(i, c, n, m);
    }
}

int get_c(int r, int c, int n, int m) {
    int ret = 0;
    for (int i = c; i > 0; i-= (i & -i)) {
        ret += bita[r][i];
    }
    return ret;
}

int get(int r, int c, int n, int m) {
    if (r < 0 || c < 0) return 0;
    if (r >= n) r = n-1;
    if (c >= m) c = m-1;

    r++; c++;
    int ret = 0;
    for (int i = r; i > 0; i -= (i&-i)) {
        ret += get_c(i, c, n, m);
    }
    return ret;
}

int get_sum(int r1, int r2, int c1, int c2, int n, int m) {
    if (r1 > r2 || c1 > c2) return 0;
    return get(r2, c2, n, m) - get(r1-1, c2, n, m) - get(r2, c1-1, n, m) + get(r1-1, c1-1, n, m);
}

vector<pair<int, pii> > arr;
vector<pair<int, pii> > arr2;

int ans[805];

void solve() {
    memset(bita, 0, sizeof bita);
    memset(ans, 0, sizeof ans);

    arr.clear(); arr2.clear();

    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x; scanf("%d", &x);
            arr.push_back(mp(x, mp(i, j)));
        }
    }

    sort(arr.begin(), arr.end());


    int l = max(n, m);

    int previ = -1;
    for (auto x : arr) {
        if (x.fi != previ) {
            while (!arr2.empty()) {
                auto y = arr2.back(); arr2.pop_back();
                inc(y.se.fi, y.se.se, n, m);
            }
            previ = x.fi;
        }
        
        int r = x.se.fi;
        int c = x.se.se;
        for (int i = 1; i < l; i++) {
            ll aa = get_sum(r-i, r+i, c-i, c+i, n, m) - get_sum(r-i+1, r+i-1, c-i+1, c+i-1, n, m);
            ans[i] += 2*aa;
            // printf("%d %d, %d got %lld\n", r, c, i, aa);
        }
        arr2.push_back(x);
    }

    ll curr = 0;
    ll ansans;
    for (int i = 1; i < l; i++) {
        curr += ans[i];
        // printf("ans[%d]: %d\n", i, ans[i]);
        if (curr >= k) {
            ansans = i;
        }
    }
    printf("%lld\n", ansans);
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