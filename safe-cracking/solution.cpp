#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi> 
#define pb push_back
#define fi first
#define se second
#define TII tuple<int, int, int>
#define MT make_tuple
#define mp make_pair
#define ts to_string
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define MIN(x) *min_element(all(x))
#define MAX(x) *max_element(all(x))
#define lb lower_bound
#define ub upper_bound
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
const int MOD = 1e9 + 7;
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, ans = 1, cnt = 0; cin >> n >> k;
    while(n--) {
        int in; cin >> in;
        if(in >= 0) ans = ans * (k - in) % MOD;
        else cnt++;
    }

    if(cnt > k) ans = 0;
    else {
        while(cnt--) ans = ans * (k--) % MOD;
    }
    cout << ans << '\n';
    return 0;
}