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

int a[305][305];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, n) rep(j, n) cin >> a[i][j];
	rep(i, n) rep(j, n) rep(k, n){
		if(a[i][j] + a[j][k] < a[i][k]){
			cout << -1 << endl;
			return 0;
		}
	}
	ll ans = 0;
	rep(i, n) rep(j, n) if(i != j){
		int f = 1;
		rep(k, n) if(k != i && k != j){
			if(a[i][k] + a[k][j] == a[i][j]){
				f = 0;
				break;
			}
		}
		if(f) ans += a[i][j];
	}
	cout << ans / 2 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
