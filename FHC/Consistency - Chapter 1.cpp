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

vector<char> v = {'A', 'E', 'I', 'O', 'U'};

bool vow(char c){
	rep(j, v.size()) if(c == v[j]) return 1;
	return 0;
}

void solve(){
	string s;
	cin >> s;
	int n = (int)(s.size());
	int ans = 1e9;
	rep(i, 26){
		char c = (char)('A' + i);
		int cur = 0;
		rep(j, n){
			if(vow(c)){
				if(!vow(s[j])) cur++;
				else cur += 2 * (s[j] != c);
			}
			else{
				if(vow(s[j])) cur++;
				else cur += 2 * (s[j] != c);
			}
		}
		ans = min(ans, cur);
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
