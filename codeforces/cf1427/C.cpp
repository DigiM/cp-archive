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
    int t;
    int x, y;

    bool operator <(data d) const {
        return t < d.t;
    }
};

vector<data> arr;
int val[100005];

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);

    arr.push_back((data){0, 1, 1});
    for (int i = 0; i < k; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        arr.push_back((data){a, b, c});
        val[i+1] = -INF;
    }

    int idx = 0;
    int maxim = -INF;
    sort(arr.begin(), arr.end());
    for (int i = 1; i <= k; i++) {
        while (idx < i) {
            if (arr[i].t - arr[idx].t < 2*n) {
                break;
            }
            maxim = max(val[idx], maxim);
            idx++;
        }
        int curr = -INF;
        // printf("idx %d: %d\n", i, idx);
        for (int j = idx; j < i; j++) {
            if (abs(arr[i].x-arr[j].x) + abs(arr[i].y-arr[j].y) <= arr[i].t-arr[j].t) {
                curr = max(curr, val[j]+1);
                // printf("%d %d can\n", j, i);
            }
        }
        val[i] = max(curr, maxim+1);
        // printf("%d: %d\n", i, val[i]);
    }
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        ans = max(ans, val[i]);
    }
    printf("%d\n", ans);
}

int main() {
    int qt = 1;
    //scanf("%d", &qt);
    for (int q = 0; q < qt; q++) {
        // printf("Case #%d: ", q+1);
        solve();
    }
}