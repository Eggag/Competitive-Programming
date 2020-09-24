#define __AVX__ 1
#define __AVX2__ 1
#define __SSE__ 1
#define __SSE2__ 1
#define __SSE2_MATH__ 1
#define __SSE3__ 1
#define __SSE4_1__ 1
#define __SSE4_2__ 1
#define __SSE_MATH__ 1
#define __SSSE3__ 1
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
#include <x86intrin.h>
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
	unordered_map<int, ll> cnt[11];
	vi vis(15, 0);
	rep(i, n){
		int len = 0;	
		ll num = a[i];
		while(num){
			num /= 10;
			len++;
		}
		vis[len] = 1;
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
			if(vis[j]){
				ll num = (ll)(1LL * (nm % k) * (cur % k)) % k;
				ll need = k - num;
				if(need == k) need = 0;
				ans += cnt[j][need];
			}
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
