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

int n;
int arr[500005];
int par[500005];
int tmp[500005];

int get_par(int x) {
    if (par[x] == x) return x;
    par[x] = get_par(par[x]);
    return par[x];
}

bool test(int now) {
    // printf("test %d\n", now);
    for (int i = 0; i < n; i++) {
        par[i] = i;
        tmp[i] = INF;
    }
    for (int i = 1; i < n; i++) {
        if (now >= abs(arr[i]-arr[i-1])) {
            par[i] = i-1;
        }
    }
    for (int i = 0; i < n; i++) {
        int pari = get_par(i);
        tmp[pari] = min(tmp[pari], arr[i]);
    }
    for (int i = 0; i < n; i++) {
        if (now < tmp[get_par(i)]) return false;
    }
    return true;
}

void solve() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", arr+i);
    }

    int ans = INF;
    int l = 0;
    int r = INF;
    while (l <= r) {
        int c = l + (r-l)/2;
        if (test(c)) {
            ans = c;
            r = c-1;
        } else {
            l = c+1;
        }
    }
    printf("%d\n", ans);
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