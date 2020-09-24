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

int c[15];
int a[15][100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, x;
	cin >> n >> m >> x;
	rep(i, n){
		cin >> c[i];
		rep(j, m) cin >> a[i][j];
	}
	int ans = 1e9;
	rep(i, 1 << n){
		int cost = 0;
		vi cur(m, 0);
		rep(j, n) if(i & (1 << j)){
			cost += c[j];
			rep(k, m) cur[k] += a[j][k];
		}
		int f = 1;
		rep(k, m) if(cur[k] < x){
			f = 0;
			break;
		}
		if(f) ans = min(ans, cost);
	}
	if(ans == 1e9) ans = -1;
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
