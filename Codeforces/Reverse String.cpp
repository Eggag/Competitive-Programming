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
const int mxN = 1005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int ok[mxN][mxN];

void solve(){
	string s, t;
	cin >> s >> t;
	int n = (int)(s.size()), m = (int)(t.size());
	rep(i, m + 1) rep(j, n + 1) ok[i][j] = 0;
	repn(rm, 1, m){
		rep(i, n){
			if(rm == 1){
				if(s[i] == t[m - 1]) ok[rm][i] = 1;
			}
			else{
				if(s[i] == t[m - rm] && (i >= 1 && ok[rm - 1][i - 1])) ok[rm][i] = 1;
			}
		}
	}
	rep(i, n){
		repn(j, i, n){
			int sz = j - i + 1;
			if(j - i + 1 > m) break;
			if(s[j] != t[j - i]) break;
			int rem = m - sz;
			if(!rem || (j && ok[rem][j - 1])){
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
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
