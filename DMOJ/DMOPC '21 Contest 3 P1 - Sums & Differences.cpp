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

ll ask(int i, int j){
	cout << "? " << i + 1 << ' ' << j + 1 << endl;
	ll res;
	cin >> res;
	return res;
}

int main(){
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<ll> ans(n, -1);
	ll cr = ask(0, 1);
	ll uwu = ask(0, 1);
	ans[1] = uwu / 2;
	ans[0] = ans[1] + cr;
	repn(i, 2, n){
		ll owo = ask(i - 1, i);
		ans[i] = uwu - owo;
		uwu = owo;
	}
	cout << '!';
	for(ll x : ans) cout << ' ' << x;
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
