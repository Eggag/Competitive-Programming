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
const int mxN = 1e6 + 5;
const int MOD = 1e9 + 9;
 
template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }
 
int n;
int d[mxN];
vi g[mxN];
set<ll> st[mxN];
ll hsh[mxN];
ll pw[mxN];
 
void dfs(int cur, int prev){
	hsh[cur] = pw[d[cur]];
	for(int x : g[cur]) if(x != prev){
		dfs(x, cur);
		(hsh[cur] *= ((1LL * pw[d[cur]]) + hsh[x]) % MOD) %= MOD;
	}
	st[d[cur]].insert(hsh[cur]);
}
 
void dfs1(int cur, int prev){
	d[cur] = 1;
	for(int x : g[cur]) if(x != prev){
		dfs1(x, cur);
		d[cur] = max(d[cur], d[x] + 1);
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	cin >> s;
	n = (int)(s.size()) / 2;
	int cur = 0;
	stack<int> sta;
	pw[0] = 179;
	repn(i, 1, n + 1) pw[i] = (pw[i - 1] * 179) % MOD;
	rep(i, s.size()){
		if(s[i] == '('){
			if(sta.size()){
				g[sta.top()].pb(cur);
				g[cur].pb(sta.top());
			}
			sta.push(cur++);
		}
		else sta.pop();
	}
	dfs1(0, -1);
	dfs(0, -1);
	repn(i, 1, n + 1) if(st[i].size()) cout << (int)st[i].size() << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
