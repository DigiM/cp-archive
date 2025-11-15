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

vector<pair<int, pii> > arr;
vector<pii> result;
pii rev_idx[500005];

bool cmp(pair<int, pii> a, pair<int, pii> b) {
    return a.se.fi < b.se.fi;
}

void solve(int q) {
    arr.clear();
    result.clear();

    int n; scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        arr.push_back(mp(i, mp(x, 0)));
        rev_idx[x] = mp(i, q);
    }
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        arr[i].se.se = x;
    }

    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < n; i++) {
        if (arr[i].se.fi == arr[i].se.se) continue;
        if (arr[i].se.fi > arr[i].se.se) {
            printf("-1\n");
            return;
        }
        pii tmp = rev_idx[arr[i].se.se];
        if (tmp.se != q) {
            printf("-1\n");
            return;
        }
        result.push_back(mp(arr[i].fi, tmp.fi));
    }

    printf("%lu\n", result.size());
    for (auto x : result) {
        printf("%d %d\n", x.fi+1, x.se+1);
    }
}

int main() {
    for (int i = 1; i <= 500000; i++) {
        rev_idx[i] = mp(-1, -1);
    }

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int qt = 1;
    scanf("%d", &qt);
    // cin >> qt;
    
    for (int q = 0; q < qt; q++) {
        printf("Case #%d: ", q+1);
        // cout << "Case #" << q+1 << ": ";
        solve(q);
    }
}