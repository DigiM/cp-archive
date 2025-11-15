#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int INF = 1e9;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

int precomp_cnt[15][1005];
int precomp_pos[15][1005];

int cnt[15];

int get_precomp_cnt(int a, int b) {
    if (b == -1) return 0;
    return precomp_cnt[a][b];
}

void solve() {
    int n; string s;
    cin >> s; n = s.length();

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            for (int j = 1; j <= 9; j++) {
                precomp_cnt[j][i] = precomp_cnt[j][i-1];
            }
        }
        precomp_cnt[s[i]-'0'][i]++;
    }

    memset(precomp_pos, -1, sizeof precomp_pos);
    for (int i = n; i --> 0;) {
        if (i < n-1) {
            for (int j = 1; j <= 9; j++) {
                precomp_pos[j][i] = precomp_pos[j][i+1];
            }
        }
        precomp_pos[s[i]-'0'][i] = i;
        // for (int j = 1; j <= 9; j++) {
        //     printf("precomp %d %d: %d\n", j, i, precomp_pos[j][i]);
        // }
    }

    for (int i = 0; i < n; i++) {
        cnt[s[i]-'0']++;
    }
    int k = 0;
    for (int i = 1; i <= 9; i++) {
        int cntx; cin >> cntx;
        cnt[i] -= cntx;
        k += cnt[i];
    }

    string ans;
    int idx = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 9; j >= 1; j--) {
            if (cnt[j] == 0) continue;
            int nextIdx = precomp_pos[j][idx];
            bool can = true;
            // printf("checking %d: %d, nextIdx: %d\n", i, j, nextIdx);
            for (int l = 1; l <= 9; l++) {
                // printf("do %d; %d %d %d\n", l, precomp_cnt[l][n-1], precomp_cnt[l][nextIdx-1], cnt[l]);
                if (get_precomp_cnt(l, n-1) - get_precomp_cnt(l, nextIdx-1) < cnt[l]) {
                    can = false;
                    break;
                }
            }
            if (can) {
                ans += '0' + j;
                cnt[j]--;
                idx = nextIdx+1;
                break;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int qt = 1;
    //scanf("%d", &qt);
    for (int q = 0; q < qt; q++) {
        // printf("Case #%d: ", q+1);
        solve();
    }
}