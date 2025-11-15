#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int INF = 1e9;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

vector<int> arr;

int calc(int c, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += (arr[i] + c - 1) / c;
    }
    // printf("calc %d %d: %d\n", c, n, total);
    return total;
}

ll calc_ans(int i, int div) {
    int res = arr[i]/div;
    int rem = arr[i]%div;
    // printf("haha %d %d %d %d\n", arr[i], div, res, rem);
    ll ret = 0;
    ll precomp1 = (ll)res*res;
    ll precomp2 = (ll)(res+1)*(res+1);
    for (int i = 0; i < div; i++) {
        if (i < rem) {
            ret += precomp2;
            // printf("plus %lld\n", precomp2);
        } else {
            ret += precomp1;
            // printf("plus %lld\n", precomp1);
        }
    }
    return ret;
}

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        arr.push_back(x);
    }

    int l = 1;
    int r = 1000000;
    int maxim = r;
    while (l <= r) {
        int c = (l+r)>>1;
        if (calc(c, n) <= k) {
            maxim = c;
            r = c-1;
        } else {
            // printf("should be this\n");
            l = c+1;
        }
        // printf("%d %d\n", l, r);
    }

    // printf("got %d\n", maxim);

    priority_queue<pair<int, pii> > pq;
    vector<pair<int, pii> > arr_stop;
    int total = 0;
    for (int i = 0; i < n; i++) {
        int tmp = (arr[i] + maxim - 1) / maxim;
        total += tmp;
        if (tmp >= arr[i]) {
            arr_stop.push_back(mp(arr[i]/tmp, mp(tmp, i)));
        } else {
            pq.push(mp(arr[i]/tmp, mp(tmp, i)));
        }
    }

    while (total != k) {
        auto tmp = pq.top();
        pq.pop();
        int cnt = tmp.se.fi + 1;
        tmp.fi = arr[tmp.se.se]/cnt;
        tmp.se.fi = cnt;
        if (cnt >= arr[tmp.se.se]) {
            arr_stop.push_back(tmp);
        } else {
            pq.push(tmp);
        }
        // printf("plusing to %d\n", tmp.se.se);
        total++;
    }

    ll ans = 0;
    while (!pq.empty()) {
        auto tmp = pq.top();
        pq.pop();
        ans += calc_ans(tmp.se.se, tmp.se.fi);
    }
    for (auto tmp : arr_stop) {
        ans += calc_ans(tmp.se.se, tmp.se.fi);
    }

    printf("%lld\n", ans);
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int qt = 1;
    //scanf("%d", &qt);
    for (int q = 0; q < qt; q++) {
        // printf("Case #%d: ", q+1);
        solve();
    }
}