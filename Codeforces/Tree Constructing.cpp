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
const int mxN = 4e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[mxN];
int deg[mxN], bad[mxN], p[mxN];
int mx, bst;

void dfs(int cur, int prev, int dist){
	if(dist >= mx){
		mx = dist;
		bst = cur;
	}
	for(int x : g[cur]) if(x != prev){
		dfs(x, cur, dist + 1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, d, k;
	cin >> n >> d >> k;
	if(n == 1){
		cout << "NO" << endl;
		return 0;
	}
	if(k == 1){
		if(n == 2 && d == 1){
			cout << "YES" << endl;
			cout << "1 2" << endl;
		}
		else cout << "NO" << endl;
		return 0;
	}
	if(d == 1){
		if(n == 2){
			cout << "YES" << endl;
			cout << "1 2" << endl;
		}
		else cout << "NO" << endl;
		return 0;
	}
	int num = 1;
	queue<pi> q;
	q.push({1, 0});
	int nxt = 2;
	while(num < n){
		pi cur = q.front();
		q.pop();
		rep(i, k - (cur.fi != 1)){
			if(num == n) break;
			g[cur.fi].pb(nxt);
			g[nxt].pb(cur.fi);
			p[nxt] = cur.fi;
			deg[nxt]++, deg[cur.fi]++;
			q.push({nxt, cur.se + 1});
			num++;
			nxt++;
		}
	}
	mx = 0;
	bst = 0;
	dfs(1, -1, 0);
	bad[bst] = 1;
	int bst1 = bst;
	bst = 0;
	mx = 0;
	dfs(bst1, -1, 0);
	bad[bst] = 1;
	int d1 = mx;
	if(d1 > d) cout << "NO" << endl;
	else{
		queue<int> q1;
		repn(i, 1, n + 1) if(deg[i] == 1 && !bad[i]) q1.push(i);
		while(d1 < d){
			if(q1.size()){
				int nw = q1.front();
				q1.pop();
				deg[p[nw]]--;
				if(deg[p[nw]] == 1) q1.push(p[nw]);
				p[nw] = bst;
				bst = nw;
			}
			else{
				cout << "NO" << endl;
				return 0;
			}
			d1++;
		}
		cout << "YES" << endl;
		vector<pi> ans;
		repn(i, 2, n + 1) ans.pb({i, p[i]});
		rep(i, ans.size()) cout << ans[i].fi << " " << ans[i].se << '\n';
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
