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

struct event {
    int val;
    int k;
    int idx;
    
    bool operator <(event o) {
        return k < o.k;
    }
};

vector<event> event_arr;

struct st {
    ll prefix_sum;
    ll suffix_sum;
    ll max_sub_sum;
    ll sum;
};

st ST[400005];

void update(int idx, int pos, int val, int L, int R) {
    if (L == R) {
        ST[idx].prefix_sum += val;
        ST[idx].suffix_sum += val;
        ST[idx].max_sub_sum += val;
        ST[idx].sum += val;
    } else {
        int idxl = idx<<1;
        int idxr = (idx<<1)|1;

        int c = (L+R)>>1;
        if (pos <= c) {
            update(idxl, pos, val, L, c);
        } else {
            update(idxr, pos, val, c+1, R);
        }
        ST[idx].prefix_sum = max(ST[idxl].prefix_sum, ST[idxl].sum + ST[idxr].prefix_sum);
        ST[idx].suffix_sum = max(ST[idxr].suffix_sum, ST[idxr].sum + ST[idxl].suffix_sum);
        ST[idx].max_sub_sum = max(max(ST[idxl].max_sub_sum, ST[idxr].max_sub_sum), ST[idxl].suffix_sum + ST[idxr].prefix_sum);
        ST[idx].sum = ST[idxl].sum + ST[idxr].sum;
    }
}

st query(int idx, int l, int r, int L, int R) {
    if (l <= L && R <= r) {
        return ST[idx];
    } else if (r < L || R < l) {
        return {-INF, -INF, -INF, -INF};
    } else {
        int idxl = idx<<1;
        int idxr = (idx<<1)|1;

        int c = (L+R)>>1;
        st stl = query(idxl, l, r, L, c);
        st str = query(idxr, l, r, c+1, R);

        st ret;
        ret.prefix_sum = max(stl.prefix_sum, stl.sum + str.prefix_sum);
        ret.suffix_sum = max(str.suffix_sum, str.sum + stl.suffix_sum);
        ret.max_sub_sum = max(max(stl.max_sub_sum, str.max_sub_sum), stl.suffix_sum + str.prefix_sum);
        ret.sum = stl.sum + str.sum;
        return ret;
    }
}

ll ans[100005];
vector<pair<pii, pii>> queries;

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        event_arr.push_back({c, a, i});
        event_arr.push_back({-c, b+1, i});
    }
    sort(event_arr.begin(), event_arr.end());

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        queries.push_back(mp(mp(a, b), mp(c, i)));
    }

    sort(queries.begin(), queries.end());

    int idx = 0;
    for (int i = 0; i < q; i++) {
        auto qr = queries[i];
        while (idx < 2*m) {
            event e = event_arr[idx];
            if (e.k > qr.first.first) {
                break;
            }
            // printf("updating %d\n", e.idx);
            update(1, e.idx, e.val, 0, m-1);
            // printf("sum: %lld\n", query(1, 0, m-1, 0, m-1).sum);
            idx++;
        }
        auto tmp_ans = query(1, qr.first.second-1, qr.second.first-1, 0, m-1);
        ans[qr.second.second] = tmp_ans.max_sub_sum;
    }

    for (int i = 0; i < q; i++) {
        printf("%lld\n", ans[i]);
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int qt = 1;
    // scanf("%d", &qt);
    // cin >> qt;
    
    for (int q = 0; q < qt; q++) {
        // printf("Case #%d: ", q+1);
        // cout << "Case #" << q+1 << ": ";
        solve();
    }
}