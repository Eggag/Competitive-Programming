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
	ll n, k, s;
	cin >> n >> k >> s;
	if(((n - 1) * k) < s || k > s){
		//either too much, or too little
		cout << "NO" << endl;
		return 0;
	}
	//say s = 13 and k = 4
	ll div = s / k;
	ll md = s % k;
	cout << "YES" << endl;
	ll prev = 1;
	ll ans = 0;
	rep(i, md){
		if(i % 2 == 0) cout << div + 2 << " ", ans += abs(div + 2 - prev), prev = div + 2;
		else cout << 1 << " ", ans += abs(1 - prev), prev = 1;
	}
	repn(i, md, k){
		if(i % 2 != 0){
			if(!md) cout << 1 << " ", ans += abs(prev - 1), prev = 1;
			else{
				if(!(md & 1)) cout << 1 << " ", ans += abs(prev - 1), prev = 1;
				else cout << 2 << " ", ans += abs(prev - 2), prev = 2;
			}
		}
		else{
			if(!md) cout << div + 1 << " ", ans += abs(div + 1 - prev), prev = div + 1;
			else{
				if(!(md & 1)) cout << div + 1 << " ", ans += abs(div + 1 - prev), prev = div + 1;
				else cout << div + 2 << " ", ans += abs(div + 2 - prev), prev = div + 2;
			}
		}
	}
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
