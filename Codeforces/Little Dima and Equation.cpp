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
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll p(ll a, ll b){
	ll res = 1;
	for(ll i = 1; i <= b; i++) res *= a;
	return res;
}

ll sum(ll num){
	ll cnt = 0;
	while(num){
		cnt += num % 10;
		num /= 10;
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll a, b, c;
	cin >> a >> b >> c;
	vector<ll> ans;
	for(ll i = 1; i <= 81; i++){
		ll cur = b * p(i, a) + c;
		if(sum(cur) == i && cur < 1000000000) ans.pb(cur);
	}
	cout << ans.size() << endl;
	rep(i, ans.size()) cout << ans[i] << " ";
	if(ans.size()) cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
