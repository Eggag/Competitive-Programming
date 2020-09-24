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

int n;
int a[5250][5250];

bool check(int x){
	for(int i = 1; i <= n; i += x) for(int j = 1; j <= n; j += x){
		int sum = 0;
		for(int k = 0; k < x; k++){
			for(int l = 0; l < x; l++){
				sum += a[i + k][j + l];
			}
		}
		if(!(sum == 0 || sum == (x * x))) return 0;
	}	
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	//WHY???
	memset(a, 0, sizeof(a));
	repn(i, 1, n + 1){
		string s;
		cin >> s;
		rep(j, (int)s.size()){
			int cur = 0;
			if(s[j] <= '9') cur = s[j] - '0';
			else cur = (s[j] - 'A') + 10;
			string s1 = "";
			rep(k, 4){
				if(cur & (1 << k)) s1 += '1';
				else s1 += '0';
			}
			reverse(all(s1));
			rep(k, 4) a[i][4 * j + k + 1] = (s1[k] - '0');
		}
	}
	int ans = 0;
	for(int i = 1; (i * i) <= n; i++){
		if(n % i == 0){
			ans = max(ans, i * check(i));
			if((n / i) != i) ans = max(ans, (n / i) * check(n / i));
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
