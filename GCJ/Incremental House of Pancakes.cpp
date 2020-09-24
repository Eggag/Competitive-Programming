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
	ll l, r;
	cin >> l >> r;
	if(l >= r){
		ll l1 = 0, r1 = 2e9;
		while(l1 < r1){
			ll mid = (l1 + r1 + 1) / 2;
			if((mid * (mid + 1) / 2) <= l && (l - (mid * (mid - 1) / 2)) >= r) l1 = mid;
			else r1 = mid - 1;
		}
		ll tot = l1;
		l -= (l1 * (l1 + 1)) / 2;
		l1++;
		ll l2 = 0, r2 = 2e9;
		while(l2 < r2){
			//how many numbers can we give to l?
			ll mid = (l2 + r2 + 1) / 2;
			if(l1 * mid + 2 * ((mid * (mid - 1)) / 2) <= r) l2 = mid;
			else r2 = mid - 1;
		}
		ll l3 = 0, r3 = 2e9;
		while(l3 < r3){
			//how many numbers can we give to r?
			ll mid = (l3 + r3 + 1) / 2;
			if((l1 + 1) * mid + 2 * ((mid * (mid - 1)) / 2) <= l) l3 = mid;
			else r3 = mid - 1;
		}
		//now we need to take care of some corner cases
		if((l2 - l3) > 1){
			l2 = l3 + 1;
		}
		else if(l3 > l2){
			l3 = l2;
		}
		tot += l2 + l3;
		r -= l1 * l2 + 2 * ((l2 * (l2 - 1)) / 2);
		l -= (l1 + 1) * l3 + 2 * ((l3 * (l3 - 1)) / 2);
		cout << tot << " " << l << " " << r << endl;
	}
	else{
		ll l1 = 0, r1 = 2e9;
		while(l1 < r1){
			ll mid = (l1 + r1 + 1) / 2;
			if((mid * (mid + 1) / 2) <= r && (r - (mid * (mid - 1) / 2)) > l) l1 = mid;
			else r1 = mid - 1;
		}
		ll tot = l1;
		r -= (l1 * (l1 + 1)) / 2;
		l1++;
		ll l2 = 0, r2 = 2e9;
		while(l2 < r2){
			//how many numbers can we give to l?
			ll mid = (l2 + r2 + 1) / 2;
			if(l1 * mid + 2 * ((mid * (mid - 1)) / 2) <= l) l2 = mid;
			else r2 = mid - 1;
		}
		ll l3 = 0, r3 = 2e9;
		while(l3 < r3){
			//how many numbers can we give to r?
			ll mid = (l3 + r3 + 1) / 2;
			if((l1 + 1) * mid + 2 * ((mid * (mid - 1)) / 2) <= r) l3 = mid;
			else r3 = mid - 1;
		}
		//now we need to take care of some corner cases
		if((l2 - l3) > 1){
			l2 = l3 + 1;
		}
		else if(l3 > l2){
			l3 = l2;
		}
		tot += l2 + l3;
		l -= l1 * l2 + 2 * ((l2 * (l2 - 1)) / 2);
		r -= (l1 + 1) * l3 + 2 * ((l3 * (l3 - 1)) / 2);
		cout << tot << " " << l << " " << r << endl;
	}	
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
	- Array bounds
	- Special cases
Be careful!
*/