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
const int mxN = 5e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[mxN];
int deg[mxN], bd[mxN], p[mxN], cnt[mxN];

void dfs(int cur, int prev){
	if(prev != -1) p[cur] = prev;
	for(int u : g[cur]) if(prev != u) dfs(u, cur);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
		deg[a]++, deg[b]++;
	}
	p[0] = -1;
	dfs(0, -1);
	int tot = 1;
	int m;
	cin >> m;
	rep(i, m){
		int cur;
		cin >> cur;
		if(cur > 0){
			int ind = cur - 1;
			tot += deg[ind] - cnt[ind] - (p[i] != -1 ? bd[p[ind]] : 0) - 1;
			bd[ind] = 1;
			if(p[ind] != -1) cnt[p[ind]]++;
		}
		else{
			int ind = abs(cur) - 1;
			tot -= deg[ind] - cnt[ind] - (p[i] != -1 ? bd[p[ind]] : 0) - 1;
			bd[ind] = 0;
			if(p[ind] != -1) cnt[p[ind]]--;
		}
		cout << tot << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
