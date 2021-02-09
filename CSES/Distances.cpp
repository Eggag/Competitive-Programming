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
const int mxN = 105;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[mxN];
vi fr[mxN], ba[mxN];

void dfs(int cur, int prev = -1, int de = 0){
	int cnt = 0, fst = -1;
	for(int x : g[cur]) if(x != prev){
		cnt++;
		if(fst == -1) fst = x;
	}
	if(cnt > 1){
		if(de % 2 == 0){
			for(int x : g[cur]) if(x != prev){
				dfs(x, cur, de + 1);
				if(x == fst){
					rep(j, fr[x].size()) fr[cur].pb(fr[x][j]);
					rep(j, ba[x].size()) ba[cur].pb(ba[x][j]);
				}
				else{
					vi curL;
					rep(j, ba[x].size()) curL.pb(ba[x][j]);
					reverse(all(curL));
					rep(j, curL.size()) fr[cur].pb(curL[j]);
					rep(j, fr[x].size()) fr[cur].pb(fr[x][j]);
				}
			}
			fr[cur].pb(cur);
		}
		else{
			for(int x : g[cur]) if(x != prev){
				dfs(x, cur, de + 1);
				if(x == fst){
					rep(j, fr[x].size()) fr[cur].pb(fr[x][j]);
					rep(j, ba[x].size()) ba[cur].pb(ba[x][j]);
				}
				else{
					vi curL;
					rep(j, ba[x].size()) curL.pb(ba[x][j]);
					reverse(all(curL));
					rep(j, curL.size()) fr[cur].pb(curL[j]);
					rep(j, fr[x].size()) fr[cur].pb(fr[x][j]);
				}
			}
			ba[cur].pb(cur);
		}
	}
	else{
		for(int x : g[cur]) if(x != prev){
			dfs(x, cur, de + 1);
			fr[cur] = fr[x];
			ba[cur] = ba[x];
		}
		if(de % 2 == 0) fr[cur].pb(cur);
		else ba[cur].pb(cur);
	}
}

void solve(){
	int n;
	cin >> n;
	rep(i, n) g[i].clear(), fr[i].clear(), ba[i].clear();
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0);
	reverse(all(fr[0]));
	rep(i, fr[0].size()) cout << fr[0][i] + 1 << " ";
	rep(i, ba[0].size()) cout << ba[0][i] + 1 << " ";
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
