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
const int b[3] = {1, 2, 0};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[3];

int f(char c){
	if(c == 'R') return 0;
	if(c == 'P') return 1;
	if(c == 'S') return 2;
}

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	rep(i, 3) g[i].clear();
	vi win(n, -1);
	rep(i, n) g[f(s[i])].pb(i);
	vector<char> ans(n, '.');
	for(int i = n - 1; i >= 0; i--){
		int op = b[f(s[i])];
		auto it = lb(all(g[op]), i);
		if(it == g[op].end()) ans[i] = s[i];
		else ans[i] = ans[*it];
	}
	rep(i, n) cout << ans[i];
	cout << '\n';
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
