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
	string s;
	cin >> s;
	string t = "abacaba";
	rep(i, n - 6){
		int f = 1;
		repn(j, i, i + 7){
			if(!(s[j] == t[j - i] || s[j] == '?')) f = 0;
		}
		if(f){
			string s1 = s;
			repn(j, i, i + 7) if(s[j] == '?') s1[j] = t[j - i];
			int cnt = 0;
			rep(j, n - 6){
				int f1 = 1;
				repn(k, j, j + 7){
					if(!(s1[k] == t[k - j])) f1 = 0;
				}
				cnt += f1;
			}
			if(cnt == 1){
				cout << "Yes\n";
				rep(j, n) if(s1[j] == '?') s1[j] = 'z';
				cout << s1 << '\n';
				return;
			}
		}
	}
	cout << "No\n";
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
