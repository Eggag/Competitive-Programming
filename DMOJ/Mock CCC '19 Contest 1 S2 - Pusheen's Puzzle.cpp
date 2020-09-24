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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int g[1005][1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, n) rep(j, n) cin >> g[i][j];
	int ans = 0;
	rep(i, n){
		int len = 0;
		repn(j, 1, n){
			if(g[i][j] < g[i][j - 1]) len++;
			else{
				ans = max(ans, len + (len > 0));
				len = 0;
			}
		}
		ans = max(ans, len + (len > 0));
	}
	rep(j, n){
		int len = 0;
		repn(i, 1, n){
			if(g[i][j] < g[i - 1][j]) len++;
			else{
				ans = max(ans, len + (len > 0));
				len = 0;
			}
		}
		ans = max(ans, len + (len > 0));
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
