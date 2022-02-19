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
#define x1 qwertyuiop
#define y1 asdfghjkl
const int mxN = 505;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
int a[mxN][mxN];

int sum(int x, int y, int x1, int y1){
	return (a[x1][y1] - (y ? a[x1][y - 1] : 0) - (x ? a[x - 1][y1] : 0) + ((x && y) ? a[x - 1][y - 1] : 0));
}

void solve(){
	cin >> n;
	rep(i, n) rep(j, n){
		char c;
		cin >> c;
		a[i][j] = (int)(c - '0');
	}
	rep(i, n) repn(j, 1, n) a[i][j] += a[i][j - 1];
	repn(i, 1, n) rep(j, n) a[i][j] += a[i - 1][j];
	int ans = 0;
	rep(i, n){
		rep(j, n - i) rep(k, n - i){
			int uwu = sum(j, k, j + i, k + i);
			if(!i){
				if(uwu == 1) ans++;
			}
			else if(i == 1){
				if(uwu == 4) ans++;
			}
			else{
				int owo = sum(j + 1, k + 1, j + i - 1, k + i - 1);
				int d = sq(i + 1) - sq(i - 1);
				if(uwu - d == owo) ans++;
			}
		}
	}
	cout << ans << '\n';
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
