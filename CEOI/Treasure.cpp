#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include "treasure.h"
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
const int mxN = 105;
 
template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }
 
int n, tot;
int l[mxN], r[mxN], u[mxN], d[mxN]; //all of these are inclusive
int LU[mxN][mxN], LD[mxN][mxN], RU[mxN][mxN], RD[mxN][mxN];
map<array<int, 4>, int> vis, ans;
 
int qry(int r1, int c1, int r2, int c2){
	array<int, 4> ar = {r1, c1, r2, c2};
	if(vis[ar]) return ans[ar];
	vis[ar] = 1;
	int ret = countTreasure(r1, c1, r2, c2);
	ans[ar] = ret;
	return ret;
}

int cst(int r1, int c1, int r2, int c2){
	array<int, 4> ar = {r1, c1, r2, c2};
	if(vis[ar]) return 0;
	return (1 + (n * n) - (r2 - r1 + 1) * (c2 - c1 + 1));
}

bool check(int i, int j){
	int cur = 0;
	if(i > 1) cur += u[i - 1];
	if(i < n) cur += d[i + 1];
	if(j > 1) cur += l[j - 1];
	if(j < n) cur += r[j + 1];
	//now we do the intersections
	if(i > 1 && j > 1) cur -= LU[i - 1][j - 1];
	if(i < n && j > 1) cur -= LD[i + 1][j - 1];
	if(i > 1 && j < n) cur -= RU[i - 1][j + 1];
	if(i < n && j < n) cur -= RD[i + 1][j + 1];
	//assert(cur == tot || cur == (tot - 1));
	return cur != tot;
}
 
void solve(int i, int j, int k){
	if(k == 1){
		if(~RU[i][j]) return;
		int q = qry(1, j, i, n);
		RU[i][j] = q;
		if(j > 1) LU[i][j - 1] = u[i] - RU[i][j];
		if(i < n){
			RD[i + 1][j] = r[j] - RU[i][j];
			if(j > 1) LD[i + 1][j - 1] = l[j - 1] - LU[i][j - 1];
		}
	}
	if(k == 2){
		if(~LU[i][j]) return;
		int q = qry(1, 1, i, j);
		LU[i][j] = q;
		if(i < n) LD[i + 1][j] = l[j] - LU[i][j];
		if(j < n){
			RU[i][j + 1] = u[i] - LU[i][j];
			if(i < n) RD[i + 1][j + 1] = r[j + 1] - RU[i][j + 1];
		}
	}
	if(k == 3){
		if(~RD[i][j]) return;
		int q = qry(i, j, n, n);
		RD[i][j] = q;
		if(i > 1) RU[i - 1][j] = r[j] - RD[i][j];
		if(j > 1){
			LD[i][j - 1] = d[i] - RD[i][j];
			if(i > 1) LU[i - 1][j - 1] = l[j - 1] - LD[i][j - 1];
		}
	}
	if(k == 4){
		if(~LD[i][j]) return;
		int q = qry(i, 1, n, j);
		LD[i][j] = q;
		if(i > 1) LU[i - 1][j] = l[j] - LD[i][j];
		if(j < n){
			RD[i][j + 1] = d[i] - LD[i][j];
			if(i > 1) RU[i - 1][j + 1] = r[j + 1] - RD[i][j + 1];
		}
	}
}
 
int cost(int i, int j, int k){
	if(k == 1) return cst(1, j, i, n);
	if(k == 2) return cst(1, 1, i, j);
	if(k == 3) return cst(i, j, n, n);
	if(k == 4) return cst(i, 1, n, j);
}

bool cmp(array<int, 4> a, array<int, 4> b){
	return cost(a[1], a[2], a[3]) < cost(b[1], b[2], b[3]);
}
 
void findTreasure(int N){
	n = N;
	memset(LD, -1, sizeof(LD));
	memset(LU, -1, sizeof(LU));
	memset(RD, -1, sizeof(RD));
	memset(RU, -1, sizeof(RU));
	tot = qry(1, 1, n, n);
	//l and r
	l[n] = r[1] = tot;
	repn(i, 1, n){
		if(i > (n - i)) l[i] = qry(1, 1, n, i);
		else l[i] = tot - qry(1, i + 1, n, n);
	}
	repn(i, 2, n + 1) r[i] = tot - l[i - 1];
	//u and d
	u[n] = d[1] = tot;
	repn(i, 1, n){
		if(i > (n - i)) u[i] = qry(1, 1, i, n);
		else u[i] = tot - qry(i + 1, 1, n, n);
	}
	repn(i, 2, n + 1) d[i] = tot - u[i - 1];
	repn(i, 1, n + 1){
		repn(j, 1, n + 1){
			if(RU[i][j] == -1){
				vector<array<int, 4>> x;
				x.pb({i * (n - j + 1), i, j, 1});
				if(j > 1) x.pb({i * (j - 1), i, j - 1, 2});
				if(i < n) x.pb({(n - i + 2) * (n - j + 1), i + 1, j, 3});
				if(i < n && j > 1) x.pb({(n - i + 2) * (j - 1), i + 1, j - 1, 4});
				sort(all(x), cmp);
				solve(x[0][1], x[0][2], x[0][3]);
			}
			if(LU[i][j] == -1){
				vector<array<int, 4>> x;
				if(j < n) x.pb({i * (n - j), i, j + 1, 1});
				x.pb({i * j, i, j, 2});
				if(i < n && j < n) x.pb({(n - i) * (n - j), i + 1, j + 1, 3});
				if(i < n) x.pb({(n - i) * j, i + 1, j, 4});
				sort(all(x), cmp);
				solve(x[0][1], x[0][2], x[0][3]);
			}
			if(RD[i][j] == -1){
				vector<array<int, 4>> x;
				if(i > 1) x.pb({(i - 1) * (n - j + 1), i - 1, j, 1});
				if(i > 1 && j > 1) x.pb({(i - 1) * (j - 1), i - 1, j - 1, 2});
				x.pb({(n - i + 1) * (n - j + 1), i, j, 3});
				if(j > 1) x.pb({(n - i + 1) * (j - 1), i, j - 1, 4});
				sort(all(x), cmp);
				solve(x[0][1], x[0][2], x[0][3]);
			}
			if(LD[i][j] == -1){
				vector<array<int, 4>> x;
				if(i > 1 && j < n) x.pb({(i - 1) * (n - j), i - 1, j + 1, 1});
				if(i > 1) x.pb({(i - 1) * j, i - 1, j, 2});
				if(j < n) x.pb({(n - i + 1) * (n - j), i, j + 1, 3});
				x.pb({(n - i + 1) * j, i, j, 4});
				sort(all(x), cmp);
				solve(x[0][1], x[0][2], x[0][3]);
			}
		}
	}
	repn(i, 1, n + 1){
		repn(j, 1, n + 1){
			if(check(i, j)) Report(i, j);
		}
	}
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
