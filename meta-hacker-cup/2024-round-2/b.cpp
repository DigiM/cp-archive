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

char grid[7][6];
char grid_tmp[7][6];
int memo[7][7][7][7][7][7][7];

int dx[] = {1, 0, 1, 1};
int dy[] = {0, 1, 1, -1};

char check_grid(int a, int b, int c, int d, int e, int f, int g) {
    int heights[] = {a,b,c,d,e,f,g};
    for (int x = 0; x < 7; x++) {
        for (int y = 0; y < 6; y++) {
            grid_tmp[x][y] = heights[x] <= 6-y-1 ? '.' : grid[x][y];
        }
    }
    
    for (int x = 0; x < 7; x++) {
        for (int y = 0; y < 7; y++) {
            if (grid_tmp[x][y] == '.') continue;
            for (int i = 0; i < 4; i++) {
                bool yes = true;
                for (int j = 1; j < 4; j++) {
                    int xx = x + j*dx[i];
                    int yy = y + j*dy[i];
                    if (xx < 0 || xx >= 7 || yy < 0 || yy >= 6 || grid_tmp[xx][yy] != grid_tmp[x][y]) {
                        yes = false;
                        break;
                    }
                }
                if (yes) {
                    // printf("found at %d %d %d\n", x, y, i);
                    return grid_tmp[x][y];
                }
            }
        }
    }

    return '.';
}

int dp(int a, int b, int c, int d, int e, int f, int g, bool is_c) {
    int &ret = memo[a][b][c][d][e][f][g];
    if (ret == -1) {
        char win = check_grid(a,b,c,d,e,f,g);
        if (win != '.') {
            ret = win == 'C' ? 1 : 2;
        } else {
            ret = 0;
            char cmp = is_c ? 'C' : 'F';
            int heights[] = {a, b, c, d, e, f, g};
            for (int i = 0; i < 7; i++) {
                if (heights[i] == 6) {
                    continue;
                }

                if (grid[i][6-heights[i]-1] == cmp) {
                    heights[i]++;
                    ret |= dp(heights[0], heights[1], heights[2], heights[3], heights[4], heights[5], heights[6], !is_c);
                    heights[i]--;
                }
            }
        }
    }
    return ret;
}

void solve() {
    memset(memo, -1, sizeof memo);
    for (int i = 0; i < 6; i++) {
        string s; cin >> s;
        // cout << s << endl;
        for (int j = 0; j < 7; j++) {
            grid[j][i] = s[j];
        }
    }

    // printf("%c\n", check_grid(6,6,4,4,5,5,3));

    int ans = dp(0, 0, 0, 0, 0, 0, 0, true);
    // int ans = 0;
    if (ans == 0) cout << "0" << endl;
    if (ans == 1) cout << "C" << endl;
    if (ans == 2) cout << "F" << endl;
    if (ans == 3) cout << "?" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int qt = 1;
    // scanf("%d", &qt);
    cin >> qt;
    
    for (int q = 0; q < qt; q++) {
        // printf("Case #%d: ", q+1);
        cout << "Case #" << q+1 << ": ";
        solve();
    }
}