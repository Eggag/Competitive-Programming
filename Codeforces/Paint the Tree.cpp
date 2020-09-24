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

int n;
ll c[5][100005];
vi g[100005];
int deg[100005];
int col[100005];

void dfs(int cur, int co, int co1, int prev){
	if((co + co1) == 3) col[cur] = 3;
	if((co + co1) == 4) col[cur] = 2;
	if((co + co1) == 5) col[cur] = 1;
	for(int u : g[cur]) if(u != prev) dfs(u, co1, col[cur], cur);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	memset(deg, 0, sizeof(deg));
	rep(i, 3) rep(j, n) cin >> c[i][j];
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		deg[a]++, deg[b]++;
		g[a].pb(b);
		g[b].pb(a);
	}
	rep(i, n) if(deg[i] == 3){
		cout << -1 << endl;
		return 0;
	}
	ll best = 1e18;
	vi b(n);
	rep(i, n) if(deg[i] == 1){
		repn(j, 1, 4){
			repn(k, 1, 4) if(j != k){
				memset(col, 0, sizeof(col));
				col[i] = j;
				col[g[i][0]] = k;
				int next;
				for(int u : g[g[i][0]]) if(u != i) next = u;
				dfs(next, j, k, g[i][0]);
				ll cur = 0;
				rep(l, n) cur += c[col[l] - 1][l];
				if(cur < best){
					best = cur;
					rep(l, n) b[l] = col[l];
				}
			}
		}
		break;
	}
	cout << best << endl;
	rep(i, b.size()) cout << b[i] << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
