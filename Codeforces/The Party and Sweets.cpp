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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<ll> b(n), g(m);
	rep(i, n) cin >> b[i];
	rep(i, m) cin >> g[i];
	ll mx = 0LL, mx1 = 0LL;
	rep(i, n){
		if(b[i] > mx){
			mx1 = mx;
			mx = b[i];
		}
		else if(b[i] > mx1) mx1 = b[i];
	}
	int f = 1;
	rep(i, m) if(g[i] < mx){
		f = 0;
		break;
	}
	if(!f) cout << -1 << endl;
	else{
		ll ans = 0LL;
		rep(i, n) ans += (ll)(1LL * m * b[i]);
		int cnt = 0;
		rep(i, m) if(g[i] > mx){
			cnt++;
			if(cnt < m) ans += max(0LL, g[i] - mx);
			else ans += max(0LL, g[i] - mx1);
		}
		cout << ans << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
