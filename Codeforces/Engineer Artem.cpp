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
const int mxN = 105;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int a[mxN][mxN];
int b[mxN][mxN];

void solve(){
	int n, m;
	cin >> n >> m;
	vector<pair<int, pi>> c;
	rep(i, n) rep(j, m) cin >> a[i][j], c.pb(mp(a[i][j], mp(i, j)));
	sort(all(c));
	reverse(all(c));
	int f = 0, k = n * m;
	rep(i, k){
		int st = i;
		while(i < k && c[i].fi == c[st].fi) i++;
		i--;
		repn(j, st, i + 1){
			int x = c[j].se.fi, y = c[j].se.se;
			if((x + y) & 1){
				if(f) b[x][y] = a[x][y] + 1;
				else b[x][y] = a[x][y];
			}
			else{
				if(f) b[x][y] = a[x][y];
				else b[x][y] = a[x][y] + 1;
			}
		}
		f ^= 1;
	}
	rep(i, n){
		rep(j, m) cout << b[i][j] << " ";
		cout << '\n';
	}
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
