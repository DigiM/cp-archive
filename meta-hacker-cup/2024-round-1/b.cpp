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

const int MAXIM = 1e7;

bool is_not_prime[MAXIM+5];
int ans[MAXIM+5];

void precalculate() {
    is_not_prime[0] = true;
    is_not_prime[1] = true;
    for (int i = 2; i*i <= MAXIM; i++) {
        if (is_not_prime[i]) continue;
        for (long long j = (long long)i*i; j <= MAXIM; j += i) {
            is_not_prime[j] = true;
        }
    }

    ans[1] = 0;
    ans[2] = 0;
    for (int i = 3; i <= MAXIM; i++) {
        ans[i] = ans[i-1];
        if (i == 5) ans[i]++;
        if (!is_not_prime[i] && !is_not_prime[i-2]) ans[i]++; 
    }
}

void solve() {
    int x; scanf("%d", &x);
    printf("%d\n", ans[x]);   
}

int main() {
    precalculate();
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int qt = 1;
    scanf("%d", &qt);
    // cin >> qt;
    
    for (int q = 0; q < qt; q++) {
        printf("Case #%d: ", q+1);
        // cout << "Case #" << q+1 << ": ";
        solve();
    }
}