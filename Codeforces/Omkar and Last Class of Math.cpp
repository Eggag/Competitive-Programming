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

ll mlcm(ll a, ll b){
	if(!a || !b) return 1e18;
	return (ll)((a / gcd(a, b)) * b);
}

void solve(){
	ll n;
	cin >> n;
	if(n % 2 == 0){
		cout << n / 2 << " " << n / 2 << endl;
	}
	else{
		ll l = 1e18;
		pair<ll, ll> bst;
		for(ll i = 1; (i * i) <= n; i++){
			if(n % i == 0){
				int mx = n / i, mn = n / (n / i);
				if(mn > mx) swap(mx, mn);
				if(mlcm(mn, mn * (mx - 1)) < l){
					l = mlcm(mn, mn * (mx - 1));
					bst = {mn, mn * (mx - 1)};
				}
				swap(mn, mx);
				if(mlcm(mn, mn * (mx - 1)) < l){
					l = mlcm(mn, mn * (mx - 1));
					bst = {mn, mn * (mx - 1)};
				}
			}
		}	
		cout << bst.fi << " " << bst.se << endl;
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
	- Array bounds
	- Special cases
Be careful!
*/
