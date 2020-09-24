#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sq(x) ((x) * (x))
const int MOD = 1e9 + 7;
 
template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }
 
string s[55][1505];
ll dp[55][1505];
 
bool good(string b, string a){
    rep(i, b.size() - a.size() + 1) if(b.substr(i, a.size()) == a) return 1;
    return 0;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    rep(i, n) rep(j, k) cin >> s[i][j];
    rep(i, k) dp[0][i] = 1;
    repn(i, 1, n) rep(j, k) rep(l, k){
        if(good(s[i][j], s[i - 1][l])) dp[i][j] = (dp[i][j] + dp[i - 1][l]) % MOD;
    }
    ll ans = 0;
    rep(i, k) ans = (ans + dp[n - 1][i]) % MOD;
    cout << ans << endl;
    return 0;
}
/*
Things to look out for:
    - Integer overflows
    - Array bounds
    - Special cases
Be careful!
*/
