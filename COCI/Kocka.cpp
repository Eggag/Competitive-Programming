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

void bad(){
	cout << "NE" << endl;
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi l(n), r(n), u(n), d(n);
	rep(i, n) cin >> l[i];
	rep(i, n) cin >> r[i];
	rep(i, n) cin >> u[i];
	rep(i, n) cin >> d[i];
	vector<pi> c(n);
	rep(i, n) c[i] = mp(1e9, 0);
	//so first work with l and r
	rep(i, n){
		if(l[i] == -1 && r[i] != -1) bad();
		if((l[i] + 1 + r[i]) > n) bad();
		if(l[i] != -1 && r[i] != -1){
			c[l[i]].fi = min(c[l[i]].fi, i);
			c[l[i]].se = max(c[l[i]].se, i);
			c[n - r[i] - 1].fi = min(c[n - r[i] - 1].fi, i);
			c[n - r[i] - 1].se = max(c[n - r[i] - 1].se, i);
		}
	}
	rep(i, n){
		if(u[i] == -1 && d[i] != -1) bad();
		if((u[i] + 1 + d[i]) > n) bad();
		if(u[i] != -1 && d[i] != -1){
			if(c[i].fi < u[i]) bad();
			if(c[i].se > (n - d[i] - 1)) bad();
		}
	}
	cout << "DA" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
