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
const int mxN = 505;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int g[mxN][mxN];
int h[mxN][mxN];
int ans[mxN][mxN];
int pos[mxN * mxN], pos1[mxN * mxN];

void solve(){
	int n, m;
	cin >> n >> m;
	rep(i, n) rep(j, m){
		cin >> g[i][j];
		pos[g[i][j]] = j;
	}
	rep(j, m) rep(i, n){
		cin >> h[i][j];
		pos1[h[i][j]] = i;
	}
	repn(i, 1, (n * m) + 1){
		ans[pos1[i]][pos[i]] = i;
	}
	rep(i, n){
		rep(j, m) cout << ans[i][j] << " ";
		cout << endl;
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
