#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl '\n'

ll gcd(ll a,ll b){ return (ll)((b == 0) ? a : gcd(b, a % b)); }

ll lcm(ll a, ll b){ return (ll)((ll)(a * b) / (ll)(gcd(a, b))); }

void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	ll mn = 1e18;
	ll mx = 0LL;
	rep(i, n) cin >> a[i], mn = min(mn, a[i]), mx = max(mx, a[i]);
	ll x = mn * mx;
	a.pb(x), a.pb(1);
	sort(all(a));
	vector<ll> b;
	for(ll i = 1; i <= sqrt(x); i++){
		if(x % i == 0){
			b.pb(i);
			if((x / i) != i) b.pb(x / i);
		}
	}
	sort(all(b));
	if(a.size() != b.size()){
		cout << -1 << endl;
		return;
	}
	rep(i, a.size()){
		if(a[i] != b[i]){
			cout << -1 << endl;
			return;
		}
	}
	cout << x << endl;
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
	- Array bounds
	- Special cases
Be careful!
*/
