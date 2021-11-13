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
	int n;
	cin >> n;
	vi p(n);
	rep(i, n) cin >> p[i];
	vi le(n), ri(n);
	int ans = 0, mx = 0, cur = 2, cnt = 0;
	le[1] = 2;
	repn(i, 2, n){
		if((p[i] > p[i - 1]) == (p[i - 1] > p[i - 2])) cur++;
		else{
			if(cur == mx) cnt++;
			else cnt = 1;
			mx = max(mx, cur);
			cur = 2;
		}
		le[i] = cur;
	}
	if(cur == mx) cnt++;
	else cnt = 1;
	mx = max(mx, cur);
	ri[n - 2] = 2, cur = 2;
	for(int i = n - 3; i >= 0; i--){
		if((p[i] > p[i + 1]) == (p[i + 1] > p[i + 2])) cur++;
		else cur = 2;
		ri[i] = cur;
	}
	repn(i, 1, n - 1) if(p[i] > p[i - 1] && p[i] > p[i + 1]){
		int l = le[i], r = ri[i];
		if(max(l, r) < mx) continue;
		if(max(l, r) == mx){
			int uwu = (l == mx) + (r == mx);
			if(cnt > uwu) continue;
		}
		if(l == 2 || r == 2) continue;
		if(max(l, r) % 2 == 0 || ((max(l, r) & 1) && l != r)) continue;
		ans++;
	}
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
