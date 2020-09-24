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

ll lcm(ll a, ll b){
	return ((a * b) / gcd(a, b));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n;
	cin >> n;
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	if(n == 2){
		cout << 2 << endl;
		return 0;
	}
	if(n & 1){
		cout << (ll)(1LL * n * (n - 1) * (n - 2)) << endl;
		return 0;
	}
	ll n1 = n - 1;
	ll a1 = (ll)(1LL * n1 * (n1 - 1) * (n1 - 2));
	ll a2 = n * (n - 1);
	a2 = lcm(a2, (n - 3));
	cout << max(a1, a2) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
