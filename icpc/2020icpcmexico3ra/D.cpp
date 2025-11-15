#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int INF = 1e9;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

void solve() {
    string s;
    int k;
    cin >> s >> k;

    string ans = "";

    ll cnt = 0;
    ll val = 0;
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            val *= 10;
            val += c-'0';
            if (val > k) {
                cout << "unfeasible" << endl;
                return;
            }
        } else {
            val = max(1LL, val);
            cnt += val;
            for (int i = 0; i < val; i++) {
                ans = ans + c;
            }
            val = 0;
        }
    }
    if (cnt > k) {
        cout << "unfeasible" << endl;
    } else {
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int qt = 1;
    // scanf("%d", &qt);
    cin >> qt;
    for (int q = 0; q < qt; q++) {
        // printf("Case #%d: ", q+1);
        solve();
    }
}