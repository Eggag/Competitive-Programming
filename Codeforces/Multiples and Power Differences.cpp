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
const int mxN = 505;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int lcm(int a, int b){
	return b * (a / gcd(a, b));
}

int g[mxN][mxN], ans[mxN][mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, n) rep(j, m) cin >> g[i][j];
	int l = 1;
	repn(i, 2, 17) l = lcm(l, i);
	rep(i, n) rep(j, m){
		if((i + j) & 1) ans[i][j] = l;
		else{
			repn(k, 1, 30){
				int k4 = sq(sq(k));
				if(l - k4 > 0 && (l - k4) % g[i][j] == 0){
					ans[i][j] = l - k4;
					break;
				}
			}
		}
	}
	rep(i, n){
		rep(j, m) cout << ans[i][j] << " ";
		cout << '\n';
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
