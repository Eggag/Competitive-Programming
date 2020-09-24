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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int a[n][n];
	rep(i, n) rep(j, n) cin >> a[i][j];
	rep(_, 4){
		int f = 1;
		rep(i, n){
			repn(j, 1, n) if(a[i][j] <= a[i][j - 1]){
				f = 0;
				break;
			}
			if(!f) break;
		}
		rep(j, n){
			repn(i, 1, n) if(a[i][j] <= a[i - 1][j]){
				f = 0;
				break;
			}
			if(!f) break;
		}
		if(f){
			rep(i, n){
				rep(j, n) cout << a[i][j] << " ";
				cout << endl;
			}
			return 0;
		}
		int b[n][n];
		rep(i, n) rep(j, n) b[j][n - i - 1] = a[i][j];
		rep(i, n) rep(j, n) a[i][j] = b[i][j];
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
