#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include "molecules.h"
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
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi find_subset(int l, int r, vi w) {
	int n = w.size();
	vector<pi> w1(n + 1);
	repn(i, 1, n + 1) w1[i] = mp(w[i - 1], i - 1);
	sort(all(w1));
	vector<ll> sum(n + 1, 0);
	repn(i, 1, n + 1) sum[i] = sum[i - 1] + w1[i].fi;
	repn(len, 1, n + 1){
		ll mn = sum[len], mx = sum[n] - sum[n - len];
		if(mn > r || mx < l) continue;
		for(int i = 0; (i + len) <= n; i++){
			ll cur = sum[i + len] - sum[i];
			if(cur <= r && cur >= l){ 
				//we found it
				vi ans;
				repn(j, i + 1, i + len + 1) ans.pb(w1[j].se);
				return ans;
			}
		}
	}
	return vi(0);
}

/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
