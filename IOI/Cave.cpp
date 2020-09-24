#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include "cave.h"
//#include "grader.c"
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

int ans[5005], ans1[5005], vis[5005];
 
void change(int l, int r){
	repn(i, l, r + 1) if(!vis[i]) ans[i] ^= 1;
}

void exploreCave(int n){
	memset(ans, 0, sizeof(ans));
	memset(vis, 0, sizeof(vis));
	rep(i, n){
		int f = (tryCombination(ans) == i); //is it already in a correct pos?
		int l = 0, r = n - 1;
		while(l < r){
			int mid = (l + r) / 2;
			change(l, mid);
			if((tryCombination(ans) == i) == f){ //doesn't change
				change(l, mid);
				l = mid + 1;
			}
			else{
				change(l, mid);
				r = mid;
			}
		}
		vis[l] = 1;
		ans1[l] = i;
		ans[l] = f;
	}
	answer(ans, ans1);
}
 
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
