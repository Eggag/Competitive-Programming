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
const int mxN = 1e7 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int p[mxN];

void sieve(int n){
	for(int i = 2; i < n; i++) if(!p[i]){
		p[i] = i;
		for(int j = i + i; j < n; j += i) if(!p[j]) p[j] = i;
	}	
}

void solve(){
	int n, k;
	cin >> n >> k;
	vi a(n);
	rep(i, n) cin >> a[i];
	rep(i, n){
		int cr = a[i];
		vi d;
		while(cr != 1){
			d.pb(p[cr]);
			cr /= p[cr];
		}
		sort(all(d));
		int cnt = 1, nm = 1;
		repn(j, 1, d.size()){
			if(d[j] == d[j - 1]) cnt++;
			else{
				if(cnt & 1) nm *= d[j - 1];
				cnt = 1;
			}
		}
		if((cnt & 1) && d.size()) nm *= d[(int)(d.size()) - 1];
		a[i] = nm;
	}
	map<int, int> vis;
	int ans = 1;
	rep(i, n){
		if(vis[a[i]]){
			vis.clear();
			ans++;
		}
		vis[a[i]] = 1;
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	sieve(mxN - 2);
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
