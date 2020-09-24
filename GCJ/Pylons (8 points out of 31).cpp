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

int r, c;
int f = 1;

void dfs(int x, int y, vector<pi> moves, vector<vi> vis){
	if(!f) return;
	vis[x][y] = 1;
	if((int)moves.size() == (r * c)){
		cout << "POSSIBLE" << endl;
		rep(i, moves.size()){
			cout << moves[i].fi + 1 << " " << moves[i].se + 1 << endl;
		}
		f = 0;
		return;
	}
	rep(i, r) rep(j, c){
		if((i != x) && (j != y) && abs(i - x) != abs(j - y) && !vis[i][j]){
			vector<pi> moves1 = moves;
			moves1.pb({i, j});
			dfs(i, j, moves1, vis);
		}
	}
}

void solve(){
	cin >> r >> c;
	rep(i, r) rep(j, c){
		f = 1;
		vector<vi> vis(25, vi (25, 0));
		dfs(i, j, {mp(i, j)}, vis);
		if(!f) return;
	}
	cout << "IMPOSSIBLE" << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
