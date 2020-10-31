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
const int mxN = 2005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
vi g[mxN];
vi seq[mxN];
int c[mxN], d[mxN];

void dfs(int cur){
	int ind = 0;
	for(int x : g[cur]){
		dfs(x);
		d[cur] += (d[x] + 1);
		rep(j, seq[x].size()){
			if(ind == c[cur]) seq[cur].pb(cur);
			seq[cur].pb(seq[x][j]);
			ind++;
		}
	}
	if(ind == c[cur]) seq[cur].pb(cur);
	if(d[cur] < c[cur]){
		cout << "NO" << endl;
		exit(0);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int rt = -1;
	rep(i, n){
		int p;
		cin >> p >> c[i];
		p--;
		if(~p) g[p].pb(i);
		else rt = i;
	}
	assert(~rt);
	dfs(rt);
	vi ans(n);
	assert((int)(seq[rt].size()) == n);
	rep(i, n) ans[seq[rt][i]] = i + 1;
	cout << "YES" << endl;
	for(int x : ans) cout << x << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
