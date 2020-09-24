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

ll fact(ll num){
	ll ret = 1;
	for(ll i = 2; i <= num; i++) ret *= i;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n;
	cin >> n;
	ll ans = ((n * (n - 1) * (n - 2) * (n - 3) * (n - 4) * (n - 5) * 7) / fact(7)) * (n - 6);
	ans /= 7;
	ans += (n * (n - 1) * (n - 2) * (n - 3) * (n - 4) * (n - 5)) / fact(6);
	ans += (n * (n - 1) * (n - 2) * (n - 3) * (n - 4)) / fact(5);
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
