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
#include<bits/stdc++.h>
#include<x86intrin.h>
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

ll n;
vector<ll> p;
ll x, a;
ll y, b;
ll k;

ll lcm(ll a, ll b){
	return (a * b) / gcd(a, b);
}

bool check(ll num){
	ll g = lcm(a, b);
	g = num / g;
	int ind = 0;
	ll ans = 0;
	rep(i, g){
		ans += (p[ind] * (x + y)) / 100;
		ind++;
	}
	for(ll i = a; i <= num; i += a) if(i % b != 0){
		ans += (p[ind] * x) / 100;
		ind++;
	}
	for(ll i = b; i <= num; i += b) if(i % a != 0){
		ans += (p[ind] * y) / 100;
		ind++;
	}
	return (ans >= k);
}

void solve(){
	cin >> n;
	ll d;
	p.clear();
	rep(i, n) cin >> d, p.pb(d);
	cin >> x >> a;
	cin >> y >> b;
	if(y > x) swap(x, y), swap(a, b);
	sort(all(p));
	reverse(all(p));
	cin >> k;
	ll l = 0, r = n;
	if(!check(n)){
		cout << -1 << endl;
		return;
	}
	while(l < r){
		ll mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
