#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second

struct data {
    int i, val;
};

vector<data> arr;
set<pii> val;

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        arr.push_back((data){i, val});
    }
    int m; scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        ll x; scanf("%lld", &x);
    }

}