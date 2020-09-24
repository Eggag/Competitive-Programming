#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'
const int inf = 1e9;

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[300005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b + n);
		g[a + n].pb(b + 2 * n);
		g[a + 2 * n].pb(b);
	}
	int s, t;
	cin >> s >> t;
	s--, t--;
	vector<int> dist(3 * n, inf);
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int u : g[cur]){
			if(dist[u] > dist[cur] + 1){
				dist[u] = dist[cur] + 1;
				q.push(u);
			}
		} 
	}
	if(dist[t] == inf) cout << -1 << endl;
	else cout << dist[t] / 3 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
