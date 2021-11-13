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

int ask(vi cr){
	cout << '?';
	for(int x : cr) cout << ' ' << x;
	cout << endl;
	int res;
	cin >> res;
	return res;
}

int main(){
	int n;
	cin >> n;
	int lst = -1;
	repn(i, 1, n){
		vi cr;
		repn(j, 1, n + 1){
			if(j < n) cr.pb(i + 1);
			else cr.pb(1);
		}
		int r = ask(cr);
		if(!r){
			lst = i;
			break;
		}
	}
	vi ans(n + 1, 0);
	if(lst == -1) lst = n;
	ans[n] = lst;
	repn(i, 1, lst){
		vi cr;
		repn(j, 1, n + 1){
			if(j < n) cr.pb(i + 1);
			else cr.pb(1);
		}
		int r = ask(cr);
		assert(r);
		ans[r] = lst - i;
	}
	repn(i, lst + 1, n + 1){
		vi cr;
		repn(j, 1, n + 1){
			if(j < n) cr.pb(1);
			else cr.pb((i - lst) + 1);
		}
		int r = ask(cr);
		assert(r);
		ans[r] = i;
	}
	cout << '!';
	repn(i, 1, n + 1) cout << ' ' << ans[i];
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
