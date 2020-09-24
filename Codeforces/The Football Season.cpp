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
	ll n, p, w, d;
	cin >> n >> p >> w >> d;
	if(!p){
		cout << "0 0 " << n << endl;
		return 0;
	}
	for(ll i = 0LL; i <= min(n, 100000LL); i++){
		ll y = i * d;
		if(p < y) continue;
		ll x = p - y;
		if(x % w != 0) continue;
		x /= w;
		ll z = n - (x + (y / d));
		if(z < 0) continue;
		cout << x << " " << y / d << " " << z << endl;
		return 0;
	}
	for(ll i = 0LL; i <= min(n, 100000LL); i++){
		ll x = i * w;
		if(p < x) continue;
		ll y = p - x;
		if(y % d != 0) continue;
		y /= d;
		ll z = n - ((x / w) + y);
		if(z < 0) continue;
		cout << x / w << " " << y << " " << z << endl;
		return 0;
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
