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

void solve(){
	ll a, b;
	cin >> a >> b;
	if(a > b) swap(a, b);
	/*
	ll l = 0, r = 1e5;
	while(l < r){
		ll mid = (l + r + 1) / 2;
		if((a + ((mid * (mid + 1)) / 2)) <= b) l = mid;
		else r = mid - 1;
	}
	ll ans = l;
	a += (l * (l + 1)) / 2;
	ans += 2 * (b - a);
	*/
	rep(i, 100000){
		ll num = (b + a + (i * (i + 1) / 2)) / 2;	
		if(num < b) continue;
		int f = 0;
		if(((i * (i + 1) / 2) - (num - b)) + a == num) f = 1;
		if(f){
			cout << i << endl;
			return;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
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
	- Array bounds
	- Special cases
Be careful!
*/
