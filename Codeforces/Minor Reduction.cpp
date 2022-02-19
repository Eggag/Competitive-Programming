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
	string s;
	cin >> s;
	int n = (int)(s.size());
	string ans = "";
	for(int i = n - 2; i >= 0; i--){
		int a = s[i] - '0', b = s[i + 1] - '0';
		if(a + b >= 10){
			string cr = to_string(a + b);
			ans = s;
			ans[i] = cr[0];
			ans[i + 1] = cr[1];
			break;
		}
	}
	if(ans.size()) cout << ans << '\n';
	else{
		rep(i, n){
			int a = s[i] - '0', b = s[i + 1] - '0';
			string cr = to_string(a + b);
			rep(j, n) if(j != (i + 1)) ans += s[j];
			ans[i] = cr[0];
			break;
		}
		cout << ans << '\n';
	}
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
