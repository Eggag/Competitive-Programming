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
	ll n, d, m;
	cin >> n >> d >> m;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> sm, bg;
	ll tot = 0LL;
	rep(i, n){
		if(a[i] > m) bg.pb(a[i]);
		else sm.pb(a[i]);
		tot += a[i];
	}
	sort(all(sm));
	sort(all(bg));
	reverse(all(sm));
	reverse(all(bg));
	if(!bg.size()){
		cout << tot << endl;
		return 0;
	}
	repn(i, 1, bg.size()) bg[i] += bg[i - 1];
	repn(i, 1, sm.size()) sm[i] += sm[i - 1];
	ll ans = 0LL;
	rep(i, bg.size()){
		ll num = i + 1;
		ll cur = (d + 1) * (num - 1);
		if((cur + 1) > n) continue;
		ll nm = sm.size();
		if(nm + cur >= n){
			ans = max(ans, bg[i] + ((n - cur - 2 >= 0) ? sm[n - cur - 2] : 0));
		}
		else{
			if(n - (nm + cur + 1) <= d){
				ans = max(ans, bg[i] + (sm.size() ? sm[(int)(sm.size() - 1)] : 0));
			}
		}
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
