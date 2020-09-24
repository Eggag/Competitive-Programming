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
const int mxN = 5005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int vis[mxN];
ll d[mxN];
int p1[mxN];
vi nxt[mxN];
ll ret = 1e18;
ll ans = 0LL;

void dfs(int v){
	if(ans >= ret) return;
	d[v] = 1;
	for(int u : nxt[v]) if(p1[u] == v){
		dfs(u);
		d[v] += d[u];
	}
	ans += d[v];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, n){
		int k;
		cin >> k;
		rep(j, k){
			int p;
			cin >> p;
			nxt[p - 1].pb(i);
		}
	}
	rep(i, n){
		memset(vis, 0, sizeof(vis));
		queue<int> q;
		q.push(i);
		p1[i] = -1;
		vis[i] = 1;
		int cnt = 1;
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			for(int u : nxt[cur]) if(!vis[u]){
				p1[u] = cur;
				q.push(u);
				vis[u] = 1;
				cnt++;
			}
		}
		if(cnt == n){
			ans = 0LL;
			dfs(i);
			ret = min(ret, ans);
		}
	}
	cout << ret << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
