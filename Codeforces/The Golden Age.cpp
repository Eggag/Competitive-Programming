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
	ll x, y, l, r;
	cin >> x >> y >> l >> r;
	vector<ll> posA = {1LL, x}, posB = {1LL, y};
	ll st = x;
	while((r / x) >= st){
		st *= x;
		posA.pb(st);
	}
	st = y;
	while((r / y) >= st){
		st *= y;
		posB.pb(st);
	}
	set<ll> bad1;
	rep(i, posA.size()) rep(j, posB.size()) if((r - posA[i]) >= posB[j]){
		ll sum = posA[i] + posB[j];
		if(sum >= l && sum <= r) bad1.insert(sum);
	}
	vector<ll> bad(all(bad1));
	ll ans = 0;
	rep(i, bad.size()) debug(bad[i]);
	rep(i, bad.size()){
		if(!i) ans = max(ans, bad[i] - l);
		else ans = max(ans, bad[i] - bad[i - 1] - 1);
	}
	if(bad.size()) ans = max(ans, r - bad[(int)bad.size() - 1]);
	else ans = max(ans, r - l + 1);
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
