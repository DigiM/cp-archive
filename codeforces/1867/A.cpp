#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

const int INF = 1e9;
const int MOD = 1e9+7;
const double EPS = 1e-9;

vector<pii> arr;
vector<int> ans;

void solve() {
    arr.clear();
    ans.clear();

    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        arr.push_back(mp(x, i));
        ans.push_back(0);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        auto x = arr[i];
        ans[x.se] = n-i;
    }
    for (int i = 0; i< n; i++) {
        if (i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int qt = 1;
    scanf("%d", &qt);
    // cin >> qt;
    
    for (int q = 0; q < qt; q++) {
        // printf("Case #%d: ", q+1);
        // cout << "Case #" << q+1 << ": ";
        solve();
    }
}