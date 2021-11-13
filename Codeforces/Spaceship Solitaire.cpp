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

map<int, map<int, int>> m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<ll> a(n + 1);
	ll sum = 0LL;
	repn(i, 1, n + 1) cin >> a[i], sum += a[i];
	int q;
	cin >> q;
	rep(i, q){
		int s, t, u;
		cin >> s >> t >> u;
		if(m.find(s) != m.end() && m[s].find(t) != m[s].end()){
			int nm = m[s][t];
			a[nm]++;
			if(a[nm] > 0) sum++;
			m[s].erase(t);
		}
		if(u > 0){
			m[s][t] = u;
			if(a[u] > 0) sum--;
			a[u]--;
		}
		cout << sum << '\n';
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
