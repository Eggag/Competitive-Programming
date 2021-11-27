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

int dot(array<int, 5> a, array<int, 5> b){
	int ans = 0;
	rep(i, 5) ans += a[i] * b[i];
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<array<int, 5>> p(n);
	rep(i, n) rep(j, 5) cin >> p[i][j];
	if(n > 40){
		cout << 0 << '\n';
		return 0;
	}
	vi gd;
	rep(i, n){
		int f = 1;
		rep(j, n) repn(k, j + 1, n) if(j != i && k != i){
			array<int, 5> a, b;
			rep(l, 5) a[l] = p[j][l] - p[i][l];
			rep(l, 5) b[l] = p[k][l] - p[i][l];
			if(dot(a, b) > 0) f = 0;
		}
		if(f) gd.pb(i + 1);
	}
	cout << (int)(gd.size()) << '\n';
	for(int x : gd) cout << x << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
