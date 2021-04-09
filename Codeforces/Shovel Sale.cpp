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
	ll n;
	cin >> n;
	ll mx = n + n - 1;
	vector<ll> p;
	ll mx1 = mx, len = 0, pt = 1, num = 0;
	while(mx1) mx1 /= 10, len++;
	rep(i, len){
		num += 9 * pt;
		pt *= 10;
	}
	if(num == mx && mx > 1) p.pb(mx);
	else{
		rep(j, 9){
			num = 0, pt = 1;
			rep(i, len){
				ll d = 9;
				if(i == (len - 1)) d = j;
				num += d * pt;
				pt *= 10;
			}
			if(mx >= num){
				if(num > 1) p.pb(num);
			}
			else break;
		}
	}
	ll ans = 0;
	rep(i, p.size()){
		ll l = 2, r = min(p[i] - 1, n);
		while(l < r){
			ll mid = (l + r) / 2;
			if((mid + mid - 1) >= p[i]) r = mid;
			else l = mid + 1;
		}
		ans += min(p[i] - 1, n) - l + 1;
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
