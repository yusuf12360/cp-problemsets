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
bool less_than(int a, int b, int c) { // check if a/b < c
    assert(b != 0);
    if(b > 0) return a < b * c;
    return a > b * c;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(11) << flush;
    int n, s, tot = 0; cin >> n >> s;
    vi a(n); for(int &p : a) cin >> p, tot += p;
    sort(all(a));

    vector<ld> ans;
    int m = -n;
    bool can = 1;

    assert(m != 0);
    if(less_than(s - tot, m, a[0])) ans.pb((ld)(s - tot) / m);
    for(int i = 0; i < n - 1; i++) {
        m += 2;
        tot -= 2 * a[i];
        if(m == 0) {
            if(s == tot && a[i] != a[i + 1]) can = 0;
        } else if(!less_than(s - tot, m, a[i]) && less_than(s - tot, m, a[i + 1]))
            ans.pb((ld)(s - tot) / m);
    }
    m += 2;
    tot -= 2 * a[n - 1];
    assert(m != 0);
    if(!less_than(s - tot, m, a[n - 1])) ans.pb((ld)(s - tot) / m);
    sort(all(ans));

    if(can) {
        int k = sz(ans);
        assert(k <= 2);
        cout << k << '\n';
        for(int i = 0; i < k; i++) {
            cout << ans[i];
            if(i < k - 1) cout << ' ';
        }
        cout << '\n';
    } else cout << "-1\n";
    return 0;
}