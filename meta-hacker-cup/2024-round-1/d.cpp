#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

const int INF = 1e9;
const int MOD = 998244353;
const double EPS = 1e-9;

const int NMAX = 1e5;

int num_choices[NMAX+5];
char choice[NMAX+5];

ll memo[NMAX+5];

ll dp(int i, int n) {
    if (i == n) {
        return 1;
    }
    ll &ret = memo[i];
    if (ret == -1) {
        if (choice[i] == '0') {
            ret = 0;
        } else {
            ret = dp(i+1, n);
            if (i < n-1 && (choice[i] == '1' || (choice[i] == '2' && choice[i+1] <= '6'))) {
                ret += dp(i+2, n);
                ret %= MOD; 
            }
        }
    }
    return ret;
}

void solve() {
    memset(num_choices, 0, sizeof num_choices);
    memset(memo, -1, sizeof memo);
    string s; cin >> s;
    int k; cin >> k;
    int n = s.length();
    if (n == 1) {
        if (s[0] == '?') {
            char x = '1' + 9 - k;
            cout << x << " 1" << endl;
        } else {
            cout << s << " 1" << endl;
        }
        return;
    }

    for (int i = 0; i < n-2; i++) {
        if (s[i] != '?') continue;

        if (s[i+1] == '?' || s[i+1]-'0' <= 6) {
            num_choices[i] = 2;
        } else {
            num_choices[i] = 1;
        } 
    }

    if (s[n-2] == '?') {
        if (s[n-1] != '?' && s[n-1]-'0' > 6) {
            num_choices[n-2] = 1;
        } else {
            num_choices[n-2] = 2;
        }
    }

    if (s[n-1] == '?') {
        if (s[n-2] == '2') {
            num_choices[n-1] = 7;
        } else {
            num_choices[n-1] = 10;
        }
    }

    // for (int i = 0; i < n; i++) printf("%d ", num_choices[i]); printf("\n");

    k--;
    int nn = n;
    if (s[n-1] == '?' && s[n-2] == '?') {
        int kk = k % 17;
        int y = 26 - k - 1;
        choice[n-2] = '0' + y / 10;
        choice[n-1] = '1' + (y % 10);
        nn = n-2;
    }
    for (int i = nn; i --> 0;) {
        if (num_choices[i] == 0) {
            choice[i] = s[i];
            // printf("choice[%d]: %d\n", i, choice[i]);
            continue;
        }

        int kk = k % num_choices[i];
        // printf("kk: %d\n", kk);
        if (num_choices[i] > 2) {
            choice[i] = '0' + num_choices[i] - kk - 1;
        } else {
            choice[i] = '1' + num_choices[i] - kk - 1;
        }
        k -= kk;
        k /= num_choices[i];
        // printf("k[%d]: %d\n", i, k);
        // printf("choice[%d]: %d\n", i, choice[i]);
    }



    for (int i = 0; i < n; i++) {
        cout << choice[i];
    }
    cout << " " << dp(0, n) << endl;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int qt = 1;
    // scanf("%d", &qt);
    cin >> qt;
    
    for (int q = 0; q < qt; q++) {
        // printf("Case #%d: ", q+1);
        cout << "Case #" << q+1 << ": ";
        solve();
    }
}