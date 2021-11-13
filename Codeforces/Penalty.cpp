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
	int n = 10;
	//england didn't deserve that penalty
	string s;
	cin >> s;
	int nm = 0, ans = 10;
	rep(i, n) if(s[i] == '?') nm++;
	rep(i, (1 << nm)){
		string s1 = s;
		int cnt = 0;
		rep(j, n) if(s1[j] == '?'){
			if(i & (1 << (cnt++))) s1[j] = '1';
			else s1[j] = '0';
		}
		int a = 0, b = 0;
		int lft = 5, lft1 = 5;
		rep(j, n){
			if(j % 2 == 0){
				if(s1[j] == '1') a++;
				lft--;
			}
			else{
				if(s1[j] == '1') b++;
				lft1--;
			}
			int f = 0;
			if(a - b > lft1) f = 1;
			if(b - a > lft) f = 1;
			if(f){
				ans = min(ans, j + 1);
				break;
			}
		}
	}
	cout << ans << '\n';
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
