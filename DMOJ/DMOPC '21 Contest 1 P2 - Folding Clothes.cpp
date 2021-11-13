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
	int n;
	cin >> n;
	vi w(n), w1(n);
	rep(i, n) cin >> w[i], w1[i] = w[i];
	sort(all(w1));
	int uwu = w1[n - 1];
	vi ans, vis(n, 0), v;
	rep(i, n) if(w[i] == uwu){
		if(i) ans.pb(i);
		if((n - i) > 0) ans.pb(n - i);
		ans.pb(-1);
		for(int j = i + 1; j < n; j++) v.pb(w[j]);
		rep(j, i) v.pb(w[j]);
		break;
	}
	for(int i = n - 2; i >= 0; i--){
		int j1 = 0;
		rep(j, v.size()){
			if(!vis[j] && v[j] == w1[i]){
				ans.pb(-(j1 + 1));
				if(j1) ans.pb(j1);
				vis[j] = 1;
				break;
			}
			if(!vis[j]) j1++;
		}
	}
	cout << (int)(ans.size()) << '\n';
	for(int x : ans) cout << x << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
