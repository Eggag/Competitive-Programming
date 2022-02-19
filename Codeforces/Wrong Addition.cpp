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
	string a, s;
	cin >> a >> s;
	int n = (int)(a.size()), m = (int)(s.size());
	int ind = m - 1;
	string ans = "";
	for(int i = n - 1; i >= 0; i--){
		int uwu = (int)(a[i] - '0'), owo = (int)(s[ind] - '0');
		if(owo < uwu){
			ans += (char)((owo + 10 - uwu) + '0');
			if(ind < 1 || (s[ind - 1] != '1')){
				cout << "-1\n";
				return;
			}
			ind -= 2;
		}
		else{
			ans += (char)((owo - uwu) + '0');
			if(ind < 0){
				cout << "-1\n";
				return;
			}
			ind--;
		}
	}
	while(ind >= 0) ans += s[ind--];
	while(ans.size() && ans[(int)(ans.size()) - 1] == '0') ans.pop_back();
	reverse(all(ans));
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
