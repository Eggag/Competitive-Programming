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

void solve(){
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	ll mx = 0;
	rep(i, n) cin >> a[i], mx = max(mx, a[i]);
	//try to do each element separately
	int f = 1;
	ll num = 1;
	vector<ll> pos = {num};
	while(num < mx) num *= k, pos.pb(num);
	vi vis((int)pos.size(), 0);
	rep(i, n){
		ll cur = a[i];
		for(int j = (int)pos.size() - 1; j >= 0; j--) if(!vis[j]){
			if(cur >= pos[j]){
				vis[j] = 1;
				cur -= pos[j];
			}
		}
		if(cur){
			f = 0;
			break;
		}
	}
	if(f) cout << "YES" << endl;
	else cout << "NO" << endl;
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
