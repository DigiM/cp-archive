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
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool allcw = true;
    bool allccw = true;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '-') {
            if (i && s[i-1] == '-') {
                cnt++;
            } else {
                cnt += 2;
            }
        } else if (c == '>') {
            allccw = false;
        } else {
            allcw = false;
        }
    }
    if (s[n-1] == '-' && s[0] == '-') cnt--;
    if (allccw || allcw) {
        printf("%d\n", n);
    } else {
        printf("%d\n", cnt);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int qt = 1;
    //scanf("%d", &qt);
    cin >> qt;
    for (int q = 0; q < qt; q++) {
        // printf("Case #%d: ", q+1);
        solve();
    }
}