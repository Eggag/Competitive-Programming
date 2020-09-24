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

vi g[1005];
map<pi, int> e;
int st;

void dfs(int cur, vi lst, vi vis){
	if(vis[cur] == 2){
		if((int)lst.size() >= 4){
			int f = 1;
			rep(i, lst.size()) rep(j, lst.size()) if(i != j && abs(i - j) > 1 && abs(i - j) != ((int)lst.size() - 1)){
				if(e[mp(lst[i], lst[j])]){
					f = 0;
					break;
				}
			}
			if(!f) return;
			rep(i, lst.size()) cout << lst[i] + 1 << " ";
			cout << endl;
			exit(0);
		}
	}
	if(vis[cur] == 1 || (lst.size() && vis[cur] == 2)) return;
	lst.pb(cur);
	if(cur != st) vis[cur] = 1;
	for(int u : g[cur]) dfs(u, lst, vis);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, r;
	cin >> n >> r;
	rep(i, r){
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[mp(a, b)] = 1;
		e[mp(b, a)] = 1;
		g[a].pb(b);
		g[b].pb(a);
	}
	rep(i, n){
		vi vs(n, 0);
		vs[i] = 2;
		st = i;
		vi emp;
		dfs(i, emp, vs);
	}
	cout << "no" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
