#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl;
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
#define endl '\n'
#define sq(x) ((x) * (x))

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ld dist(ld x, ld y, ld x1, ld y1){
	return sqrt(sq(x1 - x) + sq(y1 - y));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("area1.in", "r", stdin);
	freopen("area1.out", "w", stdout);
	ld x, y, x1, y1, x2, y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	cout << fixed << setprecision(20);
	ld d = dist(x, y, x1, y1);
	ld d1 = dist(x, y, x2, y2);
	ld d2 = dist(x1, y1, x2, y2);
	ld s = (d + d1 + d2) / 2;
	ld ans = sqrt((s * (s - d1) * (s - d2) * (s - d)));
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
