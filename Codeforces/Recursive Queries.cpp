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
const int mxN = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int g[mxN], cnt[10][mxN];

int f(int n){
	string s = to_string(n);
	int nm = 1;
	rep(i, s.size()) if(s[i] != '0') nm *= (s[i] - '0');
	return nm;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	rep(i, 1e6 + 1){
		if(i < 10) g[i] = i;
		else g[i] = g[f(i)];
		if(g[i] >= 1 && g[i] <= 9) cnt[g[i]][i]++;
	}
	repn(i, 1, 10) repn(j, 1, 1e6 + 1) cnt[i][j] += cnt[i][j - 1];
	int q;
	cin >> q;
	rep(i, q){
		int l, r, k;
		cin >> l >> r >> k;
		cout << cnt[k][r] - cnt[k][l - 1] << '\n';
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
