#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
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
const int mxN = 1e6 + 5;
const int logn = 14;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
int a[mxN], mn[logn][mxN], mx[logn][mxN];
 
int minQ(int l, int r) { // [l; r)
	int t = __lg(r - l);
	return min(mn[t][l], mn[t][r - (1 << t)]);
}
 
int maxQ(int l, int r) { // [l; r)
	int t = __lg(r - l);
	return max(mx[t][l], mx[t][r - (1 << t)]);
}

int main(){
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, c;
	scanf("%d%d%d", &n, &m, &c);
	rep(i, n) scanf("%d", &a[i]);
	memcpy(mx[0], a, sizeof a);
	memcpy(mn[0], a, sizeof a);
	for(int l = 0; l < logn - 1; l++){
		for(int i = 0; i + (2 << l) <= n; i++){
			mn[l + 1][i] = min(mn[l][i], mn[l][i + (1 << l)]);
			mx[l + 1][i] = max(mx[l][i], mx[l][i + (1 << l)]);
		}
	}
	int nm = 0;
	rep(i, n - m + 1) if((maxQ(i, i + m) - minQ(i, i + m)) <= c) printf("%d\n", i + 1), nm++;
	if(!nm) printf("NONE\n");
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
