#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	cin >> s;
	int ans = 10;
	rep(a, 10) rep(b, 10) rep(c, 10) rep(d, 10) rep(e, 10) rep(f, 10) if((a + b + c) == (d + e + f)){
		string s1 = "";
		s1 += '0' + a;
		s1 += '0' + b;
		s1 += '0' + c;
		s1 += '0' + d;
		s1 += '0' + e;
		s1 += '0' + f;
		int cur = 0;
		rep(i, 6){
			if(s[i] != s1[i]) cur++;
		}
		ans = min(ans, cur);
	}
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
