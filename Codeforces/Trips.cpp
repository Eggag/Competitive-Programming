#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int deg[mxN], lst[mxN];
set<int> g[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	vi x(m), y(m);
	rep(i, m){
		cin >> x[i] >> y[i];
		x[i]--, y[i]--;
		deg[x[i]]++, deg[y[i]]++;
		g[x[i]].insert(y[i]);
		g[y[i]].insert(x[i]);
	}
	vi st;
	rep(i, n) if(deg[i] < k) st.pb(i);
	memset(lst, -1, sizeof(lst));
	queue<int> q;
	rep(i, st.size()){
		q.push(st[i]);
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			lst[cur] = i;
			for(int u : g[cur]) if(deg[u] >= k && lst[u] != i){
				deg[u]--;
				if(deg[u] == (k - 1)) q.push(u);
			}
		}
	}
	int ans = 0;
	rep(i, n) if(deg[i] >= k) ans++;
	vi res = {ans};
	memset(lst, -1, sizeof(lst));
	int ind = 0;
	for(int i = m - 1; i >= 1; i--){
		g[x[i]].erase(g[x[i]].find(y[i]));
		g[y[i]].erase(g[y[i]].find(x[i]));
		ind++;
		if(deg[x[i]] < k || deg[y[i]] < k){
			res.pb(ans);
			continue;
		}
		deg[x[i]]--, deg[y[i]]--;
		if(deg[x[i]] == (k - 1)){
			ans--;
			q.push(x[i]);
			while(!q.empty()){
				int cur = q.front();
				q.pop();
				lst[cur] = ind;
				for(int u : g[cur]) if(deg[u] >= k && lst[u] != ind){
					deg[u]--;
					if(deg[u] == (k - 1)) q.push(u), ans--;
				}
			}
		}
		ind++;
		if(lst[y[i]] != (ind - 1) && deg[y[i]] == (k - 1)){
			ans--;
			q.push(y[i]);
			while(!q.empty()){
				int cur = q.front();
				q.pop();
				lst[cur] = ind;
				for(int u : g[cur]) if(deg[u] >= k && lst[u] != ind){
					deg[u]--;
					if(deg[u] == (k - 1)) q.push(u), ans--;
				}
			}
		}
		res.pb(ans);
	}
	reverse(all(res));
	rep(i, m) cout << res[i] << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
