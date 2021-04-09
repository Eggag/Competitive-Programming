#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
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
	int n = s.size();
	rep(i, 26) g[i].clear();
	rep(i, n) g[s[i] - 'a'].pb(i);
	vi vis(30, 0);
	int pos = 0; //next one we can go on
	string ans = "";
	rep(i, 26){
		for(int j = 25; j >= 0; j--) if(!vis[j] && g[j].size()){
			int nxt = *lb(all(g[j]), pos);
			int f = 1;
			rep(k, 26) if(!vis[k] && g[k].size() && j != k){
				if(g[k][g[k].size() - 1] < nxt) f = 0;
			}
			if(f){
				ans += (char)('a' + j);
				vis[j] = 1;
				pos = nxt;
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
