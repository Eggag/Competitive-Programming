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

int ask(int a, int b, int c){
	cout << "? " << a + 1 << " " << b + 1 << " " << c + 1 << endl;
	int ans;
	cin >> ans;
	if(ans == -1) exit(0);
	return ans;
}

void solve(){
	int n;
	cin >> n;
	int mx = 0;
	vi bst;
	repn(i, 2, n){
		int uwu = ask(0, 1, i);
		if(uwu == mx) bst.pb(i);
		if(uwu > mx){
			mx = uwu;
			bst.clear();
			bst.pb(i);
		}
	}
	int ans = bst[0];
	int mx1 = 0;
	vi bst1;
	repn(i, 1, n) if(i != ans){
		int uwu = ask(0, ans, i);
		if(uwu == mx1) bst1.pb(i);
		if(uwu > mx1){
			mx1 = uwu;
			bst1.clear();
			bst1.pb(i);
		}
	}
	if(mx >= mx1){
		if((int)(bst.size()) == n - 2){
			cout << "! 1 2" << endl;
			return;
		}
	}
	if((int)(bst1.size()) == n - 2){
		cout << "! " << ans + 1 << " " << 1 << endl;
		return;
	}
	cout << "! " << ans + 1 << " " << bst1[0] + 1 << endl;
}

int main(){
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
