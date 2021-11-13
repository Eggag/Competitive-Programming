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
const int mxN = 2005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
int p[mxN][mxN];

void query(int i){
	cout << "? " << i << endl;
	repn(j, 1, n + 1) cin >> p[i][j];
}

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	query(1);
	int odd = 0;
	repn(j, 1, n + 1) if(p[1][j] & 1) odd++;
	vector<pi> ed;
	if(odd <= ((n + 1) / 2) - 1){
		repn(j, 1, n + 1) if(p[1][j] & 1){
			query(j);
			repn(k, 1, n + 1) if(p[j][k] == 1) ed.pb(mp(j, k));
		}
	}
	else{
		repn(j, 1, n + 1) if(p[1][j] % 2 == 0){
			if(j != 1) query(j);
			repn(k, 1, n + 1) if(p[j][k] == 1) ed.pb(mp(j, k));
		}
	}
	cout << "!" << endl;
	for(pi x : ed) cout << x.fi << " " << x.se << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
