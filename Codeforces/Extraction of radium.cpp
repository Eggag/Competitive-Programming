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
	int a[n][m];
	pi mx[n];
	rep(i, n) mx[i] = mp(0, 0);
	pi mx1[m];
	rep(i, m) mx1[i] = mp(0, 0);
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
	int ans = 0;
	int s[n][m];
	rep(i, n) rep(j, m) s[i][j] = 0;
	rep(i, n) rep(j, m){
		if(mx1[j].se == i && mx[i].se == j) ans++, s[i][j] = 1;
	}
	while(q--){
		int r, c, x;
		cin >> r >> c >> x;
		r--, c--;
		a[r][c] = x;
		//debug2(r, c);
		//debug(mx[r].fi);
		//debug2(mx1[c].se, mx[r].se);
		if(x > mx[r].fi && s[r][mx[r].se]){
			s[r][mx[r].se] = 0;
			ans--;
		}
		//debug(mx1[c].fi);
		if(x > mx1[c].fi && s[mx1[c].se][c]){
			s[mx1[c].se][c] = 0;
			ans--;
		}
		if(x > mx1[c].fi){
			mx1[c].fi = x;
			mx1[c].se = r;
		}
		if(x > mx[r].fi){
			mx[r].fi = x;
			mx[r].se = c;
		}
		if(mx1[c].se == r && mx[r].se == c && !s[r][c]) s[r][c] = 1, ans++;
		//rep(i, n){
		//	rep(j, m) cout << s[i][j];
		//	cout << endl;
		//}
		//rep(i, n){
		//	rep(j, m) cout << a[i][j] << " ";
		//	cout << endl;
		//}
		//cout << "MX.fi" << endl;
		//rep(i, n) cout << i << " " << mx[i].fi << " ";
		//cout << endl;
		//rep(i, m) cout << i << " " << mx1[i].fi << " ";
		//cout << endl;
		//cout << "MX.se" << endl;
		//rep(i, n) cout << i << " " << mx[i].se << " ";
		//cout << endl;
		//rep(i, m) cout << i << " " << mx1[i].se << " ";
		//cout << endl;
		cout << ans << endl;
		//cout << "================" << endl;
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
