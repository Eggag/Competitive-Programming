#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int bc(int a){
	return __builtin_popcount(a);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vi l(n);
	int ans = 1e9;
	rep(i, n) cin >> l[i];
	repn(i, 1, (1 << n)) repn(j, 1, (1 << n)){
		if(i & j) continue;
		repn(k, 1, (1 << n)){
			if(i & k || j & k) continue;
			int cur = 0;
			int ret = 0;
			rep(s, n) if(i & (1 << s)) cur += l[s];
			ret += abs(a - cur);
			cur = 0;
			rep(s, n) if(j & (1 << s)) cur += l[s];
			ret += abs(b - cur);
			cur = 0;
			rep(s, n) if(k & (1 << s)) cur += l[s];
			ret += abs(c - cur);
			ret += 10 * (bc(i) + bc(j) + bc(k) - 3);
			ans = min(ans, ret);
		}
	}
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
