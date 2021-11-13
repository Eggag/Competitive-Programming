#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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

struct point{
	ld x, y;
};

void solve(){
	ld w, h;
	cin >> w >> h;
	ld ans = 1e18;
	ld x, y, x3, y3;
	cin >> x >> y >> x3 >> y3;
	point a = (point){x, y}, b = (point){x3, y3};
	ld w1, h1;
	cin >> w1 >> h1;
	//bottom left
	if(w1 <= a.x || h1 <= a.y) ans = 0.0;
	else{
		if(b.x + (w1 - a.x) <= w) ans = min(ans, w1 - a.x);
		if(b.y + (h1 - a.y) <= h) ans = min(ans, h1 - a.y);
	}
	//upper left
	if((h - h1) >= b.y || w <= a.x) ans = 0.0;
	else{
		if(a.y - (b.y - (h - h1)) >= 0) ans = min(ans, b.y - (h - h1));
		if(b.x + (w - a.x) <= w) ans = min(ans, w - a.x);
	}
	//bottom right
	if((w - w1) >= b.x || h1 <= a.y) ans = 0.0;
	else{
		if(a.x - (b.x - (w - w1)) >= 0) ans = min(ans, b.x - (w - w1));
		if(b.y + (h1 - a.y) <= h) ans = min(ans, h1 - a.y);
	}
	//upper right
	if((w - w1) >= b.x || (h - h1) >= b.y) ans = 0.0;
	else{
		if(a.x - (b.x - (w - w1)) >= 0) ans = min(ans, b.x - (w - w1));
		if(a.y - (b.y - (h - h1)) >= 0) ans = min(ans, b.y - (h - h1));
	}
	if(ans == 1e18) cout << -1 << '\n';
	else cout << fixed << setprecision(15) << ans << '\n';
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
