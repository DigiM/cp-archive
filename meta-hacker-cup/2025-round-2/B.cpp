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

const int NMAX = 1000000;

vector<int> arr_a, arr_b;
vector<int> arr_a_comp;

void solve() {
    arr_a.clear();
    arr_b.clear();
    arr_a_comp.clear();

    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        arr_a.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int x; scanf("%d", &x);
        arr_b.push_back(x);
    }

    sort(arr_a.begin(), arr_a.end());
    sort(arr_b.begin(), arr_b.end());
    
    int curr = 1;
    int same = arr_a[n-1];
    for (int i = n-1; i --> 0;) {
        if (arr_a[i] == same) {
            curr++;
        } else {
            arr_a_comp.push_back(curr);
            curr = 1;
            same = arr_a[i];
        }
    }
    arr_a_comp.push_back(curr);


    // printf("awkowakowa\n");
    int it = 0;
    int ans = 0;
    n = (int)arr_a_comp.size();
    int x = 0;
    for (int i = 0; i < n; i++) {
        x += arr_a_comp[i];
        int sum = 0;

        while (sum < x && it < m) {
            // printf("i: %d %d, it: %d, sum: %d\n", i, x, it, sum);
            if (sum + arr_b[it] < x) {
                sum += arr_b[it++];
            } else {
                int leftover = arr_b[it] - (x - sum);
                if (i != n-1) {
                    leftover = min(leftover, (x+arr_a_comp[i+1]) - (x-sum));
                }
                // printf("leftover: %d\n", leftover);
                arr_b[it] = leftover;
                ans+=arr_a_comp[i];
                break;
            }
        }
        if (it >= m) {
            break;
        }
    }
    printf("%d\n", ans);
}

int main() {
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