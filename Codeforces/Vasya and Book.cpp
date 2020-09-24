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
	int n, x, y, d;
	cin >> n >> x >> y >> d;
	if((abs(y - x) % d != 0) && ((y - 1) % d != 0) && ((n - y) % d != 0)){
		cout << -1 << endl;
		return;
	}
	if(abs(x - y) % d == 0){
		cout << abs(y - x) / d << endl;
		return;
	}
	int ans = 1e9;
	if((y - 1) % d == 0){
		int g = x - 1;
		int div = (g + d - 1) / d;
		div += ((y - 1) / d);
		ans = min(ans, div);
	}
	if((n - y) % d == 0){
		int g = ((n - x) + d - 1) / d;
		g += (n - y) / d;
		ans = min(ans, g);
	}
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
