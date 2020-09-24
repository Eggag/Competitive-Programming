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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(){
	int n;
	cin >> n;
	map<int, int> m;
	rep(i, n){
		int x;
		cin >> x;
		m[x]++;
	}
	vi g;
	int mn = 1e9;
	for(pi x : m){
		g.pb(x.se);
		mn = min(mn, x.se);
	}
	mn++;
	int ans = 1e9;
	for(int sc = mn; sc >= 2; sc--){
		int cur = 0;
		int f = 0;
		rep(i, g.size()){
			if(g[i] % sc == 0) cur += (g[i] / sc);
			else{
				int md = g[i] % sc;
				int d = g[i] / sc;
				if(g[i] < (sc - 1)){
					f = 1;
					break;
				}
				if(g[i] == (sc - 1)) cur++;
				else{
					//it is more than sc
					if(((sc - 1) - (md)) <= d){
						cur += d + 1;
					}
					else{
						f = 1;
						break;
					}
				}
			}
		}
		if(f) continue;
		ans = min(ans, cur);
	}
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
