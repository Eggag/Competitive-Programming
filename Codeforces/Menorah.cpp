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
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	int ans = 1e9;
	int c = 0, d = 0;
	rep(i, n){
		if(s[i] == '1') c++;
		else d++;
		if(t[i] == '1') c--;
		else d--;
	}
	if(!c && !d){
		int uwu = 0, owo = 0;
		rep(i, n){
			if(s[i] == '0' && t[i] == '1') uwu++;
			if(s[i] == '1' && t[i] == '0') owo++;
		}
		ans = uwu + owo;
	}
	rep(i, n) if(s[i] == '1' && t[i] == '1'){
		string s1 = s;
		rep(j, n) if(j != i){
			if(s1[j] == '1') s1[j] = '0';
			else s1[j] = '1';
		}
		int c1 = 0, d1 = 0;
		rep(j, n){
			if(s1[j] == '1') c1++;
			else d1++;
			if(t[j] == '1') c1--;
			else d1--;
		}
		int a = 0, b = 0;
		rep(j, n){
			if(s1[j] == '0' && t[j] == '1') a++;
			if(s1[j] == '1' && t[j] == '0') b++;
		}
		if(!c1 && !d1) ans = min(ans, a + b + 1);
		break;
	}
	rep(i, n) if(s[i] == '1' && t[i] == '0'){
		string s1 = s;
		rep(j, n) if(j != i){
			if(s1[j] == '1') s1[j] = '0';
			else s1[j] = '1';
		}
		int c1 = 0, d1 = 0;
		rep(j, n){
			if(s1[j] == '1') c1++;
			else d1++;
			if(t[j] == '1') c1--;
			else d1--;
		}
		int a = 0, b = 0;
		rep(j, n){
			if(s1[j] == '0' && t[j] == '1') a++;
			if(s1[j] == '1' && t[j] == '0') b++;
		}
		if(!c1 && !d1) ans = min(ans, a + b + 1);
		break;
	}
	if(ans == 1e9) ans = -1;
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
