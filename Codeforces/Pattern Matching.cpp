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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

bool match(string a, string b){
	rep(i, a.size()) if(a[i] != b[i] && a[i] != '_' && b[i] != '_') return 0;
	return 1;
}

vi ord;
int vis[mxN];
vi g[mxN];

void dfs(int cur){
	if(vis[cur] == 2) return;
	if(vis[cur] == 1){
		cout << "NO" << endl;
		exit(0);
	}
	vis[cur] = 1;
	for(int x : g[cur]) dfs(x);
	vis[cur] = 2;
	ord.pb(cur);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	vector<string> p(n), s(m);
	vi mt(m);
	map<string, int> cnt;
	rep(i, n) cin >> p[i], cnt[p[i]] = i + 1;
	rep(i, m) cin >> s[i] >> mt[i];
	rep(i, m){
		if(!match(s[i], p[mt[i] - 1])){
			cout << "NO" << endl;
			return 0;
		}
	}
	rep(i, m){
		rep(j, 1 << k){
			string a = s[i];
			rep(l, k) if(j & (1 << l)) a[l] = '_';
			int nm = cnt[a];
			if(nm && nm != mt[i]) g[mt[i] - 1].pb(nm - 1);
		}
	}
	rep(i, n) vis[i] = 0;
	rep(i, n) if(!vis[i]) dfs(i);
	reverse(all(ord));
	cout << "YES" << endl;
	rep(i, ord.size()) cout << ord[i] + 1 << " ";
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
