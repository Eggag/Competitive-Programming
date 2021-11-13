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

void solve(){
	int n, m;
	cin >> n >> m;
	vi p(n), p1(n, 0);
	rep(i, n) cin >> p[i], p[i]--;
	rep(i, n){
		if(i >= p[i]) p1[i - p[i]]++;
		else p1[(n - 1) - ((p[i] - i) - 1)]++;
	}
	vi ans, ans1;
	rep(i, n) if(p1[i] >= n - (2 * m)) ans.pb(i);
	rep(i, ans.size()){
		vi pp(n, -1);
		rep(j, n){
			pp[j] = (p[j] + ans[i]) % n;	
		}
		int sw = 0;
		vi vis(n, 0);
		rep(j, n) if(!vis[j]){
			int sz = 0, cr = j;
			while(!vis[cr]){
				sz++;
				vis[cr] = 1;
				cr = pp[cr];
			}
			sw += sz - 1;
		}
		if(sw <= m) ans1.pb(ans[i]);
	}
	cout << (int)(ans1.size()) << " ";
	for(int x : ans1) cout << x << " ";
	cout << '\n';
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
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
