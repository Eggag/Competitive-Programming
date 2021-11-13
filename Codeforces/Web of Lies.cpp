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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vi deg(n, 0);
	rep(i, m){
		int u, v;
		cin >> u >> v;
		u--, v--;
		if(u < v) swap(u, v);
		deg[v]++;
	}
	int ans = 0;
	rep(i, n) if(!deg[i]) ans++;
	int q;
	cin >> q;
	rep(i, q){
		int t;
		cin >> t;
		if(t == 1){
			int u, v;
			cin >> u >> v;
			u--, v--;
			if(u < v) swap(u, v);
			if(!deg[v]) ans--;
			deg[v]++;
		}
		else if(t == 2){
			int u, v;
			cin >> u >> v;
			u--, v--;
			if(u < v) swap(u, v);
			deg[v]--;
			if(!deg[v]) ans++;
		}
		else cout << ans << '\n';
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
