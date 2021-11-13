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
const int mxN = 3e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dist[mxN];

void solve(){
	int n, k;
	cin >> n >> k;
	vi a(k), t(k);
	rep(i, k) cin >> a[i];
	rep(i, k) cin >> t[i];
	set<pi> q;
	rep(i, n + 1) dist[i] = 2e9;
	rep(i, k) q.insert(mp(t[i], a[i])), dist[a[i]] = t[i];
	while(!q.empty()){
		pi f = *q.begin();
		q.erase(q.begin());
		if(f.se > 1){
			if(f.fi + 1 < dist[f.se - 1]){
				q.erase(mp(dist[f.se - 1], f.se - 1));
				dist[f.se - 1] = f.fi + 1;
				q.insert(mp(dist[f.se - 1], f.se - 1));
			}
		}
		if(f.se < n){
			if(f.fi + 1 < dist[f.se + 1]){
				q.erase(mp(dist[f.se + 1], f.se + 1));
				dist[f.se + 1] = f.fi + 1;
				q.insert(mp(dist[f.se + 1], f.se + 1));
			}
		}
	}
	repn(i, 1, n + 1) cout << dist[i] << " ";
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
