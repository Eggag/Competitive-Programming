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

int f[1000005];

void solve(){
	string s;
	cin >> s;
	int mn = 1e9, p = 0;
	int n = s.size();
	rep(i, n + 1) f[i] = 1e9;
	rep(i, s.size()){
		if(s[i] == '+') p++;
		else p--;
		if(p < mn){
			mn = p;
		}
		if(p < 0){
			f[abs(p)] = min(f[abs(p)], i);
		}
	}
	if(mn >= 0) cout << s.size() << endl;
	else if(mn < 0){
		ll sm = 0;
		rep(i, n + 1) if(f[i] != 1e9) sm += f[i] + 1;
		cout << sm + (s.size()) << endl;
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
	- Array bounds
	- Special cases
Be careful!
*/
