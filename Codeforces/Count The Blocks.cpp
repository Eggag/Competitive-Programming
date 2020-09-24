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
const int MOD = 998244353;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll pow10[200005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	pow10[0] = 1LL;
	for(ll i = 1; i < 200005; i++) pow10[i] = (1LL * pow10[i - 1] * 10) % MOD;
	for(ll i = 1; i <= n; i++){
		if(i == n) cout << 10 << endl;
		else{
			ll num = 9 * 10 * 2 * pow10[n - i - 1];
			if((n - i - 1) >= 1) (num += ((((((n - i - 1) * 10) * 81) + MOD) % MOD) * pow10[n - i - 2] + MOD) % MOD) %= MOD;
			cout << num << " ";
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

