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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> p(m);
	rep(i, m) cin >> p[i];
	ll ans = 1;
	ll nxt = p[0] + (k - (p[0] % k));
	if(p[0] % k == 0) nxt = p[0];
	ll prev = 0;
	for(ll i = 0; i < m; i++){
		ll cur = p[i] - prev;
		if(cur > nxt){
			prev = i;
			cur = p[i] - prev;
			ans++;
			nxt = cur + (k - (cur % k));;
			if(cur % k == 0) nxt = cur;
		}
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
