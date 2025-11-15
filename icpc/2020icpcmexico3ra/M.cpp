#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int INF = 1e9;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

bool skip[1005];
int cont[1005];

void solve() {
    memset(cont, -1, sizeof cont);

    string s;
    cin >> s;
    int n = s.length();
    for (int d = 1; d <= 9; d++) {
        stack<int> st;
        int x; cin >> x;
        int previ = -1;
        for (int i = 0; i < n; i++) {
            if (x == 0) break;
            if (skip[i]) continue;
            if (previ != -1 && s[previ] == '0' + d) {
                if (s[i] - '0' == d) {
                    cont[i] = previ;
                    st.push(previ);
                } else if (s[i] - '0' > d) {
                    int now = previ;
                    while (now != -1 && x > 0) {
                        skip[now] = true;
                        x--;
                        now = cont[now];
                    }
                    // printf("skipping %d: %d\n", previ, d);
                } else {
                    st.push(previ);
                }
            }
            previ = i;
        }
        if (previ != -1 && s[previ] == '0' + d) st.push(previ);
        while (x > 0) {
            int y = st.top();
            st.pop();
            if (skip[y]) continue;
            skip[y] = true;
            // printf("skipping2 %d: %d\n", y, d);
            x--;
        }
    }
    for (int i = 0; i < n; i++) {
        if (skip[i]) continue;
        cout << s[i];
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int qt = 1;
    //scanf("%d", &qt);
    for (int q = 0; q < qt; q++) {
        // printf("Case #%d: ", q+1);
        solve();
    }
}