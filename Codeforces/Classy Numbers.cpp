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

ll powt[20];

ll go(ll num){
	if(!num) return 0;
	ll num1 = num;
	int len = 0;
	while(num1){
		len++;
		num1 /= 10;
	}
	ll ans = 0;
	repn(i, 1, len){
		ans += 9; // the first digit
		ans += 81 * (i - 1);
		ans += 729 * ((i - 1) * (i - 2) / 2);
	}
	string s = to_string(num);
	int dig = (int)(s[0] - '0');
	ans += dig - 1;
	ans += (dig - 1) * 9 * (len - 1);
	ans += (((dig - 1) * 81 * ((len - 1) * (len - 2))) / 2);
	len--;
	ll cur = powt[len] * dig;
	if(cur <= num) ans++;
	repn(j, 1, 10) rep(k, len){
		ll cur = powt[len] * dig;
		cur += j * powt[k];
		if(cur <= num) ans++;
	}
	int nw = 0;
	repn(j, 1, 10) rep(k, len) repn(l, 1, 10) rep(m, len) if(k != m){
		ll cur = powt[len] * dig;
		cur += j * powt[k];
		cur += l * powt[m];
		if(cur <= num) nw++;
	}
	ans += nw / 2;
	return ans;
}

void solve(){
	ll l, r;
	cin >> l >> r;
	cout << go(r) - go(l - 1) << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	powt[0] = 1LL;
	repn(i, 1, 19) powt[i] = (powt[i - 1] * 10LL);
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
