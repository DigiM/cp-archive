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

// bool is_not_prime[1000005];
// vector<int> primes;
vector<int> check_primes;
bool visited[1000005];


int arr[100005];
int new_arr[100005];
ll coeff[100005];
ll coef[100005];

// void sieve() {
//     is_not_prime[0] = true;
//     is_not_prime[1] = true;
//     for (ll i = 2; i*i <= 1000000; i++) {
//         if (is_not_prime[i]) continue;
//         for (ll j = i*i; j <= 1000000; j += i) {
//             is_not_prime[j] = true;
//         }
//     }

//     for (int i = 0; i <= 1000000; i++) {
//         if (!is_not_prime[i]) primes.push_back(i);
//     }
// }

// bool is_prime(int x) {
//     return !is_not_prime[x];
// }

void populate_coeff(int x) {
    coeff[1] = 1;
    coeff[2] = 2;
    for (int i = 3; i <= 100000; i++) {
        coeff[i] = (x-1)*coeff[i-2]+coeff[i-1];
        coeff[i] %= MOD;
    }
}

void populate_coef(int x) {
    coef[1] = 0;
    coef[2] = 1;
    for (int i = 3; i <= 100000; i++) {
        coef[i] = (x-1)*coef[i-2]+coef[i-1];
        coef[i] %= MOD;
    }
}

ll exp(ll x, ll y) {
    if (y == 0) return 1;
    ll res = exp(x, y/2);
    res = (res * res) % MOD;
    if (y % 2) res = (res * x) % MOD;
    return res; 
}

ll calc(ll x, ll i) {
    if (x == 1 || i == 0) return 1;
    ll res = (coeff[i] * x) % MOD;
    res = (res + MOD - coef[i]) % MOD;
    printf("calc %lld %lld %lld\n", x, i, coef[i]);
    return res;
} 

int get_exp(ll x, ll y) {
    int tmp = 1;
    while (x % y == 0) {
        x /= y;
        tmp++;
    }
    return tmp;
}

void solve() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr+i);
    }
    // sieve();

    for (int i = 0; i < n; i++) {
        int x = arr[i];
        for (ll j = 2; j*j <= x; j++) {
            if (!visited[j]) {
                check_primes.push_back(j);
                visited[j] = true;
            }
            ll tmp = 1;
            while (x % j) {
                x /= j;
                tmp *= j;
            }
            if (i > 0 && i < n-1 && arr[i-1] % tmp && arr[i+1] % tmp) {
                printf("0\n");
                return;
            }
        }
    }

    sort(check_primes.begin(), check_primes.end());

    // there should be a little now
    ll res = 1;
    for (int p : check_primes) {
        populate_coeff(p);
        populate_coef(p);
        new_arr[0] = get_exp(arr[0], p);
        new_arr[n] = get_exp(arr[n-1], p);
        for (int i = 1; i < n; i++) {
            new_arr[i] = min(get_exp(arr[i-1], p), get_exp(arr[i], p));
        }
        printf("checking %d\n", p);
        for (int i = 0; i <= n; i++) {
            printf("%d ", new_arr[i]);
        }
        printf("\n");
        
        ll now = new_arr[0];
        int cnt = 1;
        for (int i = 1; i <= n; i++) {
            if (new_arr[i] == now) {
                cnt++;
            } else if (now > new_arr[i]) {
                res = (res * calc(now, cnt-1)) % MOD;
                now = new_arr[i];
                cnt = 1;
            } else {
                res = (res * calc(now, cnt)) % MOD;
                now = new_arr[i];
                cnt = 0;
            }
        }
        res = (res * calc(now, cnt)) % MOD;
        printf("res: %lld\n", res);
    }

    printf("%lld\n", res);
} 

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int qt = 1;
    // scanf("%d", &qt);
    // cin >> qt;
    
    for (int q = 0; q < qt; q++) {
        // printf("Case #%d: ", q+1);
        // cout << "Case #" << q+1 << ": ";
        solve();
    }
}