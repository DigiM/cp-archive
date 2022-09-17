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

const int MAXN = 5e5 + 5;

int compressi;
unordered_map<int, int> compress;

int n;

int cnt[MAXN];
int tmpS[MAXN];
int RA[MAXN],tmpR[MAXN];

int arr_a[MAXN], arr_b[MAXN];
int sa_a[MAXN], sa_b[MAXN];

void radixSort(int *SA, int k){
    for(int i = 0 ; i < 2*n ; i++) cnt[i] = 0;
    for(int i = 0 ; i < n ; i++) {
        cnt[i + k < n ? RA[i + k] : 0]++;
    }
    int tot = 0;
    for(int i = 0 ; i < 2*n ; i++){
        int tmp = cnt[i];
        cnt[i] = tot;
        tot += tmp;
    }
    for(int i = 0 ; i < n ; i++) tmpS[cnt[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    for(int i = 0 ; i < n ; i++) SA[i] = tmpS[i];
}

void buildSA(int* s, int* SA) {

    for(int i = 0 ; i < n ; i++){
        SA[i] = i;
        RA[i] = s[i];
        tmpS[i] = 0;
        tmpR[i] = 0;
    }

    for(int lg = 1 ; lg < n ; lg <<= 1){
        // printf("lg: %d\n", lg);
        radixSort(SA, lg);
        radixSort(SA, 0);
        int tot = 0;
        tmpR[SA[0]] = 0;
        for(int i = 1 ; i < n ; i++) tmpR[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && SA[i] + lg < n && SA[i - 1] + lg < n && RA[SA[i] + lg] == RA[SA[i - 1] + lg]) ? tot : ++tot;
        for(int i = 0 ; i < n ; i++) RA[i] = tmpR[i];
        if(RA[SA[n - 1]] == n - 1) break;
    }
}

void solve() {
    compressi = 1;
    compress.clear();

    int k;
    scanf("%d%d", &n, &k);

    bool same = true;

    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (compress[x] == 0) {
            compress[x] = compressi++;
        }
        arr_a[i] = compress[x];
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        arr_b[i] = compress[x];
        if (arr_b[i] != arr_a[i]) {
            same = false;
        }
    }

    if (same) {
        if(n == 2) {
            if (k%2) printf("NO\n");
            else printf("YES\n");
        } else if (k == 1) {
            if (n%2 == 0) {
                bool still_can = true;
                for (int i = 0; i < n; i++) {
                    if (arr_a[i] != arr_b[(i+n/2)%n]) {
                        still_can = false;
                        break;
                    }
                }
                if (still_can) {
                    printf("YES\n");
                    return;
                }
            }
            printf("NO\n");
        } else {
            printf("YES\n");
        }
        return;
    }

    if (k == 0) {
        printf("NO\n");
        return;
    }
    if (n == 2) {
        if (k%2) printf("YES\n");
        else printf("NO\n");
        return;
    }

    buildSA(arr_a, sa_a);
    buildSA(arr_b, sa_b);

    for (int i = 0; i < n; i++) {
        if (arr_a[(sa_a[0]+i)%n] != arr_b[(sa_b[0]+i)%n]) {
            printf("NO\n");
            return;
        }
    }
 
    printf("YES\n");
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