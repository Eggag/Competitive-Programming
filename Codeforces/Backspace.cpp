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
	string s, t;
	cin >> s >> t;
	if((int)(t.size()) > (int)(s.size())){
		cout << "NO\n";
		return;
	}
	int n = (int)(s.size()), m = (int)(t.size());
	int cur = 0, lst = -1, f = 0;
	rep(i, n){
		if(!cur){
			if(s[i] == t[0]){
				if(!(cur == (m - 1) && (n - i) % 2 == 0)) cur++, lst = i, f = i & 1;
			}
		}
		else{
			if(cur == m) break;
			if(s[i] == t[cur] && ((i - lst) & 1)){
				if(!(cur == (m - 1) && (n - i) % 2 == 0)) cur++, lst = i;
			}
		}
	}
	int cur1 = 0, lst1 = -1;
	rep(i, n){
		if(!cur1){
			if(s[i] == t[0] && (i & 1) != f){
				if(!(cur1 == (m - 1) && (n - i) % 2 == 0)) cur1++, lst1 = i;
			}
		}
		else{
			if(cur1 == m) break;
			if(s[i] == t[cur1] && ((i - lst1) & 1)){
				if(!(cur1 == (m - 1) && (n - i) % 2 == 0)) cur1++, lst1 = i;
			}
		}
	}
	cout << ((cur == m || cur1 == m) ? "YES" : "NO") << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
