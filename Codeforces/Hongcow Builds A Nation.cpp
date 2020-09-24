#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define f first
#define s second

vi g[1005];
int v[1005];
vi k;
int sz;
vi cl;

void dfs(int c){
	if(v[c]) return;
	sz++;
	v[c] = 1;
	for(int u : g[c]){
		dfs(u);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n, m, p;
	cin >> n >> m >> p;
	for(int i = 0; i < p; i++){
		int x;
		cin >> x;
		k.pb(x);
	}
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	for(int i = 0; i < (int) k.size(); i++){
		sz = 0;
		dfs(k[i]);
		cl.pb(sz);
	}
	sort(all(cl));
	int used = 0;
	for(int i = 0; i < (int) cl.size(); i++){
		used += cl[i];
	}
	cl[cl.size() - 1] += n - used;
	ll ans = 0;
	for(int i = 0; i < (int) cl.size(); i++){
		ans += (1LL * cl[i] * (cl[i] - 1)) / 2;
	}
	cout << ans - m << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
