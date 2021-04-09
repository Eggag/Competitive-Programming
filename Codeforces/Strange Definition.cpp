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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(){
	int n;
	cin >> n;
	vi a(n), b;
	rep(i, n){
		cin >> a[i];
		int nm = 1;
		for(int j = 2; (j * j) <= a[i]; j++){
			int cnt = 0;
			while(a[i] % j == 0) a[i] /= j, cnt++;
			if(cnt & 1) nm *= j;
		}
		if(a[i] > 1) nm *= a[i];
		b.pb(nm);
	}
	sort(all(b));
	int mx1 = 0, mx2 = 0;
	int cur = 1;
	repn(i, 1, n){
		if(b[i] == b[i - 1]) cur++;
		else{
			mx1 = max(mx1, cur);
			if(b[i - 1] == 1 || cur % 2 == 0) mx2 += cur;
			cur = 1;
		}
	}
	mx1 = max(mx1, cur);
	if(b[n - 1] == 1 || cur % 2 == 0) mx2 += cur;
	mx2 = max(mx2, mx1);
	int q;
	cin >> q;
	rep(i, q){
		ll x;
		cin >> x;
		if(x) cout << mx2 << '\n';
		else cout << mx1 << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
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
