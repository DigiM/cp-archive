#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int INF = 1e9;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

int cnt[30];
int dist[30][30];

void reset() {
    for (int i = 0; i < 26; i++) {
        cnt[i] = 0;
        for (int j = 0; j < 26; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF;
            }
        }
    }
}

void APSP() {
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (i != j && i != k && j != k) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

void solve() {
    APSP();
    int ans = INF;
    for (int i = 0; i < 26; i++) {
        int tmp = 0;
        for (int j = 0; j < 26; j++) {
            if (cnt[j] > 0 && dist[j][i] == INF) {
                tmp = INF;
                break;
            }
            tmp += cnt[j]*dist[j][i];
        }
        ans = min(ans, tmp);
    }

    if (ans == INF) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
}

string vowels = "AEIOU";
string consonants = "BCDFGHJKLMNPQRSTVWXYZ";

void solve_1() {
    string s; cin >> s;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        cnt[s[i]-'A']++;
    }

    for (char v : vowels) {
        for (char c : consonants) {
            dist[v-'A'][c-'A'] = 1;
            dist[c-'A'][v-'A'] = 1;
        }
    }

    solve();
}

void solve_2() {
    string s; cin >> s;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        cnt[s[i]-'A']++;
    }

    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        string t; cin >> t;
        dist[t[0]-'A'][t[1]-'A'] = 1;
    }

    solve();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int qt = 1;
    // scanf("%d", &qt);
    cin >> qt;
    for (int q = 0; q < qt; q++) {
        // printf("Case #%d: ", q+1);
        cout << "Case #" << q+1 << ": ";
        reset();
        solve_1();
    }
}