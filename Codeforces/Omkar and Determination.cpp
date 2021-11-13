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
const int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dy[8] = {1, -1, 1, 0, -1, 1, 0, -1};
const int mxN = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m;
vector<pi> g[mxN];

int f(int i, int j){
	return i * m + j;
}

bool cmp(pi a, pi b){
	if(a.se != b.se) return a.se < b.se;
	return a.fi < b.fi;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	int q;
	cin >> q;
	vi p(m + 1, 0);
	rep(i, n) rep(j, m) if(s[i][j] == 'X'){
		if(i > 0 && j < (m - 1)){
			if(s[i - 1][j + 1] == 'X') p[j]++;
		}
	}
	repn(i, 1, m + 1) p[i] += p[i - 1];
	rep(i, q){
		int l, r;
		cin >> l >> r;
		l--, r--;
		cout << (((r ? p[r - 1] : 0) - (l ? p[l - 1] : 0)) ? "NO" : "YES") << '\n';
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
