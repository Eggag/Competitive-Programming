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

void solve(){
	string s;
	cin >> s;
	int n = s.size();
	int ans = 1e9;
	vi cnt(n + 1, 0);
	cnt[0] = (s[0] == '0');
	repn(i, 1, n) cnt[i] = cnt[i - 1] + (s[i] == '0'); 
	//0 until i
	rep(i, n){
		int num = cnt[n - 1] - cnt[i];
		ans = min(ans, cnt[i] + ((n - i - 1) - num));
	}
	//1 until i
	rep(i, n){
		int num = cnt[n - 1] - cnt[i];
		ans = min(ans, i + 1 - cnt[i] + num);
	}
	ans = min(ans, cnt[n - 1]);
	ans = min(ans, n - cnt[n - 1]);
	cout << ans << endl;
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
	- Array bounds
	- Special cases
Be careful!
*/
