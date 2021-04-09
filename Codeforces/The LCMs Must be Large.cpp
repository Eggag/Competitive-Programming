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
const int mxN = 1e4 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi l[mxN], r[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int m, n;
	cin >> m >> n;
	int f = 1;
	rep(i, m){
		int s;
		cin >> s;
		vi vis(n, 0);
		rep(j, s){
			int x;
			cin >> x;
			vis[x - 1] = 1;
		}
		rep(j, n){
			if(vis[j]) l[i].pb(j);
			else r[i].pb(j);
		}
	}
	rep(i, m) rep(j, m) if(i != j){
		int pos = 0, cr = 1;
		rep(k, l[i].size()){
			while(pos < r[j].size() && r[j][pos] < l[i][k]) pos++;
			if(pos == r[j].size()) cr = 0;
			else if(r[j][pos] != l[i][k]) cr = 0;
		}
		if(cr) f = 0;
	}	
	cout << (f ? "possible" : "impossible") << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
