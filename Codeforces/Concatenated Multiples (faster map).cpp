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
	int n;
	ll k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	map<int, ll> cnt[11];
	rep(i, n){
		int len = 0;	
		ll num = a[i];
		while(num){
			num /= 10;
			len++;
		}
		ll nm = a[i] % k;
		cnt[len][nm]++;
	}
	ll ans = 0;
	rep(i, n){
		ll cur = 10LL;
		int len = 0;
		ll num = a[i];
		while(num){
			num /= 10;
			len++;
		}
		ll nm = a[i] % k;
		cnt[len][nm]--;
		repn(j, 1, 11){
			ll num = (ll)(1LL * (nm % k) * (cur % k)) % k;
			ll need = k - num;
			if(need == k) need = 0;
			if(cnt[j].find(need) != cnt[j].end()) ans += cnt[j][need];
			cur *= 10LL;
		}
		cnt[len][nm]++;
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
