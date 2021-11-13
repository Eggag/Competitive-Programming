#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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
const int mxN = 1e7 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int ans[mxN], p[mxN];
int res[mxN];

void sieve(int n){
	for(int i = 2; i < n; i++) if(!p[i]){
		p[i] = i;
		for(int j = i + i; j < n; j += i) if(!p[j]) p[j] = i;
	}	
}

void solve(){
	sieve(mxN - 1);
	memset(ans, -1, sizeof(ans));
	ans[1] = 1, res[1] = 1;
	repn(i, 2, mxN - 2){
		int d = p[i];
		int cur = i;
		ll mul = 1LL;
		while(cur % d == 0) cur /= d, mul *= (ll)(d);
		mul *= (ll)(d);
		mul--;
		ll nw = (ll)(1LL * res[cur] * mul / (ll)(d - 1));
		res[i] = nw;
		if(nw >= mxN) continue;
		if(ans[nw] == -1) ans[nw] = i;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	solve();
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << ans[n] << '\n';
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
