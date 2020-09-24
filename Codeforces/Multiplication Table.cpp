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

ll a[1005][1005];
int n;

void go(ll cur){
	vector<ll> res = {cur};
	repn(j, 1, n){
		res.pb(a[0][j] / cur);
	}
	rep(i, n) rep(j, n) if(i != j){
		if(a[i][j] != (res[i] * res[j])) return;
	}
	rep(i, res.size()) cout << res[i] << " ";
	cout << endl;
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	rep(i, n) rep(j, n) cin >> a[i][j];
	ll g = 0;
	rep(i, n) g = gcd(g, a[0][i]);
	for(ll i = 1; i * i <= g; i++){
		go(i);
		go(g / i);
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
