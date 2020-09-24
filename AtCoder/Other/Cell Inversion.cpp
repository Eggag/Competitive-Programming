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
	string s;
	cin >> s;
	if(s[0] != 'B' || s[2 * n - 1] != 'B'){
		cout << 0 << endl;
		return 0;
	}
	string res = "";
	res += 'L';
	repn(i, 1, 2 * n){
		if(s[i] == s[i - 1]){
			if(res[res.size() - 1] == 'L') res += 'R';
			else res += 'L';
		}
		else{
			res += res[res.size() - 1];
		}
	}
	ll ans = 1LL;
	ll l1 = 0, r1 = 0;
	rep(i, 2 * n){
		if(res[i] == 'L') l1++;
		else (ans *= l1 - r1) %= MOD, l1--;
	}
	if(l1){
		cout << 0 << endl;
		return 0;
	}
	repn(i, 1, n + 1) (ans *= i) %= MOD;
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
