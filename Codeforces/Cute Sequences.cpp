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

void solve(){
	ll a, b, m;
	cin >> a >> b >> m;
	//b = a + (a + r_0) + (a + a + r_0 + r_1)
	//a, a, 2 * a, 4 * a, 8 * a..
	//k = (2 ^ (n - 2)) * r_0 + (2 ^ (n - 3)) * r_1 + (2 ^ (n - 4)) * r_2...
	if(a == b){
		cout << 1 << " " << a << '\n';
		return;
	}
	ll mul = 1LL;
	repn(i, 2, 51){
		if((b / a) < mul) break;
		ll tot = a * mul;
		mul *= 2LL;
		ll rem = b - tot;
		vector<ll> r(i, 1LL);
		r[0] = 0;
		for(ll j = i - 1; j >= 1; j--){
			ll nm = 1LL;
			if(j > 2) nm = 1LL << (j - 2);
			rem -= nm;
		}
		if(rem < 0) continue;
		for(ll j = i - 1; j >= 1; j--){
			ll nm = 1LL;
			if(j > 2) nm = 1LL << (j - 2);
			ll mx = rem / nm;
			rem -= min(m - 1, mx) * nm;
			r[i - j] += min(m - 1, mx);
		}
		if(!rem){
			cout << i;
			ll sum = a;
			rep(j, i){
				cout << " " << sum + r[j];
				if(j) sum += sum + r[j];
			}
			cout << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
