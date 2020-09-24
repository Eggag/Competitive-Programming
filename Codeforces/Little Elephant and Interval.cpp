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

ll pow10[18];

string fun(ll num){
	string ret = "";
	while(num){
		ret += (char)((num % 10) + '0');
		num /= 10;
	}
	reverse(all(ret));
	return ret;
}

ll to_ll(string num){
	ll ret = 0;
	ll mul = 1LL;
	reverse(all(num));
	rep(i, num.size()){
		ret += (num[i] - '0') * mul;
		mul *= 10;
	}
	return ret;
}

ll solve(ll num){
	string s = fun(num);
	//debug2(num, s);
	int sz = s.size();
	ll ans = 0;
	if(num < 10) return num;
	else ans += 9;
	repn(i, 2, sz){
		ll tmp = 9 * pow10[i - 2];
		//debug2(i, tmp);
		ans += tmp;
	}
	int lst = (s[0] - '0');
	ll cur = to_ll(s.substr(1, s.size() - 1));
	//debug(cur);
	//debug(lst);
	repn(i, 1, lst) ans += pow10[sz - 2];
	ll nw = (cur + (10 - lst)) / 10;
	ans += nw;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll l, r;
	cin >> l >> r;
	pow10[0] = 1LL;
	repn(i, 1, 18) pow10[i] = (1LL * pow10[i - 1] * 10); 
	cout << solve(r) - solve(l - 1) << endl;
	//cout << solve(r) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
