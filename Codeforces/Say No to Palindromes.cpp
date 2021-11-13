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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int cnt[10][mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<string> t = {"abc", "acb", "bac", "bca", "cba", "cab"};
	rep(j, 6){
		int pos = 0;
		rep(i, n){
			if(s[i] != t[j][pos++]) cnt[j][i] = 1;
			if(i) cnt[j][i] += cnt[j][i - 1];
			if(pos == 3) pos = 0;
		}
	}
	rep(i, m){
		int l, r;
		cin >> l >> r;
		r--, l--;
		int res = 1e9;
		rep(j, 6) res = min(res, cnt[j][r] - (l ? cnt[j][l - 1] : 0));
		cout << res << '\n';
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
