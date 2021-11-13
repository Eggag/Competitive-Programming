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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	string ans = "";
	if(k == 1){
		rep(i, n) ans += 'a';
		cout << ans << '\n';
		return 0;
	}
	vector<string> pos;
	rep(i, k){
		string s1 = "";
		s1 += (char)('a' + i);
		pos.pb(s1);
		repn(j, i + 1, k){
			string s = "";
			s += (char)('a' + i);
			s += (char)('a' + j);
			pos.pb(s);
		}
	}
	int ind = 0;
	while(ans.size() < n){
		ans += pos[ind];
		ind++;
		if(ind >= pos.size()) ind = 0;
	}
	if(ans.size() > n) ans.pop_back();
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
