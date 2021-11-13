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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int a[2][mxN], cnt[mxN];
vi g[mxN];

void solve(){
	int n;
	cin >> n;
	rep(i, n) cnt[i] = 0, g[i].clear();
	rep(i, 2) rep(j, n){
		cin >> a[i][j], cnt[--a[i][j]]++;
		g[a[i][j]].pb(j);
	}
	rep(i, n) if(cnt[i] != 2){
		cout << -1 << '\n';
		return;
	}
	vi vis(n, 0), ans;
	queue<pi> q;
	rep(i, n) if(a[0][i] != a[1][i] && !vis[i]){
		vis[i] = 1;
		vi cr, ind;
		vi pos = {a[0][i]}, pos1 = {a[1][i]};
		q.push(mp(i, 0));
		while(!q.empty()){
			pi nw = q.front();
			q.pop();
			for(int x : g[a[0][nw.fi]]) if(!vis[x]){
				int nxt = (a[0][nw.fi] == a[0][x]);
				if(nw.se) nxt ^= 1;
				vis[x] = 1;
				if(nxt){
					cr.pb(x);
					pos1.pb(a[0][x]);
					pos.pb(a[1][x]);
				}
				else{
					pos.pb(a[0][x]);
					pos1.pb(a[1][x]);
				}
				ind.pb(x);
				q.push(mp(x, nxt));
			}			
			for(int x : g[a[1][nw.fi]]) if(!vis[x]){
				int nxt = (a[1][nw.fi] == a[1][x]);
				if(nw.se) nxt ^= 1;
				vis[x] = 1;
				if(nxt){
					cr.pb(x);
					pos1.pb(a[0][x]);
					pos.pb(a[1][x]);
				}
				else{
					pos.pb(a[0][x]);
					pos1.pb(a[1][x]);
				}
				ind.pb(x);
				q.push(mp(x, nxt));
			}			
		}
		sort(all(pos));
		sort(all(pos1));
		int f = 1;
		rep(j, pos.size()) if(pos[j] != pos1[j]) f = 0;
		rep(j, ind.size()) vis[ind[j]] = 0;
		vis[i] = 1;
		vi cr1 = {i};
		pos = {a[1][i]}, pos1 = {a[0][i]};
		q.push(mp(i, 1));
		while(!q.empty()){
			pi nw = q.front();
			q.pop();
			for(int x : g[a[0][nw.fi]]) if(!vis[x]){
				int nxt = (a[0][nw.fi] == a[0][x]);
				if(nw.se) nxt ^= 1;
				vis[x] = 1;
				if(nxt){
					cr1.pb(x);
					pos1.pb(a[0][x]);
					pos.pb(a[1][x]);
				}
				else{
					pos.pb(a[0][x]);
					pos1.pb(a[1][x]);
				}
				q.push(mp(x, nxt));
			}	
			for(int x : g[a[1][nw.fi]]) if(!vis[x]){
				int nxt = (a[1][nw.fi] == a[1][x]);
				if(nw.se) nxt ^= 1;
				vis[x] = 1;
				if(nxt){
					cr1.pb(x);
					pos1.pb(a[0][x]);
					pos.pb(a[1][x]);
				}
				else{
					pos.pb(a[0][x]);
					pos1.pb(a[1][x]);
				}
				q.push(mp(x, nxt));
			}	
		}
		sort(all(pos));
		sort(all(pos1));
		int f1 = 1;
		rep(j, pos.size()) if(pos[j] != pos1[j]) f1 = 0;
		if(f && !f1) for(int x : cr) ans.pb(x);
		else if(!f && f1) for(int x : cr1) ans.pb(x);
		else if(f && f1){
			if((int)(cr.size()) < (int)(cr1.size())) for(int x : cr) ans.pb(x);
			else for(int x : cr1) ans.pb(x);
		}
		else{
			cout << -1 << '\n';
			return;
		}
	}
	cout << (int)(ans.size()) << '\n';
	for(int x : ans) cout << x + 1 << " ";
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
