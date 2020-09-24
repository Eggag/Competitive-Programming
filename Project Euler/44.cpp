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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	vi p;
	unordered_map<int, int> pos;
	repn(i, 1, 10001){
		p.pb((i * ((3 * i) - 1)) / 2);
		pos[p[i - 1]] = 1;
	}	
	int ans = 1e9;
	rep(i, p.size()) repn(j, i + 1, p.size()){
		int mx = max(p[i], p[j]);
		int mn = min(p[i], p[j]);
		if(pos[mx + mn] && pos[mx - mn]) ans = min(ans, mx - mn);
		if(ans != 1e9){
			cout << ans << endl;
			return 0;
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
