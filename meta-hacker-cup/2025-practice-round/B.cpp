#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

const int INF = 1e9;
const int MOD = 1e9+7;
const double EPS = 1e-9;

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

int r, c, k;
vector<vector<int> > dist;

void bfs() {
    queue<pii> q;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (dist[i][j] == 0) {
                q.push(mp(i, j));
            }
        }
    }
    // cout << "okay\n";
    while (!q.empty()) {
        pii now = q.front();
        q.pop();

        // cout << "process " << now.fi << " " << now.se << endl;

        int ddist = dist[now.fi][now.se];
        for (int d = 0; d < 4; d++) {
            pii next = mp(now.fi + dr[d], now.se + dc[d]);
            if (next.fi < 0 || next.fi >= r || next.se < 0 || next.se >= c || dist[next.fi][next.se] != -1) {
                continue;
            }
            dist[next.fi][next.se] = ddist+1;
            q.push(next);
        }
    }
}

int floodfill(pii now) {
    queue<pii> q;

    dist[now.fi][now.se] = -1;
    q.push(now);

    int ans = 1;
    while (!q.empty()) {
        pii now = q.front();
        q.pop();

        // cout << "process " << now.fi << " " << now.se << endl;

        for (int d = 0; d < 4; d++) {
            pii next = mp(now.fi + dr[d], now.se + dc[d]);
            if (next.fi < 0 || next.fi >= r || next.se < 0 || next.se >= c || dist[next.fi][next.se] <= k) {
                continue;
            }
            dist[next.fi][next.se] = -1;
            ans++;
            q.push(next);
        }
    }
    return ans;
}

void solve() {
    for (auto x : dist) {
        x.clear();
    }
    dist.clear();

    // cout << "input\n";
    cin >> r >> c >> k;
    vector<int> f, l;
    for (int i = 0; i < c+2; i++) {
        f.push_back(0);
        l.push_back(0);
    }
    dist.push_back(f);
    for (int i = 0; i < r; i++) {
        string s; cin >> s;
        vector<int> x;
        x.push_back(0);
        for (int j = 0; j < c; j++) {
            char ch = s[j];
            if (ch == '.') x.push_back(-1);
            else x.push_back(0);
        }
        x.push_back(0);
        dist.push_back(x);
    }
    dist.push_back(l);
    r += 2;
    c += 2;

    // cout << "asd\n";

    bfs();
    // cout << "bfs\n";
    int ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (dist[i][j] > k) {
                ans = max(ans, floodfill(mp(i, j)));
            }
        }
    }
    cout << ans << endl;
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