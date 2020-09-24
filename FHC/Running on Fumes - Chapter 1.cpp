#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
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
const int mxN = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dp[mxN];

ll solve(){
	ll n, m;
	cin >> n >> m;
	vector<ll> c(n);
	rep(i, n) cin >> c[i];
	rep(i, n) dp[i] = 1e18;
	dp[0] = 0;
	multiset<ll> st;
	st.insert(dp[0]);
	vi vis(n, 0);
	vis[0] = 1;
	repn(i, 1, n){
		if(i >= (m + 1) && vis[i - m - 1]){
			auto it = st.find(dp[i - m - 1]);
			if(it != st.end()) st.erase(it);
		}		
		if(!st.size()) break;
		if(c[i]){
			vis[i] = 1;
			dp[i] = *st.begin() + c[i];
			st.insert(dp[i]);
		}
	}
	ll ret = 1e18;
	for(ll i = n - 1; i >= max(0LL, (n - (m + 1))); i--) ret = min(ret, dp[i]);
	if(ret == 1e18) ret = -1;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": " << solve() << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
