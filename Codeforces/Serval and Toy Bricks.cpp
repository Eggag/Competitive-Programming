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

int a[105], b[105];
int c[105][105];
int ans[105][105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, h;
	cin >> n >> m >> h;
	rep(i, m) cin >> a[i];
	rep(i, n) cin >> b[i];
	rep(i, n) rep(j, m) cin >> c[i][j];
	rep(i, 105) rep(j, 105) ans[i][j] = 0;
	rep(i, n) rep(j, m){
		if(c[i][j]){ //if there are any blocks in this one
			//a[j] is the max in its row
			//b[i] is the max in its col
			ans[i][j] = min(a[j], b[i]);
		}
	}
	rep(i, n){
		rep(j, m) cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
