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

vector<array<int, 3>> g[mxN];
array<int, 3> ed[mxN];
int le[mxN];
ll tot = 0LL;

void dfs(int cur, int prev){
	int f = 0;
	for(array<int, 3> x : g[cur]) if(x[0] != prev){
		dfs(x[0], cur);
		le[cur] += le[x[0]];
		tot += (ll)(1LL * (ll)(x[2]) * (ll)(le[x[0]]));
		ed[x[1]][2] = le[x[0]];
		f = 1;
	}
	if(!f) le[cur] = 1;
}

ll sng(pair<ll, ll> cur){
	ll ol = cur.fi * cur.se;
	ll nw = (cur.fi / 2) * cur.se;
	return ol - nw;
}

ll dbl(pair<ll, ll> cur){
	ll ol = cur.fi * cur.se;
	ll nw = (cur.fi / 2) * cur.se;
	return (ol - nw) + sng(mp(cur.fi / 2, cur.se));
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
	return sng(a) < sng(b);	
}

void solve(){
	int n;
	ll s;
	cin >> n >> s;
	rep(i, n) g[i].clear(), le[i] = 0;
	tot = 0LL;
	rep(i, n - 1){
		int v, u, w, c;
		cin >> v >> u >> w >> c;
		u--, v--;
		array<int, 3> a = {v, i, w}, b = {u, i, w};
		g[u].pb(a);
		g[v].pb(b);
		ed[i] = {w, c, 0};
	}
	dfs(0, -1);
	int ans = 0;
	multiset<pair<ll, ll>, decltype(cmp)*> c1(cmp);
	multiset<pair<ll, ll>, decltype(cmp)*> c2(cmp);
	rep(i, n - 1){
		if(ed[i][1] == 1) c1.insert(mp((ll)(ed[i][0]), (ll)(ed[i][2])));
		else c2.insert(mp((ll)(ed[i][0]), (ll)(ed[i][2])));
	}
	while(tot > s){
		if(c1.size() && (tot - sng(*(--c1.end()))) <= s){
			ans++;
			break;
		}
		//now we decide if the double is better than the single
		int f = 0;
		if(c2.size()){
			if(!c1.size()) f = 1;
			else{
				pair<ll, ll> tp1 = *(--c1.end());
				pair<ll, ll> tp2 = *(--c2.end());
				if(sng(tp2) > dbl(tp1)){
					if(c1.size() > 1){
						auto it = --c1.end();
						it--;
						pair<ll, ll> tp11 = *it;
						if(sng(tp2) > (sng(tp1) + sng(tp11))) f = 1;
					}
					else f = 1;
				}
			}
		}
		if(f){
			//we take the top c2
			pair<ll, ll> nw = *(--c2.end());
			tot -= sng(nw);
			c2.erase(--c2.end());
			if(nw.fi >= 2LL) c2.insert(mp((nw.fi / 2), nw.se));
			ans += 2;
		}
		else{
			//we take the top c1
			pair<ll, ll> nw = *(--c1.end());
			tot -= sng(nw);
			c1.erase(--c1.end());
			if(nw.fi >= 2LL) c1.insert(mp((nw.fi / 2), nw.se));
			ans++;
		}
	}
	cout << ans << endl;
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
