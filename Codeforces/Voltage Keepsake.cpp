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
const ld eps = 1e-8;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	ld p;
	cin >> n >> p;
	vector<array<ld, 2>> a(n);
	rep(i, n) cin >> a[i][0] >> a[i][1];
	ld l = 0.0, r = 1e12;
	rep(i, 70){
		ld mid = (l + r) / 2;
		ld tot = 0.0;
		rep(j, n){
			ld nd = mid * a[j][0];
			if(nd > a[j][1]) tot += (nd - a[j][1]) / p;	
		}
		if(tot <= (mid + eps)) l = mid;
		else r = mid;
	}
	if(l >= 9e11) cout << -1 << '\n';
	else cout << fixed << setprecision(10) << l << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
