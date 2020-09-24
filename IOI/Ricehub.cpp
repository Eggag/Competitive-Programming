#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include "ricehub.h"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
ll tot;
int x[mxN];
ll psum[mxN];

bool check(int g){
	if(g == 1) return 1;
	rep(i, n - g + 1){
		//we have the segment [i, i + g)
		int nm = g / 2;
		ll sm = psum[i + nm - 1] - (i ? psum[i - 1] : 0);
		ll sm1 = x[i + nm] * nm;
		ll cur = sm1 - sm;
		ll sm2 = psum[i + g - 1] - psum[i + nm];
		ll sm3 = x[i + nm] * (g - nm - 1);
		cur += sm2 - sm3;
		if(cur <= tot) return 1;
	}
	return 0;
}

int besthub(int R, int L, int X[], ll B){
	n = R;
	tot = B;
	rep(i, n) x[i] = X[i];
	int l = 1, r = n;
	psum[0] = x[0];
	repn(i, 1, n) psum[i] = psum[i - 1] + x[i];
	while(l < r){
		int mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	return l;
}
