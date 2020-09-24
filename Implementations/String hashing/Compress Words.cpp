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

string ans = "";
int maxLen = 0;
ll hsh[1000005], hshA[1000005];
string s[1000005];
ll inv1[1000005];
ll p = 349;
ll m = 1e9 + 7;
 
void computeHashes(string s){
	ll hash_value1 = 0;
	ll p_pow1 = 1;
	int cnt = 0;
	for(char c : s){
		hash_value1 = (hash_value1 + (c - '0' + 1) * p_pow1) % m;
		hsh[cnt] = hash_value1;
		cnt++;
		p_pow1 = (p_pow1 * p) % m;
	}
}

ll hash_value = 0;
int len = 0;
ll p_pow = 1;

void computeHashesAns(){
	//extend the hash
	while(len < ans.size()){
		hash_value = (hash_value + (ans[len] - '0' + 1) * p_pow) % m;
		hshA[len] = hash_value;
		p_pow = (p_pow * p) % m;
		len++;
	}
}

ll mypow(ll a, ll p, ll MOD){
	if(p == 0) return 1;
	if(p == 1) return (a % MOD);
	if(p & 1) return ((a % MOD) * (mypow(a, p - 1, MOD) % MOD)) % MOD;
	ll x = mypow(a, p / 2, MOD) % MOD;
	return (x * x) % MOD;
}

void computeInvs(){
	inv1[0] = 1;
	for(int j = 1; j <= 1000000; j++){
      		if(j == 1) inv1[j] = mypow(p, m - 2, m);
		else inv1[j] = (inv1[j - 1] * inv1[1]) % m;
	}
}
 
ll comp_hs(int i, int j){
	ll hs1 = ((hsh[j] - (i ? hsh[i - 1] : 0)) + m) % m;
	(hs1 *= inv1[i]) %= m;
	return hs1;
}
 
ll comp_hs_ans(int i, int j){
	ll hs1 = ((hshA[j] - (i ? hshA[i - 1] : 0)) + m) % m;
	(hs1 *= inv1[i]) %= m;
	return hs1;
}

bool eq(ll a, ll b){
	return a == b;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, n) cin >> s[i], maxLen += (int)s[i].size();
	computeInvs();
	rep(i, n){
		if(!i) ans += s[i];
		else{
			computeHashes(s[i]);
			computeHashesAns(); //keep adding on?
			int l = 0;
			repn(j, 1, min(ans.size(), s[i].size()) + 1){
				if(eq(comp_hs(0, j - 1), comp_hs_ans(ans.size() - 1 - (j - 1), ans.size() - 1))) l = j;
			}
			ans += s[i].substr(l, s[i].size() - l);
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
