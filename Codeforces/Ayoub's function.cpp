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
	ll n, m;
	cin >> n >> m;
	if(!m){
		cout << 0 << endl;
		return;
	}
	ll tot = n - m;
	ll div = (tot) / (m + 1);
	ll num = (n * (n + 1)) / 2;
	ll md = (tot) % (m + 1);
	/*
	if(!div){
		cout << (ll)(num - ((md * (md + 1)) / 2)) << endl;
		return;
	}
	*/
	ll ans = (((div * (div + 1)) / 2) * (m + 1 - md) + ((div + 1) * (div + 2) / 2) * md);
	cout << num - ans << endl;
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
