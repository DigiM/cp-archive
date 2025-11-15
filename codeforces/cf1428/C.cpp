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
    cin >> s;

    stack<char> st;
    int n = (int)s.size();
    int b_cnt = 0;
    int ans = 0;
    for (int i = n; i --> 0;) {
        char c = s[i];
        if (c == 'B') {
            b_cnt++;
        } else {
            if (b_cnt > 0) {
                b_cnt--;
            } else {
                ans++;
            }
        }
    }
    printf("%d\n", ans + (b_cnt%2));
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