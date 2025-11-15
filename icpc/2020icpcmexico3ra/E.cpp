#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int INF = 1e9;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

int arr[100005];
int ans[100005];

void solve() {
    int n, b; scanf("%d%d", &n, &b);
    int minim_idx = 0;
    int minim_val = INF;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        arr[i] = x;
        if (x < minim_val) {
            minim_idx = i;
            minim_val = x;
        }
    }

    // printf("%d %d\n", minim_idx, minim_val);

    int now = minim_idx;
    stack<int> valid;
    int currheight = 0;
    if (minim_val > 0) {
        currheight = 1;
    }
    while(true) {
        int next = (now+1)%n;
        if (arr[next] > arr[now]) {
            ans[next] = 1;
            currheight++;
        } else if (arr[next] < arr[now]) {
            if (arr[next] != 0) {
                if (currheight == 1) {
                    int tmp;
                    while (!valid.empty()) {
                        tmp = valid.top();
                        int tmp_previ = (tmp-1+n)%n;
                        if (ans[tmp] == -1 && arr[tmp] != arr[tmp_previ]) {
                            valid.pop();
                        } else {
                            break;
                        }
                    }
                    ans[tmp]++;
                    currheight++;
                }
                ans[next] = -(currheight-1);
                currheight = 1;
            } else {
                ans[next] = -currheight;
                currheight = 0;
                while (!valid.empty()) valid.pop();
            }
        } else {
            if (currheight > 1) {
                ans[next] = -(currheight-1);
                currheight = 1;
            }
        }
        if (next == minim_idx) break;
        valid.push(next);
        now = next;
    }

    if (minim_val == 0) {
        ans[minim_idx] = 0;
    } else {
        ans[minim_idx] = 1;
    }
    int previ = ans[minim_idx];
    for (int i = 1; i < n; i++) {
        int now = (minim_idx+i)%n;
        ans[now] += previ;
        previ = ans[now];
    }

    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%lld", (ll)b*ans[i]);
    }
    printf("\n");

}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int qt = 1;
    //scanf("%d", &qt);
    for (int q = 0; q < qt; q++) {
        // printf("Case #%d: ", q+1);
        solve();
    }
}