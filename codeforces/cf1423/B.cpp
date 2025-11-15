#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int INF = 1e9;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

struct data {
    int x, y;
    int val;

    bool operator <(data o) const {
        return val < o.val;
    }
};

vector<data> arr;
vector<int> adj[10005];

int match[20005];
int dist[20005];

// node from 1..n 
// 0 is NIL 
// left side 1..n 
// right side n+1..n+m 
// G = {0} U {1..n} U {n+1..n+m} 
bool bfs(int n) { 
 queue<int> q; 
 for(int i = 1 ; i <= n ; i++) 
 if(match[i] == 0) { 
 dist[i] = 0; 
 q.push(i); 
 } 
 else 
 dist[i] = INF; 
 dist[0] = INF; 
  
 while(!q.empty()) { 
 int cur = q.front(); 
 q.pop(); 
 if(cur) { 
 for(int nex : adj[cur]) { 
 if(dist[match[nex]] == INF) { 
 dist[match[nex]] = dist[cur] + 1; 
 q.push(match[nex]); 
 } 
 } 
 } 
 } 
  
 return dist[0] != INF;  
} 
int dfs(int now) { 
 if(now == 0) return 1; // found 1 augmenting path 
 for(int nex : adj[now]) { 
 if(dist[match[nex]] == dist[now] + 1 && dfs(match[nex])) { 
 match[nex] = now; 
 match[now] = nex; 
 return 1; 
 } 
 } 
 dist[now] = INF; 
 return 0; 
} 
int hopcroftKarp(int n, int x) { 
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }
    // printf("graph:::%d\n", x);
    for (int i = 0; i <= x; i++) {
        int a = arr[i].x;
        int b = arr[i].y;
        adj[a].push_back(b);
        // printf("graph %d %d\n", a, b-n);
    }
 int ret = 0; 
 memset(match, 0, sizeof match); 
 while(bfs(n)) { 
 for(int i = 1 ; i <= n ; i++) 
 if(match[i] == 0) 
 ret += dfs(i); 
 }  
//  printf("ret: %d %d\n", x, ret);
 return ret; 
} 


void solve() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        arr.push_back((data){a, n+b, c});
    }

    sort(arr.begin(), arr.end());

    int l = 0;
    int r = m-1;
    int ans = -1;
    while (l <= r) {
        int c = (l+r)>>1;
        if (hopcroftKarp(n, c) == n) {
            ans = c;
            r = c-1;
        } else {
            l = c+1;
        }
    }

    printf("%d\n", ans==-1?-1:arr[ans].val);
}

int main() {
    int qt = 1;
    //scanf("%d", &qt);
    for (int q = 0; q < qt; q++) {
        // printf("Case #%d: ", q+1);
        solve();
    }
}