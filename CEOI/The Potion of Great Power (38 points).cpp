#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, d, u, q;
vector<pair<int, vi>> g[mxN];
int h[mxN];

bool cmp(int a, int b){
	return h[a] < h[b];
}

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> d >> u >> q;
	rep(i, n) cin >> h[i];
	repn(i, 1, u + 1){
		int a, b;
		cin >> a >> b;
		int c = (int)(g[a].size()) - 1;
		if(!g[a].size()){
			//this is the first one
			vi cur = {b};
			g[a].pb(mp(i, cur));
		}
		else{
			vi cur;
			int f = 0;
			rep(j, g[a][c].se.size()){
				if(g[a][c].se[j] == b) f = 1;
				else cur.pb(g[a][c].se[j]);	
			}
			if(f){
				sort(all(cur), cmp);
				g[a].pb(mp(i, cur));
			}
			else{
				cur.pb(b);
				sort(all(cur), cmp);
				g[a].pb(mp(i, cur));
			}
		}
		c = (int)(g[b].size()) - 1;
		if(!g[b].size()){
			//this is the first one
			vi cur = {a};
			g[b].pb(mp(i, cur));
		}
		else{
			vi cur;
			int f = 0;
			rep(j, g[b][c].se.size()){
				if(g[b][c].se[j] == a) f = 1;
				else cur.pb(g[b][c].se[j]);	
			}
			if(f){
				sort(all(cur), cmp);
				g[b].pb(mp(i, cur));
			}
			else{
				cur.pb(a);
				sort(all(cur), cmp);
				g[b].pb(mp(i, cur));
			}
		}
	}
	rep(i, q){
		int x, y, v;
		cin >> x >> y >> v;
		int l = 0, r = (int)(g[x].size()) - 1;
		while(l < r){
			int mid = (l + r + 1) / 2;
			if(g[x][mid].fi <= v) l = mid; //try going smaller
			else r = mid - 1;
		}
		if(l < 0 || l >= g[x].size()){
			cout << 1000000000 << endl;
			cout.flush();
			continue;
		}
		if(g[x][l].fi > v){
			cout << 1000000000 << endl;
			cout.flush();
			continue;
		}
		int l1 = 0, r1 = (int)(g[y].size()) - 1;
		while(l1 < r1){
			int mid1 = (l1 + r1 + 1) / 2;
			if(g[y][mid1].fi <= v) l1 = mid1; //try going smaller
			else r1 = mid1 - 1;
		}
		if(l1 < 0 || l1 >= g[y].size()){
			cout << 1000000000 << endl;
			cout.flush();
			continue;
		}
		if(g[y][l1].fi > v){
			cout << 1000000000 << endl;
			cout.flush();
			continue;
		}
		vi f = g[x][l].se;
		vi s = g[y][l1].se;
		if(!f.size() || !s.size()){
			cout << 1000000000 << endl;
			cout.flush();
			continue;
		}
		int mn = 1e9;
		rep(j, f.size()){
			int l2 = 0, r2 = (int)(s.size()) - 1;
			while(l2 < r2){
				int mid2 = (l2 + r2 + 1) / 2;
				if(h[s[mid2]] <= h[f[j]]) l2 = mid2;
				else r2 = mid2 - 1;
			}
			mn = min(mn, abs(h[f[j]] - h[s[l2]]));
			if(h[s[l2]] <= h[f[j]] && l2 < ((int)s.size() - 1)){
				l2++;
				mn = min(mn, abs(h[f[j]] - h[s[l2]]));
			}
		}
		cout << mn << endl;
		cout.flush();
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
