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
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int g[1005][1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int h, w;
	cin >> h >> w;
	vi r(h), c(w);
	rep(i, h) cin >> r[i];
	rep(i, w) cin >> c[i];
	rep(i, 1005) rep(j, 1005) g[i][j] = 0;
	rep(i, h){
		rep(j, r[i]){
			g[i][j] = 1;
		}
		g[i][r[i]] = 7;
	}
	rep(i, w){
		rep(j, c[i]){
			g[j][i] += 2;
		}
		g[c[i]][i] = 7;
		if(g[c[i]][i] == 1){
			cout << 0 << endl;
			return 0;
		}
	}
	int f = 1;
	rep(i, w) if(!c[i] && g[0][i] && g[0][i] != 7) f = 0;	
	rep(i, h) if(!r[i] && g[i][0] && g[i][0] != 7) f = 0;	
	if(!f){
		cout << 0 << endl;
		return 0;
	}
	rep(i, h){
		int cur = 0;
		while(g[i][cur] && g[i][cur] != 7) cur++;
		if(cur != r[i]){
			cout << 0 << endl;
			return 0;
		}
	}
	rep(j, w){
		int cur = 0;
		while(g[cur][j] && g[cur][j] != 7) cur++;
		if(cur != c[j]){
			cout << 0 << endl;
			return 0;
		}
	}
	int pos = 1;
	repn(i, 1, h){
		rep(j, w) if(!g[i][j]){
			if(g[i - 1][j] == 3) continue;
			if(g[i - 1][j] == 2) continue;
			if(j >= 1){
				if(g[i][j - 1] == 3) continue;
				if(g[i][j - 1] == 1) continue;
			}
			g[i][j] = 5;
			pos++;
		}
	}
	int ans = 1;
	rep(i, pos - 1) ans = (ans * 2) % MOD;
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
