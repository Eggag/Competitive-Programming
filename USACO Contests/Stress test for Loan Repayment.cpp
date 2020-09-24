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

ll n, k, m;

mt19937 rng((ll)std::chrono::steady_clock::now().time_since_epoch().count());

bool check(ll num){
	ll sum = 0;
	ll cnt = 0;	
	while(cnt < k){
		if(sum >= n) return 1;
		ll nm = (n - sum) / num;
		ll nm1 = max(m, nm);
		if(nm1 == m){
			sum += (k - cnt) * m;
			break;
		}
		else{
			ll md = (((n - sum) % num) + nm1) / nm1;
			if((cnt + md) > k){
				sum += (k - cnt) * nm1;
				break;
			}
			else{
				cnt += md;
				sum += md * nm1;
			}
		}
	}
	return (sum >= n);
}

bool check1(ll num){
	//we set x to num
	ll sum = 0;
	for(ll i = 0; i < k; i++){
		sum += max(m, (n - sum) / num);
	}
	return (sum >= n);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while(true){
		n = rng() % 100000000;
		k = rng() % 100000000;
		m = rng() % 100000000;
		if((k * m) < n){
			ll l = 1, r = 1e12;
			while(l < r){
				ll mid = (l + r + 1) / 2;
				if(check(mid)) l = mid;
				else r = mid - 1;
			}
			ll ans = l;
			l = 1, r = 1e12;
			while(l < r){
				ll mid = (l + r + 1) / 2;
				if(check1(mid)) l = mid;
				else r = mid - 1;
			}
			ll ans1 = l;
			if(ans != ans1){
				debug2(n, k);
				debug(m);
				cout << "OOPS!" << endl;
				debug2(ans, ans1);
				return 0;
			}
		}
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
