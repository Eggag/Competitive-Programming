#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'
const int MOD = 998244353;
 
int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }
 
ll to_int(string s){
	ll sum = (s[0] - '0');
	ll prev = 1;
	repn(i, 1, s.size()){
		sum = (sum + (prev * 10 * (s[i] - '0')) + MOD) % MOD;
		prev = (prev * 10) % MOD;
	}
	return (sum % MOD);
}
 
ll f(ll a, ll b){
	string a1 = to_string(a);
	string b1 = to_string(b);
	string ret = "";
	rep(i, 2 * a1.size()){
		if(i % 2 == 0) ret += a1[i / 2];
		else ret += b1[i / 2];
	}
	reverse(all(ret));
	ll c = to_int(ret) % MOD;
	return c;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll ans = 0;
	rep(i, n){
		ans = (ans + f(a[i], a[i]) * n) % MOD;
	}
	cout << ans % MOD << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
