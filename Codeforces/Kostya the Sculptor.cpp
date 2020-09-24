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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll a[mxN][3];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, n) rep(j, 3) cin >> a[i][j];
	map<pair<ll, ll>, pair<ll, ll>> m;
	ll bst = 0;
	vi cur = {};
	rep(i, n){
		ll cr = min({a[i][0], a[i][1], a[i][2]});
		if(cr > bst){
			bst = cr;
			cur = {i + 1};
		}
		rep(j, 3) rep(k, 3) if(j != k){
			int p = -1;
			rep(l, 3) if(l != j && l != k) p = l; //the extra
			pair<ll, ll> nw = m[mp(a[i][j], a[i][k])];
			if(nw.fi){
				ll bg = min({a[i][j], a[i][k], a[i][p] + nw.fi});
				if(bg > bst){
					bst = bg;
					cur = {nw.se + 1, i + 1};
				}
			}
		}
		rep(j, 3) rep(k, 3) if(j != k){
			int p = -1;
			rep(l, 3) if(l != j && l != k) p = l; //the extra
			if(a[i][p] > m[mp(a[i][j], a[i][k])].fi){
				m[mp(a[i][j], a[i][k])] = mp(a[i][p], i);
			}
			if(a[i][p] > m[mp(a[i][k], a[i][j])].fi){
				m[mp(a[i][k], a[i][j])] = mp(a[i][p], i);
			}
		}
	}
	cout << cur.size() << endl;
	for(int x : cur) cout << x << " ";
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
