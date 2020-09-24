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
	ll u, v;
	cin >> u >> v;
	if(u > v){
		cout << -1 << endl;
		return 0;
	}
	vector<ll> ans = {u};
	ll diff = v - u;
	if(diff & 1){
		cout << -1 << endl;
		return 0;
	}
	for(ll i = 62; i >= 0; i--){
		while((1LL << i) <= diff){
			diff -= (1LL << i);
			ans.pb((1LL << (i - 1)));
			ans.pb((1LL << (i - 1)));
		}
	}
	rep(i, ans.size()) rep(j, ans.size()) if(ans[i] && ans[j]){
		if((ans[i] + ans[j]) == (ans[i] ^ ans[j])){
			ans[i] += ans[j];
			ans[j] = 0;
		}		
	}
	int cnt = 0;
	rep(i, ans.size()) if(ans[i]) cnt++;
	cout << cnt << endl;
	rep(i, ans.size()) if(ans[i]) cout << ans[i] << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
