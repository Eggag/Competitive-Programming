#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, q;
	cin >> n >> m >> q;
	int a[n + 1][m + 1];
	pi mx[n + 1];
	rep(i, n + 1) mx[i] = mp(0, 0);
	pi mx1[m + 1];
	rep(i, m + 1) mx1[i] = mp(0, 0);
	rep(i, n){
		rep(j, m){
			cin >> a[i][j];
			if(a[i][j] > mx[i].fi){
				mx[i].fi = a[i][j];
				mx[i].se = j;
			}
			if(a[i][j] > mx1[j].fi){
				mx1[j].fi = a[i][j];
				mx1[j].se = i;
			}
		}
	}
	while(q--){
		int r, c, x;
		int ans = 0;
		cin >> r >> c >> x;
		r--, c--;
		a[r][c] = x;
		rep(i, n) rep(j, m){
			if(a[i][j] > mx[i].fi){
				mx[i].fi = a[i][j];
				mx[i].se = j;
			}
			if(a[i][j] > mx1[j].fi){
				mx1[j].fi = a[i][j];
				mx1[j].se = i;
			}
		}
		rep(i, n) rep(j, m){
			if(mx1[j].se == i && mx[i].se == j) ans++;
		}
		cout << ans << endl;
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

