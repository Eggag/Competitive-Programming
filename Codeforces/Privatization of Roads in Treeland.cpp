#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

#ifdef LOCAL
clock_t timer = clock();
#endif

vector<pi> g[200005];
int col[200005];
int r;

void dfs(int v, int p, int pc){
	if(g[v].size() > r){
		if(pc == -1) pc = 0;
		for(auto u : g[v]) if(u.fi != p){
			col[u.se] = pc;
			dfs(u.fi, v, pc);
		}
	}
	else{
		int c = 0;
		for(auto u : g[v]) if(u.fi != p){
			if(c == pc) c++;
			col[u.se] = c;
			dfs(u.fi, v, c);
			c++;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(mp(b, i));
		g[b].pb(mp(a, i));
	}
	vi C;
	for(int i = 0; i < n; i++) C.pb(g[i].size());
	sort(all(C));
	while(k){
		C.pop_back();
		k--;
	}
	r = C.back();
	dfs(0, 0, -1);
	cout << r << endl;
	for(int i = 0; i < n - 1; i++){
		cout << col[i] + 1 << " ";
	}
	cout << endl;
#ifdef LOCAL
        cout << "Total Time: " << (double)(clock() - timer) / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
