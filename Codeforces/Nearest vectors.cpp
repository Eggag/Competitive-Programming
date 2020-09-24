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
const ld PI = 4 * atan((ld)(1));

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

bool cmp(pair<pair<ld, ld>, int> a, pair<pair<ld, ld>, int> b){
	return (ld)(atan2(a.fi.se, a.fi.fi)) < (ld)(atan2(b.fi.se, b.fi.fi));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<pair<ld, ld>, int>> p(n);
	rep(i, n) cin >> p[i].fi.fi >> p[i].fi.se, p[i].se = i;
	sort(all(p), cmp);
	ld ans = atan2(p[0].fi.se, p[0].fi.fi) + ((2 * PI) - atan2(p[n - 1].fi.se, p[n - 1].fi.fi));
	pi best = mp(p[0].se, p[n - 1].se);
	rep(i, n - 1){
		ld cur = atan2(p[i + 1].fi.se, p[i + 1].fi.fi) - atan2(p[i].fi.se, p[i].fi.fi);
		if(cur < ans){
			best = mp(p[i].se, p[i + 1].se);
			ans = cur;
		}
	}
	cout << best.fi + 1 << " " << best.se + 1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
