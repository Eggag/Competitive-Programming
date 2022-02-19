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
	int n, m;
	cin >> n >> m;
	vi s(n), t(m);
	vi vis(2, 0), vis1(2, 0);
	rep(i, n) cin >> s[i], vis[s[i]] = 1;
	rep(i, m) cin >> t[i], vis1[t[i]] = 1;
	rep(i, 2) if(vis1[i] && !vis[i]){
		cout << -1 << '\n';
		return 0;
	}
	int ind = 0;
	while(ind < m && s[0] == t[ind]) ind++;
	if(ind == m){
		cout << m << '\n';
		return 0;
	}
	int mn = 1e9;
	repn(i, 1, n) if(s[i] != s[0]) mn = min(mn, i);
	for(int i = n - 1; i >= 1; i--) if(s[i] != s[0]) mn = min(mn, n - i);
	repn(i, ind + 1, m) if(t[i] == t[i - 1]) mn--;
	cout << mn + (m - ind - 1) + m << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
