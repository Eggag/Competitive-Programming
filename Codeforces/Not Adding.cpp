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
const int mxN = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int g[mxN], vis[mxN], p[mxN];
vector<pi> d;
int cur = 0;

void sieve(){
	repn(i, 2, mxN) if(!p[i]){
		p[i] = i;
		for(int j = i + i; j < mxN; j += i) if(!p[j]) p[j] = i;
	}
}

void f(int ind, int num){
	if(ind == (int)(d.size())){
		if(g[num] != num) g[num] = gcd(g[num], cur);
		return;
	}
	int mul = 1;
	rep(i, d[ind].se + 1){
		f(ind + 1, num * mul);
		mul *= d[ind].fi;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i], vis[a[i]] = 1;
	sieve();
	vi div;
	rep(i, n){
		div.clear();
		cur = a[i];
		while(a[i] > 1){
			div.pb(p[a[i]]);
			a[i] /= p[a[i]];
		}
		if(!div.size()) continue;
		sort(all(div));
		d.clear();
		int cnt = 1;
		repn(j, 1, div.size()){
			if(div[j] == div[j - 1]) cnt++;
			else{
				d.pb(mp(div[j - 1], cnt));
				cnt = 1;
			}
		}
		d.pb(mp(div[div.size() - 1], cnt));
		f(0, 1);
	}
	int ans = 0;
	repn(i, 1, mxN) if(g[i] == i && !vis[i]) ans++;
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
