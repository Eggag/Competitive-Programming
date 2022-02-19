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

ll ask(int a, int b){
	cout << "? " << a << " " << b << endl;
	ll res;
	cin >> res;
	return res;
}

int main(){
	int n;
	cin >> n;
	vector<ll> res(n + 1, 0);
	ll g = 0;
	repn(i, 2, n + 1){
		res[i] = ask(1, i);
		g = gcd(g, res[i]);
	}
	vector<ll> ans(n + 1, 0);
	ans[1] = g;
	repn(i, 2, n + 1) ans[i] = res[i] / g;
	cout << "!";
	repn(i, 1, n + 1) cout << " " << ans[i];
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
