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
	vector<ll> a(n);
	ll df = 0LL, df1 = 0LL;
	vector<ll> p, p1;
	rep(i, n) cin >> a[i];
	rep(i, n){
		if(i % 2 == 0){
			ll cur = a[i];
			if(a[i] & 1){
				if(a[i] < 2) cur++;
				else cur--;
			}
			df += abs(a[i] - cur);
			p.pb(cur);
		}
		else{
			p.pb(2);
			df += abs(a[i] - 2);
		}
	}
	rep(i, n){
		if(i % 2 == 1){
			ll cur = a[i];
			if(a[i] & 1){
				if(a[i] < 2) cur++;
				else cur--;
			}
			df1 += abs(a[i] - cur);
			p1.pb(cur);
		}
		else{
			p1.pb(2);
			df1 += abs(a[i] - 2);
		}
	}
	if(df1 < df) swap(p, p1);
	for(int x : p) cout << x << " ";
	cout << '\n';
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
