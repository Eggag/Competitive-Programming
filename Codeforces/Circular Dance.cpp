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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pi> p(n);
	rep(i, n){
		cin >> p[i].fi >> p[i].se;
		p[i].fi--, p[i].se--;
		g[p[i].fi].pb(p[i].se);
		g[p[i].se].pb(p[i].fi);
	}
	queue<int> q;
	vi vis(n, 0);
	vis[0] = 1;
	q.push(0);
	while(q.size() != n){
		vi nxt = g[q.back()];
		//debug(q.back());
		//debug2(nxt[0], nxt[1]);
		if((p[nxt[0]].fi == nxt[1] || p[nxt[0]].se == nxt[1]) && !vis[nxt[1]]){
			q.push(nxt[1]);
			vis[nxt[1]] = 1;
		}
		else{
			q.push(nxt[0]);
			vis[nxt[0]] = 1;
		}
	}
	vi ans;
	while(q.size()) ans.pb(q.front()), q.pop();
	for(int x : ans) cout << x + 1 << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
