#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int INF = 1e9;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

int n, m;
int arr[1000005];

pii st_max[4000020];
pii st_min[4000020];
bool st_lazy[4000020];

void build(int idx, int l, int r) {
    if (l > r) return;
    if (l == r) {
        st_max[idx] = mp(arr[l], -l);
        st_min[idx] = mp(arr[l], l);
        st_lazy[idx] = false;
        return;
    }

    int c = (l+r)/2;
    int idxl = (idx<<1);
    int idxr = (idx<<1)+1;
    build(idxl, l, c);
    build(idxr, c+1, r);
    st_max[idx] = max(st_max[idxl], st_max[idxr]);
    st_min[idx] = min(st_min[idxl], st_min[idxr]);
    st_lazy[idx] = false;

    // printf("%d %d: %d %d\n", l, r, -st_max[idx].second, st_min[idx].second);
}

void run(int idx, int l, int r) {
    if (l > r) return;
    if (l == r) {
        return;
    }

    int c = (l+r)/2;
    int idxl = (idx<<1);
    int idxr = (idx<<1)+1;
    run(idxl, l, c);
    run(idxr, c+1, r);

    // printf("run %d %d: %d %d %d\n", l, r, -st_max[idx].second, st_min[idx].second, st_lazy[idx]);
}

pii get_max(int idx) {
    if (st_lazy[idx]) {
        return mp(MOD-st_min[idx].first, -st_min[idx].second);
    } else {
        return st_max[idx];
    }
}

pii get_min(int idx) {
    if (st_lazy[idx]) {
        return mp(MOD-st_max[idx].first, -st_max[idx].second);
    } else {
        return st_min[idx];
    }
}

void update(int idx, int l, int r, int L, int R, bool lazy) {
    if (L <= l && r <= R) {
        st_lazy[idx] ^= lazy;
    } else if (r < L || R < l) {
        // do nothing
    } else {
        int c = (l+r)/2;
        int idxl = (idx<<1);
        int idxr = (idx<<1)+1;
        update(idxl, l, c, L, R, st_lazy[idx] ^ lazy);
        update(idxl, c+1, r, L, R, st_lazy[idx] ^ lazy);

        st_max[idx] = max(get_max(idxl), get_max(idxr));
        st_min[idx] = min(get_min(idxl), get_min(idxr));
        st_lazy[idx] = false;
    }
    printf("update %d %d %d %d: max(%d) min(%d) lazy(%d)\n", l, r, L, R, -get_max(idx).second, get_min(idx).second, st_lazy[idx]);
}

void solve() {
    printf("\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr+i);
    }

    build(1, 0, n-1);

    scanf("%d", &m);
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        int l, r; scanf("%d%d", &l, &r);
        update(1, 0, n-1, l-1, r-1, true);
        pii maxim = get_max(1);
        if (i==i) {
            // run(1, 0, n-1);
            printf("maxim: %d %d\n", maxim.first, maxim.second);
        }

        if (maxim.second < 0) {
            maxim.second *= -1;
        }
        ans += maxim.second + 1;
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