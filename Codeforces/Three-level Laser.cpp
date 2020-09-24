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
	int n, u;
	cin >> n >> u;
	vi e(n);
	rep(i, n) cin >> e[i];
	double ans = -1;
	rep(i, n - 2){
		int i1 = e[i];
		int j = e[i + 1];
		if(j - i1 > u) continue;
		int k;
		auto pos = lower_bound(e.begin() + i + 1, e.end(), i1 + u);
		if(pos == e.end()) k = e[e.size() - 1];
		else if(e[pos - e.begin()] == i1 + u) k = e[pos - e.begin()];
		else k = e[pos - e.begin() - 1];
		if(k - i1 > u) continue;
		if(k == j) continue;
		double one = k - j;
		double two = k - i1;
		double cur = one / two;
		ans = max(ans, cur);
	}
	if(ans == -1) cout << ans << endl;
	else cout << setprecision(10) << fixed << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
