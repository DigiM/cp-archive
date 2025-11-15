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
int previ[100005];
int nexti[100005];

vector<pii> ans;

void solve() {
    memset(previ, -1, sizeof previ);
    memset(nexti, -1, sizeof nexti);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        arr.push_back(x);
    }
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 2) {
            st.push(i);
        } else if (arr[i] == 1) {
            if (st.size() > 0) {
                auto tmp = st.top();
                st.pop();
                nexti[tmp] = i;
                previ[i] = tmp;
            }
        }
    }
    if (st.size() > 0) {
        printf("%d\n", -1);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] && previ[i] == -1 && st.size() > 0) {
            auto tmp = st.top();
            st.pop();
            nexti[tmp] = i;
            previ[i] = tmp;
        }
        if (arr[i] == 3) {
            st.push(i);
        }
    }
    if (st.size() > 0) {
        printf("%d\n", -1);
        return;
    }

    int curr = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) continue;
        if (previ[i] == -1) {
            int now = i;
            // printf("start %d\n", now);
            while (now != -1) {
                if (previ[now] != -1 && arr[previ[now]] == 3) {
                    ans.push_back(mp(curr++, now));
                }
                ans.push_back(mp(curr, now));
                now = nexti[now];

                // printf("now: %d\n", now);
            }
            curr++;
        }
    }
    
    printf("%d\n", (int)ans.size());
    for (auto tmp : ans) {
        printf("%d %d\n", tmp.fi+1, tmp.se+1);
    }
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