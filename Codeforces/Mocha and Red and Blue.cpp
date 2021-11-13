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

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int f = -1;
	rep(i, n) if(s[i] != '?'){
		f = i;
		break;
	}
	if(f == -1){
		rep(i, n){
			if(i & 1) s[i] = 'B';
			else s[i] = 'R';
		}
		cout << s << '\n';
		return;
	}
	int c = (s[f] == 'B' ? 1 : 0);
	repn(i, f + 1, n){
		if(s[i] == '?'){
			if(c) s[i] = 'R';
			else s[i] = 'B';
			c ^= 1;
		}
		else c = (s[i] == 'B' ? 1 : 0);
	}
	c = (s[f] == 'B' ? 1 : 0);
	for(int i = f - 1; i >= 0; i--){
		if(c) s[i] = 'R';
		else s[i] = 'B';
		c ^= 1;
	}
	cout << s << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
