#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int INF = 1e9;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

vector<int> arr;
vector<int> ops;
vector<vector<int> > ans;

void rearrange(int n) {
    vector<int> tmp;
    int curr = n;
    int m = ops.size();
    for (int i = m-1; i >= 0; i--) {
        for (int j = ops[i]; j > 0; j--) {
            tmp.push_back(arr[curr-j]);
        }
        curr-=ops[i];
    }
    for (int i = 0; i < n; i++) {
        arr[i] = tmp[i];
    }
}

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        arr.push_back(x);
    }

    bool where = false;
    if (n%2) {
        where = true;
        reverse(arr.begin(), arr.end());
    }

    for (int i = 0; i < n; i++) {
        ops.clear();
        for (int j = 0; j < i; j++) {
            ops.push_back(1);
        }
        for (int j = i; j < n; j++) {
            if (arr[j] == i+1) {
                ops.push_back(j-i+1);
                if (j < n-1) ops.push_back(n-j-1);
                break;
            }
        }
        rearrange(n);
        if (ops.size() > 1) {
            if (where) reverse(ops.begin(), ops.end());
            ans.push_back(ops);
        }
        where = !where;
        reverse(arr.begin(), arr.end());

        // for (auto x : arr) {
        //     printf(" %d", x);
        // }
        // printf("\n");
    }

    printf("%d\n", (int)ans.size());
    for (auto v : ans) {
        printf("%d", (int)v.size());
        for (auto x : v) {
            printf(" %d", x);
        }
        printf("\n");
    }

}

int main() {
    int qt = 1;
    //scanf("%d", &qt);
    for (int q = 0; q < qt; q++) {
        // printf("Case #%d: ", q+1);
        solve();
    }
}