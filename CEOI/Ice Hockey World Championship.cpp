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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	ll m;
	cin >> n >> m;
	if(n == 1){
		ll x;
		cin >> x;
		cout << (x <= m ? 2 : 1) << endl;
	}
	else{
		ll ans = 0LL;
		vector<ll> a(n / 2), b((n + 1) / 2);
		rep(i, n / 2) cin >> a[i];
		rep(i, (n + 1) / 2) cin >> b[i];
		vector<ll> pos;
		rep(i, (1 << (n / 2))){
			ll sum = 0LL;
			rep(j, n / 2) if(i & (1 << j)) sum += a[j];
			if(sum <= m) pos.pb(sum);
		}
		sort(all(pos));
		rep(i, (1 << ((n + 1) / 2))){
			ll sum = 0LL;
			rep(j, (n + 1) / 2) if(i & (1 << j)) sum += b[j];
			if(sum <= m){
				auto it = ub(all(pos), m - sum);
				ans += (ll)(it - pos.begin());
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
