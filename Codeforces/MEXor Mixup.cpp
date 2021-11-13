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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	vector<array<int, 3>> p;
	rep(i, t){
		int a, b;
		cin >> a >> b;
		p.pb(array<int, 3>{a, b, i});
	}
	int x = 0, cr = 0;
	sort(all(p));
	vi ans(t, 0);
	rep(i, t){
		int a = p[i][0], b = p[i][1];
		while(cr < a) x ^= cr, cr++;
		if(x == b) ans[p[i][2]] = a;
		else if((b ^ x) != a) ans[p[i][2]] = a + 1;
		else ans[p[i][2]] = a + 2;
	}
	rep(i, t) cout << ans[i] << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
