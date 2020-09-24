#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	ll a = 1e9, b = 1e9, c = 1e9;
	ll ab = 1e9, bc = 1e9, ac = 1e9;
	ll abc = 1e9;
	ll cs;
	string s;
	rep(i, n){
		cin >> cs >> s;
		if(s.size() == 1){
			if(s[0] == 'A') a = min(a, cs);
			if(s[0] == 'B') b = min(b, cs);
			if(s[0] == 'C') c = min(c, cs);
		}
		if(s.size() == 2){
			sort(all(s));
			if(s[0] == 'A' && s[1] == 'B') ab = min(ab, cs);
			if(s[0] == 'A' && s[1] == 'C') ac = min(ac, cs);
			if(s[0] == 'B' && s[1] == 'C') bc = min(bc, cs);
		}
		if(s.size() == 3){
			abc = min(abc, cs);
		}
	}	
	int ans = min({a + b + c, abc, ab + c, ac + b, bc + a, ab + bc, ab + ac, bc + ac});
	if(ans < 1e9) cout << ans << endl;
	else cout << -1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
