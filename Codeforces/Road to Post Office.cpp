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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll d, k, a, b, t;
	cin >> d >> k >> a >> b >> t;
	swap(a, b);
	if(a <= b){
		cout << (ll)(d * a) << endl;
		return 0;
	}
	else{
		ll ans = 0LL;
		ans = min(k, d) * b;
		if(k >= d){
			cout << ans << endl;
			return 0;
		}
		ll rem = d - k;
		if(rem >= k && ((a - b) * k) > t){
			ans += (b * (rem - (rem % k))) + (t * (rem / k));
			rem %= k;
		}
		if(rem >= k) ans += a * ((rem - k) + 1), rem = k - 1;
		if((a - b) * rem > t){
			ans += (b * rem) + t;
		}
		else ans += rem * a;
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
