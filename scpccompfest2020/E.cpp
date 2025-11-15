#include <bits/stdc++.h>
using namespace std;

// previously submitted under DigiM, not stolen but submitted under different user

typedef long long ll;
vector<int> val, cost;
vector<ll> p;
ll bl[100005], br[100005];
int mini[100005];

ll getP(int l, int r) {
    if (l <= 0) {
        return p[r];
    }
    return p[r] - p[l-1];
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        val.push_back(x);
        if (i) p.push_back(p.back() + x);
        else p.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        cost.push_back(x);
        if (!i) {
            mini[i] = x;
        } else {
            mini[i] = min(mini[i-1], x);
        }
    }

    if (k > 1) {
        printf("%lld\n", max((ll)0, max(getP(0, n-1)-mini[n-2], (ll)val[n-1]-cost[n-1])));
        return 0;
    }

    bl[0] = max((ll)0, getP(0, n-1) - cost[0]);
    for (int i = 1; i < n; i++) {
        bl[i] = max(bl[i-1], getP(i, n-1) - cost[i]);
    }
    br[n-1] = max((ll)0, getP(n-1, n-1) - cost[n-1]);
    for (int i = n-2; i >= 0; i--) {
        br[i] = max(br[i+1], getP(i, n-1) - cost[i]);
    }

    if (k == 0) {
        printf("%lld\n", br[0]);
        return 0;
    }

    ll ans = br[1];

    for (int i = 0; i < n-1; i++) {
        ll tmpans = 0;
        if (i > 0) tmpans = max(tmpans, getP(0, i) - mini[i] + br[i+1]);
        if (i < n-2) tmpans = max(tmpans, bl[i] - val[i+1] + max(0, val[i+1] - cost[i+1]));
        ans = max(ans, tmpans);
    }
    printf("%lld\n", ans);
}