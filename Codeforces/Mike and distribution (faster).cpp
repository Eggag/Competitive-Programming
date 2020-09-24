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

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n), b(n), x(n);
	ll suma = 0, sumb = 0;
	rep(i, n) cin >> a[i], suma += a[i];
	rep(i, n) cin >> b[i], sumb += b[i];
	rep(i, n) x[i] = i;
	cout << (n / 2) + 1 << endl;
	while(1){
		shuffle(all(x), rng);
		ll sum = 0;
		rep(i, (n / 2) + 1) sum += a[x[i]];
		sum *= 2;
		ll sum1 = 0;
		rep(i, (n / 2) + 1) sum1 += b[x[i]];
		sum1 *= 2;
		if(sum > suma && sum1 > sumb){
			rep(i, (n / 2) + 1) cout << x[i] + 1 << " ";
			cout << endl;
			return 0;
		}
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
