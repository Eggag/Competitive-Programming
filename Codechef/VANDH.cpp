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
	int n, m;
	cin >> n >> m;
	if(n > m){
		string ans = "";
		rep(i, 2 * m + 3) ans += (i & 1 ? '1' : '0');
		while(n - 1 != m) ans += "010", n--;
		cout << (int)(ans.size()) << '\n';
		cout << ans << '\n';
	}
	else if(m > n){
		string ans = "";
		rep(i, 2 * n + 3) ans += (i & 1 ? '0' : '1');
		while(m - 1 != n) ans += "101", m--;
		cout << (int)(ans.size()) << '\n';
		cout << ans << '\n';
	}
	else{
		string ans = "";
		rep(i, 2 * n + 2) ans += (i & 1 ? '0' : '1');
		cout << (int)(ans.size()) << '\n';
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
