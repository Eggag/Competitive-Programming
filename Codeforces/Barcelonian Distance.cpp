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

ld a, b, c;

ld evX(ld x){
	return ((-1.0 * a * x) - c) / b;
}

ld evY(ld y){
	return ((-1.0 * b * y) - c) / a;
}

ld dist(ld x, ld y, ld x2, ld y2){
	return sqrtl(sq(y - y2) + sq(x - x2));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> a >> b >> c;
	ld x, y, x2, y2;
	cin >> x >> y >> x2 >> y2;
	ld ans = abs(x - x2) + abs(y - y2);
	if((!a || !b) || (y == y2) || (x == x2)){
		cout << fixed << setprecision(10) << ans << endl;
		return 0;
	}
	if(x > x2) swap(x, x2), swap(y, y2);
	rep(i, 2) rep(j, 2){
		ld x3 = x, y3 = y;
		if(!i) y3 = evX(x);
		else x3 = evY(y);
		ld x4 = x2, y4 = y2;
		if(!j) y4 = evX(x2);
		else x4 = evY(y2);
		ans = min(ans, dist(x, y, x3, y3) + dist(x3, y3, x4, y4) + dist(x2, y2, x4, y4));
	}
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
