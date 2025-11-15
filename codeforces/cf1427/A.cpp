#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int INF = 1e9;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

int arr[55];

void solve() {
    int n;
    scanf("%d", &n);

    bool allzero = true;
    int total = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", arr+i);
        if (arr[i] != 0) {
            allzero = false;
        }
        total += arr[i];
    }

    if (allzero) {
        printf("NO\n");
        return;
    }
    if (total == 0) {
        printf("NO\n");
        return;
    }
    sort(arr, arr+n);
    printf("YES\n");
    if (total < 0) {
        for (int i = 0; i < n; i++) {
            if(i) printf(" ");
            printf("%d", arr[i]);
        }
        printf("\n");
    } else {
        for (int i = n-1; i >= 0; i--) {
            printf("%d", arr[i]);
            if(i) printf(" ");
        }
        printf("\n");
    }

}

int main() {
    int qt = 1;
    scanf("%d", &qt);
    for (int q = 0; q < qt; q++) {
        // printf("Case #%d: ", q+1);
        solve();
    }
}