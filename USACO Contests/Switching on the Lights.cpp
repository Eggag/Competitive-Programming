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

int l[105][105];
int nc[105][105];
vector<pi> g[105][105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("lightson.in", "r", stdin);
	freopen("lightson.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	memset(l, 0, sizeof(l));
	memset(nc, 0, sizeof(nc));
	rep(i, m){
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		g[x - 1][y - 1].pb(mp(a - 1, b - 1));
	}
	vector<pi> comp = {mp(0, 0)}; //the ones from which we can go
	for(pi nw : g[0][0]) l[nw.fi][nw.se] = 1; //we light it up
	nc[0][0] = 1;
	queue<pi> q;
	l[0][0] = 1;
	int it = 0;
	while(!it || !q.empty()){
		while(q.size()){
			pi x = q.front();
			q.pop();
			for(pi nw : g[x.fi][x.se]){
				l[nw.fi][nw.se] = 1; //we light it up
			}
		}	
		for(pi ex : comp){
			if(ex.fi < (n - 1) && l[ex.fi + 1][ex.se] && !nc[ex.fi + 1][ex.se]){
				comp.pb(mp(ex.fi + 1, ex.se));
				nc[ex.fi + 1][ex.se] = 1;
				q.push(mp(ex.fi + 1, ex.se));
			}
			if(ex.fi && l[ex.fi - 1][ex.se] && !nc[ex.fi - 1][ex.se]){
				comp.pb(mp(ex.fi - 1, ex.se));
				nc[ex.fi - 1][ex.se] = 1;
				q.push(mp(ex.fi - 1, ex.se));
			}
			if(ex.se < (n - 1) && l[ex.fi][ex.se + 1] && !nc[ex.fi][ex.se + 1]){
				comp.pb(mp(ex.fi, ex.se + 1));
				nc[ex.fi][ex.se + 1] = 1;
				q.push(mp(ex.fi, ex.se + 1));
			}
			if(ex.se && l[ex.fi][ex.se - 1] && !nc[ex.fi][ex.se - 1]){
				comp.pb(mp(ex.fi, ex.se - 1));
				nc[ex.fi][ex.se - 1] = 1;
				q.push(mp(ex.fi, ex.se - 1));
			}
		}
		it++;
	}
	int ans = 0;
	rep(i, 105) rep(j, 105) ans += l[i][j];
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
