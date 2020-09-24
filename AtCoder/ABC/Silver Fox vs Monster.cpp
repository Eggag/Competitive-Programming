#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
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

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
	return a.fi < b.fi;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, d, a;
	cin >> n >> d >> a;
	vector<pair<ll, ll>> x(n);
	rep(i, n) cin >> x[i].fi >> x[i].se;
	sort(all(x));
	ll ans = 0;
	vector<ll> sum(n, 0LL);
	rep(i, n){
		ll now = 0;
		if(!i) now = (x[i].se + a - 1) / a;
		else{
			int ind = lb(all(x), mp(x[i].fi - 2 * d, 0), cmp) - x.begin();
			ll nm;
			if(ind == 0) nm = 0;
			else nm = sum[ind - 1] * a;
			ll sm = (a * sum[i - 1]) - nm;
			now = max(0LL, (x[i].se - sm + a - 1) / a);
		}
		if(i) sum[i] = sum[i - 1] + now; //maintain prefix sums
		else sum[i] = now;
		ans += now;
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
