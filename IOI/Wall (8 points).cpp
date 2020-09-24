#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include "wall.h"
#include "grader.cpp"
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
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
	vi a(n, 0);
	rep(i, k){
		if(op[i] == 1){
			repn(j, left[i], right[i] + 1){
				a[j] = max(a[j], height[i]);
			}
		}
		else{
			repn(j, left[i], right[i] + 1){
				a[j] = min(a[j], height[i]);
			}
		}
	}
	rep(i, n) finalHeight[i] = a[i];
	return;
}

/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
