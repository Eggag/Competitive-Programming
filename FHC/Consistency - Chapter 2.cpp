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

int g[30][30];

void solve(){
	string s;
	cin >> s;
	int n = (int)(s.size());
	int ans = 1e9;
	rep(i, 30) rep(j, 30) g[i][j] = (i == j ? 0 : 1e9);
	int k;
	cin >> k;
	rep(i, k){
		string t;
		cin >> t;
		g[t[0] - 'A'][t[1] - 'A'] = min(g[t[0] - 'A'][t[1] - 'A'], 1);
	}
	rep(k, 30) rep(i, 30) rep(j, 30){
		g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	}
	rep(i, 26){
		int cur = 0, f = 1;
		rep(j, n){
			if(g[s[j] - 'A'][i] == 1e9){
				f = 0;
				break;
			}
			cur += g[s[j] - 'A'][i];
		}
		if(f) ans = min(ans, cur);
	}
	cout << (ans == 1e9 ? -1 : ans) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
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
