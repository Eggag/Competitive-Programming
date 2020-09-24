#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl '\n'
 
int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pi> c(n);
	rep(i, n) cin >> c[i].fi >> c[i].se;
	if(n == 1 || ((n == 2) && ((c[0].fi == c[1].fi) || (c[0].se == c[1].se)) && (!(c[0].fi == c[1].fi && c[0].se == c[1].se)))){
		cout << -1 << endl;
		return 0;
	}
	if(n == 2){
		cout << abs(c[0].fi - c[1].fi) * abs(c[0].se - c[1].se) << endl;
	}
	if(n == 4 || n == 3){
		int ans = 1;
		int f = 0;
		rep(i, n) rep(j, n) if(i != j && !f){
			if(c[i].fi == c[j].fi) ans *= abs(c[i].se - c[j].se), f = 1;
		}
		f = 0;
		rep(i, n) rep(j, n) if(i != j && !f){
			if(c[i].se == c[j].se) ans *= abs(c[i].fi - c[j].fi), f = 1;
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
