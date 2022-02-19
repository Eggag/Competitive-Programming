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

int n, m, a, b, c, d;
vector<pi> g[mxN];
pi ed[mxN];

void die(){
	cout << "-1\n";
	exit(0);
}

int check(vi col){
	int mn = 1e9;
	repn(i, 1, 3){
		vi dist(n, 1e9);
		queue<int> q;
		dist[a] = 0;
		q.push(a);
		while(!q.empty()){
			int cr = q.front();
			q.pop();
			for(pi x : g[cr]) if(col[x.se] == i){
				if(dist[x.fi] > dist[cr] + 1){
					dist[x.fi] = dist[cr] + 1;
					q.push(x.fi);
				}
			}
		}
		mn = min(mn, dist[b]);
	}
	return mn;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	rep(i, m){
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].pb(mp(y, i));
		g[y].pb(mp(x, i));
		ed[i] = mp(x, y);
	}
	cin >> a >> b >> c >> d;
	a--, b--, c--, d--;
	rep(i, m) if((ed[i].fi == c && ed[i].se == d) || (ed[i].fi == d && ed[i].se == c)) die();
	vi col(m, 0), col1(m, 0);
	for(pi u : g[c]) col[u.se] = col1[u.se] = 1;
	for(pi u : g[d]) col[u.se] = col1[u.se] = 2;
	rep(i, m) if(!col[i]){
		col[i] = 1;
		col1[i] = 2;
	}
	int uwu = check(col), owo = check(col1);
	if(owo < uwu){
		swap(uwu, owo);
		swap(col, col1);
	}
	if(uwu == 1e9) die();
	cout << "2\n";
	rep(i, m) cout << col[i] << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
