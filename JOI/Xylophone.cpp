#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include "xylophone.h"
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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(int n){
	int l = 0, r = n - 2;
	while(l < r){
		int mid = (l + r + 1) / 2;
		int q = query(mid + 1, n);
		if(q == (n - 1)) l = mid;
		else r = mid - 1;
	}
	vi ans(n, 0), vis(n + 1, 0);
	ans[l] = 1;
	vis[1] = 1;
	if(l > 0){
		int qu2 = query(l, l + 1);
		ans[l - 1] = qu2 + 1;
		vis[ans[l - 1]] = 1;
		for(int i = l - 2; i >= 0; i--){
			int qu1 = query(i + 1, i + 2);
			if(ans[i + 1] + qu1 > n || vis[ans[i + 1] + qu1]){
				ans[i] = ans[i + 1] - qu1;
				vis[ans[i]] = 1;
				continue;
			}
			if(ans[i + 1] - qu1 < 1 || vis[ans[i + 1] - qu1]){
				ans[i] = ans[i + 1] + qu1;
				vis[ans[i]] = 1;
				continue;
			}
			vi cur = {ans[i + 1], ans[i + 2], ans[i + 1] + qu1};
			sort(all(cur));
			int qu = query(i + 1, i + 3);
			if(cur[2] - cur[0] == qu) ans[i] = ans[i + 1] + qu1;
			else ans[i] = ans[i + 1] - qu1;
			vis[ans[i]] = 1;
		}
	}
	if(l < (n - 1)){
		int qu2 = query(l + 1, l + 2);
		ans[l + 1] = qu2 + 1;
		vis[ans[l + 1]] = 1;
		for(int i = l + 2; i < n; i++){
			int qu1 = query(i, i + 1);
			if(ans[i - 1] + qu1 > n || vis[ans[i - 1] + qu1]){
				ans[i] = ans[i - 1] - qu1;
				vis[ans[i]] = 1;
				continue;
			}
			if(ans[i - 1] - qu1 < 1 || vis[ans[i - 1] - qu1]){
				ans[i] = ans[i - 1] + qu1;
				vis[ans[i]] = 1;
				continue;
			}
			vi cur = {ans[i - 2], ans[i - 1], ans[i - 1] + qu1};
			sort(all(cur));
			int qu = query(i - 1, i + 1);
			if(cur[2] - cur[0] == qu) ans[i] = ans[i - 1] + qu1;
			else ans[i] = ans[i - 1] - qu1;
			vis[ans[i]] = 1;
		}
	}
	rep(i, n) answer(i + 1, ans[i]);
}
