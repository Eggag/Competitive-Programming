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
const int mxN = 105;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int a[mxN][2][2];

void solve(){
	int n, m;
	cin >> n >> m;
	rep(i, n){
		rep(j, 2) rep(k, 2) cin >> a[i][j][k];
	}
	if(m & 1) cout << "NO" << endl;
	else{
		if(m != 2){
			int f = 0;
			rep(i, n){
				if(a[i][0][1] == a[i][1][0]) f = 1;
			}
			if(f) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		else{
			int f = 0;
			rep(i, n){
				int f1 = 1;
				rep(j, 2) rep(k, 2){
					if(a[i][j][k] != a[i][k][j]){
						f1 = 0;
						break;
					}
				}
				if(f1){
					f = 1;
					break;
				}
			}
			if(!f) cout << "NO" << endl;
			else{
				int f2 = 0;
				rep(i, n){
					if(a[i][0][1] == a[i][1][0]) f2 = 1;
				}
				if(f2) cout << "YES" << endl;
				else cout << "NO" << endl;
			}
		}
	}
}

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
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
	- Array bounds
	- Special cases
Be careful!
*/
