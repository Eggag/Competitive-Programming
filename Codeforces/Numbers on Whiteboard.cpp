#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
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
	if(n <= 3){
		cout << 2 << '\n';
		if(n == 2) cout << "1 2\n";
		else{
			cout << "1 3\n";
			cout << "2 2\n";
		}
		return;
	}
	cout << 2 << '\n';
	cout << n << " " << n - 2 << '\n';
	cout << n - 1 << " " << n - 1 << '\n';
	int nm = n - 1;
	int cnt = n - 3;
	int nxt = n - 3;
	while(cnt--){
		cout << nm << " " << nxt << '\n';
		nm = (nm + nxt + 1) / 2;
		nxt--;
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
