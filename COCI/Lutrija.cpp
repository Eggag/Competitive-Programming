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
 
bool prime(ll num){
	if(num <= 1) return 0;
	for(ll j = 2; (j * j) <= num; j++){
		if(num % j == 0) return 0;
	}
	return 1;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll a, b;
	cin >> a >> b;
	if(prime(abs(a - 2)) && prime(abs(b - 2))){
		cout << 3 << endl << a << " " << 2 << " " << b << endl;
		return 0;
	}
	if(prime(abs(a - b))){
		cout << 2 << endl << a << " " << b << endl;
		return 0;
	}
	rep(i, 2) rep(j, 2){
		//i == 0 -> add 2's
		//i == 1 -> subtract 2's
		//j == 0 -> add 2's
		//j == 1 -> subtract 2's
		rep(k, 3) rep(l, 3){
			int f = 1;
			vector<ll> ans1 = {a};
			vector<ll> ans2 = {b};
			ll a1 = a, b1 = b;
			rep(m, k){
				if(i) a1 -= 2;
				else a1 += 2;
				ans1.pb(a1);
				if(!prime(a1)){
					f = 0;
					break;
				}
			}
			if(!f) continue;
			rep(m, l){
				if(j) b1 -= 2;
				else b1 += 2;
				ans2.pb(b1);
				if(!prime(b1)){
					f = 0;
					break;
				}
			}
			if(a1 == b1){
				ans1.pop_back();
				if(i) a1 += 2;
				else a1 -= 2;
			}
			if(f && prime(abs(a1 - b1)) && (ans1.size() + ans2.size()) <= 30){
				cout << ans1.size() + ans2.size() << endl;
				reverse(all(ans2));
				rep(m, ans1.size()) cout << ans1[m] << " ";
				rep(m, ans2.size()) cout << ans2[m] << " ";
				cout << endl;
				return 0;
			}
			ans1.pb(2);
			if(f && prime(abs(a1 - 2)) && prime(abs(b1 - 2)) && (ans1.size() + ans2.size()) <= 30){
				
				cout << ans1.size() + ans2.size() << endl;
				reverse(all(ans2));
				rep(m, ans1.size()) cout << ans1[m] << " ";
				rep(m, ans2.size()) cout << ans2[m] << " ";
				cout << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
