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

int n, m;
vi g[mxN], g1[mxN];
int d[mxN];

bool cmp(int a, int b){
	return d[a] < d[b];
}

void solve(){
	cin >> n >> m;
	rep(i, n) g[i].clear(), d[i] = 1e9, g1[i].clear();
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[b].pb(a);
		g1[a].pb(b);
	}
	queue<int> q;
	q.push(0);
	d[0] = 0;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int x : g1[cur]) if(d[x] == 1e9){
			d[x] = d[cur] + 1;
			q.push(x);
		}
	}
	vi ans(n, 1e9);
	vi ord(n, 0);
	rep(i, n) ord[i] = i;
	sort(all(ord), cmp);
	rep(j, n){
		int i = ord[j];
		queue<int> q1;
		ans[i] = min(ans[i], d[i]);
		for(int x : g[i]) if(ans[x] == 1e9) q1.push(x), ans[x] = d[i];
		while(!q1.empty()){
			int cur = q1.front();
			q1.pop();
			for(int x : g[cur]) if(ans[x] == 1e9 && d[x] < d[cur]){
				ans[x] = ans[cur];
				q1.push(x);
			}
		}
	}
	rep(i, n) cout << ans[i] << " ";
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
