#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int INF = 1e9;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

set<string> x;

void solve() {
    int n;
    cin >> n;

    string s;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        string finalS = s;
        int l = s.length();
        for (int i = 1; i < l; i++) {
            string newS = s.substr(i, l-i) + s.substr(0, i);
            if (newS.compare(finalS) < 0) {
                finalS = newS;
            }
        }
        if (x.count(finalS)) {

        } else {
            ans++;
            x.insert(finalS);
        }
    }

    cout << ans << endl;
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