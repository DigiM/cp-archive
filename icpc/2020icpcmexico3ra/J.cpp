#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int INF = 1e9;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

int n, m, k;
int o, t;

vector<int> adjList[1005];
int dist[1005][1005];

void precomp_dijkstra() {
    memset(dist, -1, sizeof dist);
    for (int i = 0; i < n; i++) {
        queue<int> q;
        q.push(i);
        dist[i][i] = 0;
        while (!q.empty()) {
            int now = q.front();
            q.pop();

            for (int j = 0; j < (int)adjList[now].size(); j++){
                int nxt = adjList[now][j];
                if (dist[i][nxt] == -1) {
                    q.push(nxt);
                    dist[i][nxt] = dist[i][now] + k;
                }
            }
        }
    }
}

int arr[1005];
int val[1005];
int cost[1005];
int dp[1005][10005];

int hitung(int pos, int sisa_waktu) {
    if (sisa_waktu < 0) {
        return -INF;
    }
    if (pos == o) {
        return 0;
    }

    int &ret = dp[pos][sisa_waktu];
    if (ret == -1) {
        ret = hitung(pos+1, sisa_waktu);
        ret = max(ret, hitung(pos+1, sisa_waktu-cost[pos]) + val[pos]);
    }
    return ret;
}

void solve() {
    memset(dp, -1, sizeof dp);

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d%d", &a, &b);
        a--; b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    precomp_dijkstra();

    scanf("%d%d", &o, &t);

    int sisa_waktu = t;
    for (int i = 0; i < o; i++) {
        scanf("%d", arr+i);
        arr[i]--;
        if (i) {
            sisa_waktu -= dist[arr[i-1]][arr[i]];
        }
    }
    arr[o] = 0;
    sisa_waktu -= dist[0][arr[0]] + dist[arr[o-1]][0];
    if (sisa_waktu < 0) {
        printf("Impossible\n");
        return;
    }

    for (int i = 0; i < o; i++) {
        int a, b; scanf("%d%d", &a, &b);
        a--;
        val[i] = b;
        cost[i] = dist[arr[i]][a] + dist[a][arr[i+1]] - dist[arr[i]][arr[i+1]];
    }
    
    printf("%d\n", hitung(0, sisa_waktu));

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