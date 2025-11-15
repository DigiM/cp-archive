#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
typedef long long ll;

vector<int> val;
ll memo[2005][4005][2][2];

ll dp(int pos, int selisih, bool finish, bool skipped) {
    if (pos == val.size()) {
        if (selisih == 2000 && finish) {
            return 1;
        }
        if (selisih == 2000 && !finish && !skipped) {
            return 1;
        }
        return 0;
    }
    ll &ret = memo[pos][selisih][finish][skipped];
    if (ret == -1) {
        ret = 0;
        // taro merah
        ret = (ret+dp(pos+1, selisih+val[pos], finish, skipped))%mod;
        // taro biru
        ret = (ret+dp(pos+1, selisih-val[pos], finish, skipped))%mod;
        // skip
        ret = (ret+dp(pos+1, selisih, finish, true))%mod;
        // finish
        if (!finish) {
            for (int i = 1; i < val[pos]; i++) {
                ret = (ret+2*dp(pos+1, selisih-i+val[pos]-i, true, skipped))%mod;
                ret = (ret+2*dp(pos+1, selisih-i+val[pos]-i-1, true, skipped))%mod;
            }
        }
    }
    return ret;
}

vector<int> adjList[2005];
bool vis[2005];

int dfs(int pos) {
    int sz = adjList[pos].size();
    for (int i = 0; i < sz; i++) {
        int x = adjList[pos][i];
        if (!vis[x]) {
            vis[x] = true;
            return dfs(x) + 1;
        }
    }
    return 1;
}

int main() {
    memset(memo, -1, sizeof memo);

    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--;
        if (b > 0) adjList[a].push_back(b);
        if (a > 0) adjList[b].push_back(a);
    }

    int sz = adjList[0].size();
    for (int i = 0; i < sz; i++) {
        int x = adjList[0][i];
        if (!vis[x]) {
            vis[x] = true;
            int tmp = dfs(x) + 1;
            val.push_back(tmp);
        }
    }

    printf("%lld\n", dp(0, 2000, false, false));
}