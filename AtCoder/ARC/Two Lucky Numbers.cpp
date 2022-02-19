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
	int a, s;
	cin >> a >> s;
	string b = to_string(s);
	int n = (int)(b.size());
	string ans = "";
	if((b[n - 1] - '0') & 1) ans += '5';
	else ans += '0';
	for(int i = n - 1; i >= 0; i--){
		int cr = (b[i] - '0');
		if(i > 0 && ((b[i - 1] - '0') & 1)){
			int nw = (10 + cr) / 2;
			ans += to_string(nw);
		}
		else ans += (char)((cr / 2) + '0');
	}
	while(ans.size() && ans[(int)(ans.size()) - 1] == '0'){
		ans.pop_back();
	}
	reverse(all(ans));
	ans += to_string(a);
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
