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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[mxN];
int p1[20][mxN];
int d[mxN];

void dfs(int cur, int pre, int dist){
	d[cur] = dist;
	p1[0][cur] = pre;
	repn(i, 1, 20) p1[i][cur] = p1[i - 1][p1[i - 1][cur]];
	for(int x : g[cur]) if(x != pre) dfs(x, cur, dist + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<pi> p(n), x(m);
	vector<pi> ev;
	rep(i, n){
		cin >> p[i].fi >> p[i].se;
		ev.pb({p[i].fi, -1 * (i + 1)});
		ev.pb({p[i].se, (i + 1)});
	}
	rep(i, m) cin >> x[i].fi >> x[i].se;
	sort(all(ev));
	set<pi> st;
	vi rt;
	rep(i, 2 * n){
		int ind = ev[i].se;
		if(ind < 0){
			ind *= -1; ind--;
			st.insert(mp(p[ind].se, ind));
		}
		else{
			ind--;
			st.erase(st.find(mp(p[ind].se, ind)));
			if(st.size()){
				pi bst = *(--st.end());
				g[bst.se].pb(ind);
			}
			else rt.pb(ind);
		}
	}
	rep(i, rt.size()) dfs(rt[i], rt[i], 0);	
	ev.clear();
	vi nxt(m, -1);
	rep(i, m) ev.pb({x[i].fi, -1 * (i + 1)});
	rep(i, n){
		ev.pb({p[i].fi, -1 * (m + 1 + i)});
		ev.pb({p[i].se, (i + 1)});
	}
	sort(all(ev));
	rep(i, (2 * n) + m){
		int ind = ev[i].se;
		if(ind < 0){
			if((-1 * ind) > m){
				ind *= -1; ind -= m + 1;
				st.insert(mp(p[ind].se, ind));
			}
			else{
				ind *= -1; ind--;
				if(st.size()){
					pi bst = *(--st.end());
					nxt[ind] = bst.se;
				}
			}
		}
		else{
			ind--;
			st.erase(st.find(mp(p[ind].se, ind)));
		}
	}
	rep(i, m){
		if(nxt[i] == -1){
			cout << -1 << '\n';
			continue;
		}
		if(p[nxt[i]].se >= x[i].se){
			cout << 1 << '\n';
			continue;
		}
		int cur = nxt[i];
		for(int j = 19; j >= 0; j--){
			int b = p1[j][cur];
			if(p[b].se < x[i].se) cur = b;
		}
		if(p[p1[0][cur]].se >= x[i].se) cout << d[nxt[i]] - d[p1[0][cur]] + 1 << '\n';
		else cout << -1 << '\n';
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
