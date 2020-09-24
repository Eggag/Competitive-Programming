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
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<string> s(2);
	rep(i, 2) cin >> s[i];
	ll ans = 1;
	rep(j, n){
		if(j < (n - 1) && s[0][j] == s[0][j + 1]){
			if(!j) (ans *= 6) %= MOD;
			else{
				if(s[0][j - 1] != s[1][j - 1]){
					(ans *= 3) %= MOD;
				}
				else (ans *= 2) %= MOD;
			}
		}
		if(s[0][j] == s[1][j]){
			if(!j) (ans *= 3) %= MOD;
			else{
				if(s[0][j - 1] == s[1][j - 1]) (ans *= 2) %= MOD;
			}
		}
	}
	cout << ans % MOD << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
