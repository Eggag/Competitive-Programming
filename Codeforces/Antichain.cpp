#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
#define debug2(x, y) debug(x), debug(y)
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
	string s;
	cin >> s;
	int n = (int)(s.size());
	int ans = 1, f = 0;
	vi l(n, 0), r(n, 0);
	l[n - 1] = (s[n - 1] == '1');
	r[n - 1] = (s[n - 1] == '0');
	for(int i = n - 2; i >= 0; i--){
		l[i] = l[i + 1], r[i] = r[i + 1];
		if(l[i] && s[i] == '0') l[i] = 0;
		if(r[i] && s[i] == '1') r[i] = 0;
	}
	repn(i, 1, n){
		if(l[i] || r[i]) break;
		if(s[i - 1] == '1') f |= 1;
		if(s[i - 1] == '0') f |= 2;
		if(f == 3) ans++, f = 0;
	}
	int st = n + 1;
	repn(i, 1, n){
		if(s[i - 1] != s[n - 1]){
			st = i;
			break;
		}
	}
	int ans1 = 1;
	f = 0;
	repn(i, st + 1, n){
		if(s[i - 1] == '1') f |= 1;
		if(s[i - 1] == '0') f |= 2;
		if(f == 3) ans1++, f = 0;
	}
	cout << max(ans1, ans) << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
