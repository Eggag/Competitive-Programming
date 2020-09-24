#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
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

vi oc[405];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int r, c;
	cin >> r >> c;
	vector<string> s(r);
	rep(i, r) cin >> s[i];
	rep(i, r) rep(j, c) if(s[i][j] == 'X') oc[i].pb(j);
	int ans = 0;
	rep(i, r) rep(j, c){
		int mn = 1e9;
		repn(k, i, r){
			if(s[k][j] != '.') break;
			auto nxt = lb(all(oc[k]), j);
			if(nxt == oc[k].end()) mn = min(mn, c);
			else mn = min(mn, *nxt);
			ans = max(ans, 2 * (k - i + 1) + 2 * (mn - j));
		}
	}
	cout << ans - 1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
