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

int betw(int a, int b, int c){
	return ((a >= c && a <= b) || (a >= b && a <= c));
}

void solve(){
	int n;
	cin >> n;
	vector<pi> p(n); //{time, destination}
	rep(i, n) cin >> p[i].fi >> p[i].se;
	int go = 0, pos = 0;
	int ans = 0, cr = 0;
	vi gd(n, 0);
	int oldPos = pos;
	rep(i, n){
		oldPos = pos;
		if(i){
			if(pos < go) pos += p[i].fi - p[i - 1].fi, pos = min(go, pos);
			else pos -= p[i].fi - p[i - 1].fi, pos = max(go, pos);
		}
		if(go == pos){
			if(i && betw(p[i - 1].se, oldPos, pos)) gd[i - 1] = 1;
			go = p[i].se;
			cr = i;
		}
		else{
			if(i && betw(p[i - 1].se, oldPos, pos)) gd[i - 1] = 1;
		}
	}
	if(cr == (n - 1) || (betw(p[n - 1].se, pos, go))) gd[n - 1] = 1;
	rep(i, n) ans += gd[i];
	cout << ans << endl;
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
