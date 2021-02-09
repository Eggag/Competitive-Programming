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
	string s;
	cin >> s;
	int o1 = 0, e1 = 0;
	int o0 = 0, e0 = 0;
	int c01 = 0, c10 = 0;
	rep(i, n - 1){
		if(s[i] == '0' && s[i + 1] == '1' && (i & 1)) c01++;
		if(s[i] == '0' && s[i + 1] == '1' && !(i & 1)) c10++;
		if(s[i] == '1' && s[i + 1] == '0' && (i & 1)) c10++;
		if(s[i] == '1' && s[i + 1] == '0' && !(i & 1)) c01++;
	}
	rep(i, n){
		if(i & 1){
			if(s[i] == '0') o0++;
			else o1++;
		}
		else{
			if(s[i] == '0') e0++;
			else e1++;
		}
	}
	cout << min(o0 + e1 - c01, o1 + e0 - c10) << '\n';
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
