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
	int n, k;
	cin >> n >> k;
	vector<ll> a(n + 1);
	repn(i, 1, n + 1) cin >> a[i];
	vector<ll> sum(n + 1);
	sum[0] = 0LL;
	repn(i, 1, n + 1) sum[i] = sum[i - 1] + a[i];
	vector<ll> pos;
	repn(i, 1, n + 1) repn(j, i, n + 1) pos.pb(sum[j] - sum[i - 1]);
	for(ll i = 55; i >= 0; i--){
		//if we have more than k of that bit, only pass down the
		//ones that have it on
		//otherwise, no change
		vector<ll> pos1;
		int cnt = 0;
		rep(j, pos.size()) if(pos[j] & (1LL << i)){
			cnt++;
			pos1.pb(pos[j]);
		}
		if(cnt >= k){
			//we can have this this bit set
			pos = pos1;
		}
	}
	ll ans = pos[0];
	repn(i, 1, k) ans &= pos[i];
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
