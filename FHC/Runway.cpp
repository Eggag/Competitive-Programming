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
	vector<vi> p(n + 1, vi(m, 0));
	rep(i, n + 1) rep(j, m) cin >> p[i][j];
	rep(i, n + 1) sort(all(p[i]));
	ll ans = 0;
	repn(i, 1, n + 1){
		int x = 0, y = 0;
		ll cur = m;
		while(x < m && y < m){
			if(p[i][y] > p[i - 1][x]) x++;
			else if(p[i][y] < p[i - 1][x]) y++;
			else{
				x++, y++;
				cur--;
			}
		}
		ans += cur;
	}
	map<int, int> ls, cr, nx;
	rep(i, m) ls[p[0][i]]++;
	rep(i, m) nx[p[1][i]]++;
	repn(i, 1, n + 1){
		swap(cr, nx);
		nx.clear();
		if(i < n){
			rep(j, m) nx[p[i + 1][j]]++;
		}
		for(pi x : ls){
			ls[x.fi] = min(x.se, cr[x.fi]);
		}
		if(i < n){
			for(pi x : ls){
				if(cr[x.fi] > nx[x.fi]) ls[x.fi] = max(ls[x.fi] - (cr[x.fi] - nx[x.fi]), 0);
			}
		}
	}
	for(pi x : ls) ans += x.se;
	cout << ans - m << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": ";
		solve();
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
