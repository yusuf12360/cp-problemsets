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
const int MX = 1e6;
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    vi ans(k);
    for(int i = 1; i <= min(n, 9ll); i++) ans[i % k]++;
    for(int i = 1; i < MX; i++) {
        int cur = i, temp = i;
        while(temp) cur = cur * 10 + (temp % 10), temp /= 10;
        if(cur <= n) ans[cur % k]++;

        for(int dig = 0; dig < 10; dig++) {
            cur = i; temp = i;
            cur = cur * 10 + dig;
            while(temp) cur = cur * 10 + (temp % 10), temp /= 10;
            if(cur <= n) ans[cur % k]++;
        }
    }
    for(int i=0;i<ans.size();i++) {
        cout << ans[i];
        if(i < ans.size()-1) cout << " ";
    }
    cout << endl;
    return 0;
}