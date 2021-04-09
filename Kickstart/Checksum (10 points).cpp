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
const int mxN = 4;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int a[mxN][mxN], b[mxN][mxN], m[mxN][mxN];
int r[mxN], c[mxN];

int solve(){
	int n;
	cin >> n;
	rep(i, n) rep(j, n) cin >> a[i][j];
	rep(i, n) rep(j, n) cin >> b[i][j];
	rep(i, n) cin >> r[i];
	rep(i, n) cin >> c[i];
	int ans = 1e9;
	rep(i, 1 << (n * n)){
		int cur = 0;
		rep(j, n) rep(k, n){
			if(i & (1 << ((j * n) + k))) m[j][k] = 1, cur += b[j][k];
			else m[j][k] = a[j][k];
		}
		rep(_, 5){
			rep(j, n){
				int cnt = 0;
				rep(k, n) if(m[j][k] == -1) cnt++;
				if(cnt == 1) rep(k, n) m[j][k] = 1;
			}
			rep(j, n){
				int cnt = 0;
				rep(k, n) if(m[k][j] == -1) cnt++;
				if(cnt == 1) rep(k, n) m[k][j] = 1;
			}
		}
		int cnt1 = 0;
		rep(j, n) rep(k, n) if(m[j][k] == -1) cnt1++;
		if(!cnt1) ans = min(ans, cur);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": " << solve() << '\n';
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
