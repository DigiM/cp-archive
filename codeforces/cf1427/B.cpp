#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int INF = 1e9;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

string s;
vector<int> arr;

void solve() {
    arr.clear();

    int n, k;
    cin >> n >> k;
    cin >> s;
    int score = 0;
    bool previ = false;
    int first = 0;
    int curr = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') {
            score += 1 + previ;
            previ = true;
            if (curr > 0) arr.push_back(curr);
            curr = 0;
        } else {
            previ = false;
            if (curr >= 0) curr++;
            else first++;
        }
    }
    if (curr == -1) {
        printf("%d\n", max(2*min(k, n)-1, 0));
        return;
    }
    first += curr;
    // printf("%d\n", score);
    sort(arr.begin(), arr.end());
    for (int x : arr) {
        if (x > k) {
            score += k + k;
            k = 0;
            break;
        } else {
            score += x + x + 1;
            k-= x;
        }
    }
    // printf("s %d %d %d\n", first, k, score);
    score += 2*min(first, k);
    printf("%d\n", score);
}

int main() {
    int qt = 1;
    //scanf("%d", &qt);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> qt;
    for (int q = 0; q < qt; q++) {
        // printf("Case #%d: ", q+1);
        solve();
    }
}