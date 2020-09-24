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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
ll m;
ll ans = 0LL;
array<ll, 2> p[mxN];
ll sum[mxN];
priority_queue<ll> pq[mxN];
vi g[mxN];

void merge(int a, int b){
	if(pq[a].size() < pq[b].size()){
		swap(pq[a], pq[b]);
		swap(sum[a], sum[b]);
	}
	while(pq[b].size()){
		ll cr = pq[b].top();
		if((m - sum[a]) >= cr) pq[a].push(cr), sum[a] += cr;
		else if(pq[a].size() && cr < pq[a].top()){
			sum[a] -= pq[a].top() - cr;
			pq[a].pop();
			pq[a].push(cr);
		}
		pq[b].pop();
	}
}

void dfs(int u){
	priority_queue<ll> cur;
	if(p[u][0] <= m) cur.push(p[u][0]);
	pq[u] = cur;
	if(p[u][0] <= m) sum[u] += p[u][0];
	for(int x : g[u]){
		dfs(x);
		merge(u, x);
	}
	ll rm = p[u][1];
	ll rm1 = (ll)pq[u].size();
	ans = max(ans, (ll)(1LL * rm * rm1));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	rep(i, n){
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		if(a >= 0) g[a].pb(i);
		p[i] = {b, c};
	}
	dfs(0);
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
