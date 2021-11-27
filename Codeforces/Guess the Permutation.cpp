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

ll ask(int l, int r){
	cout << "? " << l << ' ' << r << endl;
	ll res;
	cin >> res;
	return res;
}

void solve(){
	int n;
	cin >> n;
	ll l = 1, r = n;
	while(l < r){
		ll mid = (l + r) / 2;
		if(ask(1, mid) > 0) r = mid;
		else l = mid + 1;
	}
	ll uwu = ask(l, n), owo = ask(l - 1, n);
	ll j = (l - 1) + (owo - uwu) + 1;
	ll uwu1 = ask(j, n), owo1 = ask(j + 1, n);
	cout << "! " << l - 1 << " " << j << " " << j + (uwu1 - owo1) << endl;
}

int main(){
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
