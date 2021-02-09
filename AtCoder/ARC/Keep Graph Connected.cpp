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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vector<pi> g[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	pi st;
	rep(i, m){
		int u, v, c;
		cin >> u >> v >> c;
		u--, v--;
		g[u].pb({v, c});
		g[v].pb({u, c});
		st = {u, c};
	}
	vi col(n, 0);
	col[st.fi] = st.se;
	queue<int> q;
	q.push(st.fi);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(pi x : g[cur]) if(!col[x.fi]){
			if(col[cur] == x.se) col[x.fi] = (x.se == 1 ? 2 : 1);
			else col[x.fi] = x.se;
			q.push(x.fi);
		}
	}
	rep(i, n) cout << col[i] << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
