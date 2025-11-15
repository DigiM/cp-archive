// Previously submitted in DigiM (wrong account sorry tehe)

#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int arr[50005];
int reyn[405][50005];

// for precomp
int sudah[50005];

void precomp() {
    for (int i = 0; i <= k; i++) {
        int sampai = 0;
        int sekarang = i;
        for (int j = 0; j < n; j++) {
            while (sampai < n) {
                if (sudah[arr[sampai]] >= m) {
                    if (sekarang == 0) {
                        break;
                    } else {
                        sekarang--;
                    }
                }
                sudah[arr[sampai]]++;
                sampai++;
            }
            reyn[i][j] = sampai;
            sudah[arr[j]]--;
            if (sudah[arr[j]] >= m) {
                sekarang--;
            }
            // printf("reyn %d %d %d\n", i, j, reyn[i][j]);
        }
    }
}

int rey[405][50005];

int dp(int dowh, int nal) {
    if (dowh == n) {
        return 0;
    }

    int &ret = rey[nal][dowh];
    if (ret == -1) {
        ret = n;
        for (int al = 0; al <= nal; al++) {
            ret = min(ret, dp(reyn[al][dowh], nal-al)+1);
        }
    }
    return ret;
}

int main() {
    memset(rey, -1, sizeof rey);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (k >= n) {
        cout << 0 << endl;
        return 0;
    }

    precomp();
    cout << dp(0, k) << endl;
    
}