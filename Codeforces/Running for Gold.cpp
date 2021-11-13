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
const int mxN = 5e4 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int a[mxN][5];

bool cmp(int i, int j){
	int cnt = 0;
	rep(k, 5) if(a[i][k] < a[j][k]) cnt++;
	return cnt < 3;
}

void solve(){
	int n;
	cin >> n;
	rep(i, n) rep(j, 5) cin >> a[i][j];
	vi p;
	rep(i, n) p.pb(i);
	sort(all(p), cmp);
	int ind = p[n - 1], ans = 0;
	rep(k, n) if(k != ind){
		int cnt = 0;
		rep(i, 5) if(a[ind][i] < a[k][i]) cnt++;
		if(cnt >= 3) ans++;
	}
	cout << (ans == (n - 1) ? ind + 1 : -1) << '\n';
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
