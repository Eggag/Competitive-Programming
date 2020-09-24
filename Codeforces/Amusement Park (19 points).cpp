#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl '\n'
const int MOD = 998244353;

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[25];
int f = 1;

void dfs(int cur, int prev, vi vis){
	if(vis[cur]){
		//we have visited it already
		//which contradicts the rules
		f = 0;
		return;
	}
	vis[cur] = 1;
	for(int u : g[cur]) if(u != prev) dfs(u, cur, vis);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vi a(m), b(m);
	rep(i, m){
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
	}
	//use a bitset to try every configuration???
	ll cost = 0;
	vi v(25, 0);
	rep(i, (1 << m) + 1){
		f = 1;
		int cnt = 0;
		rep(j, 25) g[j].clear();
		rep(j, m){
			if(i & (1 << j)){
				cnt++; //we will add this to the cost
				g[b[j]].pb(a[j]); //reverse it
			}
			else{
				g[a[j]].pb(b[j]);
			}
		}
		//do a dfs from every vertex?
		rep(j, n){
			dfs(j, -1, v);
		}
		//debug(cnt);
		if(f) cost = (cost + cnt) % MOD;
	}
	cout << cost % MOD << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
