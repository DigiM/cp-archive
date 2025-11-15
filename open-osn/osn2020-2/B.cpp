#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e15;

struct data {
    int x, y;
    int r;
    int c;
};

int n;
data start, finish;
vector<data> arr;

struct point {
    int val, pos;
    int node;
    bool enter;
};

int cmp(point a, point b) {
    if (a.val == b.val) {
        return a.enter > b.enter;
    }
    return a.val < b.val;
}

struct point_set {
    int val;
    int node;

    bool operator <(point_set d) const {
        if (val == d.val) {
            return node < d.node;
        }
        return val < d.val;
    }
};

vector<point> pointpoint;
set<point_set> pointset;

void baca() {
    {
        scanf("%d", &n);
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        start.x = a;
        start.y = b;
        finish.x = c;
        finish.y = d;
    }
    start.r = finish.r = 0;
    start.c = finish.c = 0;

    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        arr.push_back((data){a, b, c, d});
    }
    arr.push_back(finish);
    n++;
}

/* definisi node

start: {0}
horizontal nodes: {1 -> m}
vertical nodes: {m+1 -> 2m}

m = n+1 (pilar + finish)
*/

struct node {
    int pos;
    long long d;

    bool operator <(node n) const {
        return d > n.d;
    }
};

vector<int> adjList[200005];
vector<int> cost[200005];

void connect_line_sweep() {
    sort(pointpoint.begin(), pointpoint.end(), cmp);
    for (point p : pointpoint) {
        // printf("point point %d %d %d %d\n", p.val, p.pos, p.node, p.enter);
        if (!p.enter) {
            pointset.erase((point_set){p.pos, p.node});
        }

        // connect greater than
        auto tmp = pointset.lower_bound((point_set){p.val, -1});
        if (tmp != pointset.end()) {
            // printf("tmp %d %d\n", tmp->val, tmp->node);
            adjList[(*tmp).node].push_back(p.node);
            adjList[p.node].push_back((*tmp).node);
            cost[(*tmp).node].push_back(0);
            cost[p.node].push_back(0);
            // printf("new edge %d %d %d\n", tmp->node, p.node, 0);
        }

        // x x x o o o x x x x o

        // connect less than
        auto tmp2 = pointset.upper_bound((point_set){p.val, 3*n});
        if (tmp2 != pointset.begin()) {
            tmp2--;
            // printf("tmp2 %d %d\n", tmp2->val, tmp2->node);
            adjList[(*tmp2).node].push_back(p.node);
            adjList[p.node].push_back((*tmp2).node);
            cost[(*tmp2).node].push_back(0);
            cost[p.node].push_back(0);
            // printf("new edge %d %d %d\n", tmp2->node, p.node, 0);
        }

        if (p.enter) {
            pointset.insert((point_set){p.pos, p.node});
        }
    }
}

long long dist[200005];
priority_queue<node> pq;

long long djikstra(int start, int goal) {
    for (int i = 1; i < 2*n+1; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    pq.push((node){start, 0});
    while (!pq.empty()) {
        auto tmp = pq.top();
        pq.pop();
        if (tmp.d != dist[tmp.pos]) {
            continue;
        }
        if (tmp.pos == goal) {
            return dist[tmp.pos];
        }

        for (int i = 0; i < (int)adjList[tmp.pos].size(); i++) {
            int tmp2 = adjList[tmp.pos][i];
            int c2 = cost[tmp.pos][i];
            if (tmp.d + c2 < dist[tmp2]) {
                dist[tmp2] = tmp.d + c2;
                pq.push((node){tmp2, dist[tmp2]});
            }
        }
    }
    return -1;
}

void kerja() {
    // printf("wkwk 1\n");
    // line sweep vertical (connect horizontal)
    for (int i = 0; i < n; i++) {
        pointpoint.push_back((point){arr[i].y-arr[i].r, arr[i].x, 1+i, true});
        pointpoint.push_back((point){arr[i].y+arr[i].r, arr[i].x, 1+i, false});
    }
    pointpoint.push_back((point){start.y, start.x, 0, true});
    pointpoint.push_back((point){start.y, start.x, 0, false});
    connect_line_sweep();

    pointpoint.clear();

    // printf("wkwk 2\n");
    // line sweep horizontal (connect vertical)
    for (int i = 0; i < n; i++) {
        pointpoint.push_back((point){arr[i].x-arr[i].r, arr[i].y, n+1+i, true});
        pointpoint.push_back((point){arr[i].x+arr[i].r, arr[i].y, n+1+i, false});
    }
    connect_line_sweep();

    // printf("wkwk 3\n");
    // connect sendiri
    for (int i = 0; i < n; i++) {
        int a = 1+i;
        int b = n+1+i;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
        cost[a].push_back(arr[i].c);
        cost[b].push_back(arr[i].c);
        // printf("new edge %d %d %d\n", a, b, arr[i].c);
    }

    long long ans = djikstra(0, 2*n);
    printf("%lld\n", ans);
}

int main() {
    baca();
    kerja();
}