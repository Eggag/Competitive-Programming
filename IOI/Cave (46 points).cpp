#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include "cave.h"
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
 
void exploreCave(int n){
	int ans2[n];
	rep(i, n) ans2[i] = 0;
	vi vis(n, 0);
	rep(i, n){
		//i is the current door
		//all doors before should be already open
		int cur = tryCombination(ans2);
		if(cur == -1) break;
		if(cur > i){ //don't have to but do to not use that switch late (vis)
			rep(j, n) if(!vis[j]){
				ans2[j] ^= 1;
				cur = tryCombination(ans2);
				if(cur == i){
					ans2[j] ^= 1;
					vis[j] = 1;
					break;
				}
				ans2[j] ^= 1;
			}
		}
		else{
			rep(j, n) if(!vis[j]){
				int f = 1;
				ans2[j] ^= 1;
				cur = tryCombination(ans2);
				if(cur == -1 || cur > i) f = 0, vis[j] = 1;
				if(f) ans2[j] ^= 1;
				if(!f) break;
			}
		}
	}
	//now we know the correct order
	int ans[n];
	rep(i, n){
		ans2[i] ^= 1;
		int res = tryCombination(ans2);
		ans[i] = res;
		ans2[i] ^= 1;
	}
	answer(ans2, ans);
}
 
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
