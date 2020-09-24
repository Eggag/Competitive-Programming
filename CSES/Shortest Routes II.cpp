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

vector<pi> g[505];
ll dist[505][505];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, q;
	cin >> n >> m >> q;
	rep(i, n) rep(j, n) if(i != j) dist[i][j] = 1e18;
	rep(i, m){
		int a, b;
		ll c;
		cin >> a >> b >> c;
		a--, b--;
		dist[a][b] = min(dist[a][b], c);
		dist[b][a] = dist[a][b];
	}
	rep(k, n) rep(i, n) rep(j, n){
		dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	}
	rep(i, q){
		int a, b;
		cin >> a >> b;
		a--, b--;
		cout << (dist[a][b] == 1e18 ? -1 : dist[a][b]) << endl;
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
