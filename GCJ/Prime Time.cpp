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

void solve(){
	int m;
	cin >> m;
	vector<pair<ll, ll>> p(m);
	ll sum = 0LL;
	vector<ll> nm(505, 0LL);
	rep(i, m){
		cin >> p[i].fi >> p[i].se, sum += p[i].fi * p[i].se;
		nm[p[i].fi] = p[i].se;
	}
	ll bst = 0LL;
	for(ll sub = 2LL; sub <= 500 * 64; sub++){
		if(sub >= sum) break;
		ll rem = sum - sub;
		ll sm = 0LL, rem1 = rem;
		int f = 1;
		for(ll j = 2LL; j < 500; j++){
			ll cnt = 0;
			while(rem1 % j == 0){
				rem1 /= j;
				sm += j;
				cnt++;
			}
			if(cnt > nm[j]) f = 0;
		}
		if(rem1 == 1LL && sm == sub && f){
			bst = sum - sub;
			break;
		}
	}
	cout << bst << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
