//smh
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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
int c[15];
int a[15][2 * mxN];
map<int, int> g[10 * mxN];
vi b[mxN];
int cnt = 0;
ll ans = 0LL;
vi bst;

void addWord(int ind){
	int st = 0;
	rep(i, b[ind].size()){
		int cr = g[st][b[ind][i]];
		if(!cr) g[st][b[ind][i]] = ++cnt, st = cnt;
		else st = cr;
	}
}

void dfs(int cur, ll nw, vi st, int lvl = 0){
	if(lvl < n){
		ll nw1 = nw;
		vi st2 = st;
		for(int i = c[lvl] - 1; i >= 0; i--) if(!g[cur][i]){
			st2.pb(i);
			nw1 += a[lvl][i];
			break;
		}
		if(nw1 != nw){
			repn(i, lvl + 1, n) st2.pb(c[i] - 1), nw1 += a[i][c[i] - 1];
			if(nw1 > ans) bst = st2, ans = nw1;
		}
	}
	for(pi x : g[cur]) if(x.se){
		st.pb(x.fi);
		dfs(x.se, nw + a[lvl][x.fi], st, lvl + 1);
		st.pop_back();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	rep(i, n){
		cin >> c[i];
		rep(j, c[i]) cin >> a[i][j];
	}
	int m;
	cin >> m;
	rep(i, m){
		rep(j, n){
			int x;
			cin >> x; x--;
			b[i].pb(x);
		}
		addWord(i);
	}
	vi emp;
	dfs(0, 0LL, emp);
	rep(i, n) cout << bst[i] + 1 << ' ';
	cout << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
