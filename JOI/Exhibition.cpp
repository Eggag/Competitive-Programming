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

bool cmp(pi a, pi b){
	if(a.se != b.se) return a.se > b.se;
	return a.fi > b.fi;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<pi> p(n);
	rep(i, n) cin >> p[i].fi >> p[i].se;
	vi c(m);
	rep(i, m) cin >> c[i];
	sort(all(c));
	reverse(all(c));
	sort(all(p), cmp);
	int cur = 0;
	rep(i, m){
		while(p[cur].fi > c[i] && cur < n) cur++;
		if(cur == n || cur < n && p[cur].fi > c[i]){
			cout << i << endl;
			return 0;
		}
		cur++;
	}
	cout << m << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
