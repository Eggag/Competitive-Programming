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

int n, m, Q, k;
int dist[100005];
vi g[100005];

ll go(int d){
	ll l = 0, r = 1e5;
	while(l < r){
		ll mid = (l + r) / 2;
		if((k * ((mid * (mid + 1)) / 2)) >= d) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m >> Q >> k;
	set<pi> q;
	rep(i, 100005) dist[i] = 1e9;
	rep(i, Q){
		int x;
		cin >> x;
		x--;
		dist[x] = 0;
		q.insert(mp(x, dist[x]));
	}
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	while(!q.empty()){
		int u = q.begin() -> fi;
		q.erase(q.begin());
		for(int x : g[u]){
			if((dist[u] + 1) < dist[x]){
				q.erase(mp(x, dist[x]));
				dist[x] = dist[u] + 1;
				q.insert(mp(x, dist[x]));
			}
		}
	}
	rep(i, n){
		cout << go(dist[i]) << " ";
	}
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
