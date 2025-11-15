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

int arr[2005];
int par[2005];
int val[2005];
int whi[2005];

int get_par(int x) {
    if (par[x] != x) {
        return par[x] = get_par(par[x]);
    }
    return x;
}

vector<pii> comp;

int memo[2005][4005];

int dp(int curr, int diff, int n) {
    if (curr == n) {
        return diff == 2000;
    }
    
    int &ret = memo[curr][diff];
    if (ret == -1) {
        ret = dp(curr+1, diff - comp[curr].first, n);
        if (!ret) ret = dp(curr+1, diff + comp[curr].first, n);
    }
    return ret;
}

void bt(int curr, int diff, int n) {
    if (curr == n) {
        return;
    }
    
    if (dp(curr+1, diff - comp[curr].first, n)) {
        whi[comp[curr].second] = 1;
        bt(curr+1, diff - comp[curr].first, n);
    } else {
        whi[comp[curr].second] = 2;
        bt(curr+1, diff + comp[curr].first, n);
    }
}

void solve() {
    memset(memo, -1, sizeof memo);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2*n; i++) {
        scanf("%d", arr+i);
    }

    for (int i = 0; i < 2*n; i++) {
        par[i] = i;
        val[i] = 1;
        for (int j = i; j --> 0;) {
            if (arr[j] > arr[i]) {
                par[i] = get_par(j);
                val[get_par(i)]++;
                break;
            }
        }
    }

    for (int i = 0; i < 2*n; i++) {
        if (par[i] == i) comp.push_back(mp(val[i], i));
    }

    // for (pii x : comp) {
    //     printf("%d %d, ", x.first, x.second);
    // }
    // printf("\n");

    if (!dp(0, 2000, comp.size())) {
        printf("-1\n");
        return;
    }

    bt(0, 2000, comp.size());

    vector<int> a, b;
    for (int i = 0; i < 2*n; i++) {
        if (whi[get_par(i)] == 1) a.push_back(arr[i]);
        else b.push_back(arr[i]);
    }

    for (int x : a) {
        printf("%d ", x);
    }
    printf("\n");
    for (int x : b) {
        printf("%d ", x);
    }
    printf("\n");
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