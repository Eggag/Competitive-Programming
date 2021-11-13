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
#define inf 0x3f3f3f3f
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[mxN];
int dist[mxN][2], p[mxN][2];
int vis[mxN];
vi ord;

void dfs0(int cur){
	vis[cur] = 1;
	for(int x : g[cur]) if(!vis[x]) dfs0(x);
	ord.pb(cur);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vi c(n);
	rep(i, n){
		cin >> c[i];
		rep(j, c[i]){
			int a;
			cin >> a;
			g[i].pb(a - 1);
		}
	}
	int s;
	cin >> s;
	s--;
	memset(dist, inf, sizeof(dist));
	dist[s][0] = 0;
	p[s][0] = -1;
	set<array<int, 3>> q;
	q.insert(array<int, 3>{0, s, 0});
	while(!q.empty()){
		array<int, 3> cr = *q.begin();
		q.erase(q.begin());
		for(int x : g[cr[1]]){
			if(dist[x][cr[2] ^ 1] > cr[0] + 1){
				q.erase(array<int, 3>{dist[x][cr[2] ^ 1], x, cr[2] ^ 1});
				dist[x][cr[2] ^ 1] = cr[0] + 1;
				p[x][cr[2] ^ 1] = cr[1];
				q.insert(array<int, 3>{dist[x][cr[2] ^ 1], x, cr[2] ^ 1});
			}
		}
	}
	rep(i, n) if(!c[i] && dist[i][1] != inf){
		cout << "Win\n";
		vi v;
		int cr = i, cnt = 1;
		while(cr != -1){
			v.pb(cr);
			cr = p[cr][cnt];
			cnt ^= 1;
		}
		reverse(all(v));
		rep(j, v.size()) cout << v[j] + 1 << " ";
		cout << '\n';
		return 0;
	}
	dfs0(s);
	reverse(all(ord));
	vi ind(n, -1);
	rep(i, ord.size()) ind[ord[i]] = i;
	int d = 0;
	rep(i, n) if(~ind[i]){
		for(int x : g[i]){
			if(~ind[x] && ind[x] < ind[i]) d = 1;
		}
	}
	if(d) cout << "Draw\n";
	else cout << "Lose\n";
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
