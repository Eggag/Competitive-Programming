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

bool cmp(pi a, pi b){
	return a.se < b.se;
}

int solve(string a, string b, string c){
	unordered_map<string, bool> vis;
	unordered_map<string, int> cost;
	int n = (int)a.size();
	rep(i, n){
		string c3 = c;
		rotate(c3.begin(), c3.begin() + i, c3.end());
		if(!vis[c3]) cost[c3] = min(i, n - i);
		else cost[c3] = min({cost[c3], i, n - i});
		vis[c3] = 1;
	}
	vector<pi> g;
	rep(i, n){
		int f = 1;
		rep(j, n){
			int k = (j + i) % n;
			if(a[j] == b[k]){
				f = 0;
				break;
			}
		}
		if(f) g.pb(mp(i, min(i, n - i)));
	}
	int ret = 1e9;
	rep(i, g.size()){
		string a1 = a;
		string b1 = b;
		string c1 = "";
		rotate(b1.begin(), b1.begin() + g[i].fi, b1.end());
		rep(i, n){
			rep(j, 3){
				char ch = 'A' + j;
				if(ch != a1[i] && ch != b1[i]) c1 += ch;
			}
		}
		if(vis[c1]){
			int cur = g[i].se + cost[c1];
			ret = min(ret, cur);
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("1.txt", "r", stdin);
	//freopen("output.out", "w", stdout);
	string a, b, c;
	cin >> a >> b >> c;
	int ans = solve(a, b, c);
	ans = min(ans, solve(b, a, c));
	ans = min(ans, solve(a, c, b));
	ans = min(ans, solve(b, c, a));
	ans = min(ans, solve(c, a, b));
	ans = min(ans, solve(c, b, a));
	if(ans == 1e9) ans = -1;
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
