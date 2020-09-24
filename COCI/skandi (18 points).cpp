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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	vector<pair<pi, string>> on;
	rep(i, n) rep(j, m) if(s[i][j] == '1'){
		on.pb(mp(mp(i, j), "DOLJE")); //hor
		on.pb(mp(mp(i, j), "DESNO")); //ver
	}
	int nm = on.size();
	int mx = 1e9;
	vector<pair<pi, string>> ans;
	rep(i, (1 << nm)){
		vector<string> s1 = s;
		vector<pair<pi, string>> cur;
		rep(j, nm) if(i & (1 << j)) cur.pb(on[j]);
		rep(j, cur.size()){
			int x = cur[j].fi.fi;
			int y = cur[j].fi.se;
			if(cur[j].se == "DOLJE"){
				x++;
				while(x < n && s[x][y] == '0') s1[x][y] = '1', x++;
			}
			else{
				y++;
				while(y < m && s[x][y] == '0') s1[x][y] = '1', y++;
			}
		}
		int f = 1;
		rep(j, n) rep(k, m) if(s1[j][k] == '0'){
			f = 0;
			break;
		}
		if(f && (int)cur.size() < mx) ans = cur, mx = (int)cur.size();
	}
	cout << (int)ans.size() << endl;
	rep(i, ans.size()) cout << ans[i].fi.fi + 1 << " " << ans[i].fi.se + 1 << " " << ans[i].se << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
