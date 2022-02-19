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

vi g[30];

void solve(){
	string s;
	cin >> s;
	int n = (int)(s.size());
	rep(i, 30) g[i].clear();
	rep(i, n) g[(int)(s[i] - 'a')].pb(i);
	char mx = '.';
	int ind = -1;
	vi vis(n, 0);
	string ans = "";
	vector<string> uwu;
	while(ind < n - 1){
		rep(i, 26){
			auto it = lb(all(g[i]), ind + 1);
			if(it != g[i].end()){
				if(mx != '.'){
					char c = (char)('a' + i);			
					if(c <= mx){
						if(c == mx){
							string ans1 = ans;
							rep(i, n) if(!vis[i]) ans1 += s[i];
							uwu.pb(ans1);
						}
						ind  = *it;
						ans += s[ind];
						vis[ind] = 1;
					}
					else goto hell;
				}
				else{
					if(*it - 1 > ind) mx = s[ind + 1];
					ind  = *it;
					ans += s[ind];
					vis[ind] = 1;
				}
				break;
			}
		}
	}
	hell:;
	rep(i, n) if(!vis[i]) ans += s[i];
	uwu.pb(ans);
	cout << *min_element(all(uwu)) << '\n';
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
