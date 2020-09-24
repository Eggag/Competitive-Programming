#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include "rect.h"
//#include "grader.cpp"
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

int ver[2505][5][5];
int hor[5][2505][2505];

ll count_rectangles(vector<vi> a){
	int n = a.size();
	int m = a[0].size();
	memset(ver, 0, sizeof(ver));
	memset(hor, 0, sizeof(hor));
	repn(i, 1, n - 1){
		repn(j, 1, m - 1) repn(k, j, m - 1){
			if(j == k){
				hor[i][j][k] = a[i][j];
			}
			else{
				hor[i][j][k] = max(hor[i][j][k - 1], a[i][k]);
			}
		}
	}
	repn(j, 1, m - 1){
		repn(i, 1, n - 1) repn(k, i, n - 1){
			if(i == k){
				ver[j][i][k] = a[i][j];
			}
			else{
				ver[j][i][k] = max(ver[j][i][k - 1], a[k][j]);
			}
		}
	}
	ll ans = 0;
	repn(i, 1, n - 1) repn(j, 1, m - 1) repn(k, i, n - 1) repn(l, j, m - 1){
		int f = 1;
		repn(x, i, k + 1){
			if(hor[x][j][l] >= a[x][l + 1] || hor[x][j][l] >= a[x][j - 1]){
				f = 0;
				break;
			}
		}	
		if(!f) continue;
		repn(x, j, l + 1){
			if(ver[x][i][k] >= a[k + 1][x] || ver[x][i][k] >= a[i - 1][x]){
				f = 0;
				break;
			}
		}
		if(!f) continue;
		ans++;
	}
	return ans;
}

/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
