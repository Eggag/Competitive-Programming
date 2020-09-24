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

ll n, m;
vi vis2;
vi g[100005];
ll ans1 = 0;
int vis1[100005];
int vis3[100005];
int ind[100005];
int last[100005];
ll cn[100005];
ll d[100005];
int id = 0;
ll cc = 0;
ll ans2 = 0;
int vis4[100005];
ll cnt1[2];

bool dfs(int cur, int mid, int fin, bool fnd, vi vis){
	vis[cur] = 1;
	if(cur == mid) fnd = 1;
	if(cur == fin){
		if(fnd) return 1;
		return 0;
	}
	int ret = 0;
	for(int u : g[cur]) if(!vis[u]){
		ret |= dfs(u, mid, fin, fnd, vis);
		if(ret) break;
	}
	return ret;
}

bool check(int st, int mid, int fin){
	vis2.assign(n, 0);
	return dfs(st, mid, fin, 0, vis2);
}

void dfs1(int cur){
	//initial traversal to compute the subtree sizes
	vis1[cur] = 1;
	ind[cur] = id;
	last[id] = cur;
	cc++;
	d[cur] = 1;
	for(int u : g[cur]) if(!vis1[u]){
		dfs1(u);
		d[cur] += d[u];
	}
}	

void dfs2(int cur){
	vis3[cur] = 1;
	ll sm = 0;
	for(int u : g[cur]) if(!vis3[u]){
		ans1 += (ll)(d[u] * (cn[ind[cur]] - d[u] - 1));
		sm += d[u];
	}
	ans1 += (ll)((cn[ind[cur]] - d[cur]) * sm);
	for(int u : g[cur]) if(!vis3[u]) dfs2(u);
}

bool dfs4(int cur, int prev){
	vis4[cur] = 1;
	if(prev != -1){
		cnt1[1] += cnt1[0];
		cnt1[0]++;
	}
	int ret = 0;
	for(int u : g[cur]) if(u != prev && (ind[u] == ind[cur])){
		if(vis4[u]) return 1;
		ret |= dfs4(u, cur);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("1.out", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	int mx = 0;
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
		mx = max({mx, (int)g[a].size(), (int)g[b].size()});
	}
	if(n <= 10 && m <= 100){
		//first subtask
		ll ans = 0;
		rep(i, n) repn(k, i + 1, n) rep(j, n) if(j != i && j != k) if(check(i, j, k)) ans += 2;
		cout << ans << endl;
	}
	else{
		//subtasks 3, 4, 5
		memset(vis1, 0, sizeof(vis1));
		memset(vis3, 0, sizeof(vis3));
		memset(vis4, 0, sizeof(vis4));
		memset(d, 0, sizeof(d));
		rep(i, n) if(!vis1[i]){
			cc = 0;
			dfs1(i);
			cn[id] = cc;
			id++;
		}
		if(mx == 2){
			vi cyc(100005, 0);
			rep(i, id){
				if(dfs4(last[i], -1)) cyc[i] = 1;
				else{
					for(ll j = 2; j < cn[i]; j++) ans2 += (ll)(2 * (j - 1) * (cn[i] - j) * 1LL);
				}
			}
			rep(i, id) if(cyc[i]){
				ans2 += ((cn[i]) * (cn[i] - 1) * (cn[i] - 2));
			}
			cout << ans2 << endl;
			return 0;
		}
		rep(i, n) if(!vis3[i]) dfs2(i);
		cout << ans1 << endl;
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
